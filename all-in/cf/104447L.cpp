#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define pb push_back
#define print(x) cout << x << endl;
#define sz(x) (int) (x).size()
#define vi vector<int>
#define vl vector<ll>


void solve(){
    int n, m; cin >> n >> m;

    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2; 


    if ((((x1 + y1) % 2) == ((x2  + y2) % 2))){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
        
                if (i == x1 && j == y1) cout << 1 << " ";
        
                else if (i == x2 && j == y2) cout << 2 << " "; 
        
                else {
                    
                    if (i % 2 == j % 2){
                        cout << 3 << " ";
                    } else {
                        cout << 2 << " ";
                    }
                }
            }
            cout << endl;
        }
    } else {
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
        
                if (i == x1 && j == y1) cout << 1 << " ";
        
                else if (i == x2 && j == y2) cout << 2 << " "; 
        
                else {
        
                    if (x1 % 2 == y1 % 2){
                        if (i % 2 == j % 2) {
                            cout << 1 << " ";
                        } else {
                            cout << 2 << " ";
                        }
        
                    } else {
                        if (i % 2 == j % 2) {
                            cout << 2 << " ";
                        } else {
                            cout << 1 << " ";
                        }
                    }
                }
            }
            cout << endl;
        }
    }
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1;
    cin >> tc;
    while(tc--) solve();
}   