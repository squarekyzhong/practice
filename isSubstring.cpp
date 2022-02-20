/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string str1, string str2);
int main()
{
    string str1 ="waterbottle";
    string str2="erbottlewat";
    cout<< boolalpha<<isSubstring(str1, str2) << endl;
    return 0;
}
bool isSubstring(string str1, string str2){
    if(str1.size()>str2.size())
       return false;
    int* ch1= new int[256]();
    int* ch2= new int[256]();
    for(int i=0; i < str1.size(); i++){
        ch1[str1.at(i)]++;
    }
    for(int i=0; i< str2.size();i++){
        ch2[str2.at(i)]++;
    }
    for(int i=0; i < 256; i++){
        if(ch1[i]>ch2[i])
            return false;
    }
    return true;
}
