//
// Created by pro10 on 22.04.2022.
//

#include "common/common.hpp"

void PrintSimpleArray(int* ptr, unsigned int size)
{
	std::cout << "{ ";
	for (auto i = 0; i < size; ++i)
		std::cout << ptr[i] << " ";
	std::cout << "}" << std::endl;
}
