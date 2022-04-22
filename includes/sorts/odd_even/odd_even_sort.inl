#include "odd_even_sort.hpp"

template <typename ForwardIterator>
void	my_sort::OddEvenSort(ForwardIterator begin, ForwardIterator end)
{
	bool	is_find = true;

	if (begin >= end)
		return;
	while (is_find)
	{
		is_find = false;
		for (auto it = begin; it < end - 1; it += 2)
		{
			if (*it > *(it + 1))
			{
				std::swap(*it, *(it + 1));
				is_find = true;
			}
		}
		for (auto it = begin + 1; it < end - 1; it += 2)
		{
			if (*it > *(it + 1))
			{
				std::swap(*it, *(it + 1));
				is_find = true;
			}
		}
	}
}
