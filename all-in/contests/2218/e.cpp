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


//@brenner
const int LG = 31;
struct trie {
    trie *ch[2];

    trie() { ch[0] = ch[1] = nullptr; }
    void insert(int x, int bit = LG) {
        if (bit < 0) return;

        int nxt = (x & (1 << bit)) > 0;
        if (!ch[nxt]) ch[nxt] = new trie();
        ch[nxt]->insert(x, bit - 1);
    }
    int xor_min(int x, int bit = LG) {
        if (bit < 0) return 0;

        int nxt = (x & (1 << bit)) > 0;
        if (ch[nxt]) return ch[nxt]->xor_min(x, bit - 1);
        return (1 << bit) + ch[nxt ^ 1]->xor_min(x, bit - 1);
    }
    int xor_max(int x, int bit = LG) {
        if (bit < 0) return 0;

        int nxt = (x & (1 << bit)) > 0;
        if (ch[nxt ^ 1]) return (1 << bit) + ch[nxt ^ 1]->xor_max(x, bit - 1);
        return ch[nxt]->xor_max(x, bit - 1);
    }
    void get_all(vector<int> &v, int bit = LG, int x = 0) {
        if (bit < 0) {
            v.push_back(x);
            return;
        }
        if (ch[0]) ch[0]->get_all(v, bit - 1, x);
        if (ch[1]) ch[1]->get_all(v, bit - 1, x | (1 << bit));
    }
};

void solve_tc(){
    int n; cin >> n;

    vector<int> arr(n);
    rep(i, 0, n) cin >> arr[i];

    trie *t = new trie();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) ans = max(ans, t->xor_max(arr[i]));
        t->insert(arr[i]);
    }

    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc = 1; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}