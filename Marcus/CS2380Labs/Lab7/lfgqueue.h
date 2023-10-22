
#ifndef LFGQUEUE_H
#define LFGQUEUE_H

#include "player.h"

class LFGQueue 
{
	public:
// All of the methods are the same as in hw5.

		// Constructs a new empty queue
		LFGQueue();

		// Returns the number of players in the queue.
		int size();

		// Adds a player to the back of the queue.
		void push_player(Player* plyr);

		// Returns a pointer to the frontmost player 
		// with the specified role. If no such player 
		// exists, returns nullptr.
		Player* front_player(Player::Role r);

		// Removes the frontmost player with the
		// specified role. If no such player exists
		// does nothing.
		void pop_player(Player::Role r);	

		// Returns whether the queue contains a complete group
		// (a Defender, a Hunter, and a Bard).
		//
		// If the queue contains a complete group, the method
		// sets the first three elements of the array parameter
		// equal to the addresses of the frontmost:
		// 1. Defender (index 0)
		// 2. Hunter (index 1)
		// 3. Bard (index 2)
		bool front_group(Player** group);

		// Removes the frontmost Defender, Hunter, 
		// and Bard from the queue. If some role
		// has no player with that role, then
		// no players are removed.
		void pop_group();

	private:
		class Node
		{
			public:
				Player* p;
				Node* next;
		};

		// Each element of this array points to the head of the corresponding queue:
		// Defender (index 0), Hunter (index 1), Bard (index 2)
		Node* heads[3];
		// Each element of this array points to the tail of the corresponding queue:
		// Defender (index 0), Hunter (index 1), Bard (index 2)
		Node* tails[3];
		// Each element of this array keeps track of the number of players in the corresponding queue:
		// Defender (index 0), Hunter (index 1), Bard (index 2)
		int counts[3];
};

#endif

// IMPORTANT!:
// You can index into the heads, tails, and counts arrays using Player::Role values!
// Check out player.h to see the int value of each Role.
//
// This lets you do things like:
// "if (heads[plyr->role()] == nullptr)" and "++counts[plyr->role()]" 
