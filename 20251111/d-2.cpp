#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long result = 0;
    int p;
    int q;

    for (int i=2; i<=sqrt(N); i++) {
        if(N % i == 0) {
            if ((N / i) % i == 0) {
                p = i;
                q = N / (p*p);  
            } else {
                q = i;
                p = N / q;
            }
            break;  
        }
    }
    cout << p << endl;
    cout << q << endl;
}