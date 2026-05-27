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

struct pt {
    using T = long double;

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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<pt> pts(n);
    rep(i, 0, n) cin >> pts[i].x >> pts[i].y;
    
    if (n <= 4) {cout << "YES\n"; return 0;}
    
    vector<pt> falta;
    for (int i = 2; i < n; i++){
        if (pts[i].cross(pts[1], pts[0]) != 0) falta.pb(pts[i]);
    }
    if (sz(falta) <= 2) {cout << "YES\n"; return 0;}
    else {
        bool eh = true;
        for (int i = 2; i < sz(falta); i++){
            if (falta[i].cross(falta[1], falta[0]) != 0) eh = false;
        }
        if (eh) {cout << "YES\n"; return 0;}
    }

    falta.clear();
    for (int i = 0; i < n; i++){
        if (i == 1 || i == 2) continue;
        if (pts[i].cross(pts[1], pts[2]) != 0) falta.pb(pts[i]);
    }
    if (sz(falta) <= 2) {cout << "YES\n"; return 0;}
    else {
        bool eh = true;
        for (int i = 2; i < sz(falta); i++){
            if (falta[i].cross(falta[1], falta[0]) != 0) eh = false;
        }
        if (eh) {cout << "YES\n"; return 0;}
    }

    falta.clear();
    for (int i = 1; i < n; i++){
        if (i == 0 || i == 2) continue;
        if (pts[i].cross(pts[2], pts[0]) != 0) falta.pb(pts[i]);
    }
    if (sz(falta) <= 2) {cout << "YES\n"; return 0;}
    else {
        bool eh = true;
        for (int i = 2; i < sz(falta); i++){
            if (falta[i].cross(falta[1], falta[0]) != 0) eh = false;
        }
        if (eh) {cout << "YES\n"; return 0;}
    }

    cout << "NO\n";

    return 0;
}

//maldito talento