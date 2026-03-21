#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;
    string s; cin >> s;

    ss = '';
    bool abriu = false, fechou = false;
    for (auto x: s){
        if (abriu == false && x == '('){
            abriu == true;
        } else {
            ss += x;
        }
        if (abriu && x == ')')
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}