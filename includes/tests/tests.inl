#include "tests.hpp"

template<typename ForwardIterator, typename FunctionSort, typename Type>
static long double TestTimeTen(FunctionSort function_sort, ForwardIterator begin, ForwardIterator end, const std::vector<Type>&	buffer)
{
	unsigned int count_iter = 1000;
	std::vector<std::vector<Type>>	test_vecs;

	if (end - begin >= 1000)
		count_iter = 100;
	if (end - begin >= 1000)
		count_iter = 10;
	test_vecs.resize(count_iter);
	for (auto& vec : test_vecs)
		copy(begin, end, std::back_inserter(vec));
	Timer::Start();
	for (auto& vec : test_vecs)
		function_sort(vec.begin(), vec.end());
	Timer::Stop();
	return (static_cast<long double>(Timer::GetTime()) / count_iter);
}

template<typename ForwardIterator, typename FunctionSort, typename Type>
inline void	TestTime(std::string name_sort, FunctionSort function_sort, ForwardIterator begin, ForwardIterator end, std::vector<Type>	buffer)
{
	long double times = 0.0;
	std::cout << "Testing sort <" << LIGHT_YELLOW << name_sort << NOCOLOR << ">" << std::endl;
	
	if (begin >= end)
	{
		std::cerr << LIGHT_RED << "ERROR: " << NOCOLOR << "begin >= end" << std::endl;
		return;
	}

	buffer.clear();
	std::copy(begin, end, std::back_inserter(buffer));

	Timer::Start();
	function_sort(buffer.begin(), buffer.end());
	Timer::Stop();
	if (Timer::GetTime() == 0)
		times = TestTimeTen(function_sort, begin, end, buffer);
	else
		times = static_cast<long double>(Timer::GetTime());
	Result(std::is_sorted(buffer.begin(), buffer.end()));
	if (end - begin < 10000)
		std::cout.precision(10);
	std::cout.setf(std::ios::fixed);
	std::cout << "Count:	" << end - begin << std::endl <<
		"Times:	" << times / 1000.0 << " seconds" << std::endl << std::endl;
}

template<typename FunctionSort>
void	TestIsSorted(std::string name_sort, FunctionSort function_sort, size_t size, size_t count)
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
