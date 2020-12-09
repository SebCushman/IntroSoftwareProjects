#pragma once
#include "Items.h"
#include "../Player.h"
#include <iostream>

namespace nc
{
	class Item : public Items
	{
	public:
		Item() {}
		Item(int HP, int MP, /*int money, int value, */std::string name)
		{
			m_dHP = HP;
			m_dMP = MP;
			//m_dMoney = money;
			//m_Value = value;
			m_name = name;
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

		friend class UI;
		friend class Game;

	protected:
		int m_dHP{ 0 };
		int m_dMP{ 0 };
	};
}