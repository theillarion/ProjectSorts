//
// Created by Illarion on 19.04.2022.
//
#include "data/date.hpp"

Date::Date() :
	day(1), month(1), year(1970)
{

}

Date::Date(unsigned short day, unsigned short month, unsigned short year) :
	day(day), month(month), year(year)
{

}

Date::Date(const Date&	date) :
	day(date.day), month(date.month), year(date.year)
{

}

Date& Date::operator=(const Date& date)
{
	day = date.day;
	month = date.month;
	year = date.year;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.day << " " << date.month << " " << date.year;
	return (out);
}

std::istream& operator>>(std::istream& in, Date& date)
{
	in >> date.day >> date.month >> date.year;
	return (in);
}
