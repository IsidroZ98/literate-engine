
#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

class Pokemon
{
	public:
		// This works like a custom type with just four values.
		// Inside Pokemon methods, reference them by their names, e.g.:
		// "if (x == Fighting)", "if (y != Poison)", etc.
		enum Type {Normal, Fighting, Flying, Poison};

		// Initializes a single-type Pokemon using the information provided
		Pokemon(string name, int ndex, Type type1);

		// Initializes a multi-type Pokemon using the information provided
		Pokemon(string name, int ndex, Type type1, Type type2);

		// Returns the name of the pokemon 
		string name();

		// Returns the Ndex (national index) of the Pokemon
		int Ndex();

		// Returns the first (and possibly only) type of the Pokemon
		Type type1();

		// Returns whether the Pokemon has multiple types
		bool is_multitype();

		// If the Pokemon has two types, returns the second type of the Pokemon.
		// Otherwise returns the Pokemon's only type.
		Type type2();


		// The damage multiplier of a move against a Pokemon 
		// is the product of the multipliers for each of the Pokemon's types.

		// Reference: http://bulbapedia.bulbagarden.net/wiki/Type/Type_chart#Generation_I 
		// See the above chart (for Generation I) to understand the examples below.
		// Rows represent: Attacking types
		// Columns represent: Pokemon defending types

		// Normal attacks: 1.0 against all Pokemon defending types.
		// Fighting attacks: 2.0 against Normal, 0.5 against Flying or Poison, 1.0 against Fighting.
		// Flying attacks: 1.0 against all defending types except Fighting, 2.0 against Fighting.
		// Poison attacks: 1.0 against all types except Poison, 0.5 against Poison.

		// Example 1: if the attack type is Fighting against a Pokemon with Normal and Flying defending types (2 types)
		// the damage multiplier is 1.0 (results from multiplying 2.0 * 0.5).

		// Example 2: if the attack type is Poison against a Pokemon with the Poison defending type (only 1 type)
		// the damage multiplier is 0.5 (there is only one type).
		
		// Returns the damage multiplier against this Pokemon 
		// for a move of the parameter type.
		float damage_multiplier(Type attack_type);

	private:
		int _ndex;			// Stores the Pokemon's Ndex
		string _name;		// Stores the Pokemon's name 
		Type types[2];		// Array's 1st element stores type 1. When there is a second type, array's 2nd element stores type 2
		int type_count;		// Stores the Pokemon's quantity of types (1 or 2)
};
#endif
