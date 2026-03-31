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

inline void yes() { cout << "YES\n";}
inline void no() { cout << "NO\n"; }
inline void j1() { cout << "Alice\n"; }
inline void j2() { cout << "Bob\n"; }

void solve_tc(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    
    if (s == t) {yes(); return;}

    stack<int> pilhas, pilhat;
    int maxs = 0, maxt = 0;
    vector<int> arrs, arrt;
    for (auto c : s){
        if (c == '(') {pilhas.push(1); maxs = max(maxs, (int) pilhas.size());}
        else pilhas.pop();

        arrs.pb((int) pilhas.size());
    }
    for (auto c : t){
        if (c == '(') {
            pilhat.push(1); 
            maxt = max(maxt, (int) pilhat.size());  
            // arrt.pb((int) pilhat.size());
        } else pilhat.pop();

        arrt.pb((int) pilhat.size());
    }

    sort(all(arrs));
    sort(all(arrt));

    if (arrs == arrt) {yes(); return;}
    if (maxs != maxt) {no(); return;}

    vector<int> freqs(maxs+1), freqt(maxt+1);

    for (auto x : arrs) {
        //cout << x << " ";
        freqs[x]++;
    }
    //cout << endl;
    
    for (auto x : arrt) {
        //cout << x << " ";
        freqt[x]++;
    }

    // for (auto x : freqs) cout << x <<" ";
    // cout << endl;
    // for (auto x : freqt) cout << x <<" ";
    // cout << endl;
    for (int i = min(maxs, maxt); i >= 0; i--){
        if (freqs[i] > freqt[i] + 1 || freqt[i] > freqs[i] + 1) {no(); return;}
    }

    yes(); return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}