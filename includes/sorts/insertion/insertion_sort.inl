#include "insertion_sort.hpp"
#include "common/common.hpp"

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
				auto backup(*it_i);
				std::move_backward(it_j, it_i, it_i + 1);
				*it_j = backup;
				break;
			}
		}
	}
}
