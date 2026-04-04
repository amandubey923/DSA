#include <iostream>
using namespace std;

void swapMaxMin(int arr[], int size)
{
    int max = arr[0], min = arr[0];
    int maxIndex = 0, minIndex = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxIndex = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    }
    // swap max and min
    int temp = arr[maxIndex];

    arr[maxIndex] = arr[minIndex];

    arr[minIndex] = temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;

    swapMaxMin(arr, size);

    cout<< "Array after swapping max and min: ";

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;;
    return 0;
}

/*
//MORE STRUCTURED//--------------------------
#include <iostream>
using namespace std;

void swapMaxMin(int arr[], int size) {
    int maxIndex = 0, minIndex = 0;

    // Find the indices of the maximum and minimum elements
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the maximum and minimum elements
    int temp = arr[maxIndex];
    arr[maxIndex] = arr[minIndex];
    arr[minIndex] = temp;
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Display original array
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Swap the max and min elements
    swapMaxMin(arr, size);

    // Display array after swapping
    cout << "Array after swapping max and min: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
*/