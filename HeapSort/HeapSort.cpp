#include<iostream>
using namespace std;

//Array convert to Max Heap
//Heap Sort

void Heapify(int arr[], int index, int n ){
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left < n && arr[left] > arr[largest])
    largest = left;
    if(right <n && arr[right] > arr[largest])
    largest = right;

    if(largest != index){
        swap(arr[largest] , arr[index]);
        Heapify(arr,largest,n);
    }
}

void BuildMaxHeap(int arr[],int n){
    // step down
    for(int i=n/2-1; i >= 0; i--){
        Heapify(arr,i,n);
    }
}

void printHeap(int arr[], int n){
    for(int i=0; i<n; i++)
    cout<<arr[i] << " ";
    cout<<endl;
}
//index      0   1   2   3   4   5   6   7   8    9 
// Max heap  70  14  18  11  5   13  8   9   10   3 
// out put   3   5   8   9   10  11  13  14  18   70

void sortArray(int arr[], int n){
for(int i=n-1; i>0; i--){
    swap(arr[0],arr[i]);
    Heapify(arr,0,i);
}
}

int main(){
    int arr[]= {10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);
    sortArray(arr,10);
    printHeap(arr,10);
    return 0;
}