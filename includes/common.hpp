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

template <typename T>
bool	IsSorted(std::vector<T>& src);


template <typename T>
inline std::ostream& operator<<(std::ostream& out, std::vector<T>&	src)
{
	out << "{ ";
	for (const auto& elem: src)
		out << elem << " ";
	out << "}" << std::endl;
	return (out);
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, std::list<T>& src)
{
	out << "{ ";
	for (const auto& elem : src)
		out << elem << " ";
	out << "}" << std::endl;
	return (out);
}

template <typename Iterator>
inline bool IsSorted(Iterator begin, Iterator end)
{
	for (auto it = begin; it + 1 < end; ++it)
	{
		if (*it > *(it + 1))
			return (false);
	}
	return (true);
}

#endif //PROJECTSORTS_COMMON_HPP
