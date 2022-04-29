//
// Created by pro10 on 19.04.2022.
//

#ifndef PROJECTSORTS_TESTS_HPP
#define PROJECTSORTS_TESTS_HPP

# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <format>
# include "sorts/sorts.hpp"
# include "common/common.hpp"
# include "random/generate_random.hpp"
# include "timer/timer.hpp"

# define LIGHT_GREEN	"\033[92m"
# define LIGHT_YELLOW	"\033[93m"
# define LIGHT_RED		"\033[91m"
# define NOCOLOR		"\033[0m"

template<typename TypeData, typename FunctionSort, typename TypeOutput>
void	TestTime(std::string name_sort, FunctionSort function_sort,
	std::vector<std::vector<TypeData>>& src,
	std::ostream_iterator<TypeOutput> output, bool is_enabled_color);

template<typename FunctionSort, typename Type>
void	TestIsSorted(std::string name_sort, FunctionSort function_sort,
	std::ostream_iterator<Type>	out, size_t size, size_t count,
	bool is_enabled_color);

template<typename FunctionSort>
void	TestIsSorted(std::string name_sort, FunctionSort function_sort);

# include "tests.inl"

#endif //PROJECTSORTS_TESTS_HPP
