// Team #20 CSCI 2380 FALL 2023 HOMEWORK #6
// Edgar Hernandez
// Marcus Gutierrez
// 10/12/23
// Gustavo Dietrich 

#include "lfgqueue.h"

// Constructor: Initializes an empty LFGQueue with a default capacity of 100.
LFGQueue::LFGQueue()
{
  count = 0; 
  capacity = 100; 
  players = new Player*[capacity]; // Dynamic array to store players

  // Initialize each element to nullptr
  for (int i = 0; i < capacity; i++) 
    {
    players[i] = nullptr; 
    }
}

// Returns the number of players in the queue.
int LFGQueue::size()
{
  return count;
}

// Adds a player to the back of the queue. If the queue is full, doubles its capacity.
void LFGQueue::push_player(Player* p)
{
  if (count >= capacity) 
  {
    // Double the capacity
    capacity *= 2; 
    Player** players2 = new Player*[capacity]; 

    // Copy existing players to the new array
    for (int i = 0; i < count; i++) 
      {
        players2[i] = players[i]; 
      }
    delete []players; 

    // Update the pointer to the new array
    players = players2; 
  }
  // Add the new player to the queue
  players[count++] = p; 
}

// Returns a pointer to the frontmost player with the specified role. Returns nullptr if not found.
Player* LFGQueue::front_player(Player::Role r)
{
  for (int i = 0; i < count; i++) 
    {
    // Check if the player is not nullptr and has the specified role
    if (players[i] != nullptr && players[i]->role() == r) 
      {                                                     
      return players[i]; // Return the found player 
      }
    }
  return nullptr; // No player found
}

// Removes the frontmost player with the specified role.
void LFGQueue::pop_player(Player::Role r)
{
  for (int i = 0; i < size(); i++)
  {
    // Check if the player has the specified role and is not nullptr
    if (players[i]->role() == r && players[i] != nullptr) 
    {                                                     
    players[i] = nullptr; // Set the player at index i to nullptr
      // Shift the remaining players to fill the gap
      for (int j = i; j < size() - 1; j++) 
        {                                  
    players[j] = players[j + 1]; 
        }
      --count;   // Decrement the count of players
      return;    // Player removed, exit the loop
    }
  }
}

// Checks if there is a complete group (Defender, Hunter, and Bard) at the front of the queue.
bool LFGQueue::front_group(Player** group)
{
  bool g = true;  
  // Get the frontmost players of each role
  group[0] = front_player(Player::Defender); 
  group[1] = front_player(Player::Hunter);    
  group[2] = front_player(Player::Bard); 

  // Check if all roles are filled
  if (group[0] != nullptr && group[1] != nullptr && group[2] != nullptr) 
  {                                         
    return g; // Complete group found
  }
  else 
  {
    return g = false; // Incomplete group
  }
}

// Removes the frontmost Defender, Hunter, and Bard from the queue if a complete group exists.
void LFGQueue::pop_group()
{
  Player* g[3];       
  if (front_group(g)) 
  {                                                                    
    pop_player(Player::Defender); 
    pop_player(Player::Hunter);   
    pop_player(Player::Bard);     
  }
}
