#include "Character.h"


void nc::Character::attack(Character* target, Skill skill)
{
	bool isMagic = skill.isMagic;
	float onTarget = random(0, 1);
	if (onTarget <= skill.accuracy) {
		float connect = random(0, 1);
		if (connect <= target->evasion) {
			float damageMult = random(0, 1);
			float damage = (damageMult * ((skill.maxDam - skill.minDam + 1) + skill.minDam));
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


