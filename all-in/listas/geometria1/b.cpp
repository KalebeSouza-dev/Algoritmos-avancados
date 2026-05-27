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

int dot(Point a, Point b, Point c){
    int bax = a.x - b.x;
    int bay = a.y - b.y;
    int bcx = c.x - b.x;
    int bcy = c.y - b.y;
    return bax * bcx + bay * bcy; 
}

ll dist2(Point a, Point b){
    ll dx = a.x - b.x;
    ll dy = a.y - b.y;
    return dx*dx + dy*dy;
}

bool diagonais(Point a, Point b, Point c, Point d){
    ll acx = a.x - c.x;
    ll acy = a.y - c.y;

    ll bdx = b.x - d.x;
    ll bdy = b.y - d.y;

    return (acx*acx + acy*acy) == (bdx*bdx + bdy*bdy);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<Point> pt(4);
    rep(i, 0, 4) cin >> pt[i].x >> pt[i].y;
    auto a = pt[0], b = pt[1], c = pt[2], d = pt[3];

    ll ab = dist2(a,b);
    ll bc = dist2(b,c);

    if (dot(a, b, c) == 0
        && dot(b, c, d) == 0
        && dot(c, d, a) == 0
        && dot(d, a, b) == 0
        && diagonais(a,b,c,d)
        && ab == bc && ab > 0) cout << "SIM" << endl;
    else cout << "NAO" << endl;

    return 0;
}