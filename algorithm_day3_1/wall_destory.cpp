#include <iostream>
#include <queue>
using namespace std;

using namespace std;

const int MAXN = 1000;

// 기존의 visited + 벽 파괴 여부
int visited[MAXN+1][MAXN+1][2];

int map[MAXN+1][MAXN+1];
int n, m;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

typedef struct _p
{
    int y;
    int x;
    int d_cnt;
} P;

bool in_range(P p)
{
    return p.y > 0 && p.y <= n && p.x > 0 && p.x <= m;
}

int bfs(void)
{
    queue<P> q;
    P tmp; 

    visited[1][1][0] = 1;
    tmp.y=1, tmp.x=1, tmp.d_cnt=0;
    q.push(tmp);

    while(!q.empty())
    {
        P cur = q.front();
        q.pop();

        if(cur.y == n && cur.x == m)
            return visited[cur.y][cur.x][cur.d_cnt];
        
        for(int d=0; d<4; d++)
        {
            P next;
            next.y = cur.y + dy[d];
            next.x = cur.x + dx[d];
            next.d_cnt = cur.d_cnt;

            if(!in_range(next) || visited[next.y][next.x][next.d_cnt])
                continue;
            
            if(map[next.y][next.x] == 0)
            {
                visited[next.y][next.x][next.d_cnt] = visited[cur.y][cur.x][cur.d_cnt]+1;
                tmp.y = next.y, tmp.x = next.x, tmp.d_cnt = cur.d_cnt;
                q.push(tmp);
            }

            if(map[next.y][next.x] == 1 && next.d_cnt == 0)
            {
                visited[next.y][next.x][1] = visited[cur.y][cur.x][cur.d_cnt]+1;
                next.d_cnt = 1;
                q.push(next);
            }
        }
    }

    return -1;
}

int main(void)
{
    cin >> n >> m;

    for(int i=1; i<= n; i++)
        for(int j=1; j<=m; j++)
            scanf("%1d", &map[i][j]);
    cout << bfs() << endl;

    return 0;
}