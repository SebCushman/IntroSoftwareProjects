#include "Character.h"
#include "Game.h"


void nc::Character::attack(Character* target, Skill* skill)
{
	if (random(0, 1) <= skill->m_accuracy) {
		if (random(0, 1) > target->evasion) {
			float damage = ((random(0, 1) * (skill->m_maxDam - skill->m_minDam + 1)) + skill->m_minDam);
			if (skill->m_isMagic) {
				damage *= (mAttack / target->mDefense);
			}
			else {
				damage *= (pAttack / target->pDefense);
			}
			int finalDam = roundf(damage);
			target->currentHP -= ((finalDam < 0) ? 0 : finalDam);
			std::cout << name << " hit " << target->name << " for " << ((finalDam < 0) ? 0 : finalDam) << " damage!" << std::endl;
		}
		else {
			std::cout << name << " missed their target" << std::endl;
		}
	}
	else {
		std::cout << name << " missed their target" << std::endl;
	}
}

void nc::Character::setOwner(Game* game)
{
	owner = game;
}



