#include <iostream>
#include <climits>  // Include this for INT_MIN
using namespace std;

int getMaxSum(int mat[][3], int rows, int cols){ // Corrected declaration
    int maxRowSum = INT_MIN;

    for(int i = 0; i < rows; i++) {
        int rowSum = 0;
        for(int j = 0; j < cols; j++) {
            rowSum += mat[i][j];
        }
        maxRowSum = max(maxRowSum, rowSum);
    }
    return maxRowSum;
}
int getMaxColumnSum(int mat[][3], int rows, int cols) { 
    int maxColSum = INT_MIN;

    for (int j = 0; j < cols; j++) { // Loop through columns
        int colSum = 0;
        for (int i = 0; i < rows; i++) { // Sum all rows of the current column
            colSum += mat[i][j];
        }
        maxColSum = max(maxColSum, colSum);
    }
    return maxColSum;
}

int main(){
    int matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int rows = 3;
    int cols = 3;

    int result = getMaxSum(matrix, rows, cols);
    cout << "Maximum Row Sum: " << result << endl;

    int result1 = getMaxColumnSum(matrix, rows, cols);
    cout << "Maximum Column Sum: " << result1 << endl;

    return 0;
}
