//
// Created by Illarion on 19.04.2022.
//

# include "tests.hpp"

void Test1()
{
	std::vector<int>	src = GenerateRandomVector(INT32_MIN, INT32_MAX, 10000);
	Timer::Start();
	my_sort::QuickSort(src.begin(), src.end());
	Timer::Stop();
	std::cout << "Vector is sorted: " <<
		(std::is_sorted(src.begin(), src.end()) ? "true\n" : "false\n") <<
		"Millisecods: " << Timer::GetTime() <<
		std::endl << "Seconds: " << Timer::GetTimeSeconds() << std::endl;
}

void Test1_1()
{
	for (int i = 0; i < 100; ++i)
	{
		std::vector<int>	src = GenerateRandomVector(INT32_MIN, INT32_MAX, 10);
		Timer::Start();
		my_sort::BubbleSort(src.begin(), src.end());
		Timer::Stop();
		std::cout << src;
		std::cout << "Vector is sorted: " <<
			(std::is_sorted(src.begin(), src.end()) ? "true\n" : "false\n") <<
			"Millisecods: " << Timer::GetTime() <<
			std::endl << "Seconds: " << Timer::GetTimeSeconds() << std::endl << std::endl;
	}
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
	std::cout << (std::is_sorted(arr, arr + n) ? "true" : "false") << std::endl;
}

void Test4()
{
	std::vector<int>	src{1};
	std::cout << src;
	my_sort::QuickSort(src.begin(), src.end());
	std::cout << src << (std::is_sorted(src.begin(), src.end()) ? "true" : "false") << std::endl;
}

void Test5()
{
	for (auto i = 0; i < 100; ++i)
	{
		unsigned int size = GenerateRandomInt32(0, 1000);
		std::vector<int>	vec = GenerateRandomVector(INT32_MIN, INT32_MAX, size);
		std::cout << vec;
		my_sort::QuickSort(vec.begin(), vec.end());
		bool is_sorted = std::is_sorted(vec.begin(), vec.end());
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
