#pragma once
#include "Skill.h"
#include "Items/Items.h"

namespace nc {

	class Character {
	public:
		Character(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, int _evasion, int _position, std::string _name) {
			maxHP = _maxHP;
			currentHP = maxHP;
			mDefense = _mDefense;
			mAttack = _mAttack;
			pAttack = _pAttack;
			pDefense = _pDefense;
			evasion = _evasion;
			position = _position;
			name = _name;

		}

		void attack(Character* target, Attack skill);

		friend class Items;
		friend class Item;



	protected:
		int maxHP;
		int currentHP;
		int mDefense;
		int mAttack;
		int pDefense;
		int pAttack;
		float evasion;
		int position;
		std::string name;
		std::list<Skill> allSkills{};
		std::list<Skill> currentSkills{};
		int level;
		int xp;
		std::vector<int> xpThresh{ 0, 5, 12, 25, 40, 60 };


	};
}