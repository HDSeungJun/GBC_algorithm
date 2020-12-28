#include <iostream>
using namespace std;

int factorial(int n);

int main(void)
{
    int n, k, answer;
    cin >> n >> k;

    if(k < 0)
        cout << 0 << endl;
    else if(k > n)
        cout << 0 << endl;
    else if (k >= 0 && k <= n)
    {
        answer = factorial(n)/(factorial(n-k)*factorial(k));
        cout << answer % 100007 << endl;  
    } 

    return 0;
}

int factorial(int n)
{
    int arr[n+1];
    
    
    return arr[n];
}