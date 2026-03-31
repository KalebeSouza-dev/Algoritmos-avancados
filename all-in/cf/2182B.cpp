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
    int a, b; cin >> a >> b;
    if (b < a) swap(a, b);
    int c = b, d = a;

    ll ans = 0, custo = 1;
    int idx = 1;
    while(a>=0 || b>=0){
        if (idx % 2 == 1){
            if (a >= custo) {
                ans++;
                a-=custo;
            } else {
                break;
            }
        } else {
            if (b >= custo){
                ans++;
                b-=custo;
            } else {
                break;
            }
        }
        custo *= 2; idx++;
    }

    ll ans2 = 0, custo2 = 1;
    idx = 1;
    a = c; b = d;
    while(a>=0 || b>=0){
        if (idx % 2 == 1){
            if (a >= custo2) {
                ans2++;
                a-=custo2;
            } else {
                break;
            }
        } else {
            if (b >= custo2){
                ans2++;
                b-=custo2;
            } else {
                break;
            }
        }
        custo2 *= 2; idx++;
    }
    //cout << a << " " << b << endl;
    cout << max(ans,ans2) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}