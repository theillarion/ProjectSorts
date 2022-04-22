#include "shaker_sort.hpp"

template <typename ForwardIterator>
void	my_sort::ShakerSort(ForwardIterator begin, ForwardIterator end)
{
	ForwardIterator	local_begin	= begin;
	ForwardIterator	local_end	= end;
	bool			is_find		= true;

	while (is_find && local_begin < local_end)
	{
		is_find = false;
		for (auto it = local_begin; it < local_end - 1; ++it)
		{
			if (*it > *(it + 1))
			{
				std::swap(*it, *(it + 1));
				is_find = true;
			}
		}
		if (is_find == false)
			break;
		--local_end;
		for (auto it = local_end - 1; it >= local_begin + 1; --it)
		{
			if (*(it - 1) > *it)
			{
				std::swap(*(it - 1), *it);
				is_find = true;
			}
		}
		++local_begin;
	}
}
