//
// Created by pro10 on 19.04.2022.
//

#ifndef PROJECTSORTS_TESTS_HPP
#define PROJECTSORTS_TESTS_HPP

# include <iostream>
# include <vector>
# include <string>
# include <format>
# include <algorithm>
# include "common.hpp"
# include "generate_random.hpp"
# include "quick_sort.hpp"
# include "bubble_sort.hpp"
# include "date.hpp"
# include "timer.hpp"

# define LIGHT_YELLOW	"\033[93m"
# define LIGHT_RED		"\033[91m"
# define NOCOLOR		"\033[0m"
# define OK				"\033[92mOK\033[0m"
# define KO				"\033[91mKO\033[0m"

void Test1();
void Test1_1();
void Test2();
void Test3();
void Test5();

template<typename FunctionSort>
void TestIsSorted(std::string name_sort, FunctionSort function_sort);

template<typename FunctionSort>
void	TestIsSorted(std::string name_sort, FunctionSort function_sort, size_t size, size_t count);

template<typename ForwardIterator, typename FunctionSort>
void	TestTime(std::string name_sort, FunctionSort function_sort, ForwardIterator begin, ForwardIterator end);

static inline void	Result(bool is_success)
{
	static size_t i = 1;
	static std::string test = "Test #";
	std::cout << (test + std::to_string(i++) + ": " + (is_success ? OK : KO)) << std::endl;
}

template<typename FunctionSort>
inline void	TestIsSorted(std::string name_sort, FunctionSort function_sort, size_t size, size_t count)
{
	std::vector<int>	vec;
	bool				_result;

	for (auto i = 0; i < count; ++i)
	{
		vec = GenerateRandomVector(INT32_MIN, INT32_MAX, size);
		function_sort(vec.begin(), vec.end());
		_result = std::is_sorted(vec.begin(), vec.end());
		if (!_result)
		{
			std::cout << LIGHT_RED << "ERROR!" << NOCOLOR << std::endl;
			break;
		}
		Result(_result);
		vec.clear();
	}
}

template<typename Type, typename FunctionSort>
inline void	TestTime(std::string name_sort, FunctionSort function_sort, std::vector<Type>&	src)
{
	unsigned long long	times = 0;
	size_t				count = 0;
	std::vector<Type>	backup;

	backup.resize(src.size());
	
	for (int i = 0; times == 0 && i < 100; ++i)
	{
		std::copy(src.begin(), src.end(), backup.begin());
		Timer::Start();
		function_sort(backup.begin(), backup.end());
		Timer::Stop();
		if (!std::is_sorted(backup.begin(), backup.end()))
		{
			std::cout << LIGHT_RED << "ERROR!" << NOCOLOR << std::endl;
			break;
		}
		times += Timer::GetTime();
		++count;
	}
	std::cout << "Testing sort <" << LIGHT_YELLOW << name_sort << NOCOLOR << ">" << std::endl;
	Result(std::is_sorted(backup.begin(), backup.end()));
	std::cout <<	"Count:	" << src.size() << std::endl <<
					"Times:	" << (static_cast<double>(times) / (count)) / 1000.0 << " seconds" << std::endl << std::endl;
}

template<typename FunctionSort>
inline void TestIsSorted(std::string name_sort, FunctionSort function_sort)
{
	std::vector<int>	vec;

	std::cout << "Testing sort <" << LIGHT_YELLOW << name_sort << NOCOLOR << ">" << std::endl << std::endl;

	//	TEST 1
	function_sort(vec.begin(), vec.end());
	Result(vec.empty());

	vec.clear();
	
	//	TEST 2
	vec = { 1 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();
	
	//	TEST 3
	vec = { 1, 2, 3 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();
	
	//	TEST 4
	vec = { 3, 2, 1, 4 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));
	
	vec.clear();

	//	TEST 5
	vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 6
	vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, -10 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));
	std::cout << vec;

	vec.clear();

	//	TEST 7
	vec = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 8
	vec = { 10, -2, -3, 4, -5, 6, -7, 8, -9, -10 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 9
	vec = { 1, 5, 3, 10, 5, -100, 7, 6, 1, 10 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 10
	vec = { 1, 1, 1, -1, -1, -1, 1, 1, -1, -1, 1, 1 };
	function_sort(vec.begin(), vec.end());
	Result(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();
	
	std::cout << std::endl << "Random tests" << std::endl;
	
	//	TEST 11 - 20
	for (int i = 0; i < 10; ++i)
	{
		vec.clear();
		size_t	size = (size_t)GenerateRandomInt32(0, 100);
		vec = GenerateRandomVector(INT32_MIN, INT32_MAX, 100);
		function_sort(vec.begin(), vec.end());
		Result(std::is_sorted(vec.begin(), vec.end()));
	}
}

#endif //PROJECTSORTS_TESTS_HPP
