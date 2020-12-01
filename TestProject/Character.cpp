#include "Character.h"


void nc::Character::attack(Character* target, nc::Attack skill)
{
	bool isMagic = skill.m_isMagic;
	float onTarget = random(0, 1);
	if (onTarget <= skill.m_accuracy) {
		float connect = random(0, 1);
		if (connect <= target->evasion) {
			float damageMult = random(0, 1);
			float damage = (damageMult * ((skill.m_maxDam - skill.m_minDam + 1) + skill.m_minDam));
			if (isMagic) {
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


