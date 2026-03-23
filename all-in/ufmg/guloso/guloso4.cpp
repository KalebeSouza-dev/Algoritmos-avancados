#include "bits/stdc++.h"
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n; cin >> n;
    stack<string> nomes;

    while(n--){
        string s; cin >> s;
        nomes.push(s);
    }
    set<string> out;
    while(!nomes.empty()){
        string s = nomes.top();
        nomes.pop();

        if (!out.count(s)){
            cout << s << endl;
            out.insert(s);
        }
    } 
}
