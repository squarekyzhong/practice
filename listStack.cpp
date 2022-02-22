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
class stackList{
    private:
          list<stack<T>*> ls;
          int capacity = 10;
    public:
           void push(T data){
               if(ls.size()&&getLastStack()->size()+1 <= capacity){//not empty or not full
                   stack<T>* lastStack = getLastStack();
                   lastStack->push(data);
               }
               else{
                   stack<T>* newStack = new stack<T>();
                   ls.push_back(newStack);
                   newStack->push(data);
               }
           }
           
           void pop(){
               if((getLastStack()->size())){//if the stack is not empty

                  stack<T>* lastStack = getLastStack();
                  cout << "getLastStack().size() " << getLastStack()->size() << endl;
                  cout << "poped element " << lastStack->top() << endl;
                  lastStack->pop();    
               }
               else{//if the stack is empty
                   ls.pop_back();
                   stack<T>* lastStack = getLastStack();
                   cout << "getLastStack().size() " << getLastStack()->size() << endl;
                   cout << "poped element " << lastStack->top() << endl;
                   lastStack->pop();
               }
           }
           
           stack<T>* getLastStack(){
               return ls.back();
           }
    
};

template<typename T> void printElement(stackList<T> st);
int main()
{ 
    stackList<int> st;
    for(int i=0; i < 101; i++){
        st.push(i);
    }
    printElement(st);
    return 0;
}
template<typename T> void printElement(stackList<T> st){
          while(st.getLastStack()){
              st.pop();
          }
}
