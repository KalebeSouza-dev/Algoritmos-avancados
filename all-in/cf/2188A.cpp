#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    vector<int> out;
    int k = 1;
    int lim = n/2;
    if (n%2==1) cout << n/2 + 1 << " ";
    for (int i = 0; i < lim; i++){
        out.push_back(k);
        out.push_back(n);
        k++; n--;
    }

    for(int i = (int) out.size()-1; i >= 0; i--) cout << out[i] << " ";

    cout << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}