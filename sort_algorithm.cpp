//
//  main.cpp
//  malinfo
//
//  Created by 钟方天 on 1/3/22.
//

#include <iostream>

using namespace std;
template<typename T>
class Sort{
    public:
          void bubble_sort(T arr[], int length){
              for(int i = 0; i < length-1; i++){ //each loop, the greatest one will move to the end.O(n^2)
                  for(int j=0; j < length-1; j++){
                      if(arr[j] > arr[j+1]){
                          swap(arr[j], arr[j+1]);
                      }
                  }
              }
          }
          void select_sort(T arr[], int length){
              
              for(int i = 0; i < length-1; i++){
                  int mindex = i;
                  for(int j = i+1; j < length; j++){
                      if(arr[mindex] > arr[j]){
                         mindex = j;
                      }
                  }
                  swap(arr[i], arr[mindex]);
              }
          }
          
          void merge_sort(T arr[], int low, int high, int length){
              if(low < high){
                //first, we have to separate the arr in half until it cannot be separated anymore
                //sort the left part, sort the right part, and finally merge them.
                int middle = (low + high) / 2;
                cout << middle <<endl;
                merge_sort(arr, low, middle, length);//(0, 3),(0, 1),(0, 0), (1, 1), (2, 3),(2, 2), (3, 3), (4, 6), (4, 5), (4, 4), (5, 5), (6, 6),
                merge_sort(arr, middle+1, high, length);
                merge(arr, low, middle, high, length);
              }
          }
          void merge(T arr[], int low, int middle, int high, int length){
              T* helper = new T[length];//this is an assisted array that copys the elements in arr
              for(int i=0; i < length; i++){
                  helper[i] = arr[i];
              }
              int left = low;
              int right = middle+1;
              int current = low;
              while(left<=middle&&right<=high){  //the loop sorts the elements separated by middle element.
                     if(helper[left] > helper[right]){
                         arr[current]=helper[right];
                         right++; //if the right element smaller, right++;
                     }
                     else{
                         arr[current] = helper[left];
                         left++; //if the left element smaller, left++;
                     }
                     current++;
              }
              int remaining = middle - left;
              for(int i=0; i <=remaining; i++){
                  arr[current+i] = helper[left+i];
              }
          }
          
          void merge_sort(T arr[], int length){
              merge_sort(arr, 0, length-1, length);
          }
          //this is a divide and conqure algorithm
          void quick_sort(T arr[], int length){
              quick_sort(arr, 0, length-1, length);
          }
          void quick_sort(T arr[], int low, int high, int length){// choose a pivotal element and then compare it with the left elements in an array
                                                                  //the elements smaller than the pivotal, places them in the left, otherwise right
                                                                 //1. partition, 2. quick_sort the left, 3. quick_sort the right
              if(low < high){
                int pi = partition(arr, low, high); //(03, 4, 56), (0, 0)
                quick_sort(arr, low, pi-1,length); //(56), (13),()
                quick_sort(arr, pi+1, high, length);
              }
          }
          int partition(T arr[], int low, int high){
              int pivotal = high;  // assume the pivotal one is always the last element, and the first or median are ok as well.
              //cout << "low " << low << endl;
              //cout << "high " << pivotal << endl;
              int left =low -1;
              
              for(int i = low; i <= high-1; i++){ // finish the partition
                  if(arr[i] < arr[pivotal]){
                      left++;
                      swap(arr[left], arr[i]);
                  }
              }
              //cout << "left " << left << endl;
              // finally place the pivotal one in the place that divides the smaller and greater ones.
              swap(arr[left+1], arr[pivotal]);
              
            
              int pos = left+1;
              //cout << pos << endl;
              return pos;     //return the place that the pivotoal element stands at
          }
          void radix_sort(T arr[], int length){
              
          }
          
          void swap(T& a, T& b){
              T temp; //exchange values
              temp = a;
              a = b;
              b = temp;
          }
};
int main()
{
   
    Sort<int> sort;
    int arr[] ={7,4, 2, 3, 1, 8, 6};
    cout << "sort an array with 5 different algorithms" << endl;
    //sort.bubble_sort(arr, 7);
    //sort.select_sort(arr, 7);
    //sort.merge_sort(arr, 7);
    sort.quick_sort(arr, 7);// (4231 6 87), (1234) (6 87), ()
    cout << endl;
    for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] <<' ';
    }
    return 0;
}
