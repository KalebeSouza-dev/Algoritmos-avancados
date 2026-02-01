#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

//void solve_tc(){}

const int MAXN = 1e5 + 100;
const ll INF = 1e12;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string dna;
    cin >> dna;
    int cont = 1;
    int out = 1;
    for(int i=1; i <= dna.length(); i++){
        //cout << dna[i] << endl;
        if (dna[i] == dna[i-1]){
            cont += 1;
        }
        else {
            out = max(out, cont);
            cont = 1;
        }
        //cout << cont << " " << out << endl;
    }
    cout << out << endl;
    //int t; cin >> t;
    //while(t--) solve_tc();
    
    return 0;
}