#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> X(Q);
    for (int i = 0; i < Q; i++) cin >> X[i];

    vector<ll> p(N + 1, 0), ans(N + 1, 0);

    ll mul = 1;
    ll inv2 = inv(2);

    p[1] = 1;

    ll totalProb = 1; // sempre soma das probabilidades

    for (int i = 0; i < Q; i++) {
        int x = X[i];

        // contribuição total distribuída
        // só precisa atualizar mesa x
        ll prob_x = p[x] * mul % MOD;

        // contribuição geral
        ans[x] = (ans[x] + x * totalProb % MOD * inv2) % MOD;

        // remove excesso (ajuste fino)
        ans[x] = (ans[x] - x * (totalProb - prob_x + MOD) % MOD * inv2 % MOD + MOD) % MOD;

        // update probabilidades
        mul = mul * inv2 % MOD;

        ll add = inv2 * inv(mul) % MOD;
        p[x] = (p[x] + add) % MOD;
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] % MOD << '\n';
    }

    return 0;
}