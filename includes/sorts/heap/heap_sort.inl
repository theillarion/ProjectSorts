#include "heap_sort.hpp"

template <typename Type>
static void	Push(std::vector<Type>&	src, int root, int size)
{
	if (root * 2 + 1 < size)
	{
		int largest	= root * 2 + 1;
		int r_ 		= root * 2 + 2;
		if (r_ < size && src[r_] > src[largest])
			largest = r_;
		if (src[largest] > src[root])
		{
			std::swap(src[largest], src[root]);
			Push(src, largest, size);
		}
	}
}

template <typename Type>
static void	BuildHeap(std::vector<Type>&	src)
{
	for (int i = src.size() / 2 - 1; i >= 0; --i)
		Push(src, i, src.size());
}

template <typename Type>
void	my_sort::HeapSort(std::vector<Type>&	src)
{
	BuildHeap(src);
	for (int i = src.size() - 1; i >= 0; --i)
	{
		std::swap(src[0], src[i]);
		Push(src, 0, i);
	}
}

//template <typename ForwardIterator>
//static inline void	Push(ForwardIterator begin, ForwardIterator end, ForwardIterator root)
//{
//	if (root * 2 + 1 < size)
//	{
//		int largest = root * 2 + 1;
//		int r_ = root * 2 + 2;
//		if (r_ < size && src[r_] > src[largest])
//			largest = r_;
//		if (src[largest] > src[root])
//		{
//			std::swap(src[largest], src[root]);
//			Push(src, largest, size);
//		}
//	}
//}
//
//template <typename ForwardIterator>
//static inline void	BuildHeap(ForwardIterator begin, ForwardIterator end)
//{
//	for (auto i = end / 2 - 1; i >= begin; --i)
//		Push(src, i, src.size());
//}
//
//template <typename ForwardIterator>
//inline void	my_sort::HeapSort(ForwardIterator begin, ForwardIterator end)
//{
//	BuildHeap(begin, end);
//	for (auto it = end - 1; it >= begin; --it)
//	{
//		std::swap(*begin, *it);
//		Push(begin, it, begin);
//	}
//}
