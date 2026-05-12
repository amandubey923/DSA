#include <iostream>
using namespace std;

// Returns n! (factorial of n)
int factorial(int n)
{
    int fact = 1;
    // Multiply all integers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Returns the binomial coefficient nCr = n! / (r! * (n-r)!)
int nCr(int n, int r)
{
    // Compute required factorial values
    int fact_n = factorial(n);
    int fact_r = factorial(r);
    int fact_nmr = factorial(n - r);

    // Apply nCr formula and return result
    return fact_n / (fact_r * fact_nmr);
}

int main()
{
    // Example input values
    int n = 8, r = 2;

    // Print combination result
    cout << nCr(n, r) << endl;

    return 0;
}