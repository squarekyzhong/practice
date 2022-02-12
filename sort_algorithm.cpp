/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
          
          void quick_sort(T arr[], int length){
              
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
    sort.merge_sort(arr, 7);
    for(int i =0; i < sizeof(arr)/sizeof(arr[0]); i++){
        cout << arr[i] <<' ';
    }
    return 0;
}
