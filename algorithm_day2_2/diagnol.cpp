/*
문제출처: https://www.acmicpc.net/problem/2168
문제정의: 타일 하나 = 1*1
    x, y가 주어지면 타일로 x*y를 빈틈 없이 채움 (x=가로길이, y=세로길이)
    x*y의 벽에 대각선을 하나 그었을 때 대각선의 일부가 그려진 타일의 개수를 구하라.
주의점: x, y 는 1e9 이하의 자연수
힌트: 유클리드 호제법 활용
*/
#include <cstdio>

int gcd(int x, int y)
{
    return y ? gcd(y, x%y) : x;
}

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d\n", x+y-gcd(x, y)); //대각선이 타일의 꼭짓점을 지나는 개수 = 최대 공약수 => 가로 + 세로 - 최대공약수

    return 0;
}