//
// Created by Illarion on 17.04.2022.
//

#ifndef PROJECTSORTS_QUICK_SORT_HPP
#define PROJECTSORTS_QUICK_SORT_HPP

# include <vector>
# include <iterator>

namespace my_sort
{
	template <typename ForwardIterator>
	void	QuickSort(ForwardIterator	begin, ForwardIterator	end);
	
}

template<typename ForwardIterator>
static inline auto	FindPivot(ForwardIterator begin, ForwardIterator end)
{
	if (*begin > *end)
		return	*begin;
	else
		return	*end;
}

template<typename ForwardIterator>
static inline ForwardIterator	Partition(auto PivotElement, ForwardIterator begin, ForwardIterator end)
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
void	OutputRange(ForwardIterator begin, ForwardIterator end)
{
	static unsigned int count = 1;
	std::cout << count++ << " : { ";
	for (auto it = begin; it <= end; ++it)
		std::cout << *it << " ";
	std::cout << "}" << std::endl;
}

template<typename ForwardIterator>
inline void my_sort::QuickSort(ForwardIterator begin, ForwardIterator end)
{
	if (begin < end)
	{
		auto		v = FindPivot(begin, end - 1);
		ForwardIterator	m = Partition(v, begin, end - 1);
		//OutputRange(begin, end);
		QuickSort(begin, m);
		if (begin == m)
			QuickSort(m + 1, end);
		else
			QuickSort(m, end);
	}
}

#endif //PROJECTSORTS_QUICK_SORT_HPP
