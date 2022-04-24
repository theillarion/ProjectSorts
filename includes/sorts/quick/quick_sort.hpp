//
// Created by Illarion on 17.04.2022.
//

#ifndef PROJECTSORTS_QUICK_SORT_HPP
#define PROJECTSORTS_QUICK_SORT_HPP

namespace my_sort
{
	template <typename ForwardIterator>
	void	QuickSort(ForwardIterator	begin, ForwardIterator	end);
	template <typename ForwardIterator, typename FindPivot>
	void	QuickSort(ForwardIterator	begin, ForwardIterator	end, FindPivot find_pivot);
}

# include "quick_sort.inl"

#endif //PROJECTSORTS_QUICK_SORT_HPP
