//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_COMMON_HPP
# define PROJECTSORTS_COMMON_HPP

# include <iostream>
# include <vector>
# include <list>

template <typename T>
std::ostream&	operator<<(std::ostream& out, std::vector<T>&	src);

template <typename T>
std::ostream&	operator<<(std::ostream& out, std::list<T>& src);

template<typename ForwardIterator>
void	PrintRange(ForwardIterator begin, ForwardIterator end);

void PrintSimpleArray(int* ptr, unsigned int size);

# include "common.inl"

#endif //PROJECTSORTS_COMMON_HPP