#pragma once
#include "Character.h"

namespace nc {
	class NPC : public Character {
	public:
		NPC(int _maxHP, int _mDefense, int _mAttack, int _pDefense, int _pAttack, float _evasion, int _position, std::string _name)
			: Character(_maxHP, _mDefense, _mAttack, _pDefense, _pAttack, _evasion, _position, _name) {}

		void takeTurn();
		void move();
				
		Vector2 playerInRange(Attack skill);
		bool playerInSight();

		friend class Game;
		friend class UI;


	protected:

		int xpValue{ 0 };
		Vector2 attackDelta{ 0, 0 };
		
	};
}