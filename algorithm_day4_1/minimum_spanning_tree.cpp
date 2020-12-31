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

const int MAX_V = 1e4;
const int MAX_E = 1e5;

int parent[MAX_V+1];
int v_count, e_count;

typedef struct _w_node
{
    int v1;
    int v2;
    int weight;
} W_NODE;
 
int find(int u) 
{
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
 
void unite(int a, int b) 
{
    parent[find(a)] = find(b);
}

int compare(W_NODE n1, W_NODE n2)
{
    return n1.weight < n2.weight;
}

int main(void)
{
    vector<W_NODE> graph;

    for(int i=0; i<= MAX_V; i++)
        parent[i] = i;
    
    cin >> v_count >> e_count;
    for(int i=0; i<e_count; i++)
    {
        W_NODE node;
        scanf("%d %d %d", &node.v1, &node.v2, &node.weight);
        graph.push_back(node);
    }
    sort(graph.begin(), graph.end(), compare);

    int count = 0;
    int min_const = 0;
    int idx = 0;

    while(count != v_count-1)
    {
        W_NODE t_node;
        t_node = graph[idx];
        if(find(t_node.v1) != find(t_node.v2))
        {
            min_const += t_node.weight;
            count++;
            unite(t_node.v1, t_node.v2);
        }
        else
        {
            idx++;
        }
    }

    printf("%d\n", min_const);

    return 0;

}