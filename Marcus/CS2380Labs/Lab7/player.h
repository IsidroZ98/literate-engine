
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
	public:
		// This works like a custom type with just three values.
		// Outside of Player methods, reference them like:
		// "if (p->role == Player::Defender)", etc.
		enum Role {Defender=0, Hunter=1, Bard=2};

		// Initializes a player with the given name and role
		Player(string name, Role role);

		// Returns the name of the player
		string name();
		
		// Returns the role of the player
		Role role();
		
	private:
		string _name;
		Role _role;
};

#endif

