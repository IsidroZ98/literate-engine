
#ifndef POKEDEX_H
#define POKEDEX_H

#include <string>
#include "pokemon.h"

using namespace std;

class Pokedex
{
	public:
		// A file containing a Pokedex should contain a line
		// for each Pokemon in the Pokedex. This line
		// should be the summary string of the Pokemon.
		// See pokemon.txt for an example.

		// Constructs an empty pokedex.
		Pokedex();

		// Constructs a Pokedex with the Pokemon found in
		// the specified file. 
		Pokedex(string filename);

		// Writes the Pokedex to the file.
		void save(string filename);

		// Adds a pokemon to the pokedex.
		void add(Pokemon* p);

		// Removes a pokemon from the pokedex.
		void remove(Pokemon* p);

		// Returns a (pointer to a) pokemon in the pokedex with the given name.
		// If none exists, returns nullptr.
		//
		// Hint: loop through all of A, searching for a Pokemon with
		// the given name. Return the first one found.
		Pokemon* lookup_by_name(string name);

		// Returns a (pointer to a) pokemon in the pokedex with the given Ndex.
		// If none exists, returns nullptr.
		//
		// Hint: look in A[ndex]. 
		Pokemon* lookup_by_Ndex(int ndex);

		// Returns the number of pokemon in the pokedex.
		int size();

	
	private:
		// The pokedex is represented as an array of Pokemon pointers.
		//
		// 1. Initialize the values in A to nullptr.
		// 2. When adding a Pokemon('s pointer), store the pointer in
		//    the array index equal to the Pokemon's Ndex.
		// 3. When removing a Pokemon('s pointer), do so by setting the
		//    corresponding array index equal to nullptr.
		Pokemon* A[1000];
};

#endif

