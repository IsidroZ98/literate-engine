//***********************************************************************
// Team #20 CSCI 2380 Fall 2023 HOMEWORK #1
// Edgar Hernandez
// Marcus Gutierrez
// 1/31/23
// Gustavo Dietrich
//***********************************************************************

#include "pokemon.h"
#include <iostream>
#include <string>

using namespace std;

Pokemon::Pokemon(string name, int ndex, Type type1) { // calls our variables defined and established in pokemon.h file 
  _name = name;
  _ndex = ndex;
  types[0] = type1;
  type_count = 1;
}

Pokemon::Pokemon(string name, int ndex, Type type1, Type type2) { // calls again our variables established in pokemon.h file
  _name = name;
  _ndex = ndex;
  types[0] = type1;
  types[1] = type2;
  type_count = 2;
}

string Pokemon::name() { 
return _name; 
}

int Pokemon::Ndex() {
return _ndex; 
}

Pokemon::Type Pokemon::type1() { 
  return types[0]; 
}

bool Pokemon::is_multitype() // true false variable established
{
  return type_count == 2; // checks to see if the the count is 2
}

Pokemon::Type Pokemon::type2() // calls type 2 pokemon, returns type 2 and if not it will return type 1 (0 is our 1st type) 
{
  if (is_multitype()) {
    return types[1];
  } else {
    return types[0];
  }
}

float Pokemon::damage_multiplier(Type attack_type) // single precision variable 
{
  float damageMultiplier = 1.0;
// calls our attacking types from pokemon.h
  for (int i = 0; i < type_count; i++) { //for loop created for attacking types
    if (attack_type == Fighting) {
      if (types[i] == Normal) {
        damageMultiplier *= 2.0;
      } else if (types[i] == Flying || types[i] == Poison) {
        damageMultiplier *= 0.5;
      }
    } else if (attack_type == Flying && types[i] == Fighting) {
      damageMultiplier *= 2.0;
    } else if (attack_type == Poison && types[i] == Poison) {
      damageMultiplier *= 0.5;
    }
  }

  return damageMultiplier; // returns dmg multiplier
}
