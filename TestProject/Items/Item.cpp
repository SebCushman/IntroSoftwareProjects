#include "Item.h"

bool nc::Item::Use(Character* target)
{
	if (m_dHP != 0)
	{
		return true;
		//target.m_currentHP += m_dHP;
	}
	else if (m_dMP != 0)
	{
		return true;
		//target.m_currentMP += m_dMP;
	}
	else if (m_dMoney != 0)
	{
		return true;
		//target.m_Money += m_dMoney;
	}
	return false;
}
