/*
문제출처: https://www.acmicpc.net/problem/2042
문제정의: 주어지는 구간의 구간합을 구하여라. 
입력: 
    line 1: 수의 개수 N, 수의 변경 횟수 M, 구간합을 구하는 횟수 K
    line 2 ~ line N+1: N개의 수
    line N+2 ~ line N+M+K+1: a ,b c
        iff(a==1) b번째 수를 c로 변경 (b+(c-b)) 
        iff(a==2) [b,c] 구간합
주의점: 입, 출력 수 범위: long long
*/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class FenwickTree {
public:
    int size;
    vector<T> arr;
    vector<long long> data;

    FenwickTree<T>(long long _N) {
        size = _N;
        arr.resize(size + 1);
        data.resize(size + 1);
    }

    void update(long long x, long long val) {
        T delta_val = val - arr[x];
        arr[x] = val;

        while (x <= size) {
            data[x] += delta_val;
            x += (x&-x);
        }
    }
    long long sum(long long x) {
        long long ret = 0;
        while (x) {
            ret += data[x];
            x &= x - 1;
        }
        return ret;
    }
    long long sum(long long x, long long y) {
        return sum(y) - sum(x - 1);
    }
};

long long n, m, k;

int main(void)
{
    long long tmp, a, b, c;

    scanf("%lld %lld %lld", &n, &m, &k);
    FenwickTree<long long> bit = FenwickTree<long long>(n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld", &tmp);
        bit.arr.push_back(tmp);
        bit.update(i, tmp);
    }
    for(int i=0; i<m+k; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);

        if(a == 1)
            bit.update(b, c);
        else if(a == 2)
            printf("%lld\n", bit.sum(b, c));
    }

    return 0;
}