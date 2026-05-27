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

int count_bits(int n){
    int c = 0;
    for (int i = 0; i < 30; i++){
        if (n & (1 << i)) c++;
    }
    return c;
}

set<int> crivo(int num){
    vector<bool> bl(num+1, true);
    set<int> primos = {2}; 
    bl[0] = false; bl[1] = false; bl[2] = false;
    
    for(int i = 3; i < num; i+=2){
        if(bl[i]){
            primos.insert(i);
            for(int j = 2*i; j < num; j+=i) bl[j] = false;
        }
    }
    
    return primos;
}

const int MAXN = 1e5 + 100;

void solve_tc(vi &prefix){
    int l, r; cin >> l >> r;

    //cout << prefix[r] << " " << prefix[l-1] << endl; 
    cout << prefix[r] - (l ? prefix[l-1] : 0) << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    auto primes = crivo(60);
    vi prefix_sum(MAXN, 0);

    for(int i = 1; i < MAXN; i++){
        prefix_sum[i] = prefix_sum[i-1];

        if(primes.count(count_bits(i))){
            prefix_sum[i]++;
        }
    }
    
    // for(auto x : primes) cout << x << " "; cout << endl;
    // for(auto x : prefix_sum) cout << x << " "; cout << endl;


    int tc = 1; cin >> tc;
    while(tc--) solve_tc(prefix_sum);
    
    return 0;
}
 
//maldito talento