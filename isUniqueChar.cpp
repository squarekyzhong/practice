//
//  isUniqueChar.cpp
//  data_structure
//
//  Created by 钟方天 on 2/18/22.
//


#include <iostream>
#include<list>
#include "isUniqueChar.hpp"
using namespace std;

template<typename T>
class stack{
    private:
          int i=0;
          int compacity;
          T arr[];
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
bool uniqueString(string str, int setofsize);
int main()
{
    string str="abcdedg";
    //cout<<str.size()<<endl;
    cout<<boolalpha<<uniqueString(str, 128)<<endl;
    return 0;
}

bool uniqueString(string str, int setofsize){
    if(str.size() > setofsize)
       return false;
    else{
        int* countChar=new int[setofsize]();
        for(int i=0; i < str.size();i++){
            countChar[str[i]]++;
        }
        for(int i=0; i<setofsize;i++){
            if(countChar[i] > 1)
               return false;
        }
    }
    return true;
}
