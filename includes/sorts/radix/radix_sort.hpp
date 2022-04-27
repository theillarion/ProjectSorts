//
// Created by Illarion on 25.04.2022.
//

#ifndef PROJECTSORTS_RADIX_SORT_HPP
#define PROJECTSORTS_RADIX_SORT_HPP

# include <vector>
# include <list>

namespace my_sort
{
	template <typename ForwardIterator>
	void	RadixSort(ForwardIterator begin, ForwardIterator end);
};

# include "radix_sort.inl"

#endif //PROJECTSORTS_RADIX_SORT_HPP
