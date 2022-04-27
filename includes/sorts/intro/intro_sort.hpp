//
// Created by Illarion on 27.04.2022.
//

#ifndef PROJECTSORTS_INTRO_SORT_HPP
#define PROJECTSORTS_INTRO_SORT_HPP

# include <algorithm>
# include "sorts/heap/heap_sort.hpp"
# include "sorts/insertion/insertion_sort.hpp"

namespace my_sort
{
	template <typename ForwardIterator>
	void	IntroSort(ForwardIterator begin, ForwardIterator end);
}

# include "intro_sort.inl"

#endif //PROJECTSORTS_INTRO_SORT_HPP
