/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

bool isequal(string a, string b);
string sort(string a);
int partition(char arr[], int low, int high);
void quick_sort(char a[], int low, int high);
void swap(char& a, char& b);
int main()
{
    string str="abcdedg";
    string str2 ="ccccccc";
    cout << boolalpha << isequal(str, str2)<< endl;
    return 0;
}
bool isequal(string a, string b){
    if(a.size()!=b.size())
       return false;
    else if(a==b){
        return true;
    }
    else{
       return sort(a)==sort(b);
    }
    return true;
}
//quick sort
string sort(string a){
    size_t sz = a.size();
    char* stringToChar = new char[sz];
    strcpy(stringToChar,a.c_str());
    quick_sort(stringToChar, 0, sz-1);
    string sortedStr = stringToChar;
    cout << sortedStr << endl;
    return sortedStr;
}
void quick_sort(char arr[], int low, int high){
    if(low < high){
        int pos = partition(arr, low, high); //distribution
        quick_sort(arr, low, pos-1); //sort the elements in the left
        quick_sort(arr, pos+1, high); //sort the elements in the right
    }
}

int partition(char arr[], int low, int high){
    int left= low-1;
    int pivotal = high;//choose the last element as the pivotal
    for(int i=low; i<=high-1;i++){
        if(arr[i] < arr[pivotal]){
           left++;
           swap(arr[i], arr[left]); //move the element greater than the pivotal to the right
        }
    }
    swap(arr[left+1], arr[pivotal]);//put the pivotal in the right place
    return left+1;
}

void swap(char& a, char& b){//exchange the values
    char temp = a;
    a = b;
    b = temp;
}
