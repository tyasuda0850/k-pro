#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    const int INF = 1e9;
    int ans = INF;
    unordered_map<long long, int> last_pos;

    for (int i = 0; i < N; i++) {
        long long x = A[i];
        if (last_pos.count(x)) {
            ans = min(ans, i - last_pos[x] + 1);
        }
        last_pos[x] = i;
    }

    if (ans == INF) cout << -1 << endl;  // ない場合
    else cout << ans << endl;
}
