#include<iostream>
using namespace std;

void intersectionArray(int arr1[], int size1, int arr2[], int size2){
    for(int i = 0; i<size1; i++){
        for (int j = 0; j<size2; j++){
            if (arr1[i] == arr2[j]){
                cout<<arr1[i]<<" ";
                break;
            }
        }
    }
}

int main(){
    int arr1[]={1,2,3,4,5,6};
    int arr2[]={4,5,6,7,8};

    int size1=sizeof(arr1)/sizeof (arr1[0]);
    int size2=sizeof(arr2)/sizeof (arr2[0]);

    cout<<"Intersection of Two Array: "<<endl;

    intersectionArray(arr1, size1, arr2, size2);

    cout<<endl;




    return 0;
}

/*
#include <iostream>
using namespace std;

void printIntersection(int arr1[], int size1, int arr2[], int size2) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {  // If an element is common in both arrays
                cout << arr1[i] << " ";
                break;  // Move to the next element in arr1 after finding a match
            }
        }
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};  // First array
    int arr2[] = {3, 4, 5, 6, 7};  // Second array
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "Intersection of the two arrays: ";
    printIntersection(arr1, size1, arr2, size2);
    cout << endl;

    return 0;
}
*/