
#include "player.h"

// Initializes a player with the given name and role
Player :: Player(string name, Role role)
{
	_name = name;
	_role = role;
}

// Returns the name of the player
string Player :: name()
{
	return _name;
}

// Returns the role of the player
Player::Role Player :: role()
{
	return _role;
}

