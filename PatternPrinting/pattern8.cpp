#include <iostream>
using namespace std;

int main() {
    // Number of rows in each half of the butterfly pattern.
    // Increase or decrease this value to change the size of the pattern.
    int n = 7;

    // Print the upper half of the butterfly (expanding wings).
    for (int i = 1; i <= n; i++) {
        // Print stars on the left wing.
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Print spaces between the two wings.
        // Gap decreases as i increases.
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }

        // Print stars on the right wing.
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Move to the next line after finishing one row.
        cout << endl;
    }

    // Print the lower half of the butterfly (contracting wings).
    for (int i = n; i >= 1; i--) {
        // Print stars on the left wing.
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Print spaces between the two wings.
        // Gap increases as i decreases.
        for (int j = 1; j <= 2 * (n - i); j++) {
            cout << " ";
        }

        // Print stars on the right wing.
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }

        // Move to the next line after finishing one row.
        cout << endl;
    }

    // Indicate successful program completion.
    return 0;
}
