#include <iostream>
#include<list>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class myQueue{
       private:
              stack<T> st1;
              stack<T> st2;
       public:
              void pop(){
                  while(!st1.empty()){
                      T top = st1.top();
                      st2.push(top);
                      st1.pop();
                  }
                  st2.pop();
                  while(!st2.empty()){
                      T top = st2.top();
                      st1.push(top);
                      st2.pop();
                  }
              }
              
              void push_back(T data){
                  st1.push(data);
              }
              
              T front(){
                  cout << "top" << endl;
                  while(!st1.empty()){//change the order
                      T top = st1.top();
                      st2.push(top);
                      st1.pop();
                  }
                  cout << "st2.top() " << st2.top() << endl;
                  T peek = st2.top();
                  while(!st2.empty()){//recover the st1
                      T newTop=st2.top();
                      st1.push(newTop);
                      st2.pop();
                  }
                  return peek;
              }
              
              void printElement(){
                  while(!st1.empty()){
                      cout << "element " <<st1.top() << endl;
                      st1.pop();
                  }
              }
              
};

template<typename T> void printElement(myQueue<T> st);
int main()
{ 
    myQueue<int> que;
    for(int i=0; i < 100; i++){
        que.push_back(i);
    }
    que.front();
    que.pop();
    que.front();
    printElement(que);
    return 0;
}
template<typename T> void printElement(myQueue<T> st){
          st.printElement();
}
