//
// Created by Illarion on 19.04.2022.
//

#include "sorts/sorts.hpp"

#include "tests/tests.hpp"
#include "random/generate_random.hpp"

int main()
{
	std::vector<int>	numbers = GenerateRandomVector(INT32_MIN, INT32_MAX, 500000000);

	TestTime("Quick sort", my_sort::QuickSort<std::vector<int>::iterator>, numbers);
	TestTime("Original sort", std::sort<std::vector<int>::iterator>, numbers);
	return 0;
}


//TestIsSorted("Quick sort", my_sort::QuickSort<std::vector<int>::iterator>);
//TestIsSorted("Quick sort", my_sort::QuickSort<std::vector<int>::iterator>, 100, 10000);
////Test1();
/*TestTime("Bubble sort", my_sort::BubbleSort<std::vector<int>::iterator>, numbers);
TestTime("Shaker sort", my_sort::ShakerSort<std::vector<int>::iterator>, numbers);
TestTime("Odd-Even sort", my_sort::OddEvenSort<std::vector<int>::iterator>, numbers);
TestTime("Comb sort", my_sort::CombSort<std::vector<int>::iterator>, numbers);
TestTime("Selection sort", my_sort::SelectionSort<std::vector<int>::iterator>, numbers);
TestTime("Insertion sort", my_sort::InsertionSort<std::vector<int>::iterator>, numbers);*/