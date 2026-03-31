#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

void solve_tc(){
    int n; cin >> n;

    vector<pair<string,int>> rounds(n);
    map<string,int> total;

    for (int i = 0; i < n; i++) {
        cin >> rounds[i].first >> rounds[i].second;
        total[rounds[i].first] += rounds[i].second;
    }

    int mx = INT_MIN;
    for (auto& p : total){
        mx = max(mx, p.second);
    }

    map<string,int> cur;
    for (int i = 0; i < n; i++) {
        string name = rounds[i].first;
        int val = rounds[i].second;

        cur[name] += val;

        if (cur[name] >= mx && total[name] == mx) {
            cout << name << endl;
            return;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1;
    while(tc--) solve_tc();
    
    return 0;
}