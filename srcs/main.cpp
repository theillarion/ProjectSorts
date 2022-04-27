//
// Created by Illarion on 19.04.2022.
//

#include "sorts/sorts.hpp"
#include "tests/tests.hpp"
#include "report/report.hpp"

int main()
{
	using vector_iter = std::vector<int>::iterator;

	std::vector<std::pair<std::string, std::function<void(std::vector<int>::iterator, std::vector<int>::iterator)>>>	functions_sort
	{
		{"Bubble sort", my_sort::BubbleSort<vector_iter>},
		{"Comb sort", my_sort::CombSort<vector_iter>},
		{"Odd-Even sort", my_sort::OddEvenSort<vector_iter>},
		{"Shaker sort", my_sort::ShakerSort<vector_iter>},
		{"Shell sort", my_sort::ShellSort<vector_iter>},
		{"Selection sort", my_sort::SelectionSort<vector_iter>},
		{"Insertion sort", my_sort::InsertionSort<vector_iter>},
		{"Merge sort", my_sort::MergeSort<vector_iter>},
		{"Heap sort", my_sort::HeapSort<vector_iter>},
		{"Quick sort", my_sort::QuickSort<vector_iter>},
		{"Intro sort", my_sort::IntroSort<vector_iter>},
		{"Origin sort", std::sort<vector_iter>},
		{"Stable origin sort", std::stable_sort<vector_iter>}
	};

	Report report{ functions_sort, "result", "win11", "test1", "C:/Users/pro10/forProject/tests", "../../../result" };

	report.CreateReport<int>(10, 10000, true);

	return 0;
}
