#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXK = 20;

int N, Q;
vector<long long> X;
vector<vector<int>> g;
vector<vector<long long>> best;

void dfs(int v, int p) {
    // 自分の値を入れておく
    best[v].push_back(X[v]);

    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);

        // 子の best[to] を v にマージ
        // いったん全部突っ込んでからソート＆20個に絞る簡単実装でOK
        for (long long val : best[to]) {
            best[v].push_back(val);
        }

        // 降順にして上位20個だけ残す
        sort(best[v].rbegin(), best[v].rend());
        if ((int)best[v].size() > MAXK) {
            best[v].resize(MAXK);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    X.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> X[i];

    g.assign(N + 1, {});
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    best.assign(N + 1, {});
    dfs(1, -1);  // 根は1

    while (Q--) {
        int v, k;
        cin >> v >> k;
        cout << best[v][k - 1] << "\n";
    }
}
