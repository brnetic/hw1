#include <iostream>
#include "split.h"

using namespace std;

void deallocate(Node *in){
  if(!in){
    return;
  }
  deallocate(in->next);
  delete in;
}
void print(Node *in){
  if(!in){
    cout<<endl;
    return;
  }
  cout<<in->value<<" ";
  print(in->next);
}

int main(){

  Node s(1,NULL);
  Node* in = new Node(1,NULL);
  in->next = new Node(2,NULL);
  in->next->next = new Node(3,NULL);
  in->next->next->next = new Node(4,NULL);
  in->next->next->next->next = new Node(5,NULL);
  in->next->next->next->next->next = new Node(6,NULL);
  

  Node evens_(0,NULL);
  Node odds_(0,NULL);

  Node* evens = &evens_;
  Node* odds = &odds_;

  split(in,odds,evens);
  print(odds);
  print(evens);
  deallocate(evens);
  deallocate(odds);
  
  

  return 0;
}