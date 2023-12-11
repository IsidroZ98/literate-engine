// Team #20 CSCI 2380 FALL 2023 HOMEWORK #7
// Edgar Hernandez
// Marcus Gutierrez
// 10/19/23
// Gustavo Dietrich 

#include "lfgqueue.h"

// constructor made for lfgqueue
LFGQueue::LFGQueue() {
    // start of 3 queues
    for (int i = 0; i < 3; i++) {
        heads[i] = NULL;
        tails[i] = NULL;
        counts[i] = 0;
    }
}

// get size of queues
int LFGQueue::size() {
    return counts[0] + counts[1] + counts[2];
}

// adds player to queue goes off role
void LFGQueue::push_player(Player* p) {
    int index;

    // index based on player role
    if (p->role() == Player::Defender) {
        index = 0;
    } else if (p->role() == Player::Hunter) {
        index = 1;
    } else {
        index = 2;
    }

    // new node created that connects to other nodes
    Node* n = new Node();
    n->p = p;
    n->next = NULL;

    if (counts[index] == 0) {
        // sets new node as only node in queue
        heads[index] = tails[index] = n;
    } else {
        //add new node to ending of queue
        tails[index]->next = n;
        tails[index] = n;
    }
    counts[index]++; // count is increased
}

// get front player from role
Player* LFGQueue::front_player(Player::Role r) {
    int index;

    // find out index based on role
    if (r == Player::Defender) {
        index = 0;
    } else if (r == Player::Hunter) {
        index = 1;
    } else {
        index = 2;
    }

    if (heads[index] == NULL)
        return NULL; // Queue is empty
    else
        return heads[index]->p; // Return the front player
}

// Remove the front player of a specific role
void LFGQueue::pop_player(Player::Role r) {
    int index;

    // Determine the index based on the role
    if (r == Player::Defender) {
        index = 0;
    } else if (r == Player::Hunter) {
        index = 1;
    } else {
        index = 2;
    }

    if (counts[index] > 0) {
        // Check if the queue is not empty
        heads[index] = heads[index]->next;
        if (heads[index] == NULL)
            tails[index] = NULL;
        counts[index]--; // Decrease the count
    }
}

// Get the front group of players with one player for each role
bool LFGQueue::front_group(Player** group) {
    // Set each group element to the front player of a specific role
    group[0] = front_player(Player::Defender);
    group[1] = front_player(Player::Hunter);
    group[2] = front_player(Player::Bard);

    // Check if any of the groups is set to NULL
    if (group[0] == NULL || group[1] == NULL || group[2] == NULL) {
        group[0] = group[1] = group[2] = NULL;
        return false; // Return false if any group is incomplete
    } else
        return true; // Return true if all groups are complete
}

// Remove the front group of players
void LFGQueue::pop_group() {
    // Check if any of the roles is missing a player
    if (front_player(Player::Defender) == NULL || front_player(Player::Hunter) == NULL || front_player(Player::Bard) == NULL)
        return; // Return without popping if the group is incomplete

    // If all players are present, pop each player from the group
    pop_player(Player::Defender);
    pop_player(Player::Hunter);
    pop_player(Player::Bard);
}
