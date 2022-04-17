//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_ODD_EVEN_SORT_HPP
# define PROJECTSORTS_ODD_EVEN_SORT_HPP

# include <vector>

namespace my_sort
{
	template <typename T>
	void	OddEvenSort(std::vector<T>& src);
}

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

#endif //PROJECTSORTS_ODD_EVEN_SORT_HPP
