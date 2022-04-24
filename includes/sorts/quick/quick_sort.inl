#include "quick_sort.hpp"

template<typename ForwardIterator>
static auto	FindPivotMedian(ForwardIterator begin, ForwardIterator end)
{
	if (end - begin == 1 || end - begin == 2)
		return (*begin);
	ForwardIterator	middle = begin + (std::distance(begin, end) / 2);
	if (*middle < *begin)
		std::swap(*middle, *begin);
	if (*(end - 1) < *begin)
		std::swap(*(end - 1), *begin);
	if (*(end - 1) < *middle)
		std::swap(*(end - 1), *middle);
	return (*middle);
}

template<typename ForwardIterator>
static auto	FindPivotDefault(ForwardIterator begin, ForwardIterator end)
{
	if (*begin >= *(end - 1))
		return (*begin);
	else
		return (*(end - 1));
}

template<typename ForwardIterator>
static ForwardIterator	Partition(auto PivotElement, ForwardIterator begin, ForwardIterator end)
{
	ForwardIterator	local_first = begin;
	ForwardIterator	local_end = end - 1;

	if (local_first >= local_end)
		return local_first;
	do
	{
		while (*local_first < PivotElement && local_first < end)
			++local_first;
		while (*local_end >= PivotElement && local_end > begin)
			--local_end;
		if (local_first < local_end)
			std::swap(*local_first, *local_end);
	} while (local_first < local_end);
	return local_first;
}

template<typename ForwardIterator>
void my_sort::QuickSort(ForwardIterator begin, ForwardIterator end)
{
	if (begin < end)
	{
		auto		v = FindPivotDefault(begin, end);
		ForwardIterator	m = Partition(v, begin, end);
		QuickSort(begin, m);
		if (begin == m)
			QuickSort(m + 1, end);
		else
			QuickSort(m, end);
	}
}

template <typename ForwardIterator, typename FindPivot>
void my_sort::QuickSort(ForwardIterator begin, ForwardIterator end, FindPivot find_pivot)
{
	if (begin < end)
	{
		auto		v = find_pivot(begin, end);
		ForwardIterator	m = Partition(v, begin, end);
		QuickSort(begin, m);
		if (begin == m)
			QuickSort(m + 1, end);
		else
			QuickSort(m, end);
	}
}