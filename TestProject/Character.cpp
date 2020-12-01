#include "Character.h"


void nc::Character::attack(Character* target, nc::Attack skill)
{
	if (random(0, 1) <= skill.m_accuracy) {
		if (random(0, 1) > target->evasion) {
			float damage = (random(0, 1) * ((skill.m_maxDam - skill.m_minDam + 1) + skill.m_minDam));
			if (skill.m_isMagic) {
				damage *= (mAttack / target->mDefense);
			}
			else {
				damage *= (pAttack / target->pDefense);
			}
			int finalDam = round(damage);
			target->currentHP -= finalDam;
		}
	}
}


