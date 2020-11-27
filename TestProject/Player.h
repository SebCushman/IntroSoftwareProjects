#pragma once
#include "Character.h"


namespace nc {
	class Player : public Character {
	public:


	protected:

		int money{ 0 };
		std::vector<class Item> inventory{};
	};
}