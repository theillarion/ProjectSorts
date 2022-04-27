#include "radix_sort.hpp"

template <typename Type>
void	SortPockets(std::vector<std::list<Type>>& pockets, int count, unsigned int base = 10, unsigned int size = 11)
{
	int				temp;
	for (int current_digit = 1; current_digit <= size && count != pockets[0].size(); ++current_digit)
	{
		for (auto i = 0; i < pockets.size(); ++i)
		{
			for (auto it = pockets[i].begin(); !pockets[i].empty() && it != pockets[i].end();)
			{
				temp = (abs(*it / (int)pow(10, current_digit)) % base);
				if (temp == i)
					++it;
				else
				{
					bool	is_find = false;
					for (auto it_j = pockets[temp].begin(); it_j != pockets[temp].end(); ++it_j)
					{
						if (*it <= *it_j)
						{
							pockets[temp].emplace(it_j, *it);
							is_find = true;
							break;
						}

					}
					if (!is_find)
						pockets[temp].push_back(*it);
					it = pockets[i].erase(it);
				}
			}
		}
	}
}

template <typename ForwardIterator>
void	my_sort::RadixSort(ForwardIterator begin, ForwardIterator end)
{
	using value_type = std::iterator_traits<ForwardIterator>::value_type;
	std::vector<std::list<value_type>>	positive_pockets;
	std::vector<std::list<value_type>>	negative_pockets;
	unsigned int count_positive = 0;
	unsigned int count_negative = 0;
	unsigned int count_zeros = 0;
	int base = 10;

	positive_pockets.resize(base);
	negative_pockets.resize(base);
	for (auto it = begin; it != end; ++it)
	{
		if (*it < 0)
		{
			negative_pockets[abs(*it % base)].push_back(*it);
			++count_negative;
		}
		else if (*it > 0)
		{
			positive_pockets[*it % base].push_back(*it);
			++count_positive;
		}
		else
			++count_zeros;
	}
	if (count_positive > 0)
		SortPockets(positive_pockets, count_positive);

	if (count_negative > 0)
		SortPockets(negative_pockets, count_negative);

	if (!negative_pockets[0].empty())
		std::move(negative_pockets[0].begin(), negative_pockets[0].end(), begin);
	if (count_zeros > 0)
		std::fill(begin + count_negative, begin + count_negative + count_zeros, 0);
	if (!positive_pockets[0].empty())
		std::move(positive_pockets[0].begin(), positive_pockets[0].end(), begin + count_negative + count_zeros);
}
