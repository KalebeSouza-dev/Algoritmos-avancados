#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

bool palindromo(const string& s) {
    int i = 0, j = s.size() - 1;
    while (j > i) {
        if (s[i] != s[j]) return false;
        i++; j--;
    }
    if (s.size() % 2 != 0) {
        int meio = s.size() / 2;
        if (s[meio] == '1') return false;
    }
    return true;
}

void solve_tc(){
    int n; cin >> n;

    string aux = bitset<30>(n).to_string();
    int start = aux.find('1');
    if (start == (int)string::npos) {
        cout << "YES\n";
        return;
    }
    aux = aux.substr(start);

    if (palindromo(aux)) {
        cout << "YES\n";
        return;
    }

    int i = aux.size() - 1;
    while (i >= 0 && aux[i] == '0') i--;
    string auxzeros = aux.substr(0, i + 1);

    cout << (palindromo(auxzeros) ? "YES" : "NO") << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}