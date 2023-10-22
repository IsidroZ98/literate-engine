
#include "player.h"

Player :: Player(string name, Role role)
{
	_name = name;
	_role = role;
}

string Player :: name()
{
	return _name;
}

Player::Role Player :: role()
{
	return _role;
}

