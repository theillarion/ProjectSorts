#include "merge_sort.hpp"

template<typename ForwardIterator>
static void	Merge(ForwardIterator orig_begin, ForwardIterator orig_end,
	ForwardIterator begin, ForwardIterator middle, ForwardIterator end)
{
	std::sort(begin, end + 1);
	if (std::distance(orig_begin, orig_end) == std::distance(begin, end))
		std::move(begin, end + 1, orig_begin);
}

template<typename ForwardIterator>
static void	Sort(ForwardIterator orig_begin, ForwardIterator orig_end,
	ForwardIterator begin, ForwardIterator end)
{
	if (begin <= end)
	{
		ForwardIterator	middle = begin + (std::distance(begin, end) / 2);
		if (middle > begin)
			Sort(orig_begin, orig_end, begin, middle);
		if (middle + 1 < end)
			Sort(orig_begin, orig_end, middle + 1, end);
		Merge(orig_begin, orig_end, begin, middle, end);
	}
}

template<typename ForwardIterator>
void	my_sort::MergeSort(ForwardIterator begin, ForwardIterator end)
{
	if (begin < end)
		Sort(begin, end - 1, begin, end - 1);
}
