//
// Created by Illarion on 19.04.2022.
//

#ifndef PROJECTSORTS_GENERATE_RANDOM_HPP
#define PROJECTSORTS_GENERATE_RANDOM_HPP

# include <vector>
# include <random>
# include <data/date.hpp>

int	GenerateRandomInt32(int min, int max);

std::vector<int>	GenerateRandomVector(int min, int max, size_t	size);

std::string	GenerateRandomString(size_t	min_len_word, size_t	max_len_word);

Date	GenerateRandomDate(size_t min_year, size_t max_year);

#endif //PROJECTSORTS_GENERATE_RANDOM_HPP
