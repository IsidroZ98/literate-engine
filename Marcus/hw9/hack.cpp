// Team #18 CSCI 2380 SPRING 2023 HOMEWORK #9
// Marcus Gutierrez
// 4/7/23
// Gustavo Dietrich

#include "hack.h"

void Dave(EvilComputer* ec, string pw){
  if(pw.size() == 4){ 
    ec->guess("Dave", pw);
    return;
  }
    for(char c = 48; c < 58; c++){
      Dave(ec, pw + c);
    }
}

void MrMean(EvilComputer* ec, string pw, int l)
{
  if (pw.size() == l) 
  {
    ec->guess("Mr. Mean", pw); 
    return;
  }

  MrMean(ec, pw + 'g', l); 
  MrMean(ec, pw + 'r', l);
}

void MsChief(EvilComputer* ec, string pw, int l)
{
  if (pw.size() == l) 
  {
    ec->guess("Ms. Chief", pw); 
    return;
  }

  for (char c = 48; c < 58; c++) 
    {
      MsChief(ec, pw + c, l); 
    }
  
  for (char c = 97; c < 123; c++)
    {
      MsChief(ec, pw + c, l);  
    }
}

void DrEvil(EvilComputer* ec, string pw, int l)
{
  if (pw.size() == l - 4)
  {
    ec->guess("Dr. Evil", "gato" + pw);
    ec->guess("Dr. Evil", pw + "gato");
    return;
  }

  for (char c = 48; c < 58; c++)
    {
      DrEvil(ec, pw + c, l);
    }
  
  for (char c = 97; c < 123; c++)
    {
      DrEvil(ec, pw + c, l);
    }
}

void hack(EvilComputer* ec)
{
  ec->guess("Guest", "passw123");  
  Dave(ec, ""); 

  for (int i = 1; i < 9; i++)  
    {
      MrMean(ec, "", i);  
    }

  for (int i = 4; i < 9; i++) 
    {
      MsChief(ec, "haha", i); 
    }

  for (int i = 4; i < 9; i++) 
    {
      DrEvil(ec, "", i); 
    }
}