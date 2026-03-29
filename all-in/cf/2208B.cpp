#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n, k, p, m; cin >> n >> k >> p >> m;
    vector<int> arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }
    p--;
    int cont = 0;
    while (m > 0){
        if (p < k){
            if (arr[p] > m) break;
            m -= arr[p];
            int tmp = arr[p];
            arr.erase(arr.begin() + p);
            arr.push_back(tmp);
            
            p = n-1;
            cont++;
        } else {
            sort(arr.begin(), arr.begin() + k);
            
            if(arr[0] > m) break;
            m -= arr[0];
            int b = arr[0];
            
            arr.erase(arr.begin());
            p--;
            arr.push_back(b);
        }
    }
    cout << cont << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}