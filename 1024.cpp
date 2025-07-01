#include <iostream>

using namespace std;

int main(void)
{
    int N, L;
    cin >> N >> L;

    for (int i = L; i <= 100; i++)
    {
        int a = N - i * (i - 1) / 2;

        // a가 음수일 경우 가능한 조합 없음
        if (a < 0)
            break;

        // a % i 가 정수가 아닐 경우 다음 i로 넘어감
        if (a % i != 0)
            continue;

        a /= i;
        // 첫째 항 : 0 이상 정수일 경우
        for (int x = 0; x < i; x++)
        {
            cout << a + x;
            if (x != i -1)
                cout << " ";
        }
        cout << "\n";
        return 0;
    }

    // 조건 만족하는 수열 없으면 -1 출력
    cout << -1 << endl;
    return 0;
}