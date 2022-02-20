/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

void rotatePixel(size_t d, int* arr);
int main()
{
    cout <<"matrix" <<endl;
    int arr[3][3]={{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    rotatePixel(3, &arr[0][0]);//get the address of the first element.
    for(int i=0; i < 3;i++){
        for(int j=0; j < 3; j++){
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}

void rotatePixel(size_t d, int* arr){
    for(int layer=0; layer < d/2; layer++){
        int first = layer;
        int last = d-1-layer;
        for(int i=first; i < last; i++){
            int offset = i-first;
            int top =*(arr+first*d+i);//save the top
            *(arr+first*d+i) = *(arr+(last-offset)*d+first); //move left to top
            *(arr+(last-offset)*d+first) =*(arr+last*d+last-offset); //move bottom to left
            *(arr+last*d+last-offset) =*(arr+i*d+last);//move right to bottom
            *(arr+i*d+last) = top; //move top to right
        }
    }
}
