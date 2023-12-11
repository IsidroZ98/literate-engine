// Team #20 CSCI 2380 FALL 2023 HOMEWORK #12
// Edgar Hernandez
// Marcus Gutierrez
// 11/29/23
// Gustavo Dietrich 
////////////////////////////////////////////////////////////////

#include "autocompleter.h"

// Constructor
Autocompleter::Autocompleter() {
  // Initialize root to nullptr
  root = nullptr;
}

// Insert a string into the Autocompleter
void Autocompleter::insert(string x) {
  // If the tree is empty, create a new node and set it as the root
  if (root == nullptr) {
    root = new Node(x);
  } else {
    // Traverse the tree to find the correct position for the new node
    Node* cur = root;
    while (true) {
      // If the string already exists, break out of the loop
      if (cur->s == x) {
        break;
      } else if (cur->s > x) {
        // If the string is less than the current node, go left
        if (cur->left == nullptr) {
          cur->left = new Node(x);
          break;
        } else {
          cur = cur->left;
        }
      } else if (cur->s < x) {
        // If the string is greater than the current node, go right
        if (cur->right == nullptr) {
          cur->right = new Node(x);
          break;
        } else {
          cur = cur->right;
        }
      }
    }
  }
}

// Get the size of the Autocompleter
int Autocompleter::size() {
  return completion_count("");  // Returns the completion count for an empty string
}

// Get the completion count for a given string
int Autocompleter::completion_count(string x) {
  return completion_count_recurse(x, root); // Returns the completion count for x and root
}

// Recursive function to calculate the completion count
int Autocompleter::completion_count_recurse(string x, Node* root) {
  int count = 0;
  if (root == nullptr) {
    return 0;
  }
  // Check if the current node's string starts with x
  if (root->s.find(x) == 0) {
    count = count + 1;
  }4

  // Recursively calculate completion count for left and right subtrees
  count += completion_count_recurse(x, root->left);
  count += completion_count_recurse(x, root->right);

  return count;
}

// Recursive function to get completions and store them in an array
void Autocompleter::completions_recurse(string x, string* suggestions, Node* root) {
  if (root == nullptr) {
    return;
  }
  // Check if the array is already full
  if (suggestions[4] != "") {
    return;
  }

  // Recursively get completions for left subtree
  completions_recurse(x, suggestions, root->left);

  // If the current node's string starts with x, add it to suggestions
  if (root->s.find(x) == 0) {
    for (int i = 0; i < 5; i++) {
      if (suggestions[i] == "") {
        suggestions[i] = root->s;
        break;
      }
    }
  }

  // Recursively get completions for right subtree
  completions_recurse(x, suggestions, root->right);
}

// Get completions for a given string and store them in an array
void Autocompleter::completions(string x, string* suggestions) {
  // Initialize the array with empty strings
  for (int i = 0; i < 5; i++) {
    suggestions[i] = "";
  }

  // Get completions and store them in the array
  completions_recurse(x, suggestions, root);
}


/*
binary trees 
dealing with nullptr 
the size of the tree depends on code
post order does the opposite of pre order 

practice, creating ur own trees and go over practice problems, try to do them without watching the videos first



*/





