#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

struct Point {
    ll x, y;
    bool operator<(const Point &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};
Point centro(const vector<Point>& pts) {
    double sumX = 0.0, sumY = 0.0;
    for (const auto& p : pts) {
        sumX += p.x;
        sumY += p.y;
    }
    return { sumX / 4, sumY / 4};
}
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
bool equalsPoint(Point a, Point b){
    if (a.x == b.x && a.y == b.y) return true;
    return false;
}
void verifica(vector<Point> pts, Point p){
    vector<Point> qx = pts;
    qx.push_back(p);
    auto convex = convex_hull(qx);
    if (convex.size() <= 4) {
        //cout << z.x << " " << z.y << endl;
        bool tinha = false;
        for (auto z : convex) {
            if (equalsPoint(z, p)) {
                tinha=true;
                break;
            }
        }
        if (!tinha){
            cout << "YES" << endl;
            exit(0);
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<Point> q1(4);
    vector<Point> q2(4);

    for (int i = 0; i < 4; i++){
        cin >> q1[i].x >> q1[i].y;
    }
    for (int i = 0; i < 4; i++){
        cin >> q2[i].x >> q2[i].y;
    }
    // ideia: pegar 4 pontos, mais 1 ponto do outro quadrado e ver o size do hull
    // fazer para os dois quadrados, entao vou rodar o convex 8 vezes com 5 pontos;
    // verificar se o ponto que adicionei está no convex, ou ele foi excluido
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (equalsPoint(q1[i], q2[j])){
                cout << "YES" << endl;
                exit(0);
            }
        }
    }
    for (int i = 0; i < 4; i++){
        verifica(q2, q1[i]);
        verifica(q1, q2[i]);
    }

    //verificar pelo centro
    verifica(q1, centro(q2));
    verifica(q2, centro(q1));
    
    cout << "NO" << endl;
    return 0;
}