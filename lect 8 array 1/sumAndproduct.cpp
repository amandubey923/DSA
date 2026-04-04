#include<iostream>
using namespace std;

void sumAndProduct(int arr[], int size, int &sum, int &product){
    sum = 0;
    product =1;
    for(int i = 0; i<size;i++){
        sum += arr[i];
        product *= arr[i];
    }
}
int main (){
    int arr[]={1,2,3,4,5,6};
    int size=6;  
    //int size = sizeof(arr)/sizeof(arr[0]);

    int sum,product;

    sumAndProduct(arr, size, sum, product);
    cout<<"sum: "<<sum<<endl;
    cout<<"product: "<<product<<endl;
}