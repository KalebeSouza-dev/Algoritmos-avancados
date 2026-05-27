#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

void solve_tc(){
    int n; cin >> n;
    vector<string> id(n);
    vector<pair<vi, int>> arr(n, {vi(3), 0});

    rep(i, 0, n){
        cin >> arr[i].first[0] >> arr[i].first[1] >> arr[i].first[2];
        
        cin.ignore(); getline(cin, id[i]);
        
        // return;
        arr[i].second = i;
    }
    sort(all(arr));

    cout << id[arr[0].second] << endl;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; 
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento