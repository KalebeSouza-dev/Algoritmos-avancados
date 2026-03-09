#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void num(ll n) {cout << n << "\n";}

//notebook
struct Point {
    ll x, y;
    bool operator<(const Point &other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};
// se for colinear retorna true
bool prod(Point O, Point A, Point B) {
    return ((A.x - O.x) * (B.y - O.y) -
           (A.y - O.y) * (B.x - O.x)) == 0;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++){
        cin >> pts[i].x >> pts[i].y; 
    }
    sort(all(pts));
    //somar todos os trios e subrair os colineares
    // fazer todas as combinaçoes e retirar os prod == 0
    // soma de todos os triangulos == combinacao
    // n! / 3! * (n - 3)! == n * (n-1) * (n-2) / 6
    if (n < 3) num(0);
    else if (n == 3) {
        if (!prod(pts[0],pts[1],pts[2])) num(1);
        else num(0);
    } else {
        ll trios = 1LL * n*(n-1)*(n-2) / 6;
        ll out = trios;
        for (int i = 0; i < n - 2; i++){
            for(int j = i+1; j < n - 1; j++){
                for (int k = j+1; k < n; k++){
                    if (prod(pts[i], pts[j],  pts[k])) out--;
                }
            }
        }
        num(out);
    }

    return 0;
}