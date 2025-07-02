#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    // 배열 한 줄 단위 입력
    char friends[50][50];
    for (int i = 0; i < N; i++)
        cin >> friends[i];

    int maxcnt = 0;

    // 각 행 (사람 A)
    for (int i = 0; i < N; i++)
    {
        // 2-친구 여부 초기화
        bool isFriend[50] = { false };

        // 각 열 (사람 A ~ A + N)
        for (int j = 0; j < N; j++)
        {
            // 본인 제외
            if (i == j)
                continue;

            // 직접 친구
            if (friends[i][j] == 'Y')
                isFriend[j] = true;
            else
                for (int k = 0; k < N; k++)
                    if (friends[i][k] == 'Y' && friends[k][j] == 'Y') // 친구의 친구
                    {
                        isFriend[j] = true;
                        break;
                    }
        }

        int cnt = 0;
        for (int j = 0; j < N; j++)
            if (isFriend[j])
                cnt++;
        
        maxcnt = max(maxcnt, cnt);
    }

    cout << maxcnt << endl;

    return 0;
}