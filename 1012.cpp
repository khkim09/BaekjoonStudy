#include <iostream>
#include <algorithm>

using namespace std;

int map[50][50];

void dfs(int a, int b, int m, int n)
{
    map[a][b] = 0; // visited

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, -1, 0, 1 };

    for (int i = 0; i < 4; i++)
    {
        int na = a + dy[i];
        int nb = b + dx[i];

        if (na >= 0 && na < n && nb >= 0 && nb < m && map[na][nb] == 1)
            dfs(na, nb, m, n);
    }
}

int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        // 배열 초기화
        fill(&map[0][0], &map[0][0] + 50 * 50, 0);

        int M, N, K;
        cin >> M >> N >> K;

        int X, Y;
        for (int j = 0; j < K; j++)
        {
            cin >> X >> Y;
            map[Y][X] = 1;
        }

        // 필요한 배추흰지렁이
        int cnt = 0;

        for (int y = 0; y < N; y++)
            for (int x = 0; x < M; x++)
                if (map[y][x] == 1)
                {
                    dfs(y, x, M, N);
                    cnt++;
                }
        
        cout << cnt << '\n';
    }
    return 0;
}