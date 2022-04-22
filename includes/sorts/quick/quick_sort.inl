#include "quick_sort.hpp"


template<typename ForwardIterator>
static auto	FindPivot(ForwardIterator begin, ForwardIterator end)
{
	if (*begin > *end)
		return	*begin;
	else
		return	*end;
}

template<typename ForwardIterator>
static ForwardIterator	Partition(auto PivotElement, ForwardIterator begin, ForwardIterator end)
{
	ForwardIterator	local_first = begin;
	ForwardIterator	local_end = end;

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
		auto		v = FindPivot(begin, end - 1);
		ForwardIterator	m = Partition(v, begin, end - 1);
		QuickSort(begin, m - 1);
		if (begin == m)
			QuickSort(m + 1, end);
		else
			QuickSort(m, end);
	}
}
