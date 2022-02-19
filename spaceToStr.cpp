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

void spaceToStr(char arr[],size_t length, string str);
int main()
{
    string str="wwwwwww";
    string str2 ="ccccccc";
    char arr[100]={'a','b',' ',' ','c','d','e','d','g','h'};
    spaceToStr(arr, 10, str);
    int ind=0;
    while(arr[ind]!='\0'){
        cout<< arr[ind] <<endl;
        ind++;
    }
    return 0;
}
void spaceToStr(char arr[], size_t length, string str){
    int numSpace = 0;
    for(int i=0; i < length; i++){
        if(arr[i]==' ')
           numSpace++;
        //cout << arr[i] << endl;
    }
    size_t newLen= length+(str.size()-1)*numSpace;
    char* newArr = new char[newLen];
    int newIndex = newLen - 1;
    for(int i=length-1; i >=0; i--){
        if(arr[i]!=' '){
            newArr[newIndex]=arr[i];
            cout<<newArr[newIndex];
            cout<<newIndex<<endl;
            newIndex--;
        }
        else{
            size_t len = str.size()-1;
            for(int i=len; i>=0; i--){
                newArr[newIndex] = str[i];
                cout << newArr[newIndex];
                cout<<newIndex<< endl;
                newIndex--;
            }
        }
    }
    for(int i=0; i< newLen; i++){
        arr[i] = newArr[i];
    }
 }
