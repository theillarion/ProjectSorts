#include "bubble_sort.hpp"

template <typename ForwardIterator>
void	my_sort::BubbleSort(ForwardIterator begin, ForwardIterator end)
{
	bool	is_find;

	for (auto it_i = end; it_i != begin; --it_i)
	{
		is_find = false;
		for (auto it_j = begin; it_j + 1 < it_i; ++it_j)
		{
			if (*it_j > *(it_j + 1))
			{
				std::swap(*it_j, *(it_j + 1));
				is_find = true;
			}
		}
		if (is_find == false)
			break;
	}
}
