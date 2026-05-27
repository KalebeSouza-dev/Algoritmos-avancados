#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int k; cin >> k;
    string s, comp = "tamocompetindo"; cin >> s;
    int n = sz(s);

    rep(i, 0, n+1 - 14){
        int diff = 0;
        for (int j = i; j < i+14; j++){
            if (s[j] != comp[j-i]) diff++;
        }
        //cout << diff << endl;
        if (diff <= k) {
            cout << "SIM" << endl; return 0;
        }
    }

    cout << "NAO" << endl;

    return 0;
}