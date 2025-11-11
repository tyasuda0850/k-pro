#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// バブルソート(O(nlogn))
int main() {
    string S;
    cin >> S; 

    string T = "atcoder";
    map<char,int> pos;
    for (int i = 0; i < 7; i++) pos[T[i]] = i;

    vector<int> P(7);
    for (int i = 0; i < 7; i++) {
        P[i] = pos[S[i]];
    }

    long long inv = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (P[i] > P[j]) inv++;
        }
    }

    cout << inv << endl;
}
