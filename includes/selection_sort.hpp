//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_SELECTION_SORT_HPP
# define PROJECTSORTS_SELECTION_SORT_HPP

# include <vector>

namespace my_sort
{
	template<typename T>
	void	SelectionSort(std::vector<T>& src);
}

template<typename T>
inline void	my_sort::SelectionSort(std::vector<T>& src)
{
	size_t	min_index;

	for (auto i = 0; i < src.size() - 1; ++i)
	{
		min_index = i;
		for (auto j = i + 1; j < src.size(); ++j)
			if (src[j] < src[min_index])
				min_index = j;
		if (i != min_index)
			std::swap(src[i], src[min_index]);
	}
}

#endif //PROJECTSORTS_SELECTION_SORT_HPP
