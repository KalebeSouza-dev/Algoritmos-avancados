#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    ll l, r; cin >> l >> r;
    //2 3 5 7
    ll out = 0;
    out += r / 2 - (l-1)/2;
    out += r / 3 - (l-1)/3;
    out += r / 5 - (l-1)/5;
    out += r / 7 - (l-1)/7;

    out -= r / 6 - (l-1) / 6;
    out -= r / 10 - (l-1) / 10;
    out -= r / 14 - (l-1) / 14;
    out -= r / 15 - (l-1) / 15;
    out -= r / 21 - (l-1) / 21;
    out -= r / 35 - (l-1) / 35;

    out += r / 30 - (l-1) / 30;
    out += r / 42 - (l-1) / 42;
    out += r / 70 - (l-1) / 70;
    out += r / 105 - (l-1) / 105;

    out -= r / 210 - (l-1) / 210;

    cout << ((r - l + 1) - out) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}