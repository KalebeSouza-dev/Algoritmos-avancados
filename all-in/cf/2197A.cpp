#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int sum_digits(ll n){
    int s = 0;
    while(n > 0){
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve_tc(){
    int n; cin >> n;

    int out = 0;
    for(ll y = n; y <= n + 200; y++){
        if(y - sum_digits(y) == n)
            out++;
    }

    cout << out << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}