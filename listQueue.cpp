/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue{
    private:
          list<T> l;
    public://push, pop, front, back, size, empty
          void push(T data){
              l.push_back(data); 
          }
          
          void pop(){
              if(!empty()){
                  l.pop_front();
              }
          }
          
          T front(){
              return l.front();
          }
          
          T back(){
              return l.back();
          }
          
          int size(){
              return l.size();
          }
          
          bool empty(){
              return l.empty();
          }
          void clear(){
              l.clear();
          }
};

template<typename T> void printElement(Queue<T> st);
int main()
{
    Queue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.pop();
    q.pop();
    cout << "last element " << q.back() << endl;
    cout << "size" << q.size() << endl;
    printElement(q);
    return 0;
}
template<typename T> void printElement(Queue<T> st){
          while(!st.empty()){
            cout << st.front() << endl;
            st.pop();
          }
}
