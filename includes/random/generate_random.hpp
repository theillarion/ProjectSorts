//
// Created by Illarion on 19.04.2022.
//

#ifndef PROJECTSORTS_GENERATE_RANDOM_HPP
#define PROJECTSORTS_GENERATE_RANDOM_HPP

# include <vector>
# include <random>

inline int	GenerateRandomInt32(int min, int max)
{
	std::random_device				rnd;
	std::mt19937					gen(rnd());
	std::uniform_int_distribution<int>	uniform(min, max);
	return (uniform(gen));
}

inline std::vector<int>	GenerateRandomVector(int min, int max, size_t	size)
{
	std::vector<int>				result;
	std::random_device				rnd;
	std::mt19937					gen(rnd());
	std::uniform_int_distribution<>	uniform(min, max);

	result.reserve(size);
	for (auto i = 0; i < size; ++i)
		result.push_back(uniform(gen));

	return (result);
}

#endif //PROJECTSORTS_GENERATE_RANDOM_HPP
