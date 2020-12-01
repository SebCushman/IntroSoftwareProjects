#pragma once
#include "Items.h"
#include <iostream>
#include "../Characters/Character.h"

namespace nc
{
	class Item : public Items
	{
	public:
		Item() {}
		Item(int HP, int MP, int money, int value)
		{
			m_dHP = HP;
			m_dMP = MP;
			m_dMoney = money;
			m_Value = value;
		}

		friend std::ostream& operator << (std::ostream& os, Item& item)
		{
			os << "Item\n";
			os << "----\n";
			os << "HP: " << item.m_dHP << "\n"; 
			os << "MP: "<< item.m_dMP << "\n"; 
			os << "Money: " << item.m_dMoney << "\n";
			os << "Value: " << item.m_Value << "\n";

			return os;
		}

		bool Use(Character* target);

	protected:
		int m_dHP{ 0 };
		int m_dMP{ 0 };
	};
}