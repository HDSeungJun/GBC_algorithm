/*
문제출처: https://www.acmicpc.net/problem/1517
문제정의: 수열이 주어져 bubble sort로 정렬을 수행할 때 swap()의 횟수를 구하라.
1 <= N <= 500000, 0 <= A[i] <= 1e9 (int)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN =500001;
int input[MAXN];
template <typename T>
class FenwickTree {
public:
    int size;
    vector<T> arr;
    vector<int> data;

    FenwickTree<T>(int _N) {
        size = _N;
        arr.resize(size + 1);
        data.resize(size + 1);
    }

    void update(int x, int val) {
        T delta_val = val - arr[x];
        arr[x] = val;

        while (x <= size) {
            data[x] += delta_val;
            x += (x&-x);
        }
    }
    long long sum(int x) {
        long long ret = 0;
        while (x) {
            ret += data[x];
            x &= x - 1;
        }
        return ret;
    }
    long long sum(int x, int y) {
        return sum(y) - sum(x - 1);
    }
};

int main(void)
{
    int n, tmp;
    long long answer = 0;
    FenwickTree<int> bit = FenwickTree<int>(n);

    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &input[i]);
        bit.arr.push_back(input[i]);
    }
    sort(bit.arr.begin(), bit.arr.end());
    bit.arr.erase(unique(bit.arr.begin(), bit.arr.end()), bit.arr.end());

    for(int i=1; i<=n; i++)
        input[i] = lower_bound(bit.arr.begin(), bit.arr.end(), input[i])-bit.arr.begin()+2;
    bit.arr.resize(MAXN);
    for(int i=1; i<= MAXN; i++)
        bit.arr[i] = 0;
    
    for(int i=n; i>=1; i--)
    {
        answer += bit.sum(input[i]-1);
        bit.update(i, input[i]);
    }

    printf("%lld\n", answer);

    return 0;
}