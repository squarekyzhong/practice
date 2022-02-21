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
class stackWithMin: public stack<T>{
    private:
          stack<T> st2;
    public://push, pop, top, size, empty, min
          void push(T data){
              if(data <= min()){
                  st2.push(data);
                  cout << "data" << data <<endl;
              }
              stack<T>::push(data);
          }
          
          void pop(){
              if(stack<T>::top()==min()){
                  st2.pop();
              }
              stack<T>::pop();
          }
          
          T min(){
              if(st2.empty()){
                  return INT_MAX;
              }
              else{
                  return st2.top();
              }
          }
};

template<typename T> void printElement(stackWithMin<T> st);
int main()
{ 
    stackWithMin<int> sm;
    sm.push(1);
    sm.push(2);
    sm.push(3);
    printElement(sm);
    cout << sm.min() <<endl;
    return 0;
}
template<typename T> void printElement(stackWithMin<T> st){
          while(!st.empty()){
            cout << st.top() << endl;
            st.pop();
          }
}
