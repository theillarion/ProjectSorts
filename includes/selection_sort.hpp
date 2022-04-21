//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_SELECTION_SORT_HPP
# define PROJECTSORTS_SELECTION_SORT_HPP

# include <vector>

namespace my_sort
{
	template<typename ForwardIterator>
	void	SelectionSort(ForwardIterator begin, ForwardIterator end);
}

//template<typename T>
//inline void	my_sort::SelectionSort(std::vector<T>& src)
//{
//	size_t	min_index;
//
//	for (auto i = 0; i < src.size() - 1; ++i)
//	{
//		min_index = i;
//		for (auto j = i + 1; j < src.size(); ++j)
//			if (src[j] < src[min_index])
//				min_index = j;
//		if (i != min_index)
//			std::swap(src[i], src[min_index]);
//	}
//}

template<typename ForwardIterator>
inline void	my_sort::SelectionSort(ForwardIterator begin, ForwardIterator end)
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

#endif //PROJECTSORTS_SELECTION_SORT_HPP
