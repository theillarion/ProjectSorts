//
// Created by Illarion on 19.04.2022.
//

#include "sorts/sorts.hpp"
#include "tests/tests.hpp"
#include "report/report.hpp"
#include "data/date.hpp"
#include <string>

int main()
{
	using current_type = int;
	using vector_iter = std::vector<current_type>::iterator;
	using vector_iter_string = std::vector<std::string>::iterator;
	using vector_iter_date = std::vector<Date>::iterator;

	std::vector<std::pair<std::string, std::function<void(vector_iter, vector_iter)>>>	functions_sort_all
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

	std::vector<std::pair<std::string, std::function<void(vector_iter, vector_iter)>>>	functions_sort_group_1
	{
		{"Bubble sort", my_sort::BubbleSort<vector_iter>},
		{"Comb sort", my_sort::CombSort<vector_iter>},
		{"Odd-Even sort", my_sort::OddEvenSort<vector_iter>},
		{"Shaker sort", my_sort::ShakerSort<vector_iter>},
		{"Shell sort", my_sort::ShellSort<vector_iter>},
		{"Selection sort", my_sort::SelectionSort<vector_iter>},
		{"Insertion sort", my_sort::InsertionSort<vector_iter>},
	};

	std::vector<std::pair<std::string, std::function<void(vector_iter, vector_iter)>>>	functions_sort_group_2
	{
		{"Merge sort", my_sort::MergeSort<vector_iter>},
		{"Heap sort", my_sort::HeapSort<vector_iter>},
		{"Quick sort", my_sort::QuickSort<vector_iter>},
		{"Intro sort", my_sort::IntroSort<vector_iter>},
		{"Origin sort", std::sort<vector_iter>},
		{"Stable origin sort", std::stable_sort<vector_iter>}
	};

	bool is_rewrite = false;
	Report<int>{ functions_sort_all, "result", "win11", "test1", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 100000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test1", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(1000000, 100000000, is_rewrite);

	Report<int>{ functions_sort_all, "result", "win11", "test2", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 100000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test2", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(1000000, 100000000, is_rewrite);

	Report<int>{ functions_sort_all, "result", "win11", "test6", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 100000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test6", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(1000000, 100000000, is_rewrite);

	Report<int>{ functions_sort_all, "result", "win11", "test7", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 100000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test7", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(1000000, 100000000, is_rewrite);

	Report<int>{ functions_sort_all, "result", "win11", "test8", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 100000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test8", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(1000000, 100000000, is_rewrite);

	Report<int>{ functions_sort_all, "result", "win11", "test9", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 100000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test9", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(1000000, 100000000, is_rewrite);

	Report<int>{ functions_sort_all, "result", "win11", "test10", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 100000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test10", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(1000000, 100000000, is_rewrite);
	
	Report<int>{ functions_sort_all, "result", "win11", "test5", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10, 1000000, is_rewrite);
	Report<int>{ functions_sort_group_2, "result", "win11", "test5", "C:/Users/pro10/forProject/tests", "../../../result" }.CreateReport(10000000, 100000000, is_rewrite);

	return 0;
}
