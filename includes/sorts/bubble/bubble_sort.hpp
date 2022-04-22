//
// Created by Illarion on 15.04.22.
//

#ifndef PROJECTSORTS_BUBBLE_SORT_HPP
# define PROJECTSORTS_BUBBLE_SORT_HPP

# include <vector>

namespace my_sort
{
	template <typename ForwardIterator>
	void	BubbleSort(ForwardIterator begin, ForwardIterator end);
}

# include "bubble_sort.inl"

#endif //PROJECTSORTS_BUBBLE_SORT_HPP
