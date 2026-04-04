#include <iostream>
using namespace std;

void printUniqueValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j] && i != j) {  // Check if value is found elsewhere in the array
                isUnique = false;
                break;  // No need to check further if it's not unique
            }
        }
        if (isUnique) {
            cout << arr[i] << " ";  // Print the unique value
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 1, 2, 3, 5};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unique values in the array: ";
    printUniqueValues(arr, size);
    cout << endl;

    return 0;
}


/*
#include<iostream>
using namespace std;

void printUniqueValues(int arr[], int size){
    for(int i = 0; i<size; i++){
        bool isUnique = true ;
        for(int j= 0; j<size; j++){
            if (arr[i]==j && i!=j){
                isUnique = false;
                break;
            }
        }
        if(isUnique){
            cout<<arr[i]<<" ";
        }
    }
}
int main(){
    int arr[]={1,2,3,1,2,3,4};
    int size = 7;

    cout<<"Unique Value in Array: "<<endl;
    printUniqueValues(arr,size);
    cout<<endl;
    return 0;

}
*/