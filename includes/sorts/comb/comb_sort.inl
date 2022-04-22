#include "comb_sort.hpp"

template<typename ForwardIterator>
void my_sort::CombSort(ForwardIterator begin, ForwardIterator end)
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
