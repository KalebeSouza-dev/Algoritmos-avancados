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
    inline void j1() { cout << "Alice\n"; }
    inline void j2() { cout << "Bob\n"; }

    void solve_tc(){
        cout << "CASE" << endl;
        int n; cin >> n;
        string s; cin >> s;

        if (count(all(s), 'b') == 0) {cout << 0 << endl; return;}
        if (count(all(s), 'a') == 0) {cout << 0 << endl; return;}

        ll ans = LLONG_MAX;
        //aaabbb ou bbbaaa
        
        //aaabbbaaa
        vector<int> idxa;
        rep(i, 0, n){
            if (s[i] == 'a') idxa.pb(i);
        }

        int inia = 0, fima = n-1;
        while (inia < n && s[inia] == 'a') inia++;
        while (fima >= 0 && s[fima] == 'a') fima--;
        
        for (int i = 0; i < sz(idxa); i++){
            if (idxa[sz(idxa) - 1 - i] == n-1 - i) fima--;
            else {break;}
        }
        
        int ansa = 0;
        for (auto x : idxa){
            if (x < inia || x > fima) continue;
            if (abs(x - inia) < abs(x - fima)){
                ansa += abs(x - inia);
                inia++;
            }else{
                ansa += abs(x - fima);
                fima--;
            } 
        }
        cout << inia << " " << fima << endl;
        
        //bbbaaabbb
        vector<int> idxb;
        int inib = 0, fimb = n-1;
        rep(i, 0, n){
            if (s[i] == 'b') idxb.pb(i);
        }
        for (int i = 0; i < sz(idxb); i++){
            if (idxb[i] == i) inib++;
            else {break;}
        }
        for (int i = 0; i < sz(idxb); i++){
            if (idxb[sz(idxb) - 1 - i] == n-1 - i) fimb--;
            else {break;}
        }
        int ansb = 0;
        for (auto x : idxb){
            if (x < inib || x > fimb) continue;
            if (abs(x - inib) < abs(x - fimb)){
                ansb += abs(x - inib);
                inib++;
            }else{
                ansb += abs(x - fimb);
                fimb--;
            } 
        }
        cout << min(ansa, ansb) << endl;
    }

    int main(){
        cin.tie(0)->sync_with_stdio(0);
        
        int tc; cin >> tc;
        while(tc--) solve_tc();
        
        return 0;
    }