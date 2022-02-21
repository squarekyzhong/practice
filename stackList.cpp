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
          stack<T> *st;
          int num_of_stack = 10;
          int last_stack = -1;
          int incre = 10; //if all of stacks are full, increment the num_of_stack by 10
          int capacity = 10;//each stack can store 10 elements
          int* size; // num of elements in each stack
    public://push, pop, top, size, empty, min
          stackList(){
              st =  new stack<T>[num_of_stack];
              size = new int[num_of_stack]();
          }
          void push(T data){
            int last= getLastStack();
            if(last!=-1){//not empty
                  if(size[last]+1 > capacity){//if the stack is full
                     last++;//next stack
                     if(last <= num_of_stack-1){//there still has some stacks available.
                        st[last].push(data);
                        size[last]++;
                        last_stack = last; //points to the current stack
                     }
                     else{//all stacks are full
                         stack<T> *temp = new stack<T>[num_of_stack+incre];//expand the stack array
                         int* sz = new int[num_of_stack+incre];
                         for(int i=0; i < num_of_stack; i++){//walk through all stacks
                                temp[i] = st[i]; //copy all stack variables in st to temp
                                sz[i] = size[i]; //copy num of elements in each stack to sz
                         }
                         st = temp;
                         size = sz;
                         num_of_stack+=incre;//update the num of stacks
                         st[last].push(data);
                         size[last]++;
                         last_stack = last; //points to the current stack
                       }
                  }
                  else{//the stack is not full
                     st[last].push(data);
                     size[last]++;
                    }
            }
            else{
                 last = 0;
                 st[last].push(data);
                 size[last]++;
                 last_stack = last;
           }
          }
          void pop(){
              int last = getLastStack();
              cout << "last stack " << last << endl;
              cout << "size of last stack " << size[last] << endl;
              if(last==-1 || !st){
                  cout << "stack is empty" << endl;
              }
              else if(size[last]){//the last stack is not empty
                  cout <<"poped element " << st[last].top() << endl;
                  st[last].pop();
                  size[last]--;
              }
              else{//the last stack is empty
                  if(last-1 >= 0){
                    last--;
                    cout << "poped element ";
                    cout << st[last].top() << endl;
                    cout <<"size of last stack before pop " << size[last] << endl;
                    st[last].pop();
                    size[last]--;
                    cout <<"size of last stack after pop " << size[last] << endl;
                    last_stack = last;
                  }
                  else{
                      cout << "stack is empty" <<endl;
                  }
              }
          }
          
          int getLastStack(){
              return last_stack;
          }
          
};

template<typename T> void printElement(stackList<T> st);
int main()
{
    stackList<int> st;
    for(int i=0; i < 101; i++){
        st.push(i);
    }
    st.pop();
    st.pop();
    return 0;
}
template<typename T> void printElement(stackList<T> st){
          
}
