/*
문제출처: https://www.acmicpc.net/problem/1629
문제정의: A B C가 주어질 때 A를 B번 곱한 수를 C로 나눈 나머지를 구하라.
주의점: A B C 모두 int
*/
#include <iostream>
using namespace std;

long long pow_mod(int a, int b, int c)
{
    long long result;
    if(b == 0)
        return 1;
    
    result = pow_mod(a, b/2, c);
    result = result * result % c;

    if(b%2)
        return result * a % c;
    return result;
    
}

int main(void)
{
    long a, b, c;
    cin >> a >> b >> c;
    cout << pow_mod(a,b,c) <<endl;

    return 0;
}