    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef pair<ll,ll> pii;
    #define all(x) (x).begin(),(x).end()

    void solve_tc(){
        int n; cin >> n;
        string s; cin >> s;
        sort(all(s));
        cout << s << endl;
    }

    int main(){
        cin.tie(0)->sync_with_stdio(0);

        solve_tc();
        
        return 0;
    }