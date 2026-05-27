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

int dot(Point a, Point b, Point c) {
    int bax = a.x - b.x;
    int bay = a.y - b.y;
    int bcx = c.x - b.x;
    int bcy = c.y - b.y;
    return bax * bcx + bay * bcy;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<Point> pts(3);
    rep(i,0,3) cin >> pts[i].x >> pts[i].y;

    if (dot(pts[0], pts[1], pts[2]) == 0 ||
        dot(pts[1], pts[0], pts[2]) == 0 ||
        dot(pts[1], pts[2], pts[0]) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}