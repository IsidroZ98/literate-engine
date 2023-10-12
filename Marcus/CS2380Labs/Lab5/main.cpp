
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <fstream>
#include "pokedex.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file << ", line " << line << "." << endl;
        //abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main()
{
	// ***** Test Pokemon *****


	// Test type_to_string()
	test(type_to_string(Pokemon::Normal) == "Normal");
	test(type_to_string(Pokemon::Fighting) == "Fighting");
	test(type_to_string(Pokemon::Flying) == "Flying");
	test(type_to_string(Pokemon::Poison) == "Poison");

	
	// Test string_to_type()
	test(string_to_type("Normal") == Pokemon::Normal); 
	test(string_to_type("Fighting") == Pokemon::Fighting); 
	test(string_to_type("Flying") == Pokemon::Flying); 
	test(string_to_type("Poison") == Pokemon::Poison); 
	string_to_type("Sleepy");


	// Test string-based constructor via
	// checking that instance variables were set correctly.
	Pokemon bouffalant("Bouffalant, #626, Normal,");
	Pokemon mankey("Mankey, #056, Fighting,");
	Pokemon tornadus("Tornadus, #641, Flying,");
	Pokemon grimer("Grimer, #088, Poison,");
	Pokemon timburr("Timburr, #532, Fighting,");
	Pokemon tonkamon("Tonkamon, #001, Flying,");
	
	Pokemon pidgey("Pidgey, #016, Normal, Flying,");
	Pokemon fletchling("Fletchling, #661, Normal, Flying,");
	Pokemon zubat("Zubat, #041, Poison, Flying,");
	Pokemon toxicroak("Toxicroak, #454, Poison, Fighting,");
	Pokemon golbat("Golbat, #042, Poison, Flying,");
	Pokemon hoothoot("Hoothoot, #163, Flying, Normal,");

	// Check that _name was set correctly 
	test(bouffalant.name() == "Bouffalant");
	test(mankey.name() == "Mankey");
	test(tornadus.name() == "Tornadus");
	test(grimer.name() == "Grimer");
	test(timburr.name() == "Timburr");
	test(tonkamon.name() == "Tonkamon");

	test(pidgey.name() == "Pidgey");
	test(fletchling.name() == "Fletchling");
	test(zubat.name() == "Zubat");
	test(toxicroak.name() == "Toxicroak");
	test(golbat.name() == "Golbat");	
	test(hoothoot.name() == "Hoothoot");

	// Check that _ndex was set correctly 
	test(bouffalant.Ndex() == 626);
	test(mankey.Ndex() == 56);
	test(tornadus.Ndex() == 641);
	test(grimer.Ndex() == 88);
	test(timburr.Ndex() == 532);
	test(tonkamon.Ndex() == 1);

	test(pidgey.Ndex() == 16);
	test(fletchling.Ndex() == 661);
	test(zubat.Ndex() == 41);
	test(toxicroak.Ndex() == 454);
	test(golbat.Ndex() == 42);
	test(hoothoot.Ndex() == 163);

	// Check that types were set correctly
	test(bouffalant.type1() == Pokemon::Normal);
	test(!bouffalant.is_multitype());

	test(mankey.type1() == Pokemon::Fighting);	
	test(!mankey.is_multitype());

	test(tornadus.type1() == Pokemon::Flying);
	test(!tornadus.is_multitype());

	test(grimer.type1() == Pokemon::Poison);
	test(!grimer.is_multitype());

	test(timburr.type1() == Pokemon::Fighting);
	test(!timburr.is_multitype());

	test(tonkamon.type1() == Pokemon::Flying);
	test(!tonkamon.is_multitype());

	test(pidgey.type1() == Pokemon::Normal);
	test(pidgey.is_multitype());
	test(pidgey.type2() == Pokemon::Flying);
	
	test(fletchling.type1() == Pokemon::Normal);
	test(fletchling.is_multitype());
	test(fletchling.type2() == Pokemon::Flying);
	
	test(zubat.type1() == Pokemon::Poison);
	test(zubat.is_multitype());
	test(zubat.type2() == Pokemon::Flying);
	
	test(toxicroak.type1() == Pokemon::Poison);
	test(toxicroak.is_multitype());
	test(toxicroak.type2() == Pokemon::Fighting);
	
	test(golbat.type1() == Pokemon::Poison);
	test(golbat.is_multitype());
	test(golbat.type2() == Pokemon::Flying);

	test(hoothoot.type1() == Pokemon::Flying);
	test(hoothoot.is_multitype());
	test(hoothoot.type2() == Pokemon::Normal);
	

	// Test summary()	
	test(bouffalant.summary() == "Bouffalant, #626, Normal,");
	test(mankey.summary() == "Mankey, #056, Fighting,");
	test(tornadus.summary() == "Tornadus, #641, Flying,");
	test(grimer.summary() == "Grimer, #088, Poison,");
	test(timburr.summary() == "Timburr, #532, Fighting,");
	test(tonkamon.summary() == "Tonkamon, #001, Flying,");

	test(pidgey.summary() == "Pidgey, #016, Normal, Flying,");
	test(fletchling.summary() == "Fletchling, #661, Normal, Flying,");
	test(zubat.summary() == "Zubat, #041, Poison, Flying,");
	test(toxicroak.summary() == "Toxicroak, #454, Poison, Fighting,");
	test(golbat.summary() == "Golbat, #042, Poison, Flying,");
	test(hoothoot.summary() == "Hoothoot, #163, Flying, Normal,");




	// ***** Test Pokedex ***** 

	Pokedex D1;

	// Test add() and size()
	test(D1.size() == 0);
	D1.add(&bouffalant);
	test(D1.size() == 1);
	D1.add(&mankey);
	test(D1.size() == 2);
	D1.add(&tornadus);
	test(D1.size() == 3);
	D1.add(&grimer);
	test(D1.size() == 4);
	D1.add(&timburr);
	test(D1.size() == 5);
	D1.add(&tonkamon);
	test(D1.size() == 6);
	
	D1.add(&pidgey);
	test(D1.size() == 7);
	D1.add(&fletchling);
	test(D1.size() == 8);
	D1.add(&zubat);
	test(D1.size() == 9);
	D1.add(&toxicroak);
	test(D1.size() == 10);
	D1.add(&golbat);
	test(D1.size() == 11);
	D1.add(&hoothoot);
	test(D1.size() == 12);

	D1.add(&bouffalant);
	test(D1.size() == 12);
	D1.add(&hoothoot);	
	test(D1.size() == 12);


	// Test add(), lookup_by_Ndex()
	test(D1.lookup_by_Ndex(626) == &bouffalant);
	test(D1.lookup_by_Ndex(56) == &mankey);
	test(D1.lookup_by_Ndex(641) == &tornadus);
	test(D1.lookup_by_Ndex(88) == &grimer);
	test(D1.lookup_by_Ndex(532) == &timburr);
	test(D1.lookup_by_Ndex(1) == &tonkamon);
	test(D1.lookup_by_Ndex(16) == &pidgey);
	test(D1.lookup_by_Ndex(661) == &fletchling);
	test(D1.lookup_by_Ndex(41) == &zubat);
	test(D1.lookup_by_Ndex(454) == &toxicroak);
	test(D1.lookup_by_Ndex(42) == &golbat);
	test(D1.lookup_by_Ndex(163) == &hoothoot);

	test(D1.lookup_by_Ndex(12) == nullptr);
	test(D1.lookup_by_Ndex(34) == nullptr);
	test(D1.lookup_by_Ndex(567) == nullptr);


	// Test lookup_by_name()
	test(D1.lookup_by_name("Bouffalant") == &bouffalant);
	test(D1.lookup_by_name("Mankey") == &mankey);
	test(D1.lookup_by_name("Tornadus") == &tornadus);
	test(D1.lookup_by_name("Grimer") == &grimer);
	test(D1.lookup_by_name("Timburr") == &timburr);
	test(D1.lookup_by_name("Tonkamon") == &tonkamon);
	test(D1.lookup_by_name("Pidgey") == &pidgey);
	test(D1.lookup_by_name("Fletchling") == &fletchling);
	test(D1.lookup_by_name("Zubat") == &zubat);
	test(D1.lookup_by_name("Toxicroak") == &toxicroak);
	test(D1.lookup_by_name("Golbat") == &golbat);
	test(D1.lookup_by_name("Hoothoot") == &hoothoot);

	test(D1.lookup_by_name("Lemon") == nullptr);	
	test(D1.lookup_by_name("Fakemon") == nullptr);	
	test(D1.lookup_by_name("Notarealmon") == nullptr);	


	// Test remove()
	test(D1.size() == 12);
	test(D1.lookup_by_name("Bouffalant") == &bouffalant);
	test(D1.lookup_by_Ndex(626) == &bouffalant);
	test(D1.lookup_by_name("Zubat") == &zubat);
	test(D1.lookup_by_Ndex(41) == &zubat);
	test(D1.lookup_by_name("Hoothoot") == &hoothoot);
	test(D1.lookup_by_Ndex(163) == &hoothoot);

	D1.remove(&bouffalant);
	test(D1.size() == 11);
	test(D1.lookup_by_name("Bouffalant") == nullptr);
	test(D1.lookup_by_Ndex(626) == nullptr);

	D1.remove(&zubat);
	test(D1.size() == 10);
	test(D1.lookup_by_name("Zubat") == nullptr);
	test(D1.lookup_by_Ndex(41) == nullptr);

	D1.remove(&hoothoot);
	test(D1.size() == 9);
	test(D1.lookup_by_name("Hoothoot") == nullptr);
	test(D1.lookup_by_Ndex(163) == nullptr);

	test(D1.lookup_by_name("Mankey") == &mankey);
	test(D1.lookup_by_name("Tornadus") == &tornadus);
	test(D1.lookup_by_name("Grimer") == &grimer);
	test(D1.lookup_by_name("Timburr") == &timburr);
	test(D1.lookup_by_name("Tonkamon") == &tonkamon);
	test(D1.lookup_by_name("Pidgey") == &pidgey);
	test(D1.lookup_by_name("Fletchling") == &fletchling);
	test(D1.lookup_by_name("Golbat") == &golbat);
	test(D1.lookup_by_name("Toxicroak") == &toxicroak);
	

	// Test save() and load(). 
	// This will create and modify files on your computer 
	// in the directory where the program lives.

	// Delete old version of test_pokedex1.txt if it exists
	remove("./test_pokedex1.txt");

	// Save Mankey, Tornadus, Grimer, Timburr, Tonkamon,
	//      Pidgey, Fletchling, Golbat, Toxicroak	
	D1.save("./test_pokedex1.txt"); 
	                           
	// Create a Pokedex with:
	// Mankey, Tornadus, Grimer, Timburr, Tonkamon,
	// Pidgey, Fletchling, Golbat, Toxicroak	
	Pokedex D2("./test_pokedex1.txt");

	test(D2.size() == 9);	

	test(D2.lookup_by_name("Bouffalant") == nullptr);

	Pokemon* p = D2.lookup_by_name("Mankey");
	test(p != nullptr);
	test(p->name() == mankey.name());
	test(p->Ndex() == mankey.Ndex());
	test(p->type1() == mankey.type1());
	test(p->is_multitype() == mankey.is_multitype());

	p = D2.lookup_by_name("Tornadus");
	test(p != nullptr);
	test(p->Ndex() == tornadus.Ndex());

	p = D2.lookup_by_name("Grimer");
	test(p != nullptr);
	test(p->Ndex() == grimer.Ndex());

	p = D2.lookup_by_name("Timburr");
	test(p != nullptr);
	test(p->Ndex() == timburr.Ndex());

	p = D2.lookup_by_name("Tonkamon");
	test(p != nullptr);
	test(p->Ndex() == tonkamon.Ndex());

	p = D2.lookup_by_name("Pidgey");
	test(p != nullptr);
	test(p->name() == pidgey.name());
	test(p->Ndex() == pidgey.Ndex());
	test(p->type1() == pidgey.type1());
	test(p->is_multitype() == pidgey.is_multitype());
	test(p->type2() == pidgey.type2());

	p = D2.lookup_by_name("Fletchling");
	test(p != nullptr);
	test(p->Ndex() == fletchling.Ndex());
	
	test(D2.lookup_by_name("Zubat") == nullptr);

	p = D2.lookup_by_name("Toxicroak");
	test(p != nullptr);
	test(p->Ndex() == toxicroak.Ndex());

	p = D2.lookup_by_name("Golbat");
	test(p != nullptr);
	test(p->Ndex() == golbat.Ndex());

	test(D2.lookup_by_name("Hoothoot") == nullptr);

	D2.add(&bouffalant);
	D2.add(&zubat);
	D2.add(&hoothoot);
	D2.remove(&mankey);
	D2.remove(&toxicroak);
	test(D2.size() == 10);

	// Remove file made during testing
	remove("./test_pokedex1.txt");


	// Delete old version of test_pokedex2.txt if it exists
	remove("./test_pokedex2.txt");

	// Save Bouffalant, Tornadus, Grimer, Timburr, Tonkamon,
	//      Pidgey, Fletchling, Zubat, Golbat, Hoothoot 	
	D2.save("./test_pokedex2.txt");

	// Create a Pokedex with:
	// Bouffalant, Tornadus, Grimer, Timburr, Tonkamon,
	// Pidgey, Fletchling, Zubat, Golbat, Hoothoot 	
	Pokedex D3("./test_pokedex2.txt"); 	

	test(D3.size() == 10);

	p = D3.lookup_by_name("Bouffalant");
	test(p->name() == bouffalant.name());
	test(p->Ndex() == bouffalant.Ndex());
	test(p->type1() == bouffalant.type1());
	test(p->is_multitype() == bouffalant.is_multitype());

	test(D3.lookup_by_name("Mankey") == nullptr);

	p = D3.lookup_by_name("Tornadus");
	test(p != nullptr);
	test(p->Ndex() == tornadus.Ndex());

	p = D3.lookup_by_name("Grimer");
	test(p != nullptr);
	test(p->Ndex() == grimer.Ndex());

	p = D3.lookup_by_name("Timburr");
	test(p != nullptr);
	test(p->Ndex() == timburr.Ndex());

	p = D3.lookup_by_name("Tonkamon");
	test(p != nullptr);
	test(p->Ndex() == tonkamon.Ndex());

	p = D3.lookup_by_name("Pidgey");
	test(p != nullptr);
	test(p->name() == pidgey.name());
	test(p->Ndex() == pidgey.Ndex());
	test(p->type1() == pidgey.type1());
	test(p->is_multitype() == pidgey.is_multitype());
	test(p->type2() == pidgey.type2());
	
	p = D3.lookup_by_name("Fletchling");
	test(p != nullptr);
	test(p->Ndex() == fletchling.Ndex());
	
	p = D3.lookup_by_name("Zubat");
	test(p != nullptr);
	test(p->Ndex() == zubat.Ndex());

	p = D3.lookup_by_name("Golbat");
	test(p != nullptr);
	test(p->Ndex() == golbat.Ndex());

	test(D3.lookup_by_name("Toxicroak") == nullptr);

	p = D3.lookup_by_name("Hoothoot");
	test(p != nullptr);
	test(p->Ndex() == hoothoot.Ndex());

	// Remove file made during testing
	remove("./test_pokedex2.txt");


	ifstream f;
	f.open("./pokedex.txt");
	assert(f.is_open()); // If this fails, you're missing pokedex.txt
	f.close();
 
	Pokedex D4("./pokedex.txt");	
	test(D4.size() == 125);

	p = D4.lookup_by_name("Staraptor");
	test(p != nullptr);
	test(p->name() == "Staraptor");
	test(p->Ndex() == 398);
	test(p->type1() == Pokemon::Normal);
	test(p->is_multitype());
	test(p->type2() == Pokemon::Flying);

	p = D4.lookup_by_Ndex(143);
	test(p != nullptr);
	test(p->name() == "Snorlax");
	test(p->Ndex() == 143);
	test(p->type1() == Pokemon::Normal);
	test(!p->is_multitype());

	test(D4.lookup_by_name("Pikachu") == nullptr);
	test(D4.lookup_by_Ndex(25) == nullptr);	
	
	cout << "Assignment complete." << endl; 
}

