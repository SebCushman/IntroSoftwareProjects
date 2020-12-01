#include "Item.h"

namespace nc
{
	bool Item::Use(Player* target)
	{
		if (m_dHP != 0)
		{
			target->currentHP += m_dHP;
			return true;
		}
		else if (m_dMP != 0)
		{
			std::list<Skill>::iterator it = target->allSkills.begin();
			for (int i = 0; i < target->allSkills.size(); i++)
			{
				std::advance(it, i);
			}
			return true;
		}
		else if (m_dMoney != 0)
		{
			//target.
			return true;
		}
		return false;
	}
}
