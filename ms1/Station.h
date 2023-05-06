
/*
Student Name:- Faizal Aslam
Student ID:- 152121216
Student Email:- faizal-aslam@myseneca.ca
Date:- 2022-11-19
Course Section:- OOP345 ZRA

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{
	class Station
	{
	private:
		int m_id{};
		std::string m_itemName{};
		std::string m_description{};
		size_t m_nextSerial{};
		size_t m_itemsNum{};

	public:
		Station(const std::string& record);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif