#include "intro_sort.hpp"

template<typename ForwardIterator>
static void Sort(ForwardIterator begin, ForwardIterator end, int depth)
{
	if (begin < end)
	{
		if (depth == 0)
			my_sort::HeapSort(begin, end);
		else if (std::distance(begin, end) <= 16)
			my_sort::InsertionSort(begin, end);
		else
		{
			auto		v = FindPivotMedian(begin, end);
			ForwardIterator	m = Partition(v, begin, end);
			Sort(begin, m, depth - 1);
			if (begin == m)
				Sort(m + 1, end, depth - 1);
			else
				Sort(m, end, depth - 1);
		}
	}
}

template <typename ForwardIterator>
void	my_sort::IntroSort(ForwardIterator begin, ForwardIterator end)
{
	Sort(begin, end, (int)(2 * log(std::distance(begin, end))));
}
