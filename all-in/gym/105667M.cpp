#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s; cin >> s;
    for (auto c : s){
        if (c == 'O') cout << ".-.-";
        else cout << ".-";
    }
    cout << endl;

    return 0;
}
