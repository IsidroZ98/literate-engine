
#include <sstream>
#include <cstdlib>
#include <iostream>
#include "lfgqueue.h"

using namespace std;


inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl;
        //abort();
}

#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))


int main()
{
	// Variables used for testing
	Player* group[3];
	Player daria("Daria", Player::Defender);
	Player daniela("Daniela", Player::Defender);
	Player hector("Hector", Player::Hunter);
	Player hugo("Hugo", Player::Hunter);
	Player berta("Berta", Player::Bard);
	Player bernardo("Bernardo", Player::Bard);


	// Test size(), push_player(), front_player(), pop_player() 
	LFGQueue q;
	test(q.size() == 0);
	test(q.front_player(Player::Defender) == nullptr);
	test(q.front_player(Player::Hunter) == nullptr);
	test(q.front_player(Player::Bard) == nullptr);

	q.push_player(&daniela);
	test(q.size() == 1);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == nullptr);
	test(q.front_player(Player::Bard) == nullptr);

	q.push_player(&hector);
	test(q.size() == 2);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == nullptr);

	q.push_player(&berta);
	test(q.size() == 3);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == &berta);

	q.push_player(&hugo);
	test(q.size() == 4);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == &berta);

	q.push_player(&bernardo);
	test(q.size() == 5);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == &berta);

	q.push_player(&daria);
	test(q.size() == 6);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == &berta);

	// Order is now [Daniela, Hector, Berta, Hugo, Bernardo, Daria]

	q.pop_player(Player::Defender);
	test(q.size() == 5);
	test(q.front_player(Player::Defender) == &daria);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == &berta);
	
	q.pop_player(Player::Hunter);
	test(q.size() == 4);
	test(q.front_player(Player::Defender) == &daria);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == &berta);
	
	q.pop_player(Player::Bard);
	test(q.size() == 3);
	test(q.front_player(Player::Defender) == &daria);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == &bernardo);

	q.pop_player(Player::Bard);
	test(q.size() == 2);
	test(q.front_player(Player::Defender) == &daria);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == nullptr);

	q.pop_player(Player::Defender);
	test(q.size() == 1);
	test(q.front_player(Player::Defender) == nullptr);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == nullptr);

	q.pop_player(Player::Hunter);
	test(q.size() == 0);
	test(q.front_player(Player::Defender) == nullptr);
	test(q.front_player(Player::Hunter) == nullptr);
	test(q.front_player(Player::Bard) == nullptr);

	
	// Test previous methods plus front_group()
	q.push_player(&hugo);
	test(q.size() == 1);
	test(q.front_player(Player::Defender) == nullptr);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == nullptr);
	test(!q.front_group(group));

	q.push_player(&hector);
	test(q.size() == 2);
	test(q.front_player(Player::Defender) == nullptr);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == nullptr);
	test(!q.front_group(group));

	q.push_player(&berta);
	test(q.size() == 3);
	test(q.front_player(Player::Defender) == nullptr);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == &berta);
	test(!q.front_group(group));

	q.push_player(&bernardo);
	test(q.size() == 4);
	test(q.front_player(Player::Defender) == nullptr);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == &berta);
	test(!q.front_group(group));

	q.push_player(&daria);
	test(q.size() == 5);
	test(q.front_player(Player::Defender) == &daria);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == &berta);
	test(q.front_group(group));

	q.push_player(&daniela);
	test(q.size() == 6);
	test(q.front_player(Player::Defender) == &daria);
	test(q.front_player(Player::Hunter) == &hugo);
	test(q.front_player(Player::Bard) == &berta);
	test(q.front_group(group));

	// Order is now [Hugo, Hector, Berta, Bernardo, Daria, Daniela]

	// Test previous methods plus pop_group()
	group[0] = group[1] = group[2] = nullptr;
	test(q.front_group(group));
	test(group[0] == &daria);
	test(group[1] == &hugo);
	test(group[2] == &berta);

	q.pop_group();	 
	test(q.size() == 3);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == &bernardo);

	// Test pop_group() If some role has no player with that role (group is not complete), then no players are removed	
	q.pop_player(Player::Bard);
	test(q.size() == 2);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == nullptr);


	group[0] = group[1] = group[2] = nullptr;
	test(!q.front_group(group));
	test(group[0] == &daniela);
	test(group[1] == &hector);
	test(group[2] == nullptr);

	q.pop_group();
	test(q.size() == 2);
	test(q.front_player(Player::Defender) == &daniela);
	test(q.front_player(Player::Hunter) == &hector);
	test(q.front_player(Player::Bard) == nullptr);
	
	q.pop_player(Player::Defender);
	q.pop_player(Player::Hunter);
	test(q.size() == 0);

	// Test a set of 999 players: 333 of each role in the following order:
	// 333 defenders, 1 hunter, 1 bard, 1 hunter, 1 bard...

	// Create the players
	Player** players = new Player*[999];
	ostringstream oss;
	for (int i = 0; i < 333; ++i)
	{
		oss.str("");
		oss << "Defender " << i+1;
		players[i] = new Player(oss.str(), Player::Defender);
	}
	for (int i = 333; i < 999; i+=2)
	{
		oss.str("");
		oss << "Hunter " << (i-333)/2+1;
		players[i] = new Player(oss.str(), Player::Hunter);
	}
	for (int i = 334; i < 999; i+=2)
	{
		oss.str("");
		oss << "Bard " << (i-334)/2+1;
		players[i] = new Player(oss.str(), Player::Bard);
	}
		
	// Add them to the queue	
	for (int i = 0; i < 999; ++i)
		q.push_player(players[i]);
	test(q.size() == 999);	

	// Repeatedly check and remove the frontmost players.
	// Because of how we scrambled, this has a fixed order.
	for (int i = 0; i < 333; ++i)
	{
		group[0] = group[1] = group[2] = nullptr;
		test(q.front_group(group));	

		oss.str("");
		oss << "Defender " << i+1;
		test(group[0]->name() == oss.str());

		oss.str("");
		oss << "Hunter " << i+1;
		test(group[1]->name() == oss.str());

		oss.str("");
		oss << "Bard " << i+1;
		test(group[2]->name() == oss.str());

		q.pop_group();
		test(q.size() == 999 - 3 * (i+1));
	}

	test(q.size() == 0);
	test(!q.front_group(group));

	for (int i = 0; i < 999; ++i)
		delete players[i];
	delete[] players; 
	
	cout << "Assignment complete." << endl;
}





