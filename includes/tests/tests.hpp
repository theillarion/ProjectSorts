//
// Created by pro10 on 19.04.2022.
//

#ifndef PROJECTSORTS_TESTS_HPP
#define PROJECTSORTS_TESTS_HPP

# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include "sorts/sorts.hpp"
# include "common/common.hpp"
# include "random/generate_random.hpp"
# include "data/date.hpp"
# include "timer/timer.hpp"

# define LIGHT_YELLOW	"\033[93m"
# define LIGHT_RED		"\033[91m"
# define NOCOLOR		"\033[0m"
# define OK				"\033[92mOK\033[0m"
# define KO				"\033[91mKO\033[0m"

void	Test1();
void	Test1_1();
void	Test2();
void	Test3();
void	Test5();
void	TestForArray();
void	Result(bool is_success);

template<typename ForwardIterator, typename FunctionSort>
void	TestTime(std::string name_sort, FunctionSort function_sort, ForwardIterator begin, ForwardIterator end);

template<typename FunctionSort>
void	TestIsSorted(std::string name_sort, FunctionSort function_sort, size_t size, size_t count);

template<typename FunctionSort>
void	TestIsSorted(std::string name_sort, FunctionSort function_sort);

# include "tests.inl"

#endif //PROJECTSORTS_TESTS_HPP
