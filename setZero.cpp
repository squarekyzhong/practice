/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

template<typename T> void setZero(T* arr, int row, int col);
int main()
{
    int arr[10][10];
    for(int i=0; i < 10;i++){
        for(int j=0; j < 10; j++){
            arr[i][j] = i*10+j;
        }
    }
    arr[5][5] = 0;
    setZero(&arr[0][0], 10, 10);
    
    for(int i=0; i < 10; i++){
        for(int j=0; j < 10;j++){
            cout<<arr[i][j]<<'\t';
        }
        cout<<endl;
    }
    
    return 0;
}
template<typename T>
void setZero(T* arr, int row, int col){
    bool *rowArr = new bool[row];
    bool *colArr = new bool[col];
    for(int i=0; i < row; i++){
        for(int j=0; j < col; j++){
            if(*(arr+i*col+j)==0){
                rowArr[i]=true;
                colArr[j]=true;
            }
        }
    }
    
    for(int i=0; i < row; i++){
        for(int j=0; j < col;j++){
            if(rowArr[i]==true || colArr[j]==true){
                *(arr+i*col+j)=0;
            }
        }
    }
}
