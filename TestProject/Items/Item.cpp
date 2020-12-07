#include "Item.h"

namespace nc
{
	bool Item::Use(Character* target)
	{
		if (m_dHP != 0)
		{
			if ((target->currentHP + m_dHP) >= target->maxHP)
			{
				target->currentHP = target->maxHP;
				return true;
			}
			else
			{
				target->currentHP += m_dHP;
				return true;
			}
			return false;
		}
		else if (m_dMP != 0)
		{
			for (int i = 0; i < target->currentSkills.size(); i++)
			{
				if ((target->currentSkills[i]->m_currentCharges + m_dHP) >= target->currentSkills[i]->m_maxCharges)
				{
					target->currentSkills[i]->m_currentCharges = target->currentSkills[i]->m_maxCharges;
					return true;
				}
				else
				{
					target->currentSkills[i]->m_currentCharges += m_dHP;
				}
			}
			return false;
		}
		/*else if (m_dMoney != 0)
		{
			static_cast<Player*>(target).
			return true;
		}*/
		return false;
	}
}
