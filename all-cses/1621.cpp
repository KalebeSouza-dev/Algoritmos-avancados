#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

//void solve_tc(){}

const int MAXN = 1e5 + 100;
const ll INF = 1e12;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    set<int> s;
    int k;
    for(int i = 0; i < n; i++) {
        cin >> k;
        s.insert(k);
    }
    cout << s.size() << endl;
    //int t; cin >> t;
    //while(t--) solve_tc();
    
    return 0;
}