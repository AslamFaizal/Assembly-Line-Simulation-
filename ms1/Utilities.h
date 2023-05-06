
/*
Student Name:- Faizal Aslam
Student ID:- 152121216
Student Email:- faizal-aslam@myseneca.ca
Date:- 2022-11-19
Course Section:- OOP345 ZRA

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{
	
	class Utilities
	{
	private:
		size_t m_widthField{ 1 };
	public:
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	};
}
#endif