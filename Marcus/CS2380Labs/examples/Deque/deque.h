
#ifndef DEQUE_H
#define DEQUE_H

#include <string>

using namespace std;

class Deque 
{
        public:
                Deque();
                void push_back(string s);
                void pop_back();
                string back();
                void push_front(string s);
                void pop_front();
                string front();
                int size();

        private:
		class Node
		{
			public:
				string s;
				Node* next;
		};

		Node* head;
		Node* tail;
};

#endif


