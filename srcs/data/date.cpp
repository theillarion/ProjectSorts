//
// Created by Illarion on 19.04.2022.
//
#include "data/date.hpp"

Date::Date(unsigned short day, unsigned short month, unsigned short year) :
	day(day), month(month), year(year)
{

}

Date::Date(const Date&	date_time) :
	day(date_time.day), month(date_time.month), year(date_time.year)
{

}

std::ostream&	operator<<(std::ostream&	out, const Date &date_time)
{

	out << "{ " << ((date_time.day <= 9) ? "0" : "") << date_time.day <<
		"." << ((date_time.month <= 9) ? "0" : "") << date_time.month <<
		"." << date_time.year << " }" << std::endl;
	return (out);
}
