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
          T* arr;
          int first=-1;
          int last=-1;
          int max = 10;
          int incre = 10;
    public://push, pop, front, back, size, empty
          Queue(){
              arr = new T[max];
          }
          bool push(T data){
              if(empty()){
                  first = 0;
                  arr[first]=data;
                  last = first;
                  return true;
              }
              else if(last+1 >=max ){
                  max+=incre;
                  T* temp = new T[max];
                  for(int i=0; i <= last;i++){
                      temp[i] = arr[i];
                  }
                  arr = temp;
                  last++;
                  arr[last]=data;
                  return true;
              }
              else{
                  last++;
                  arr[last] = data;
                  return true;
              }
              return false;
          }
          bool pop(){
              if(!empty()){
                for(int i=1; i <= last; i++){
                      arr[i-1] = arr[i];
              }
              last--;
              return true;
              }
              return false;
          }
          T front(){
              return arr[first];
          }
          T back(){
              return arr[last];
          }
          int size(){
              return last+1;
          }
          bool empty(){
              return last==-1;
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
    printElement(q);
    return 0;
}
template<typename T> void printElement(Queue<T> st){
          while(!st.empty()){
            cout << st.front() << endl;
            st.pop();
          }
}
