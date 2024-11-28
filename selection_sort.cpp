#include<iostream>
using namespace std;
void swapping(int &a, int &b) {  //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void selectionSort(int *array, int size){
   int i, j, imin;
   for(i = 0; i<size-1; i++) {
      imin = i; //get index of minimum data
      for(j = i+1; j<size; j++)
         if(array[j] < array[imin])
            imin = j;

      //placing in correct position
      swap(array[i], array[imin]);
   }
}
int main(){
   int n;
   n = 5;
   int arr[5] = {12, 19, 55, 2, 16}; // initialize the array
   cout << "Array before Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
   selectionSort(arr, n);
   cout << "Array after Sorting: ";
   for(int i = 0; i<n; i++)
      cout << arr[i] << " ";
   cout << endl;
}