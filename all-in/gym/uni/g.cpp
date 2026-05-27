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
    string sp = "BR-SP";

    if (s[3] != 'S' && s[4] !='P') cout << "N";
    else if (s[3] == 'S' && s[4] == 'P') cout << "S";
    else if ((s[3] == 'S' && s[4] == '?') || (s[3] == '?' && s[4] =='P')) cout << "T";
    else cout << "N";
    cout << endl;
    

    return 0;
}

//maldito talento