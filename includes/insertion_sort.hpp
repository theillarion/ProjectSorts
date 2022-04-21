//
// Created by Illarion on 15.04.2022.
//

#ifndef PROJECTSORTS_INSERTION_SORT_HPP
# define PROJECTSORTS_INSERTION_SORT_HPP

# include <vector>

namespace my_sort
{
	template<typename ForwardIterator>
	void	InsertionSort(ForwardIterator begin, ForwardIterator end);

}

//template<typename T>
//inline void	my_sort::InsertionSort(std::vector<T>& src)
//{
//	std::vector<T>	result;
//	bool			is_insert;
//
//	for (const auto& elem : src)
//	{
//		if (result.empty())
//			result.push_back(elem);
//		else
//		{
//			is_insert = false;
//			for (int i = result.size() - 1; i >= 0; --i)
//			{
//				if (result[i] <= elem)
//				{
//					result.insert(result.begin() + i + 1, elem);
//					is_insert = true;
//					break ;
//				}
//			}
//			if (is_insert == false)
//				result.insert(result.begin(), elem);
//		}
//	}
//	src = result;
//}

template<typename ForwardIterator>
inline void	my_sort::InsertionSort(ForwardIterator begin, ForwardIterator end)
{
	if (begin >= end)
		return;
	for (auto it_i = begin + 1; it_i < end; ++it_i)
	{
		if (*(it_i - 1) <= *it_i)
			continue;
		for (auto it_j = begin; it_j < it_i; ++it_j)
		{
			if (*it_i < *it_j)
			{
				auto backup = *it_i;
				std::move(it_j, it_i, it_j + 1);
				*it_j = backup;
				break;
			}
		}
	}
}

#endif //PROJECTSORTS_INSERTION_SORT_HPP
