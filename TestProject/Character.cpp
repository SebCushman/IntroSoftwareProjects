#include "Character.h"


void nc::Character::attack(Character* target, nc::Attack skill)
{
	if (random(0, 1) <= skill.m_accuracy) {
		float connect = random(0, 1);
		if (connect <= target->evasion) {
			float damage = (random(0, 1) * ((skill.m_maxDam - skill.m_minDam + 1) + skill.m_minDam));
			if (skill.m_isMagic) {
				damage *= (mAttack / target->mDefense);
			}
			else {
				damage *= (pAttack / target->pDefense);
			}
			int finalDam = round(damage);
			target->currentHP -= damage;
		}
	}
}


