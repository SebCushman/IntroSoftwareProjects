#pragma once
#include <iostream>

namespace nc
{
	class Items
	{
	public:
		Items() {}
		Items(int money, int value)
		{
			m_dMoney = money;
			m_Value = value;
		};

		friend std::ostream& operator << (std::ostream& os, Items& item)
		{
			os << "Items\n";
			os << "-----\n";
			os << "Money: " << item.m_dMoney << "\n";
			os << "Value: " << item.m_Value << "\n\n";
			return os;
		}


	protected:
		int m_Value{ 0 };
		int m_dMoney{ 0 };
	};
}