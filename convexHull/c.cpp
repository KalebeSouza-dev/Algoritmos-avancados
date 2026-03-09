#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

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
    vector<pair<ll,ll>> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    cout << area(p) << endl;
    return 0;
}