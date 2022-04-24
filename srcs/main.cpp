//
// Created by Illarion on 19.04.2022.
//

#include "sorts/sorts.hpp"

#include "tests/tests.hpp"

int main()
{
	std::ofstream	file("result__win11__1000__unsorted__-1000_1000__no_uniq", std::ios_base::trunc);
	std::vector<std::vector<int>>	numbers;
	std::ostream_iterator<char>	output(file);
	
	try
	{
		numbers = ReaderNumbersFromFile<int>("C:\\Users\\pro10\\OneDrive\\Рабочий стол\\tests\\1_000\\unsorted__-1000_1000__no_uniq");

		TestTime("Bubble sort", my_sort::BubbleSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Shaker sort", my_sort::ShakerSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Odd-Even sort", my_sort::OddEvenSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Comb sort", my_sort::CombSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Selection sort", my_sort::SelectionSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Insertion sort", my_sort::InsertionSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Heap sort", my_sort::HeapSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Shell sort", my_sort::ShellSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Merge sort", my_sort::MergeSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Quick sort", my_sort::QuickSort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
		TestTime("Original sort", std::sort<std::vector<int>::iterator>, numbers.begin(), numbers.end(), output, false);
	}
	catch (std::exception exp)
	{
		std::cerr << "Exception: " << exp.what() << std::endl;
	}
	return 0;
}
