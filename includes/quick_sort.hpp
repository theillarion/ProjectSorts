//
// Created by Illarion on 17.04.2022.
//

#ifndef PROJECTSORTS_QUICK_SORT_HPP
#define PROJECTSORTS_QUICK_SORT_HPP

# include <vector>
# include <iterator>

namespace my_sort
{
	template <typename Iterator>
	void	QuickSort(Iterator	first, Iterator	end);
	
}

template<typename Iterator>
static inline auto	FindPivot(Iterator first, Iterator end)
{
	if (*first > *end)
		return	*first;
	else
		return	*end;
}

template<typename Iterator>
static inline Iterator	Partition(auto PivotElement,
									Iterator first, Iterator end)
{
	Iterator	local_first = first;
	Iterator	local_end = end;

	if (local_first >= local_end)
		return local_first;
	do
	{
		while (*local_first < PivotElement && local_first < end)
			++local_first;
		while (*local_end >= PivotElement && local_end > first)
			--local_end;
		if (local_first < local_end)
			std::swap(*local_first, *local_end);
	} while (local_first < local_end);
	return local_first;
}

template<typename Iterator>
inline void my_sort::QuickSort(Iterator first, Iterator end)
{
	if (end > first)
	{
		auto		v = FindPivot(first, end);
		Iterator	m = Partition(v, first, end);
		if (first == m)
			return;
		QuickSort(first, m - 1);
		QuickSort(m, end);
	}
}

#endif //PROJECTSORTS_QUICK_SORT_HPP
