//
// Created by Illarion on 15.04.22.
//

#ifndef PROJECTSORTS_BUBBLE_SORT_HPP
# define PROJECTSORTS_BUBBLE_SORT_HPP

# include <vector>

namespace my_sort
{
	//template <typename T>
	//void	BubbleSort(std::vector<T>& src);

	template <typename ForwardIterator>
	void	BubbleSort(ForwardIterator begin, ForwardIterator end);
}
/*
template <typename T>
inline void	my_sort::BubbleSort(std::vector<T>& src)
{
	bool	is_find;

	for (auto i = src.size() - 1; i > 0; --i)
	{
		is_find = false;
		for (auto j = 0; j + 1 <= i; ++j)
		{
			if (src[j] > src[j + 1])
			{
				std::swap(src[j], src[j + 1]);
				is_find = true;
				std::cout << src;
			}
		}
		if (is_find == false)
			break;
	}
}
*/

template <typename ForwardIterator>
inline void	my_sort::BubbleSort(ForwardIterator begin, ForwardIterator end)
{
	bool	is_find;

	for (auto it_i = end; it_i != begin; --it_i)
	{
		is_find = false;
		for (auto it_j = begin; it_j + 1 < it_i; ++it_j)
		{
			if (*it_j > *(it_j + 1))
			{
				std::swap(*it_j, *(it_j + 1));
				is_find = true;
			}
		}
		if (is_find == false)
			break;
	}
}

#endif //PROJECTSORTS_BUBBLE_SORT_HPP
