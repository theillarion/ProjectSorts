//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_ODD_EVEN_SORT_HPP
# define PROJECTSORTS_ODD_EVEN_SORT_HPP

# include <vector>

namespace my_sort
{
	/*template <typename T>
	void	OddEvenSort(std::vector<T>& src);*/
	template <typename ForwardIterator>
	void	OddEvenSort(ForwardIterator begin, ForwardIterator end);
}

/*
template <typename T>
inline void	my_sort::OddEvenSort(std::vector<T>& src)
{
	bool	is_find;

	is_find = true;
	while (is_find)
	{
		is_find = false;
		for (auto j = 0; j + 1 < src.size(); j += 2)
		{
			if (src[j] > src[j + 1])
			{
				std::swap(src[j], src[j + 1]);
				is_find = true;
				std::cout << src;
			}
		}
		for (auto j = 1; j + 1 < src.size(); j += 2)
		{
			if (src[j] > src[j + 1])
			{
				std::swap(src[j], src[j + 1]);
				is_find = true;
				std::cout << src;
			}
		}
	}
}
*/

template <typename ForwardIterator>
inline void	my_sort::OddEvenSort(ForwardIterator begin, ForwardIterator end)
{
	bool	is_find = true;

	if (begin >= end)
		return;
	while (is_find)
	{
		is_find = false;
		for (auto it = begin; it < end - 1; it += 2)
		{
			if (*it > *(it + 1))
			{
				std::swap(*it, *(it + 1));
				is_find = true;
			}
		}
		for (auto it = begin + 1; it < end - 1; it += 2)
		{
			if (*it > *(it + 1))
			{
				std::swap(*it, *(it + 1));
				is_find = true;
			}
		}
	}
}

#endif //PROJECTSORTS_ODD_EVEN_SORT_HPP
