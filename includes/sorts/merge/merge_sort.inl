#include "merge_sort.hpp"

template<typename ForwardIterator>
static void	SortTwo(ForwardIterator begin, ForwardIterator middle, ForwardIterator end)
{
	using value_type = std::iterator_traits<ForwardIterator>::value_type;
	std::vector<value_type>	buffer;
	ForwardIterator			beginFirst;
	ForwardIterator			beginSecond;

	if (end - begin == 1)
		return;
	buffer.reserve(end - begin);
	beginFirst = begin;
	beginSecond = middle;
	if (beginFirst == middle)
		move(middle, end, begin);
	else if (beginSecond == end)
		return;
	else
	{
		while (beginFirst < middle || beginSecond < end)
		{
			if (beginFirst == middle && beginSecond != end)
				buffer.push_back(*(beginSecond++));
			else if (beginSecond == end && beginFirst != middle)
				buffer.push_back(*(beginFirst++));
			else if (*beginFirst <= *beginSecond)
				buffer.push_back(*(beginFirst++));
			else
				buffer.push_back(*(beginSecond++));
		}
	}
	std::move(buffer.begin(), buffer.end(), begin);
}

template<typename ForwardIterator>
static void	Merge(ForwardIterator orig_begin, ForwardIterator orig_end,
	ForwardIterator begin, ForwardIterator middle, ForwardIterator end)
{
	SortTwo(begin, middle + 1, end + 1);
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
