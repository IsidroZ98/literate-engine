// Team #20 CSCI 2380 FALL 2023 HOMEWORK #5
// Edgar Hernandez
// Marcus Gutierrez
// 10/10/23
// Gustavo Dietrich 

#include "pokemon.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


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

bool Pokemon::is_multitype() 
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
  return damageMultiplier;
  }
// this was all code we used in previous pokemon lab that applies to this one

// constructor to create a Pokemon from a summary string
Pokemon::Pokemon(string summary) {

  // check and remove trailing comma from the summary
  if (summary.at(summary.length() - 1) == ',')
    summary = summary.substr(0, summary.length()-1);

  // use a stringstream to break up the summary string
  stringstream index(summary);
  string dex;
  vector<string> token;

  // break up the summary using the comma, acts as a delimiter
  while (getline(index, dex, ','))
  {
  // removes spaces 
    if (dex.find(" ") == 0)
      dex = dex.substr(1);

  // remove #
    if (dex.find("#") == 0)
      dex = dex.substr(1);
    
    token.push_back(dex);
  }

// get name and index from token
  _name = token.at(0);
  _ndex = stoi(token.at(1));

  if (token.size() == 3)
  {
    types[0] = string_to_type(token.at(2));
    type_count = 1;
  }
  else
  {
    types[0] = string_to_type(token.at(2));
    types[1] = string_to_type(token.at(3));
    type_count = 2;
  }
}

// Constructor for summary
string Pokemon::summary() {
  stringstream pokemon;

  // add name and index to the summary
  pokemon << _name << ", ";
  pokemon << "#";

  // add zeros 
  if (_ndex >= 10 && _ndex < 100)
    pokemon << "0";

  if (_ndex < 10)
    pokemon << "00";

  pokemon << _ndex << ", ";

  // add types to summary
  if (type_count == 2) {
    pokemon << type_to_string(types[0]) << ", ";
    pokemon << type_to_string(types[1]) << ",";
  }
  else {
    pokemon << type_to_string(types[0]) << ",";
  }

  // return the final string 
  return pokemon.str();
}

// convert type enum to string 
string type_to_string(Pokemon::Type t) {
  switch (t) {
    case Pokemon::Normal:
      return "Normal";
    case Pokemon::Fighting:
      return "Fighting";
    case Pokemon::Flying:
      return "Flying";
    case Pokemon::Poison:
      return "Poison";
  }
}

// convert string to enum
Pokemon::Type string_to_type(string s) {
  if (s == "Fighting") {
    return Pokemon::Fighting;
  }
  else if (s == "Flying") {
    return Pokemon::Flying;
  }
  else if (s == "Normal") {
    return Pokemon::Normal;
  }
  else if (s == "Poison") {
    return Pokemon::Poison;
  }
}
