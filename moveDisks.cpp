/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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
              Tower(){
                  
              }
              Tower(int i){
                  index = i;
              }
              
              int getIndex(){
                  return index;
              }
              
              void add(int d){
                  if(!isEmpty()&&d>=disks.top()){
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
                      moveDisks(n-1, buffer, target);
                      moveTopTo(target);
                      moveDisks(n-1, target, this);
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

template<typename T> void printElement(Tower<T> st);
int main()
{ 
    int num_disks = 10;
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
template<typename T> void printElement(Tower<T> st){
          
}
