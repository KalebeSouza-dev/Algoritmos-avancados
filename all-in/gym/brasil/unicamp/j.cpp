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

    vector<string> out = {
        "123\n456\n789",
        "*23\n456\n789",
        "*23\n45*\n789",
        "*23\n45*\n7*9",
        "1*3\n*5*\n7*9",
        "1*3\n***\n7*9",
        "***\n*5*\n7*9",
        "***\n4*6\n***",
        "***\n*5*\n***",
        "***\n***\n***"
    };

    cout << out[n] << endl;

    return 0;
}