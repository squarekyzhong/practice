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
class stack{
    private:
          T arr[];
          int i=0;
          int compacity;
    public:
          stack(int length){
              arr=new T[length];
              compacity = length;
          }
          void push(T a){
              i++;
              arr[i] = a;
          }
          T pop(){
              if(i>0){
                int ret = arr[i];
                i--;
                return ret;  
              }
              else{
                  return -1;
              }
          }
};

string simplifyStr(string str);
int main()
{
    string str = "aabbcccddd";
    str = simplifyStr(str);
    cout << str <<endl;
    return 0;
}
string simplifyStr(string str){
    size_t len = str.size();
    string simpStr="";
    size_t count=1;
    for(int i=1; i < len;i++){
        if(str.at(i)==str.at(i-1)){//the preceding one is the same as the later one.
            count++; //count how many similar characters in a row;
        }
        else{//they are not equal, and thus begining from 1.
            simpStr+=str.at(i-1);
            simpStr+=to_string(count);
            //cout<<simpStr<<endl;
            count=1;
        }
    }
    if(simpStr.size()>=str.size())//if the simplied one never be short, give up. 
        return str;
    return simpStr;
}
