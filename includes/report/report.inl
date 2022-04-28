#include "report.hpp"

std::string	Report::NowTimeToString()
{
	time_t seconds = time(NULL);

	return (asctime(localtime(&seconds)));
}

Report::Report(vector_pair_functions functions_sort,
	std::string name, std::string name_os,
	std::string name_test,
	std::string path_to_dir_src,
	std::string path_to_dir_dst) :
	functions_sort(functions_sort), name(name), name_os(name_os),
	name_test(name_test), path_to_dir_src(path_to_dir_src), path_to_dir_dst(path_to_dir_dst)
{

}

template <typename Type>
void	Report::CreateReport(unsigned int count_min, unsigned int count_max, bool is_rewrite_files)
{
	bool							is_enable_color = false;
	std::vector<std::vector<int>>	numbers;
	std::string						path_to_file_input;
	std::string						path_to_file_output;
	std::ofstream					file;

	auto TempFunction = [](int number) -> std::string
	{
		std::string result;
		int count = 0;

		while (number)
		{
			if (count != 0 && count % 3 == 0)
			{
				result.insert(result.begin(), '_');
				count = 0;
			}
			result.insert(result.begin(), (number % 10) + '0');
			number /= 10;
			++count;
		}
		return (result);
	};

	try
	{
		for (int count_elements = count_min; count_elements <= count_max; count_elements *= 10)
		{
			std::string	dst = TempFunction(count_elements);
			bool		is_exist = false;

			path_to_file_input = std::format("{}/{}/{}", path_to_dir_src, dst, name_test);
			path_to_file_output = std::format("{}/{}/result__{}__{}", path_to_dir_dst, dst, name_os, name_test);

			numbers = ReaderNumbersFromFile<Type>(path_to_file_input);

			if (!is_rewrite_files && std::filesystem::is_regular_file(path_to_file_output))
			{
				std::clog << "File <" << path_to_file_output << "> " << LIGHT_YELLOW << "NO REWRITE" << NOCOLOR << std::endl;
				continue;
			}
			else if (std::filesystem::is_regular_file(path_to_file_output))
				is_exist = true;

			std::ofstream	file(path_to_file_output, std::ios_base::trunc);
			std::ostream_iterator<char>	out(file);

			std::string	buff = "Report created on: " + NowTimeToString() + "\n";
			std::copy(buff.begin(), buff.end(), out);

			for (const auto& pair_sort : functions_sort)
				TestTime(pair_sort.first, pair_sort.second, numbers.begin(), numbers.end(), out, is_enable_color);

			ResultIsSortedToString(true, true, true);	// reset static variable

			file.close();

			if (is_exist)
				std::clog << "File <" << path_to_file_output << ">: " << LIGHT_GREEN << "REWRITE" << NOCOLOR << std::endl;
			else
				std::clog << "File <" << path_to_file_output << ">: " << LIGHT_GREEN << "OK" << NOCOLOR << std::endl;
		}
	}
	catch (std::exception exp)
	{
		std::cerr << "Exception: " << exp.what() << std::endl;
	}
}
