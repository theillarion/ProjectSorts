//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_COMB_SORT_HPP
#define PROJECTSORTS_COMB_SORT_HPP

# include <vector>

namespace my_sort
{
	template<typename ForwardIterator>
	void	CombSort(ForwardIterator begin, ForwardIterator end);
}

template<typename ForwardIterator>
inline void my_sort::CombSort(ForwardIterator begin, ForwardIterator end)
{
	const double reduction_factor = 1.247330950103979;
	int step = (end - begin) / reduction_factor;

	while (step > 1)
	{
		for (auto it = begin; it < end - step; it += step)
			if (*it > *(it + step))
				std::swap(*it, *(it + step));
		step /= reduction_factor;
	}
	BubbleSort(begin, end);
}

#endif //PROJECTSORTS_COMB_SORT_HPP
