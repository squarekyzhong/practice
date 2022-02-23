#include <iostream>
#include<list>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Tower{
       private:
              stack<T> disks;
              int index;
       public:
              Tower(int i){
                  index = i;
              }
              
              int getIndex(){
                  return index;
              }
              
              void add(int d){
                  if(!isEmpty()&&d >= disks.top()){
                      cout << "it is placed in the wrong place." << endl;
                      exit(1);
                  }
                  else{
                      disks.push(d);
                  }
              }
              
              void moveTopTo(Tower* t){
                  int top = disks.top();
                  disks.pop();
                  t->add(top);
                  cout << "Move disk " << top << " from " << index << " to " << t->getIndex() << endl;
              }
              
              void moveDisks(int n, Tower* target, Tower* buffer){
                  if(n > 0){
                      moveDisks(n-1, buffer, target); //(2, tower[0],tower[1], tower[2]),
                      moveTopTo(target);                       // (1, tower[0], tower[2], tower[1])
                                                             //(v0->tower[2])
                      cout << "this->getIndex() " << this->getIndex()<<endl;
                      buffer->moveDisks(n-1, target, this);//(1, tower[0], tower[1], tower[2])
                  }
              }
              
              bool isEmpty(){
                  return disks.empty();
              }
              
              void showStack(){
                  while(disks.size()){
                      cout<<"disks element " << disks.top() <<endl;
                      disks.pop();
                  }
              }
};

int main()
{
    int num_disks = 3;
    //list<int> *plist = new list<int>[radix];

    Tower<int> *tower[3] ={new Tower<int>(0), new Tower<int>(1),new Tower<int>(2)};
    for(int i=num_disks-1; i >= 0; i--){
        tower[0]->add(i);
    }
    //tower[0]->showStack();
    cout << "index "<< tower[1]->getIndex() << endl;
    tower[0]->moveDisks(num_disks, tower[2], tower[1]);
    
    return 0;
}

