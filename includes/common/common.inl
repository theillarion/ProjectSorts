#include "common.hpp"

template <typename T>
inline std::ostream& operator<<(std::ostream& out, std::vector<T>&	src)
{
	out << "{ ";
	for (const auto& elem: src)
		out << elem << " ";
	out << "}" << std::endl;
	return (out);
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, std::list<T>& src)
{
	out << "{ ";
	for (const auto& elem : src)
		out << elem << " ";
	out << "}" << std::endl;
	return (out);
}

template <typename Type>
inline std::ostream& operator<<(std::ostream& out, const std::set<Type>& src)
{
	if (src.size() == 1)
		out << *(src.begin());
	else if (src.size() > 1)
	{
		out << "{ ";
		for (const auto& elem : src)
			out << elem << " ";
		out << "}";
	}
	return (out);
}

template<typename ForwardIterator>
inline void	PrintRange(ForwardIterator begin, ForwardIterator end)
{
	static unsigned int count = 1;
	std::cout << count++ << " : { ";
	for (auto it = begin; it <= end; ++it)
		std::cout << *it << " ";
	std::cout << "}" << std::endl;
}

template <typename Type>
inline std::vector<std::vector<Type>>	ReaderNumbersFromFile(const std::string& path)
{
	std::ifstream					file;
	std::vector<std::vector<Type>>	result;
	std::string						line_buffer;

	if (!std::filesystem::is_regular_file(path))
		throw std::invalid_argument("File isn't exists");

	file.open(path);
	if (!file.is_open())
		throw std::ifstream::failure("File isn't open");

	while (std::getline(file, line_buffer))
	{
		std::vector<Type>	numbers;
		std::stringstream	buff(line_buffer);

		std::copy(std::istream_iterator<Type>(buff), std::istream_iterator<Type>(), std::back_inserter(numbers));
		result.push_back(numbers);
	}
	file.close();
	return (result);
}
