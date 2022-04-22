#include "insertion_sort.hpp"

template<typename ForwardIterator>
void	my_sort::InsertionSort(ForwardIterator begin, ForwardIterator end)
{
	if (begin >= end)
		return;
	for (auto it_i = begin + 1; it_i < end; ++it_i)
	{
		if (*(it_i - 1) <= *it_i)
			continue;
		for (auto it_j = begin; it_j < it_i; ++it_j)
		{
			if (*it_i < *it_j)
			{
				auto backup = *it_i;
				std::move(it_j, it_i, it_j + 1);
				*it_j = backup;
				break;
			}
		}
	}
}
