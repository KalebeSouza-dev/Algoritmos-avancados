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
using ld = long double;

struct pt {
    using T = ld;

    T x, y;
    explicit pt(T x=0, T y=0) : x(x), y(y) {}
    bool operator < (pt p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator == (pt p) const { return tie(x,y)==tie(p.x,p.y); }
    pt operator + (pt p) const { return pt(x+p.x, y+p.y); }
    pt operator - (pt p) const { return pt(x-p.x, y-p.y); }
    pt operator * (T d) const { return pt(x*d, y*d); }
    pt operator / (T d) const { return pt(x/d, y/d); }
    T dot(pt p) const { return x*p.x + y*p.y; }
    T cross(pt p) const { return x*p.y - y*p.x; }
    T cross(pt &a, pt &b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    pt unit() const { return *this/dist(); } // makes dist()=1
    pt perp() const { return pt(-y, x); } // rotates +90 degrees
    pt normal() const { return perp().unit(); } 
    // friend ostream& operator << (ostream &os, pt p) {
    //     return os << "(" << p.x << ", " << p.y << ")";}
    T ori(pt a, pt b) const { T f = cross(a, b); return (f < 0 ? -1 : (f > 0 ? 1 : 0)); }    
    pt r90cw(){ return pt(y, -x);} // rotate 90 degrees clock wise
    pt r90ccw(){ return pt(-y, x);} // rotate 90 degrees counter clock wise 
};

bool onSegment(pt &s, pt &e, pt &p) {
    return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

bool in_polygon(vector<pt> &a, pt p, bool strict = true) {
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (onSegment(a[i], a[j], p)) return !strict;
        ans ^= ((p.y < a[i].y) - (p.y < a[j].y)) * p.cross(a[i], a[j]) > 0;
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;

    
    pt k;
    vector<pii> pttt = {{0, 100}, {100, 0}, {200, 0}, {100, -100}, {0, -100}, {-100, 0}, {-200, 0}, {-100, 100}};
    vector<pt> pts(8);
    for (int i = 0; i < 8; i++){
        pts[i].x = pttt[i].first;
        pts[i].y = pttt[i].second;
    }
    rep(i, 0, n){
        cin >> k.x >> k.y;

        if (in_polygon(pts, k, false)){
            cout << "S" << endl;
        } else {
            cout << "N" << endl;
        }

    }

    return 0;
}

//maldito talento