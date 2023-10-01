#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5+1;
const int logN = 19;

int n, q, arr[maxN][logN];

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> arr[i][0];

    // Precomputation
    for (int i = 1; i < logN; i++) {
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            arr[j][i] = min(arr[j][i - 1], arr[j + (1 << (i - 1))][i - 1]);
        }
    }

    for (int i = 0; i < q; i++) {
        long long l, r;
        cin >> l >> r;
        l--, r--;
        long long len = r - l + 1;
        long long k = log2(len);
        cout << min(arr[l][k], arr[r - (1 << k) + 1][k]) << endl;
    }

    return 0;
}
