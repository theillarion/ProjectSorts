//
// Created by Illarion on 27.04.2022.
//

#ifndef PROJECTSORTS_REPORT_HPP
#define PROJECTSORTS_REPORT_HPP

# include <string>
# include <vector>
# include <functional>
# include <ctime>
# include <iterator>
# include <format>

template <typename Type>
class Report
{
private:
	std::string						name;
	std::string						name_os;
	std::string						name_test;
	std::string						path_to_dir_src;
	std::string						path_to_dir_dst;

	using vector_iter = std::vector<Type>::iterator;
	using vector_pair_functions = std::vector<std::pair<std::string, std::function<void(vector_iter, vector_iter)>>>;
	vector_pair_functions	functions_sort;

	std::string	NowTimeToString();
public:

	Report(vector_pair_functions functions_sort,
		std::string name, std::string name_os,
		std::string name_test,
		std::string path_to_dir_src,
		std::string path_to_dir_dst);

	void	CreateReport(unsigned int count_min, unsigned int count_max, bool is_rewrite_files);
};

# include "report.inl"

#endif //PROJECTSORTS_REPORT_HPP
