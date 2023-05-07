////////////////////////////////////////////////////
// Team #18 CSCI 2380 SPRING 2023 HOMEWORK #13
// Marcus Gutierrez
// 5/6/23
// Gustavo Dietrich
//////////////////////////////////////////////////// 
#include "loginserver.h"

LoginServer::LoginServer() {
    // new server 
    // set & map are established to no accounts
    unordered_set<string> S = {};
    unordered_map<string, string> M = {}; 
}

bool LoginServer::create_user(string username, string password) {
    if(M.find(username) == M.end()) {
        M[username] = password; 
        // if username present also accepts password
        return true;
    }
    return false;
}

bool LoginServer::delete_user(string username, string password) {
    if(M.find(username) == M.end()) {
        return false;
    }
    else {
        if(M.find(username)->second == password) {                                        
            if(S.find(username) != S.end()) {
                S.erase(username); 
                M.erase(username); 
            } 
            // if no username is entered it is erased from map and set
            else {
                M.erase(username); 
            }
            return true;
        }
        return false;
    }
}

bool LoginServer::login(string username, string password) {
    if(M.find(username) == M.end()) { 
        return false; 
    }
    else if(S.find(username) != S.end()) {
        return false;
    } 
    // doesnt return if no usernames are present in map or set
    else if(M[username] == password) {
        S.insert(username);
        return true;
    } 
    // username is inserted if found in set
    else {
        return false;
    }
}
int LoginServer::total_user_count() {
    return M.size();
}
bool LoginServer::logout(string username) {
    if(S.find(username) != S.end()) {
        S.erase(username); // erases username
        return true;
    }
    return false;
}
bool LoginServer::is_logged_in(string username) {
    if(S.find(username) != S.end()) {
        return true;
    }
    return false;
}

int LoginServer::active_user_count() {
    return S.size();
} // returns login count

void LoginServer::logout_everyone() {
    S.clear();
} // logs everyone out & clears usernames and passwords

bool LoginServer::change_password(string username, string old_pw, string new_pw) {
    if(M.find(username) != M.end()) {
        if(M[username] == old_pw) {
            M[username] = new_pw;
            return true;
        } // changes credentials if username password are false and sets new information to true
    }
    return false;
}

/* End of code: 2:06PM */