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
class Stack{
    private:
           int len = 0;
           T* arr;
           int max = 10;
           int incre = 10;
    //empty, size, top, push, pop
    public:
           Stack(){
               arr = new T[max];
           }
           bool empty(){
               return len==0;
           }
           size_t size(){
               return len;
           }
           T top(){//index starting from 0
               return arr[len-1];
           }
           bool push(T data){
               if(len+1>max){
                   max += incre;
                   arr = new T[max];
               }
               len++;
               arr[len-1] = data;
               return true;
           }
           bool pop(){
               if(len!=0){
                 arr[len-1]='\0';
                 len--;
                 return true;
               }
               return false;
           }
};

template<typename T> void printElement(Stack<T> st);
int main()
{
    Stack<int> st;
    st.push(0);
    st.push(1);
    st.push(2);
    cout <<"size " << st.size() << endl;
    cout << st.top() << endl;
    printElement(st);
    return 0;
}
template<typename T> void printElement(Stack<T> st){
               while(!st.empty()){
                 cout << st.top() << endl;
                 st.pop();
               }
           }
