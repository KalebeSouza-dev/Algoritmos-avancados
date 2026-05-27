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
    map<char, int> freq;
    for (auto c: s)freq[c]++;

    bool impar = false;
    string in = "", out, imp = "";

    for (auto [k, v] : freq) {
        if (v % 2 == 1){
            if (impar) {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            else {
                impar = true;
                imp = string(v, k); 
            }
        } else {
            in += string((int) v/2, k);
        }
    }

    out = in; reverse(all(out));
    cout << in << imp << out << endl;

    return 0;
}

//maldito talento