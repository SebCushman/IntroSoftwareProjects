#pragma once
#include "pch.h"

namespace nc {
	class Skill {
	public:


		friend class Character;

	protected:
		float accuracy{ 0 };
		float minDam{ 0 };
		float maxDam{ 0 };
		bool isMagic{ false };
	};
}