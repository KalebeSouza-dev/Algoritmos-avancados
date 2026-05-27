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

//notebook
struct Point {
    ll x, y;

    bool operator<(const Point &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};
ll prod(Point O, Point A, Point B) {
    return (A.x - O.x) * (B.y - O.y) -
           (A.y - O.y) * (B.x - O.x);
}
vector<Point> convex_hull(vector<Point> pts) {
    int n = pts.size(), k = 0;
    if (n <= 1) return pts;

    sort(all(pts));
    vector<Point> H(2*n);

    for (int i = 0; i < n; i++) {
        while (k >= 2 && prod(H[k-2], H[k-1], pts[i]) < 0)
            k--;
        H[k++] = pts[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && prod(H[k-2], H[k-1], pts[i]) < 0) // <= 0 remove os colineares
            k--;
        H[k++] = pts[i];
    }

    H.resize(k-1);
    return H;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    vector<pii> pttt = {{0, 100}, {100, 0}, {200, 0}, {100, -100}, {0, -100}, {-100, 0}, {-200, 0}, {-100, 100}};

    vector<Point> pts(8);
    for (int i = 0; i < 8; i++){
        pts[i].x = pttt[i].first;
        pts[i].y = pttt[i].second;
    }

    Point k;
    vector<Point> original = convex_hull(pts);
    for (int i = 0; i < n; i++){
        cin >> k.x >> k.y;
        pii kk = {k.x, k.y};

        if (count(all(pttt), kk)) {
            cout << "S" << endl;
            continue;
        }
        auto copy = pts;
        copy.pb(k);

        vector<Point> hull = convex_hull(copy);

        sort(all(hull));
        sort(all(original));

        //for (auto [x, y] : hull) cout << x << ' ' << y << endl;
        if (!count(all(hull), k)){
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}

//maldito talento