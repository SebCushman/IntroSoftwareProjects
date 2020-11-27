#pragma once
#include "pch.h"

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

			//populate skill lists from DB


		}

		void attack(Character* target, class skill);

		void levelUp();


	protected:
		int maxHP;
		int currentHP;
		int mDefense;
		int mAttack;
		int pDefense;
		int pAttack;
		int evasion;
		int position;
		std::string name;
		std::list<class Skill> allSkills{};
		std::list<class Skill> currentSkills{};
		int level;
		int xp;
		std::vector<int> xpThresh{ 0, 5, 12, 25, 40, 60 };


	};
}