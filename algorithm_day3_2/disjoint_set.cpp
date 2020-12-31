#include <stdio.h>
using namespace std;
 
int n, m, a, b, c;
int parent[1000001];
 
int find(int u) 
{
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
 
void unite(int a, int b) 
{
    parent[find(a)] = find(b);
}
 
int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; ++i)
        parent[i] = i;
 
    for(int i=0; i<m; i++) 
    {
        scanf("%d %d %d", &c, &a, &b);
 
        if (c == 0)
            unite(a, b);
        else
            if (find(a) == find(b))
                puts("YES");
            else
                puts("NO");
    }
    return 0;
}
