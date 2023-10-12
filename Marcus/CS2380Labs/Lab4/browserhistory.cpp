// Team #20 CSCI 2380 FALL 2023 HOMEWORK #3
// Edgar Hernandez
// Marcus Gutierrez
// 10/1/23
// Gustavo Dietrich 

#include "browserhistory.h"

BrowserHistory::BrowserHistory(string default_url) {
    past.push(default_url);
}

string BrowserHistory::current_url() {
    return past.top();
}

void BrowserHistory::go_to_url(string url) {
    future = stack<string>();  // Clear the future stack when navigating to a new URL
    past.push(url);
}

void BrowserHistory::back() {
    if (past.size() > 1) {
        future.push(past.top());
        past.pop();
    }
}

bool BrowserHistory::can_go_back() {
    return past.size() > 1;
}

int BrowserHistory::past_url_count() {
    return past.size() - 1;
}

void BrowserHistory::forward() {
    if (!future.empty()) {
        past.push(future.top());
        future.pop();
    }
}

