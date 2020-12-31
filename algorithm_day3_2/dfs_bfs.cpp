#include <iostream>
#include <queue>
using namespace std;

#define MAX_N  1001

int v_count, e_count, s_node;
int visited[MAX_N];
int adj_mat[MAX_N][MAX_N];

void dfs(int cur) 
{
    cout << cur << ' ';

    visited[cur] = 1;
    for(int i=1; i<=v_count; i++)
    {
        if(visited[i] == 1 || adj_mat[cur][i] == 0)   continue;
        dfs(i);
    }
}

void bfs(int cur) 
{
    queue<int> q;
    q.push(cur);
    visited[cur] = 0;

    while(!q.empty())
    {
        cur = q.front();
        cout << q.front() << ' ';
        q.pop();
        for(int i=1; i<=v_count; i++)
        {
            if(visited[i] == 0 || adj_mat[cur][i] == 0)    continue;
            q.push(i);
            visited[i] = 0;
        }
    }
}

int main(void)
{
    int v1, v2;
    cin >> v_count >> e_count >> s_node;
    for(int i=0; i<e_count; i++)
    {
        cin >> v1 >> v2;
        adj_mat[v1][v2] = adj_mat[v2][v1] = 1;
    }
    dfs(s_node);
    cout << endl;
    bfs(s_node);
    cout << endl;

    return 0;
}