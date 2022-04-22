#include "selection_sort.hpp"

template<typename ForwardIterator>
void	my_sort::SelectionSort(ForwardIterator begin, ForwardIterator end)
{
	ForwardIterator	min_iterator;

	for (auto it_i = begin; it_i < end; ++it_i)
	{
		min_iterator = it_i;
		for (auto it_j = it_i + 1; it_j < end; ++it_j)
			if (*it_j < *min_iterator)
				min_iterator = it_j;
		if (it_i != min_iterator)
			std::swap(*it_i, *min_iterator);
	}
}
