#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;

        // ler posições dos amigos (não precisamos usar)
        for (int i = 0; i < n; i++) {
            long long tmp;
            cin >> tmp;
        }

        if (k == 1) {
            // pode colocar em qualquer lugar
            cout << x / 2 << "\n";
            continue;
        }

        long long d = x / (k - 1);

        for (int i = 0; i < k; i++) {
            cout << i * d << " ";
        }
        cout << "\n";
    }
}
