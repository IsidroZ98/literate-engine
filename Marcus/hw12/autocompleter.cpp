////////////////////////////////////////////////////
// Team #18 CSCI 2380 SPRING 2023 HOMEWORK #12
// Marcus Gutierrez
// 4/27/23
// Gustavo Dietrich
//////////////////////////////////////////////////// 

#include "autocompleter.h"
 
/* needs comments */

Autocompleter::Autocompleter()
{
  root = nullptr;
}

void Autocompleter::insert(string x)
{
  if(root == nullptr)
  {
    root = new Node(x);
  }
  else 
  {
    Node* cur = root;
    while(true)
    {
      
      if(cur->s == x)
      {
        break;
      }
      else if(cur->s > x)
      {
        if(cur->left == nullptr)
        {
          cur->left = new Node(x);
          break;
        }
        else{
         cur = cur->left;
        }  
      }
        
      else if(cur->s < x)
      {
        if(cur->right == nullptr)
        {
         cur->right = new Node(x);
         break;
        }
        else
        {
          cur = cur->right;
        }
      }
    }
  }
}

int Autocompleter::size()
{
  return completion_count("");   
}

int Autocompleter::completion_count(string x)
{
  return completion_count_recurse(x, root);
}

int Autocompleter::completion_count_recurse(string x, Node* root)
{
  int count = 0;
  if(root == nullptr){
    return 0;
  }
  if(root->s.find(x) == 0){
    count = count + 1;
  }

  count += completion_count_recurse(x, root->left);
  
  
  count += completion_count_recurse(x, root->right);
  return count;
}

void Autocompleter::completions_recurse(string x, string* suggestions, Node* root)
{
  if(root == nullptr)
  {
    return;
  }
  if(suggestions[4] != ""){
    return;
  }
  completions_recurse(x, suggestions, root->left);
  if(root->s.find(x) == 0)
  {
    for(int i = 0; i < 5; i++)
    {
      if(suggestions[i] == "")
      {
        suggestions[i] = root->s;
        break;
      }
    }
  }
  completions_recurse(x, suggestions, root->right);
}

void Autocompleter::completions(string x, string* suggestions)
{
  for(int i = 0; i < 5; i++)
  {
    suggestions[i] = "";
  }

  completions_recurse(x, suggestions, root);
}
