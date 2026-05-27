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

    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    ll a, b;
    
    ll diff = 0, total = 0;
    rep(i, 0, n){
        if (s1[i] == '*' && s1[i] == s2[i]) total++;
        else if (s1[i] == '*' && s2[i] != s1[i]) diff++;
    }

    total += diff;
    // cout << total << " " << diff << endl;

    long double q = (long double) diff / total;

    cout << fixed << setprecision(2) << q << endl;

    // cout << a / b << endl;


    return 0;
}