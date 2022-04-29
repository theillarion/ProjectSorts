//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_COMMON_HPP
# define PROJECTSORTS_COMMON_HPP

# include <iostream>
# include <vector>
# include <list>
# include <string>
# include <set>
# include <filesystem>
# include <fstream>

template <typename T>
std::ostream&	operator<<(std::ostream& out, std::vector<T>&	src);

template <typename T>
std::ostream&	operator<<(std::ostream& out, std::list<T>& src);

template <typename Type>
std::ostream& operator<<(std::ostream& out, const std::set<Type>& src);

template<typename ForwardIterator>
void	PrintRange(ForwardIterator begin, ForwardIterator end);

void PrintSimpleArray(int* ptr, unsigned int size);

template <typename Type>
std::string SetToString(const std::set<Type>& src);

template <typename Type>
std::string	to_string(Type value);

template <typename Type>
std::vector<std::vector<Type>>	ReadAllLineFromFile(const std::string& path);

# include "common.inl"

#endif //PROJECTSORTS_COMMON_HPP