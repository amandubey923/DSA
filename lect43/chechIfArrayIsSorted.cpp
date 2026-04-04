#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>  arr, int n){
    if(n==0 || n==1){
        return true;
    }
    return arr[n-1] >= arr[n-2] && isSorted(arr,n-1);

}

int main(){
vector<int> arr={5,3,2,1,4};

cout<<isSorted(arr,arr.size())<<endl;

    return 0;
}