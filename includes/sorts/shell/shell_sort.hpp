//
// Created by Illarion on 23.04.2022.
//

#ifndef PROJECTSORTS_SHELL_SORT_HPP
#define PROJECTSORTS_SHELL_SORT_HPP

#include <iostream>
#include <vector>

namespace my_sort
{
	template <typename ForwardIterator>
	void	ShellSort(ForwardIterator begin, ForwardIterator end);
}

# include "shell_sort.inl"

#endif //PROJECTSORTS_SHELL_SORT_HPP
