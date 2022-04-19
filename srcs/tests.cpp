//
// Created by Illarion on 19.04.2022.
//

# include "common.hpp"
# include "quick_sort.hpp"
# include "date.hpp"
# include "generate_random.hpp"

# define LIGHT_RED "\033[91m"
# define LIGHT_GREEN "\033[92m"
# define NOCOLOR "\033[0m"

void PrintSimpleArray(int	*ptr, unsigned int size)
{
	std::cout << "{ ";
	for (auto i = 0; i < size; ++i)
		std::cout << ptr[i] << " ";
	std::cout << "}" << std::endl;
}

void Test1()
{
	std::vector<int>	src = {3, 1, 4, 1, 5, 9, 2, 3};
	std::cout << src;
	my_sort::QuickSort(src.begin(), src.end() - 1);
	std::cout << src;
}

void Test1_1()
{
	std::vector<int>	src = {-6, -3, 2, 10, 1, 3, -6, -4, 1, 3 };
	std::cout << src;
	my_sort::QuickSort(src.begin(), src.end());
	std::cout << src;
}


void Test2()
{
	std::vector<Date>	src = {
			{16, 01, 2002},
			{12, 01, 2000},
			{29, 12, 1992},
			{18, 9, 2020}
	};
	std::cout << src;
	my_sort::QuickSort(src.begin(), src.end() - 1);
	std::cout << src;
}

void Test3()
{
	const unsigned int n = 10;
	int	*arr = new int[n]{1, 5, 3, 10, 5, -100, 7, 6, 1, 10};

	PrintSimpleArray(arr, n);
	my_sort::QuickSort(arr, arr + (n - 1));
	PrintSimpleArray(arr, n);
	std::cout << (IsSorted(arr, arr + n) ? "true" : "false") << std::endl;
}

void Test4()
{
	std::vector<int>	src{1};
	std::cout << src;
	my_sort::QuickSort(src.begin(), src.end());
	std::cout << src << (IsSorted(src.begin(), src.end()) ? "true" : "false") << std::endl;
}

void Test5()
{
	for (auto i = 0; i < 100; ++i)
	{
		unsigned int size = GenerateRandomInt32(0, 1000);
		std::vector<int>	vec = GenerateRandomVector(INT32_MIN, INT32_MAX, size);
		std::cout << vec;
		my_sort::QuickSort(vec.begin(), vec.end());
		bool is_sorted = IsSorted(vec.begin(), vec.end());
		std::cout << vec;
		if (is_sorted)
			std::cout << "TRUE" << std::endl;
		else
		{
			std::cout << "FALSE" << std::endl;
			return ;
		}
	}
	std::cout << std::endl;
}
