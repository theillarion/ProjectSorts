#include "includes/common.hpp"
#include "includes/selection_sort.hpp"
#include "includes/quick_sort.hpp"

int main()
{
	std::vector<int>	src = {3, 1, 4, 1, 5, 9, 2, 3};
	std::cout << src;
	my_sort::QuickSort(src.begin(), src.end() - 1);
	std::cout << src;
	std::vector<int>::iterator it = src.begin();
	std::vector<int>::iterator::value_type;
	return 0;
}
