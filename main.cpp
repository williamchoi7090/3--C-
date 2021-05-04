#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct imp{
  int a;
  int list;
  struct imp* b;
};
class PrioQ{
  private:
  imp* c;
  public:
  PrioQ(){
    c= NULL;
  }
  void insert(int b, int a) {
    imp *t, *q;
    t= new imp;
    t->list= b;
    t->a= a;
    if (c== NULL || a< c-> a){
      t->b= c;
      c= t;
    }
    else{
      q= c;
      while (q-> b != NULL && q-> b->a<= a)
      q= q-> b;
      t-> b= q->b;
      q-> b= t;
    }
  }
  void del(){
    imp* d;
    if(c== NULL)
    cout<< "List\n";
    else{
      d= c;
      cout<< "The deleted value is: "<< d->list<< endl;
      c= c-> b;
      free(d);
    }
  }
  void show(){
    imp* prio;
    prio= c;
    if (c== NULL)
    cout<< "The list is empty\n";
    else{
      cout<< "The list is:\n";
      cout<< "The second number is the priority\n";
      while(prio!= NULL){
        cout<< prio-> a<< " "<< prio->list<< endl;
        prio = prio-> b;
      }
    }
  }
};
int main(){
  int c, b, a;
  PrioQ pq;
  do{
    cout<< "1.Insert  2.Delete  3.Display  4.Exit\n";
    cout<< "Enter your choice: ";
    cin>>c;
    switch(c) {
      case 1:
      cout<< "Enter a value: ";
      cin>> b;
      cout<< "Enter its priority : ";
      cin>> a;
      pq.insert(b, a);
      break;
      case 2:
      pq.del();
      break;
      case 3:
      pq.show();
      break;
      case 4:
      break;
      default:
      cout<< "Invalid choice\n";
    }
  }
  while(c!= 4);
  return 0;
}