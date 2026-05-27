#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<long> h(n);

    for (int i = 0; i < n; ++i)
        cin >> h[i];

    long l = 1, r = INT_MAX;
    long k = -1;

    while (l <= r) {
        long med = (l + r) / 2;

        long g = 1;

        for (int i = 0; i < n - 1; ++i) {
            if (abs(h[i] - h[i + 1]) > med)
                g++;
        }

        if (g == m) {
            if (k == -1)
                k = med;
            else
                k = min(k, med);
        }

        if (g > m)
            l = med + 1;
        else
            r = med - 1;
    }

    cout << k << '\n';

    return 0;
}