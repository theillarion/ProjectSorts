//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_INSERTION_SORT_HPP
# define PROJECTSORTS_INSERTION_SORT_HPP

# include <vector>

namespace my_sort
{
	template<typename T>
	void	InsertionSort(std::vector<T>& src);

}

template<typename T>
inline void	my_sort::InsertionSort(std::vector<T>& src)
{
	std::vector<T>	result;
	bool			is_insert;

	for (const auto& elem : src)
	{
		if (result.empty())
			result.push_back(elem);
		else
		{
			is_insert = false;
			for (int i = result.size() - 1; i >= 0; --i)
			{
				if (result[i] <= elem)
				{
					result.insert(result.begin() + i + 1, elem);
					is_insert = true;
					break ;
				}
			}
			if (is_insert == false)
				result.insert(result.begin(), elem);
		}
	}
	src = result;
}

#endif //PROJECTSORTS_INSERTION_SORT_HPP
