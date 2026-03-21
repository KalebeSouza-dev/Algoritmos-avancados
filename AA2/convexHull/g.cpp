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

ll prod(ll x1,ll  y1,ll x2,ll y2,ll x3,ll y3){
    return ((x1 - x2) * (y3 - y2)) - ((x3 - x2) * (y1- y2));
}

void solve_tc(){
    ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    ll p = prod(x1, y1, x2, y2, x3, y3);
    if (p == 0) cout << "TOUCH";
    else if (p < 0) cout << "LEFT";
    else cout << "RIGHT";
    cout << endl;
}

int kmp(string str, int n){
    vector<int> arr;
    arr.push_back(0);
    int j = 0;
    int out = 0;
    for(int i = 1; i < str.length(); i ++){
        while(j > 0){
            if (str[j] != str[i]) j = arr[j-1];
            else break;
        }
        if (str[j] == str[i]) j++;
        if(j >= n) {
            out++;
            j = arr[j-1];
        }
        arr.push_back(j);
    }
    return out;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string s, a; cin >> s >> a;
    cout << kmp(a + "#" + s, a.size()) << endl;
    
    return 0;
}

ll prod(ll x1,ll  y1,ll x2,ll y2,ll x3,ll y3){
    return ((x1 - x2) * (y3 - y2)) - ((x3 - x2) * (y1- y2));
}
void solve_tc(){
    ll x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll p = prod(x1, y1, x2, y2, x3, y3);
    if (p == 0) cout << "TOUCH";
    else if (p < 0) cout << "LEFT";
    else cout << "RIGHT";
    cout << endl;
}
