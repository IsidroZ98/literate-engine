#include "pokedex.h"
#include <fstream>
#include <iostream>
using namespace std;

// constructor for pokedex
Pokedex::Pokedex() {
  // for loop count
  for (int i = 0; i < 1000; i++) {
    A[i] = nullptr; // array start set to nullptr
  }
}

// constructor for pokedex that reads the data
Pokedex::Pokedex(string filename) 
{
  for (int i = 0; i < 1000; i++) // for loop
    {
    A[i] = nullptr; // another array set to nullptr
}

  ifstream inFile(filename);
  if (!inFile) {
    cout << "the file isnt opening lil bro"; // error message if file cannot be read
  }

  string line;

  while (getline(inFile, line)) {
    Pokemon* poke = new Pokemon(line);
    add(poke); // add pokemon to pokedex
  }

  inFile.close(); // closes the file
}

// save pokedex data
void Pokedex::save(string filename) {
  ofstream outFile(filename);

  if (!outFile) {
    cout << "the file isnt opening lil bro";
  }

  // more loop and array work also writes out summary 
  for (int i = 0; i < 1000; i++) {
    if (A[i] != nullptr) {
      outFile << A[i]->summary() << endl;
    }
  }
  outFile.close();
}
// add pokemon to pokedex
void Pokedex::add(Pokemon* p) {
  A[p->Ndex()] = p;
}
// remove pokemon from pokedex
void Pokedex::remove(Pokemon* p) {
  A[p->Ndex()] = nullptr;
}
// lookup pokemon by pokedex
Pokemon* Pokedex::lookup_by_name(string name) {
  for (int i = 0; i < 1000; i++) {
    if (A[i] != nullptr) {
      Pokemon* temp = A[i];
      if (name.compare(temp->name()) == 0) {
        return temp;
      }
    }
  }
  return nullptr;
}
// lookup pokemon by index
Pokemon* Pokedex::lookup_by_Ndex(int ndex) {
  return A[ndex];
}

int Pokedex::size() 
{
  int result = 0;
// last loop and array that ends with result
  for (int i = 0; i < 1000; i++) {
    if (A[i] != nullptr) {
      result++;
    }
  }

  return result; 
}
