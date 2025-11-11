#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 1秒で10^8 ~ 10^9回の処理が可能(大体の見積もり), 1,1,3でまとめればO(N)くらいでいける.N(敵の数) 愚直にやると10^14くらい
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    //for (int i = 0; i < N; i++) {
        // Process each element A[i] as needed
    //    cout << A[i] << endl;
    //}

    const int INF = 1e9;
    int t = 1;
    for (int N = 0; N < A.size(); N++) {
        while (A[N] > 0) {
            if (t % 3 == 0) {
                A[N] -= 3;
                //printf("%lld\n", A[N]);
            } else {
                A[N] -= 1;
                //printf("%lld\n", A[N]); 
            }
        t++;
        }
    }
    cout << t-1 << endl;
    return 0;
}