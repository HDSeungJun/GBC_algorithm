#include <iostream>
#include <vector>
using namespace std;
 
#define MAX 10001
 
int v_count, e_count;
vector<int> adj_list[MAX];
int visited[MAX];
 
void dfs(int node)
{
    visited[node] = 1;

    for (int i = 0; i < adj_list[node].size(); i++)
    {
        int next = adj_list[node][i];

        if (!visited[next])
            dfs(next);
    }
}
 
int main(void)
{
    cin >> v_count >> e_count;

    for (int i = 0; i < e_count; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }       

    int count = 0;
    for (int i = 1; i <= v_count; i++)
        if (!visited[i])
        {
            dfs(i);
            count++;
        }

    cout << count << endl;
    return 0;
}