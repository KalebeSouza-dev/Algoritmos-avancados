#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

void solve_tc(){
    string kal; cin >> kal;
    sort(all(kal));
    cout << kal << endl;
    int k = 0;
    string out = "";
    for (char a : kal){
        int v = a - 'A';
        k += v;
        cout << v << endl;
        out += (char)(v + 97 + 19);
    }
    cout << endl << k << endl;
    cout << (string) out << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}