/*
문제: https://www.acmicpc.net/problem/11053
0. 문제 정의: 어떤 수열이 주어졌을 때 그 수열의 가장 긴 증가하는 부분 수열의 길이를 구하라.
- 주의점: 주어지는 수열은 정렬된 수열이 아님.
    1 <= N <= 1000 N 수열의 길이 
1. 함수 정의: f(x) = 가장 긴 증가하는 부분 수열의 길이를 구한다.
2. 점화식 정의: 
    f(x) = 현재위치보다 앞의 값들 중 작은 값들 중 가장 긴 길이
3. Base case 정의: 길이 = 1
*/
#include <cstdio>
#include <vector>
using namespace std;

typedef struct _element 
{
    int value;
    int len;
} ELEMENT;

int main(void)
{
    int length, i, j, tmp, max_len, answer = 0;
    ELEMENT t_element;
    vector<ELEMENT> sequence;

    scanf("%d", &length);
    for(i=0; i<length; i++)
    {
        scanf("%d", &tmp);
        t_element.value = tmp;
        t_element.len = 1;
        sequence.push_back(t_element);
    }

    for(i=0; i<length; i++)
    {
        max_len = 0;
        for(j=0; j<i; j++)
        {
            if(sequence[j].value < sequence[i].value)
            {
                if(max_len < sequence[j].len)
                    max_len = sequence[j].len;
            }
        }
        sequence[i].len = max_len + 1;

        if(answer < sequence[i].len)
            answer = sequence[i].len;
    }
    printf("%d\n", answer);

    return 0;
}
