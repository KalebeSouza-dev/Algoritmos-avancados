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

    string s; cin >> s;
    int n = sz(s);

    for (int i = 0; i < n-1; i++){
        cout << s[i];
    }
    if (s[n-1] == 'u') cout << "ivis" << endl;
    else cout << s[n-1] << endl;


    return 0;
}

//maldito talento