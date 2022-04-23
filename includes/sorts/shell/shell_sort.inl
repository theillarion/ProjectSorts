#include "shell_sort.hpp"

template <typename ForwardIterator>
void	my_sort::ShellSort(ForwardIterator begin, ForwardIterator end)
{
	unsigned int step = (end - begin) / 2;

	if (begin < end)
	{
		while (step)
		{
			for (auto it_i = begin + step; it_i < end; ++it_i)
				for (auto it_j = it_i; it_j - begin >= step; it_j -= step)
					if (*(it_j - step) > *it_j)
						std::swap(*(it_j - step), *it_j);
			step /= 2;
		}
	}
}
