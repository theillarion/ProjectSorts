#include "tests.hpp"

static std::string	OutputColor(const std::string&	color, bool is_enable)
{
	if (is_enable)
		return (color);
	return std::string("");
}

static std::string	ResultIsSortedToString(bool is_success, bool is_enabled_color = true, bool is_reset = false)
{
	static size_t i = 1;
	std::string result;
	std::string	color;

	if (is_reset)
	{
		i = 1;
		return ("");
	}
	color = (is_success ? LIGHT_GREEN : LIGHT_RED);

	return (
		"Test #" + std::to_string(i++) + ": " +
		(is_enabled_color ? color : "") +
		(is_success ? "OK" : "KO") +
		(is_enabled_color ? NOCOLOR : "") + "\n"
	);
}

template <typename Type>
static std::string SetToString(const std::set<Type>& src)
{
	std::string result;

	if (src.size() == 1)
		result = std::to_string(*src.begin());
	else if (src.size() > 1)
	{
		result += "{ ";
		for (const auto& elem : src)
			result += elem + " ";
		result += "}";
	}
	return (result);
}

template <typename Type>
std::string	to_string(Type value)
{
	std::stringstream	buff;
	buff << value;
	return (buff.str());
}

std::string	TimesToString()
{
	std::string result;
}

template<typename ForwardIterator, typename FunctionSort, typename Type>
void	TestTime(std::string name_sort, FunctionSort function_sort,
						ForwardIterator begin, ForwardIterator end,
						std::ostream_iterator<Type> output, bool is_enabled_color)
{
	using value_type = std::iterator_traits<ForwardIterator>::value_type;
	double	times;
	std::vector<value_type>	buffer;
	std::set<unsigned int>	sizes;
	std::string				result;
	bool					is_true;

	if (begin >= end)
	{
		std::cerr << LIGHT_RED << "ERROR: " << NOCOLOR << "begin >= end" << std::endl;
		return;
	}

	std::copy(begin, end, std::back_inserter(buffer));

	
	for (auto& elems : buffer)
	{
		Timer::Start();
		function_sort(elems.begin(), elems.end());
		Timer::Stop();
		times += Timer::GetTimeSec();
	}
	
	times /= buffer.size();

	bool is_sorted = true;
	for (auto& elems : buffer)
	{
		sizes.insert(elems.size());
		if (!std::is_sorted(elems.begin(), elems.end()))
		{
			is_sorted = false;
			break;
		}
	}

	result =	"Testing sort <" +
				OutputColor(LIGHT_YELLOW, is_enabled_color) +
				name_sort +
				OutputColor(LIGHT_YELLOW, is_enabled_color) + ">" + '\n' +
				ResultIsSortedToString(is_sorted, is_enabled_color) +
				"Count arrays: " + std::to_string(buffer.size()) + "\n" + 
				"Count elems: " + SetToString(sizes) + "\n" +
				"Times: " + std::to_string(times) + " seconds\n" +
				"       " + std::to_string(times * 1000) + " milliseconds\n"
				"       " + std::to_string(times * 1000000) + " microseconds\n";

	std::copy(result.begin(), result.end(), output);
}

template<typename FunctionSort, typename Type>
void	TestIsSorted(std::string name_sort, FunctionSort function_sort,
			std::ostream_iterator<Type>	out, size_t size, size_t count,
			bool is_enabled_color = false)
{
	std::vector<int>	vec;
	std::string			buffer;
	bool				is_sorted;

	for (auto i = 0; i < count; ++i)
	{
		vec = GenerateRandomVector(INT32_MIN, INT32_MAX, size);
		function_sort(vec.begin(), vec.end());
		is_sorted = std::is_sorted(vec.begin(), vec.end());
		buffer += ResultIsSortedToString(is_sorted, is_enabled_color);
		std::copy(buffer.begin(), buffer.end(), out);
		if (!is_sorted)
			break;
		buffer.clear();
		vec.clear();
	}
}

template<typename FunctionSort>
void TestIsSorted(std::string name_sort, FunctionSort function_sort)
{
	std::vector<int>	vec;

	std::cout << "Testing sort <" << LIGHT_YELLOW << name_sort << NOCOLOR << ">" << std::endl << std::endl;

	//	TEST 1
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(vec.empty());

	vec.clear();

	//	TEST 2
	vec = { 1 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 3
	vec = { 1, 2, 3 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 4
	vec = { 3, 2, 1, 4 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 5
	vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 6
	vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, -10 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 7
	vec = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 8
	vec = { 10, -2, -3, 4, -5, 6, -7, 8, -9, -10 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 9
	vec = { 1, 5, 3, 10, 5, -100, 7, 6, 1, 10 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	//	TEST 10
	vec = { 1, 1, 1, -1, -1, -1, 1, 1, -1, -1, 1, 1 };
	function_sort(vec.begin(), vec.end());
	std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));

	vec.clear();

	std::cout << std::endl << "Random tests" << std::endl;

	//	TEST 11 - 20
	for (int i = 0; i < 10; ++i)
	{
		vec.clear();
		size_t	size = (size_t)GenerateRandomInt32(0, 100);
		vec = GenerateRandomVector(INT32_MIN, INT32_MAX, 100);
		function_sort(vec.begin(), vec.end());
		std::cout << ResultIsSortedToString(std::is_sorted(vec.begin(), vec.end()));
	}
}
