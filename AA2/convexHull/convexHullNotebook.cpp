#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

//notebook
struct Point {
    ll x, y;
    bool operator<(const Point &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
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
        while (k >= 2 && prod(H[k-2], H[k-1], pts[i]) <= 0)
            k--;
        H[k++] = pts[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && prod(H[k-2], H[k-1], pts[i]) <= 0) // <= 0 remove os colineares
            k--;
        H[k++] = pts[i];
    }

    H.resize(k-1);
    return H;
}
ll areaHull(const vector<Point> &pol){ // retorna 2*a
    ll area2 = 0;
    for (int i = 0; i < pol.size(); i ++){
        int j = (i + 1) % pol.size();
        area2 += pol[i].x * pol[j].y;
        area2 -= pol[i].y * pol[j].x; 
    }
    
    return llabs(area2);
}
ll area(const vector<pair<ll, ll>> &pol){ // retorna 2*a
    ll area2 = 0;
    for (int i = 0; i < pol.size(); i ++){
        int j = (i + 1) % pol.size();
        area2 += pol[i].first * pol[j].second;
        area2 -= pol[i].second * pol[j].first; 
    }
    
    return llabs(area2);
}
int main() {
    int n; cin >> n;
    //vector<Point> pts(n);
    vector<pair<ll,ll>> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    //vector<Point> hull = convex_hull(pts);

    cout << area(p) << endl;
    // cout << hull.size() << "\n";
    // for (auto &p : hull)
    //     cout << p.x << " " << p.y << "\n";

    return 0;
}