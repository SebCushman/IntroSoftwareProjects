#include "NPC.h"

void nc::NPC::takeTurn()
{
	if (playerInSight) {
		std::vector<Skill> skills;
		std::vector<Vector2> deltas;
		for (Skill skill : currentSkills) {
			Vector2 delta = playerInRange(skill);
			if (delta.x != 0 || delta.y != 0) {
				deltas.push_back(delta);
				skills.push_back(skill);
			}
		}
		if (skills.size() > 0) {
			int skill = random(0, skills.size() - 1);
			//rotate enemy sprite to face player's direction
			//play the appropriate skill animation skills[skill].animation
			attack(owner->characters.at(0), skills.at(skill));
		}
	}
}

void nc::NPC::move()
{
	//pick a direction, towards the player if they're near enough, or a random direction, and adjust the position of the NPC

}

nc::Vector2 nc::NPC::playerInRange(nc::Attack skill)
{
	Vector2 delta{ 0, 0 };
	bool isWall{ false };
	
	
	//check 8 directions up to the range of the passed in skill
	//if player detected, returns an int representing either the direction or directional delta, else it returns 0
	
	
	return delta;
}

bool nc::NPC::playerInSight()
{
	bool inSight = false;

	//work with sage on detecting distance in his 1D array

	return inSight;
}
