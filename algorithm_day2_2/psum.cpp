/*
문제출처: https://www.acmicpc.net/problem/11660
문제정의: N*N 배열이 주어졌을 때 (x1, y1)부터 (x2, y2) 합을 구하라.
주의점: 1 <= N <= 1024
    1 <= M <= 100000
    각 element <= 1000;
힌트: 포함배제의 원리, prefix sum(partial sum) 활용 
*/
#include <cstdio>
using namespace std;

#define MAX_N 1025
int arr[MAX_N][MAX_N];
int psum[MAX_N][MAX_N] = {0,};

int main(void)
{
    int n, m;
    int i, j;
    int x1, x2, y1, y2;
    int result;

    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            scanf("%d", &arr[i][j]);
            if(i==0 && j==0)    psum[i][j] = arr[i][j];
            else if(i==0)   psum[i][j] = psum[i][j-1] + arr[i][j];
            else if(j==0)   psum[i][j] = psum[i-1][j] + arr[i][j];
            else    psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + arr[i][j];
        }
    for(i=0; i<m; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(!(x1 && y1 && x2 && y2))
            printf("%d\n", 0);
        else
        {
            --x1; --y1; --x2; --y2;
            if(x1==0 & y1==0)   result = psum[x2][y2];
            else if(y1==0)  result = psum[x2][y2] - psum[x1-1][y2];
            else if(x1==0)  result = psum[x2][y2] - psum[x2][y1-1];
            else    result = psum[x2][y2] - (psum[x2][y1-1] + psum[x1-1][y2]) + psum[x1-1][y1-1];

            printf("%d\n", result);
        }
    }

    return 0;
}