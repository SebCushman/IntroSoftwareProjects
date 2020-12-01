#pragma once
#include "Character.h"

namespace nc {
	class NPC : public Character {
	public:
		NPC(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, float _evasion, int _position, std::string _name)
			: Character(_maxHP, _mDefense, _mAttack, _pDefense, _pAttack, _evasion, _position, _name) {}

		void takeTurn();
		void move();
				
		int playerInRange(Attack skill);
		bool playerInSight();



	protected:

		int xpValue{ 0 };
		
	};
}