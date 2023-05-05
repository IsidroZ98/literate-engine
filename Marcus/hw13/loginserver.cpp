////////////////////////////////////////////////////
// Team #18 CSCI 2380 SPRING 2023 HOMEWORK #12
// Marcus Gutierrez
// 4/27/23
// Gustavo Dietrich
//////////////////////////////////////////////////// 

/* needs comments */

#include "loginserver.h"

LoginServer::LoginServer()
{
  unordered_set<string> S = {};
  unordered_map<string, string> M = {}; 
}

bool LoginServer::create_user(string username, string password)
{
  if(M.find(username) == M.end()) 
  {
    M[username] = password; 
    return true;
  }
  return false;
}

bool LoginServer::delete_user(string username, string password)
{
  if(M.find(username) == M.end()) 
  {
    return false;
  }
  else
  {
    if(M.find(username)->second == password)
    {                                        
      if(S.find(username) != S.end()) 
      {
        S.erase(username); 
        M.erase(username); 
      }
      else
      {
        M.erase(username); 
      }
      return true;
    }
    return false;
  }
}

int LoginServer::total_user_count()
{
  return M.size();
}

bool LoginServer::login(string username, string password)
{
  if(M.find(username) == M.end()){ 
    return false;
  }
  else if(S.find(username) != S.end()) 
  {
    return false;
  }
  else if(M[username] == password) 
  {
    S.insert(username);

    return true;
  }
  else
  {
    return false;
  }
}

bool LoginServer::logout(string username)
{
  if(S.find(username) != S.end()) 
  {
    S.erase(username); 
    return true;
  }
  
    return false;
  
}

bool LoginServer::is_logged_in(string username)
{
  if(S.find(username) != S.end())
  {
    return true;
  }
  
    return false;
  
}

int LoginServer::active_user_count()
{
  return S.size();
}

void LoginServer::logout_everyone()
{
  S.clear();
}

bool LoginServer::change_password(string username, string old_pw, string new_pw)
{
  if(M.find(username) != M.end()) 
  {
    if(M[username] == old_pw) 
    {
      M[username] = new_pw;
      
      return true;
    }
  }
  return false;
}