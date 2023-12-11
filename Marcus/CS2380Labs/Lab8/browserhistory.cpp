// Team #20 CSCI 2380 FALL 2023 HOMEWORK #8
// Edgar Hernandez
// Marcus Gutierrez
// 11/6/23
// Gustavo Dietrich 
////////////////////////////////////////////////////////////////
#include "browserhistory.h"

// constructor made for browser history 
BrowserHistory::BrowserHistory(string default_url) {
    // node created for our default url
    head = new Node();
    head->url = default_url;
    head->next = nullptr;
    head->prev = nullptr;
    tail = head;
    current = head;
}

// return current url
string BrowserHistory::current_url() {
    return current->url;
}

// go to new url and add it to our history 
void BrowserHistory::go_to_url(string url) {
    Node* n = new Node();
    n->url = url;
    n->prev = current;
    n->next = nullptr;

    // node created for new url then update current node and tail 
    current->next = n;
    current = n;
    tail = n;
}

// go from current url to previous url
void BrowserHistory::back() {
    if (can_go_back()) {
        current = current->prev;
    }
}

// true false input to see if we can go back from current to previous
bool BrowserHistory::can_go_back() {
    return current->prev != nullptr;
}

// count our webpages in our history
int BrowserHistory::past_url_count() {
    int count = 0;
    Node* n = current->prev;
    while (n != nullptr) {
        count++;
        n = n->prev;
    }
    return count;
}

// go forward to the next url
void BrowserHistory::forward() {
    if (can_go_forward()) {
        current = current->next;
    }
}

// true false to see if we can go forward to our future url
bool BrowserHistory::can_go_forward() {
    return current->next != nullptr;
}

// keep count of urls that are established future 
int BrowserHistory::future_url_count() {
    int count = 0;
    Node* n = current->next;
    while (n != nullptr) {
        count++; // increase count
        n = n->next;
    }
    return count;
}
