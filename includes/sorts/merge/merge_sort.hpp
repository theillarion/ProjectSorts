//
// Created by Illarion on 22.04.2022.
//

#ifndef PROJECTSORTS_MERGE_SORT_HPP
#define PROJECTSORTS_MERGE_SORT_HPP

# include <algorithm>

namespace my_sort
{
	template<typename ForwardIterator>
	void	MergeSort(ForwardIterator begin, ForwardIterator end);
}

# include "merge_sort.inl"

#endif //PROJECTSORTS_MERGE_SORT_HPP
