// Team #20 CSCI 2380 FALL 2023 HOMEWORK #7
// Edgar Hernandez
// Marcus Gutierrez
// 10/19/23
// Gustavo Dietrich 

#include "lfgqueue.h"

LFGQueue::LFGQueue() // Sets up 3 queues for all roles, starting with head[i] and tail[i] = NULL, and count[i] = 0.
{
    for(int i = 0; i < 3; i++)
    {
        heads[i] = NULL;
        tails[i] = NULL;
        counts[i] = 0;
    }
}

int LFGQueue::size() // declares the size
{
    
    return counts[0] + counts[1] + counts[2]; // returns counts
}

void LFGQueue::push_player(Player* p) // void function for player setup
{
    
    int index; // Sets the index depending on the given role pushed in.
    if(p->role() == Player::Defender)
    {
        index = 0;
    }
    else if(p->role() == Player::Hunter)
    {
        index = 1;
    }
    else
    {
        index = 2;
    }
    
    Node* n = new Node(); // Creates a new node and connects it to the old node.
    n->p = p;
    n->next = NULL;
    
    if(counts[index] == 0)
    {
        heads[index] = tails[index] = n; // This shows the new node is the only node in the queue.
    }
    else
    {
        tails[index]->next  = n; // This shows that the new node is being added to the queue
        tails[index] = n; // As the new tail.
    }
    counts[index]++; // Increases as more nodes are created.
}
Player* LFGQueue::front_player(Player::Role r)
{
    int index; // Sets index depending on what role.
    if(r == Player::Defender)
    {
        index = 0;
    }
    else if(r == Player::Hunter)
    {
        index = 1;
    }
    else
    {
        index = 2;
    }

    if(heads[index] == NULL)
        return NULL;
    else
        return heads[index]->p;
}

void LFGQueue::pop_player(Player::Role r)
{
    int index; // Sets index depending on what role is being popped.
    if(r == Player::Defender)
    {
        index = 0;
    }
    else if(r == Player::Hunter)
    {
        index = 1;
    }
    else
    {
        index = 2;
    }
    
    if(counts[index] > 0) // Code only works if the group is bigger than 0.
    {
        heads[index] = heads[index]->next;
        if(heads[index] == NULL)
            tails[index] = NULL;
        counts[index]--; // Pops the received role and decreases count by 1 if head != NULL.
    }
}
bool LFGQueue::front_group(Player** group)
{
    group[0] = front_player(Player::Defender); // Sets group[0] to the Defender, if there is one,
    group[1] = front_player(Player::Hunter); // Group[1] to the next Hunter, if there is one,
    group[2] = front_player(Player::Bard); // And group[2] to the next Bard, if there is one.
    
    if(group[0] == NULL || group[1] == NULL || group[2] == NULL) // Checks if any of the groups are set to NULL.
    {
        group[0] = group[1] = group[2] = NULL; // set all to NULL if only 1 or 2 groups are set to NULL.
        return false;
    }
    else
        return true; 
}
void LFGQueue::pop_group()
{
  if (front_player(Player::Defender) == NULL || front_player(Player::Hunter) == NULL || front_player(Player::Bard) == NULL)
    // If less than 3 players are NULL, returns the group list without popping.
    return;
  
  // If all players = NULL, pops each player in the group.
    pop_player(Player::Defender); 
    pop_player(Player::Hunter);
    pop_player(Player::Bard);
}
