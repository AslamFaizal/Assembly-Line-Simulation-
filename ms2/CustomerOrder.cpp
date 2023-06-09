/*
Student Name:- Faizal Aslam
Student ID:- 152121216
Student Email:- faizal-aslam@myseneca.ca
Date:- 2022-11-25
Course Section:- OOP345 ZRA

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/


#include <string>
#include <iostream>
#include "Station.h"
#include "Utilities.h"
#include "CustomerOrder.h"

using namespace std;
namespace sdds
{
	size_t CustomerOrder::m_widthField = 0u;

	CustomerOrder::CustomerOrder(const string& str) {
		size_t next_pos = 0;
		Utilities util;
		bool more;
		m_name = util.extractToken(str, next_pos, more);
		m_product = util.extractToken(str, next_pos, more);
		for (size_t i = next_pos; i < str.size(); i++)
		{
			if (str[i] == util.getDelimiter())
			{
				m_cntItem++;
			}
		}
		m_cntItem++;
		m_lstItem = new Item* [m_cntItem];
		for (size_t i = 0; i < m_cntItem; i++)
		{
			m_lstItem[i] = new Item(util.extractToken(str, next_pos, more));
		}
		m_widthField = m_widthField > util.getFieldWidth() ? m_widthField : util.getFieldWidth();
	}

	CustomerOrder::CustomerOrder(const CustomerOrder& rightOperand) {
		throw string("Error, customer order cannot be copied");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& rightOperand) noexcept {
		*this = std::move(rightOperand);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& rightOperand) noexcept {
		if (this != &rightOperand)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			
			m_lstItem = rightOperand.m_lstItem;

			m_name = rightOperand.m_name;
			m_product = rightOperand.m_product;
			m_cntItem = rightOperand.m_cntItem;

			rightOperand.m_lstItem = nullptr;
			rightOperand.m_name = "";
			rightOperand.m_product = "";
			rightOperand.m_cntItem = 0u;
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder() {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
	bool CustomerOrder::isOrderFilled() const {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (!m_lstItem[i]->m_isFilled)
				return false;
		}
		return true;
	}
	bool CustomerOrder::isItemFilled(const string& itemName) const {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				if (!m_lstItem[i]->m_isFilled) return false;
			}
		}
		return true;
	}
	void CustomerOrder::fillItem(Station& station, ostream& os) {
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if ( m_lstItem[i]->m_itemName == station.getItemName())
			{
				if (station.getQuantity() > 0)
				{
					station.updateQuantity();
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					os.width(4);
					os.setf(ios::right);
					os << "Filled ";
					os.unsetf(ios::right);
					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
					return;
				}
				else
				{
					os.setf(ios::right);
					os << "Unable to fill ";
					os.unsetf(ios::right);
					os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
					return;
				}
			}
		}
	}
	void CustomerOrder::display(ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[";
			os.width(6);
			os.fill('0');
			os.setf(ios::right);
			os << m_lstItem[i]->m_serialNumber;
			os << "] ";
			os.fill(' ');
			os.width(m_widthField + 2);
			os.unsetf(ios::right);
			os.setf(ios::left);
			os << m_lstItem[i]->m_itemName;
			os << " - ";
			m_lstItem[i]->m_isFilled ? os << "FILLED" << endl : os << "TO BE FILLED" << endl;
		}
	}
}