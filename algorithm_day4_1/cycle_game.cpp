/*
문제출처: https://www.acmicpc.net/problem/1197
문제정의: 최소신장트리를 크루스칼 알고리즘으로 구현
    크루스칼 알고리즘 
        1) Edge의 가중치를 기준으로 Edge 오름차순 정렬
        2) cycle이 안되면 edge를 추가
            Cycle 여부는 union-finde를 사용하여 판정
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 5e5;
const int MAX_M = 1e6;

int parent[MAX_V+1];
int v_count, t_count;

typedef struct node
{
    int v1;
    int v2;
} NODE;
 
int find(int u) 
{
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
 
void unite(int a, int b) 
{
    parent[find(a)] = find(b);
}

int main(void)
{
    vector<NODE> graph;

    for(int i=0; i<= MAX_V; i++)
        parent[i] = i;
    
    cin >> v_count >> t_count;
    for(int i=0; i<t_count; i++)
    {
        NODE node;
        scanf("%d %d", &node.v1, &node.v2);
        graph.push_back(node);
    }

    int count = 0;
    int idx = 0;

    while(t_count--)
    {
        NODE t_node;
        t_node = graph[idx];
        if(find(t_node.v1) != find(t_node.v2))
        {
            count++;
            idx++;
            unite(t_node.v1, t_node.v2);
        }
        else
            break;
    }
    if(t_count < 0)
        printf("%d\n", 0);
    else
        printf("%d\n", ++count);

    return 0;

}