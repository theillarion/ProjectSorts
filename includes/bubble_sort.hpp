//
// Created by Illarion on 15.04.22.
//

#ifndef PROJECTSORTS_BUBBLE_SORT_HPP
# define PROJECTSORTS_BUBBLE_SORT_HPP

# include <vector>

namespace my_sort
{
	template <typename T>
	void	BubbleSort(std::vector<T>& src);
}

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

#endif //PROJECTSORTS_BUBBLE_SORT_HPP
