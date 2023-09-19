
#include <cstdlib>
#include <iostream>
#include "pokemon.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file << ", line " << line << "." << endl;
        //abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main()
{
	// Create a bunch of pokemon objects. 
	// (Data taken from the official list, plz don't sue me The Pokemon Company)
	Pokemon bouffalant("Bouffalant", 626, Pokemon::Normal);
	Pokemon cinccino("Cinccino", 573, Pokemon::Normal);
	Pokemon garbodor("Garbodor", 569, Pokemon::Poison);
	Pokemon mankey("Mankey", 56, Pokemon::Fighting);
	Pokemon tornadus("Tornadus", 641, Pokemon::Flying);

	Pokemon pidgey("Pidgey", 16, Pokemon::Normal, Pokemon::Flying);
	Pokemon fletchling("Fletchling", 661, Pokemon::Normal, Pokemon::Flying);
	Pokemon zubat("Zubat", 41, Pokemon::Poison, Pokemon::Flying);
	Pokemon toxicroak("Toxicroak", 454, Pokemon::Poison, Pokemon::Fighting);
	Pokemon hawlucha("Hawlucha", 701, Pokemon::Fighting, Pokemon::Flying);
	Pokemon hoothoot("Hoothoot", 163, Pokemon::Flying, Pokemon::Normal);
	Pokemon pikachu("Pikachu", 001, Pokemon::Normal, Pokemon::Poison);

	// Test name()	
	test(bouffalant.name() == "Bouffalant");
	test(cinccino.name() == "Cinccino");
	test(garbodor.name() == "Garbodor");
	test(mankey.name() == "Mankey");
	test(tornadus.name() == "Tornadus");
	test(pidgey.name() == "Pidgey");
	test(fletchling.name() == "Fletchling");
	test(zubat.name() == "Zubat");
	test(toxicroak.name() == "Toxicroak");
	test(hawlucha.name() == "Hawlucha");
	test(hoothoot.name() == "Hoothoot");
	test(pikachu.name() == "Pikachu");

	// Test Ndex()	
	test(bouffalant.Ndex() == 626);
	test(cinccino.Ndex() == 573);
	test(garbodor.Ndex() == 569);
	test(mankey.Ndex() == 56);
	test(tornadus.Ndex() == 641);

	test(pidgey.Ndex() == 16);
	test(fletchling.Ndex() == 661);
	test(zubat.Ndex() == 41);
	test(toxicroak.Ndex() == 454);
	test(hawlucha.Ndex() == 701);
	test(hoothoot.Ndex() == 163);
	test(pikachu.Ndex() == 001);

	// Test is_multitype()
	test(!bouffalant.is_multitype());	
	test(!cinccino.is_multitype());	
	test(!garbodor.is_multitype());	
	test(!mankey.is_multitype());	
	test(!tornadus.is_multitype());	

	test(pidgey.is_multitype());	
	test(fletchling.is_multitype());	
	test(zubat.is_multitype());	
	test(toxicroak.is_multitype());	
	test(hawlucha.is_multitype());	
	test(hoothoot.is_multitype());	
	test(pikachu.is_multitype());
	
	// Test type1()
	test(bouffalant.type1() == Pokemon::Normal);
	test(cinccino.type1() == Pokemon::Normal);
	test(garbodor.type1() == Pokemon::Poison);
	test(mankey.type1() == Pokemon::Fighting);
	test(tornadus.type1() == Pokemon::Flying);

	test(pidgey.type1() == Pokemon::Normal);
	test(fletchling.type1() == Pokemon::Normal);	
	test(zubat.type1() == Pokemon::Poison);	
	test(toxicroak.type1() == Pokemon::Poison);	
	test(hawlucha.type1() == Pokemon::Fighting);	
	test(hoothoot.type1() == Pokemon::Flying);	
	test(pikachu.type1() == Pokemon::Normal);

	// Test type2()
	test(bouffalant.type2() == Pokemon::Normal);
	test(cinccino.type2() == Pokemon::Normal);
	test(garbodor.type2() == Pokemon::Poison);
	test(mankey.type2() == Pokemon::Fighting);
	test(tornadus.type2() == Pokemon::Flying);

	test(pidgey.type2() == Pokemon::Flying);
	test(fletchling.type2() == Pokemon::Flying);	
	test(zubat.type2() == Pokemon::Flying);	
	test(toxicroak.type2() == Pokemon::Fighting);	
	test(hawlucha.type2() == Pokemon::Flying);	
	test(hoothoot.type2() == Pokemon::Normal);	
	test(pikachu.type2() == Pokemon::Poison);
	
	// Test damage_multiplier() for single-type Pokemon
	test(bouffalant.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(bouffalant.damage_multiplier(Pokemon::Fighting) == 2.0);	
	test(bouffalant.damage_multiplier(Pokemon::Flying) == 1.0);	
	test(bouffalant.damage_multiplier(Pokemon::Poison) == 1.0);	
	
	test(garbodor.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(garbodor.damage_multiplier(Pokemon::Fighting) == 0.5);	
	test(garbodor.damage_multiplier(Pokemon::Flying) == 1.0);	
	test(garbodor.damage_multiplier(Pokemon::Poison) == 0.5);	
	
	test(mankey.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(mankey.damage_multiplier(Pokemon::Fighting) == 1.0);	
	test(mankey.damage_multiplier(Pokemon::Flying) == 2.0);	
	test(mankey.damage_multiplier(Pokemon::Poison) == 1.0);	

	test(tornadus.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(tornadus.damage_multiplier(Pokemon::Fighting) == 0.5);
	test(tornadus.damage_multiplier(Pokemon::Flying) == 1.0);	
	test(tornadus.damage_multiplier(Pokemon::Poison) == 1.0);	
	

	// Test damage_multiplier() for multitype Pokemon
	test(pidgey.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(pidgey.damage_multiplier(Pokemon::Fighting) == 1.0);	
	test(pidgey.damage_multiplier(Pokemon::Flying) == 1.0);	
	test(pidgey.damage_multiplier(Pokemon::Poison) == 1.0);	

	test(fletchling.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(fletchling.damage_multiplier(Pokemon::Fighting) == 1.0);	
	test(fletchling.damage_multiplier(Pokemon::Flying) == 1.0);	
	test(fletchling.damage_multiplier(Pokemon::Poison) == 1.0);

	test(zubat.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(zubat.damage_multiplier(Pokemon::Fighting) == 0.25);	
	test(zubat.damage_multiplier(Pokemon::Flying) == 1.0);	
	test(zubat.damage_multiplier(Pokemon::Poison) == 0.5);

	test(toxicroak.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(toxicroak.damage_multiplier(Pokemon::Fighting) == 0.5);	
	test(toxicroak.damage_multiplier(Pokemon::Flying) == 2.0);	
	test(toxicroak.damage_multiplier(Pokemon::Poison) == 0.5);

	test(hawlucha.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(hawlucha.damage_multiplier(Pokemon::Fighting) == 0.5);	
	test(hawlucha.damage_multiplier(Pokemon::Flying) == 2.0);	
	test(hawlucha.damage_multiplier(Pokemon::Poison) == 1.0);

	test(hoothoot.damage_multiplier(Pokemon::Normal) == 1.0);	
	test(hoothoot.damage_multiplier(Pokemon::Fighting) == 1.0);	
	test(hoothoot.damage_multiplier(Pokemon::Flying) == 1.0);	
	test(hoothoot.damage_multiplier(Pokemon::Poison) == 1.0);

	test(pikachu.damage_multiplier(Pokemon::Normal) == 1.0);
	test(pikachu.damage_multiplier(Pokemon::Fighting) == 1.0);
	test(pikachu.damage_multiplier(Pokemon::Flying) == 1.0);
	test(pikachu.damage_multiplier(Pokemon::Poison) == 0.5);

	cout << "Assignment complete." << endl;
}




