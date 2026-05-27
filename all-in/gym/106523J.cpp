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

int crivo(int num){
    vector<bool> prim(num+1, true);
    int qtd = 1;

    for(int i = 3; i <= num; i+=2){
        if (prim[i]){
            qtd++;

            if (1LL * i * i <= num){
                for (int j = i*i; j <= num; j += 2*i){
                    prim[j] = false;
                }
            }
        }
    }

    return qtd;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    if (n == 1) cout << 0 << endl;
    else if (n == 2) cout << 1 << endl;
    else {
        cout << crivo(n) << endl;
    }

    return 0;
}

//maldito talento