#include "heap_sort.hpp"

template <typename ForwardIterator>
static void	Push(ForwardIterator begin, ForwardIterator end, auto root_value, unsigned int root_index)
{
	if (root_index * 2 + 1 < end - begin)
	{
		ForwardIterator	largest = begin + (root_index * 2 + 1);
		ForwardIterator	right_child = begin + (root_index * 2 + 2);
		if (right_child < end && *right_child > *largest)
			largest = right_child;
		if (*largest > root_value)
		{
			std::swap(*largest, *(begin + root_index));
			Push(begin, end, *largest, std::distance(begin, largest));
		}
	}
}

template <typename ForwardIterator>
static void	BuildHeap(ForwardIterator begin, ForwardIterator end)
{
	for (auto i = (end - begin) / 2 - 1; i >= 0; --i)
		Push(begin, end, *(begin + i), i);
}

template <typename ForwardIterator>
void	my_sort::HeapSort(ForwardIterator begin, ForwardIterator end)
{
	if (begin < end)
	{
		BuildHeap(begin, end);
		for (auto it = end; it > begin; --it)
		{
			std::swap(*begin, *(it - 1));
			Push(begin, it - 1, *begin, 0);
		}
	}
}
