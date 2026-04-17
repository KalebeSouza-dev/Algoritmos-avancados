#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k; cin >> n >> k;
    vi arr(n); rep(i, 0, n) cin >> arr[i];
    vector<bool> bl(n, true);
    
    for(int i = n-1; i>=0; i--){
        if (arr[i] >= arr[i-1] + 1)
    }



    return 0;
}
