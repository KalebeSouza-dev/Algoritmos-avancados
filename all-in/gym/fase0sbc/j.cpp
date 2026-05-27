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
    vi arr(n * 2);

    vi out(n, 0);
    rep(i, 0, n){
        cin >> arr[i];
        arr[i+n] = arr[i];
    }
    rep(i, 0, n){
        if (arr[i] > arr[i+1]){
            out[i] = (i+2) % n;
        }
    }
    

    
    for (auto c : out) cout << c << " ";
    cout << endl;

    return 0;
}

//maldito talento