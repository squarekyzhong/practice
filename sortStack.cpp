#include <iostream>
#include<list>
#include<stack>
#include<bits/stdc++.h>
#include<cstdlib>
#include<time.h>
using namespace std;
template<typename T>
class sort_stack{
    private:
       stack <T> st;
    public:
       void sort(){
           cout << "sort" << endl;
           stack<T> st2;
           while(!st.empty()){
               T top = st.top();
               st.pop();
               if(!st2.empty()){
                   //cout <<"top " << top <<endl;
                   int count = 0;
                   while(!st2.empty()&&(top > st2.top())){
                       //cout << "st2 top " << st2.top()<<endl;
                       st.push(st2.top());
                       st2.pop();
                       //cout << "size " << st2.size() << endl;
                       count++;
                   }
                   //cout << "top " << top << endl;
                   st2.push(top);
                   //cout << "size " << st2.size() << endl;
                   while(count>0){
                      st2.push(st.top());
                      st.pop();
                      count--;
                   }
               }
               else{
                  st2.push(top);
                  
               }
           }
           
           while(!st2.empty()){
               st.push(st2.top());
               st2.pop();
           }
       }
       void push(T data){
           st.push(data);
       }
       void showElement(){
           while(!st.empty()){
               cout<< st.top() << endl;
               st.pop();
           }
       }
};

int main()
{
    sort_stack<int> sor;
    srand((int)time(NULL));
    for(int i=0; i<5;i++){
        sor.push(rand());
    }
    //sor.push(1070882872);
    //sor.push(1992510720);
    //sor.push(1008084760);
    //sor.push(0);
    //sor.push(1);
    sor.sort();
    sor.showElement();
    return 0;
}

    
