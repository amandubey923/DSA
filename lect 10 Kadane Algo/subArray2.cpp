#include<iostream>
#include<vector>
using namespace std;
int main(){
   
    int n = 7;
    int arr[7]= {3,-4,5,4,-1,7,-8};

    int maxSum= INT16_MIN;
    for (int st=0; st<n; st++){
            int currSum=0;
            for(int end= st; end<n; end++){
                currSum += arr[end];
                maxSum = max(currSum, maxSum);
            }
        }
      cout<<"Max SubArray sum= "<<maxSum<<endl;
    }





















/*
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 5;
    int arr[5]= {1, 2, 3, 4, 5};
    for(int st=0; st<n; st++){
        for(int end=st; end<n; end++){
            for(int i=st; i<=end; i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
*/