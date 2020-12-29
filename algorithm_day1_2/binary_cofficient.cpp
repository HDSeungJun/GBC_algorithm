/*
0. 문제 정의: n과 k가 주어졌을 때 nCk%10007를 구하라. (1 <= n <= 1000 , 0<= k <= n)
- 주의점: n과 k가 값이 충분히 크므로 dp로 풀어야 함.
1. 함수 정의: 조합을 dp로 어떻게 짤까?
    - 파스칼의 삼각형을 활용
    파스칼의 삼각형: nCk = n-1Ck-1 + n-1Ck
2. 점화식 정의: f(n,k) = f(n-1, k-1) + f(n-1, k) ;
    f(x, y) = xCy
3. Base case 정의: nC0 = 1, nC1 = n
*/

#include <cstdio>
using namespace std;

#define LIMIT 1001

int main(void)
{
    int coff[LIMIT][LIMIT] = {0,};
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i=0; i<=n; i++)
        for(int j=0; j<=k; j++)
        {
            if(j == 0 || i==j)
                coff[i][j] = 1;
            else if(j == 1)
                coff[i][j] = i;
            else 
                coff[i][j] = (coff[i-1][j-1] + coff[i-1][j])%10007;
        }
    printf("%d\n", coff[n][k]);

    return 0;
}