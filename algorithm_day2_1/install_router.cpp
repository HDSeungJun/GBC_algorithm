/*
문제출처: https://www.acmicpc.net/problem/2110
문제정의: N개의 집이 수직선 상에 존재   
    공유기 C개를 N개의 집에 설치하되 가장 인접한 두 공유기의 거리를 최대로 하도록 설치하려고 함. (한 집에 공유기는 최대 하나만 설치 가능)
주의점: 2 <= N <= 2e5
    2 <= C <= N
    0 <= xn < 1e9 (xn은 집의 좌표)
함수정의: y = f(x) (x=가장 인접한 공유기의 거리)
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5;
int xn[MAX_N];
int c, n;

bool f(int x);

int main(void)
{
    int lo, hi, mid;
    int result;
    lo = 1;

    scanf("%d %d", &n, &c);
    for(int i=0; i<n; i++)
        scanf("%d", &xn[i]);
    sort(xn, xn+n);
    hi = xn[n-1]-xn[0];

    while(hi >= lo)
    {
        mid = (lo + hi) / 2;
        if (f(mid))
        {
            result = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    printf("%d\n", result);

    return 0;
}

bool f(int x)
{
    int xi = xn[0];
    int tmp;
    
    for(int i=0; i<c; i++)
    {
        tmp = lower_bound(xn, xn+n, xi)-xn;
        if(tmp == n)
            return false;
        xi = xn[tmp] + x; 
    }
    return true;
}
