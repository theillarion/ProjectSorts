//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_SHAKER_SORT_HPP
# define PROJECTSORTS_SHAKER_SORT_HPP

# include <vector>

namespace my_sort
{
	template <typename T>
	void	ShakerSort(std::vector<T>& src);
}

template <typename T>
inline void	my_sort::ShakerSort(std::vector<T>& src)
{
	int	left	= 0;
	int	right	= src.size() - 1;
	bool	is_find = false;

	while (left < right)
	{
		is_find = false;
		for (auto i = left; i + 1 <= right; ++i)
		{
			if (src[i] > src[i + 1])
			{
				std::swap(src[i], src[i + 1]);
				is_find = true;
			}
		}
		if (is_find == false)
			break;
		--right;
		for (auto i = right; i - 1 >= left; --i)
		{
			if (src[i - 1] > src[i])
			{
				std::swap(src[i], src[i - 1]);
				is_find = true;
			}
		}
		if (is_find == false)
			break ;
		++left;
	}
}

#endif //PROJECTSORTS_SHAKER_SORT_HPP
