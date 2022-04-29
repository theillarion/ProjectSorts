//
// Created by Illarion on 19.04.2022.
//

#ifndef PROJECTSORTS_DATE_HPP
#define PROJECTSORTS_DATE_HPP

# include <compare>
# include <ostream>

struct Date
{
	unsigned short year;
	unsigned short month;
	unsigned short day;

	Date();
	Date(unsigned short day, unsigned short month, unsigned short year);
	Date(const Date&	date_time);

	auto operator<=>(const Date&	date_time) const = default;
	Date& operator=(const Date& date);
	
	friend std::ostream& operator<<(std::ostream&	out, const Date&	date_time);
	friend std::istream& operator>>(std::istream&	in, Date& date_time);
};

#endif //PROJECTSORTS_DATE_HPP
