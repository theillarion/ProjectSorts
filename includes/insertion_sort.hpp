//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_INSERTION_SORT_HPP
# define PROJECTSORTS_INSERTION_SORT_HPP

# include <vector>

namespace my_sort
{
	template<typename ForwardIterator>
	void	InsertionSort(ForwardIterator begin, ForwardIterator end);

}

template<typename ForwardIterator>
inline void	my_sort::InsertionSort(ForwardIterator begin, ForwardIterator end)
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

#endif //PROJECTSORTS_INSERTION_SORT_HPP
