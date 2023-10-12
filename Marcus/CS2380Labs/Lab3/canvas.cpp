// Team #20 CSCI 2380 FALL 2023 HOMEWORK #3
// Edgar Hernandez
// Marcus Gutierrez
// 9/26/23
// Gustavo Dietrich 

#include <iostream>
#include "canvas.h"
#include <string> 

using namespace std;

Canvas::Canvas(int width)
{
  _width = width;
  C = new char*[5];
  
  for(int i = 0; i < 5; i++)
  {
    C[i] = new char[width];
  }
  
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0;j <width; j++)
    {
      C[i][j]=' ';
    }
  }
  if(width == 0)
  {
    _width = 0;
  }
}

Canvas::Canvas(char x)
{
  _width = 5;

  C = new char*[5];
  for(int i = 0; i < 5; i++)
  {
    C[i] = new char[_width];
  }
  if(x =='A')
  {
    C[0][0] = ' '; C[0][1] = '#'; C[0][2] = '#'; C[0][3] = '#'; C[0][4] = ' ';
    
    C[1][0] = '#'; C[1][1] = ' '; C[1][2] = ' '; C[1][3] = ' '; C[1][4] = '#';
    
    C[2][0] = '#'; C[2][1] = '#'; C[2][2] = '#'; C[2][3] = '#'; C[2][4] = '#';
    
    C[3][0] = '#'; C[3][1] = ' '; C[3][2] = ' '; C[3][3] = ' '; C[3][4] = '#';
    
    C[4][0] = '#'; C[4][1] = ' '; C[4][2] = ' '; C[4][3] = ' '; C[4][4] = '#';

  }
  else if(x =='B')
  {
    C[0][0] = '#'; C[0][1] = '#'; C[0][2] = '#'; C[0][3] = '#'; C[0][4] = ' ';
  
    C[1][0] = '#'; C[1][1] = ' '; C[1][2] = ' '; C[1][3] = ' '; C[1][4] = '#';
  
    C[2][0] = '#'; C[2][1] = '#'; C[2][2] = '#'; C[2][3] = '#'; C[2][4] = ' ';
  
    C[3][0] = '#'; C[3][1] = ' '; C[3][2] = ' '; C[3][3] = ' '; C[3][4] = '#';
    
    C[4][0] = '#'; C[4][1] = '#'; C[4][2] = '#'; C[4][3] = '#'; C[4][4] = ' ';
  }
  else if(x =='C')
  {
    
    C[0][0] = ' '; C[0][1] = '#'; C[0][2] = '#'; C[0][3] = '#'; C[0][4] = '#';
    
    C[1][0] = '#'; C[1][1] = ' '; C[1][2] = ' '; C[1][3] = ' '; C[1][4] = ' ';
    
    C[2][0] = '#'; C[2][1] = ' '; C[2][2] = ' '; C[2][3] = ' '; C[2][4] = ' ';
    
    C[3][0] = '#'; C[3][1] = ' '; C[3][2] = ' '; C[3][3] = ' '; C[3][4] = ' ';
    
    C[4][0] = ' '; C[4][1] = '#'; C[4][2] = '#'; C[4][3] = '#'; C[4][4] = '#';
  }
  else if(x =='D')
  {
    C[0][0] = '#'; C[0][1] = '#'; C[0][2] = '#'; C[0][3] = '#'; C[0][4] = ' ';
    
    C[1][0] = '#'; C[1][1] = ' '; C[1][2] = ' '; C[1][3] = ' '; C[1][4] = '#';
    
    C[2][0] = '#'; C[2][1] = ' '; C[2][2] = ' '; C[2][3] = ' '; C[2][4] = '#';
    
    C[3][0] = '#'; C[3][1] = ' '; C[3][2] = ' '; C[3][3] = ' '; C[3][4] = '#';
    
    C[4][0] = '#'; C[4][1] = '#'; C[4][2] = '#'; C[4][3] = '#'; C[4][4] = ' ';
  }
  else 
  {
    for(int i =0; i<5 ;i++)
    {
      for(int j =0; j<_width; j++)
      {
        C[i][j]=' ';
      }
    }
  }
}
int Canvas::width()
{
  return _width;
}
string Canvas::to_string()
{
  string str;
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < _width; j++)
    { 
      str = str + C[i][j];
    }
    str = str + "\n";
  }
if(_width == 0)
  {
    return " ";
  }
  return str;
}
void Canvas::replace(char old_char, char new_char) 
{ 
  for (int i = 0; i < _width; i++) 
  {
    for (int j = 0; j < 5; j++) 
    {
      if (C[i][j] == old_char) 
      {
        C[i][j] = new_char;
      }
    }
  }
}

Canvas::~Canvas() { 
  for(int i=0;i<_width;i++) { delete [] C[i]; } 
  delete [] C;
C = nullptr; 
}

Canvas::Canvas(string s) {
  if (s == "") {
    cout << "Canvas is empty.\n";
    C = nullptr;
    _width = 0;
    return;
  }

  Canvas aux("");
  int x = s.length();
  for (int i = 0; i < x; ++i) {
    aux.add(s[i]);
  }

  _width = aux._width;
  C = aux.C;

  cout << "Canvas:\n" << to_string();
  cout << "Width: " << _width << '\n';
}


void Canvas::add(char x) {

  int twoCol = 2, moreCol = 5;
  char **newCanv;

  if (_width == 0) {
    cout << "";
    twoCol = 0;
    newCanv = new char *[moreCol];
    for (int col = 0; col < moreCol; ++col)
      newCanv[col] = new char[5];
    for (int col = 0; col < moreCol; ++col)
      for (int row = 0; row < 5; ++row)
        newCanv[col][row] = ' ';
  } else {
    cout << "Assignment complete. \n";
    newCanv = new char *[_width + twoCol + moreCol];
    for (int col = 0; col < _width; ++col)
      newCanv[col] = C[col];
    for (int col = _width; col < _width + twoCol + moreCol; ++col)
      newCanv[col] = new char[5];
    for (int col = _width; col < _width + twoCol + moreCol; ++col)
      for (int row = 0; row < 5; ++row)
        newCanv[col][row] = ' ';
  }
  
  Canvas auxCanv(x);
  if (x == 'A' || x == 'B' || x == 'C' || x == 'D') {
    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 5; ++j)
        newCanv[i + _width + twoCol][j] = auxCanv.C[i][j];
    }
  }
  if (C != nullptr)
    delete[]C; 
  C = newCanv;
  _width = _width + twoCol + moreCol;
  
  cin.ignore();

}