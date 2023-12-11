// Team #20 CSCI 2380 FALL 2023 HOMEWORK #13
// Edgar Hernandez
// Marcus Gutierrez
// 12/11/23
// Gustavo Dietrich 
////////////////////////////////////////////////////////////////

#include "loginserver.h"

// constructor created from loginserver.h class 
LoginServer::LoginServer() {
    
}
// function from loginserver class that checks true false and returns based on username exist or not
bool LoginServer::create_user(string username, string password) {
    if (M.find(username) != M.end()) {
        return false;
      // check if username already exist return false if it does since it fails the creation
    }

    M[username] = password;
    return true;
  // if not return true and adds to system
}
// another bool setup for user deletion
bool LoginServer::delete_user(string username, string password) {
    auto it = M.find(username);
// username search 
  
    if (it != M.end() && it->second == password) {
        S.erase(username);
        M.erase(it);
        return true;
      /* code here checks username, if pw match and erases if true */
    }
    return false; // pw dont match return false
}

int LoginServer::total_user_count() {
    return M.size();
  // returns size goes off # of users
}

bool LoginServer::login(string username, string password) {
    if (M.find(username) != M.end() && M[username] == password) // check parameters 
    {
        if (S.find(username) == S.end()) {
            S.insert(username);
            return true; // credentials correct return true and proceed login, 
        }
    }
    return false; // invalid credentials or user is logged in already
}

bool LoginServer::logout(string username) {
    if (S.find(username) != S.end()) {
        S.erase(username);
        return true;
    }
  // code checks usernames and logged in status, erase if true (logging out)

    return false; // false if user not logged in
}

bool LoginServer::is_logged_in(string username) {
    return S.find(username) != S.end();
  // login check
}

int LoginServer::active_user_count() {
    return S.size();
} // return size of active users

void LoginServer::logout_everyone() {
    S.clear();
} // clear users, logout all 

bool LoginServer::change_password(string username, string old_pw, string new_pw) {
    auto it = M.find(username);

    if (it != M.end() && it->second == old_pw) {
        it->second = new_pw;
        return true;
    } // pw change and more check on pw putting old to new

    return false;
  // username or pw not correct return false
}
