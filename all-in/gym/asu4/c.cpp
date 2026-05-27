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

    int x, y; cin >> x >> y;
    string s; cin >> s;

    y += count(all(s), 'U') - count(all(s), 'D');
    x += count(all(s), 'R') - count(all(s), 'L');
    
    cout << x << " " << y << endl;

    return 0;
}

//maldito talento