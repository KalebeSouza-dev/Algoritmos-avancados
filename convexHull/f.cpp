#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

struct Point{
    ll x, y;
};
bool prodc(Point O, Point A, Point B) {
    return (__int128)(A.x - O.x) * (B.y - O.y) -
           (__int128)(A.y - O.y) * (B.x - O.x) == 0;
}
bool verificacao(const vector<Point> &pts, int a, int b, int n){
    vector<Point> falta;
    for (int i = 0; i < n; i++){
        if (i == a || i == b) continue;
        if (prodc(pts[a], pts[b], pts[i])) continue;
        else falta.push_back(pts[i]);
    }
    if (falta.size() <= 2) {
        return true;
    } else {
        bool flag = true;
        for (int i = 2; i < falta.size(); i++){
            if (prodc(falta[0], falta[1], falta[i])) continue;
            else flag = false;
        }
        if (flag) {
            return true;
        }
    }
    return false;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<Point> pts(n);
    for (int i=0; i<n;i++){
        cin >> pts[i].x >> pts[i].y;
    }
    if (n <= 4) {
        cout << "YES" << endl;
    } else if (verificacao(pts, 0, 1, n) || verificacao(pts, 0, 2, n) || verificacao(pts, 1, 2, n)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}