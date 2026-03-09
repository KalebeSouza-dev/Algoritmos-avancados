#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    int n; cin >> n;
    vector<int> arr(n+1);

    bool out = true;
    for(int i = 1; i <= n; i++)cin >> arr[i];

    vector<bool> visited(n+1, false);
    
    for(int i = 1; i <= n; i++){
         if(visited[i]) continue;

        set<int> c, exp;
        for(int pos = i; pos <= n; pos *= 2){
            visited[pos] = true;
            c.insert(arr[pos]);
            exp.insert(pos);
        }

        if(c != exp){
            out = false;
            break;
        }
    }
    cout << (out ? "YES" : "NO") << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc;
    cin >> tc;

    while(tc--) solve_tc();
    
    return 0;
}