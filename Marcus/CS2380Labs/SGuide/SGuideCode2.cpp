// Suppose the content of a doubly-linked-list-based deque of strings is (from front to tail) "alpha","beta","gamma"; what would the content of the list be after the enigma() function is executed. List the VALUES separated by a comma please.
// Do NOT include the double quotes and do NOT include blank spaces in your answer (just the strings separated by commas).
#include <iostream> 
using namespace std; 


class Deque

{

        public:

                void enigma();

        private:

        class Node {

                public:

                        string s;

                        Node* next;

                        Node* prev;

        };

        Node* head;

        Node* tail;

        int count;

};

 

void Deque::enigma()

{

        if (tail == head || tail == nullptr)

                return;

        Node* cur = tail;

        while (true)

        {

                if (cur == nullptr)

                        break;

                Node* tmp = cur->next;

                cur->next = cur->prev;

                cur->prev = tmp;

                cur = cur->next;

        }

        Node* tmp = tail;

        tail = head;

        head = tmp;

}