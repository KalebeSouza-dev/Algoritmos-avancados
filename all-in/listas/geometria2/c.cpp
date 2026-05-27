#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline void yes() { cout << "YES\n"; }
inline void no() { cout << "NO\n"; }

using ld = long double;
using ll = long long;

const double eps = 1e-7;
bool eq(ld a, ld b = 0) {
    return abs(a - b) <= eps;
}

struct pt {
    using T = ll;

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

vector<pt> convexHull(vector<pt> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<pt> h(sz(pts)+1); //h(2*sz(pts)+2) pra ter colinear
    int s = 0, t = 0;       
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (pt p : pts) {               // troca por > 0,coolinear
            while (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--; 
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

void solve_tc(){
    int n, r; cin >> n >> r;
    vector<pt> pts(n);
    rep(i, 0, n) cin >> pts[i].x >> pts[i].y;

    auto convex = convexHull(pts);
    // for (auto [x, y] : convex) cout << x << y << endl;
    if (sz(convex) <= r) yes();
    else no();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento