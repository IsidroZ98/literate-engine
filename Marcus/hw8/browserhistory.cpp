#include "browserhistory.h"

BrowserHistory::BrowserHistory(string def_url){
head=new Node();
  
head->url=def_url;

head->next=NULL;

head->prev=NULL;

tail=head;

current=head;

}

string BrowserHistory::current_url(){
  return current->url;

}

void BrowserHistory::go_to_url(string url){
  
 Node* n=new Node();

 n->url=url;

 n->prev=current;

 n->next=NULL;

 current->next=n;

 current=n;

 tail=n;

}

                               

void BrowserHistory::back(){
  
  if(can_go_back()){
  current=current->prev;
}

}

                               

bool BrowserHistory::can_go_back(){

return current->prev!=NULL;

}

                               

int BrowserHistory::past_url_count(){

int c=0;

for(Node* n=current->prev;n!=NULL;n=n->prev){

c++;
}
  return c;
}

                               

void BrowserHistory::forward(){

if(can_go_forward()){

current=current->next;

}
}

                               

bool BrowserHistory::can_go_forward(){
  
 return current->next!=NULL;

}

                               

int BrowserHistory::future_url_count(){

int c=0;
  
 for(Node* n=current->next;n!=NULL;n=n->next){

 c++;
}
  return c;
}
