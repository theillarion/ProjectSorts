#include "random/generate_random.hpp"

int	GenerateRandomInt32(int min, int max)
{
	std::random_device				rnd;
	std::mt19937					gen(rnd());
	std::uniform_int_distribution<int>	uniform(min, max);
	return (uniform(gen));
}

std::vector<int>	GenerateRandomVector(int min, int max, size_t	size)
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

std::string	GenerateRandomString(size_t	min_len_word, size_t	max_len_word)
{
	std::string	result;
	size_t		len;

	len = min_len_word;
	if (max_len_word - min_len_word > 0)
		len = GenerateRandomInt32((int)min_len_word, (int)max_len_word);

	result.resize(len);
	std::generate(result.begin(), result.end(), []() -> char { return((char)GenerateRandomInt32(97, 122)); });

	return (result);
}

Date	GenerateRandomDate(size_t min_year, size_t max_year)
{
	Date	result;

	result.day = GenerateRandomInt32(1, 31);
	result.month = GenerateRandomInt32(1, 12);
	result.year = GenerateRandomInt32(min_year, max_year);

	return (result);
}
