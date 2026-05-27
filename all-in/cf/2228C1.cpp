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

// QUESTAO MALDIT
// TLE DNVVV
map<pii, vector<ll>> comb;
int d1, d2;
vector<ll> aux;

// lembra o k-star de TC, gerar toda a linguagem
void gen(ll num,  int len){
    if(len > 18) return;

    aux.pb(num);
    gen(num * 10 + d1, len+1);

    if (d1 != d2)
        gen(num * 10 + d2, len+1);
}

// BUSCA BINARIA
void solve_tc(){
    //cout << "CASE" << endl;
    ll a; int n; cin >> a >> n;
    cin >> d1 >> d2;

    vector<ll>& vals = comb[{min(d1, d2), max(d1, d2)}];

    // for (int i = 0; i < 20; i++){
    //     cout << vals[i] << " ";
    // }
    // cout << endl;

    //primeiro criar todas as combinacoes de numeros possiveis até 1e18 com m1 e m2
    //dps só pegar primeiro maior que A, e o menor, e ver o abs
    auto it = lower_bound(all(vals), a); // it aponta pro primeiro maior que A

    ll ans = 1e18;
    if (it != vals.end())
        ans = min(ans, abs(a - *it));

    if (it != vals.begin()){
        --it;
        ans = min(ans, abs(a - *it));
    }

    // for (auto v : vals) cout << v << " ";
    // cout << endl;

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;

    // pre processo tds os d possiveis
    for (int i = 0; i < 9; i++){
        for (int j = i+1; j <= 9; j++){
            aux.clear();

            d1 = i; d2 = j;

            if (d1 == 0) aux.pb(0);
            else gen(i, 1); 
            
            gen(j, 1);

            sort(all(aux));
            aux.erase(unique(all(aux)), aux.end());

            comb[{i, j}] = aux;
        }
    }

    while(tc--) solve_tc();
    
    return 0;
}

//maldito talento