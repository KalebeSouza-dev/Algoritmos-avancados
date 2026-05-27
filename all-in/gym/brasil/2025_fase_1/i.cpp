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

struct Point{
    int x, y;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n; vector<Point> pts(n);
    rep(i, 0, n){
        cin >> pts[i].x >> pts[i].y;
    }
    



    return 0;
}