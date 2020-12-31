// FIXME: 
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;

const int MAXN = 1000;

char arr[MAXN][MAXN + 1];
int N, M;
// 방향별로 배열 만드는것
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0,1 ,0, -1 };
// 범위 벗어나는 거 방지하는 함수
bool inrange(int y, int x) {
    return y >= 0 && y < N&&x >= 0 && x < M;
}

int s_dist[MAXN][MAXN];
int f_dist[MAXN][MAXN];
int results[MAXN];
bool visited[MAXN][MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) scanf("%s", arr[i]);

    queue<P> q;
    // 시작점을 q 넣는다.
    q.push(make_pair(0,0));
    s_dist[0][0] = 1;
    visited[0][0] = 1;
    // while문 ======================================
    while (!q.empty()) {
        // 한 노드를 큐에서 뺀다.
        int uy = q.front().first, ux = q.front().second;
        q.pop();
        // 뽑은 노드와 인접한 노드를 탐색한다. 그 노드들 중에서 아직 방문 안한 노드들을 큐에 넣는다.
        for (int d = 0; d < 4; ++d) {
            int vy = uy + dy[d], vx = ux + dx[d];
            if (!inrange(vy, vx) || arr[vy][vx] == '1' || visited[vy][vx]) continue;
            s_dist[vy][vx] = s_dist[uy][ux] + 1;
            visited[vy][vx] = true;
            q.push(make_pair(vy,vx));
        }
    }
    // ================================================
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            visited[i][j] = 0;
    f_dist[N-1][M-1] = 1;
    visited[N-1][M-1] = 1;
    q.push(make_pair(N-1,M-1));
     // while문 ======================================
    while (!q.empty()) {
        // 한 노드를 큐에서 뺀다.
        int uy = q.front().first, ux = q.front().second;
        q.pop();
        // 뽑은 노드와 인접한 노드를 탐색한다. 그 노드들 중에서 아직 방문 안한 노드들을 큐에 넣는다.
        for (int d = 0; d < 4; ++d) {
            int vy = uy + dy[d], vx = ux + dx[d];
            if (!inrange(vy, vx) || arr[vy][vx] == '1' || visited[vy][vx]) continue;
            f_dist[vy][vx] = f_dist[uy][ux] + 1;
            visited[vy][vx] = true;
            q.push(make_pair(vy,vx));
        }
    }
    /*
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            printf("%d ", s_dist[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            printf("%d ", f_dist[i][j]);
        printf("\n");
    }
    printf("\n");
    */
    // ================================================
    int e1[4]={0,};
    int e2[4]={0,};
    int result;
    int min1, min2;
    int z_count = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
        {
            if(arr[i][j] == '1')
            {
                for (int d = 0; d < 4; ++d) {
                    int vy = i + dy[d], vx = j + dx[d]; 
                    e1[d] = 2e8;
                    e2[d] = 2e8;
                    if(inrange(vy, vx))
                    {
                        if(s_dist[vy][vx] != 0)
                            e1[d] = s_dist[vy][vx];
                        if(f_dist[vy][vx] != 0)
                            e2[d] = f_dist[vy][vx];
                        if(arr[vy][vx] == '1')
                            z_count++;
                    }
                    else
                        z_count++;
                }
                if(z_count == 4)
                {
                    s_dist[i][j] = 2e8;
                }
                else
                    z_count = 0;
                sort(e1, e1+4);
                sort(e2, e2+4);
                
                s_dist[i][j] += (e1[0]+e2[0]+1);
            }
        }
    }
/*
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
            printf("%d ", s_dist[i][j]);
        printf("\n");
    }
    printf("\n");
*/
    for(int i=0; i<MAXN; i++)
        results[i] = 2e8;
    int count =1;
    if(s_dist[N-1][M-1] != 0)
        results[0] = s_dist[N-1][M-1];
    
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
        {
            if(arr[i][j] == '1')
                results[count++] = s_dist[i][j];
        }
    sort(results, results+MAXN);
    /*
    printf("results:\n");
    for(int i=0; i<MAXN; i++)
        printf("%d ", results[i]);
*/
    if(results[0] >= 2e8)
        printf("%d\n", -1);
    else
        printf("%d\n", results[0]);


    // ===============
    return 0;
}