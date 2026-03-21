#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 100;
const ll INF = 1e12;

struct Node {
    bool end;
    Node* pont[3];

    Node(){
        end = false;
        for(int i = 0; i < 3; i++)
            pont[i] = nullptr;
    }
};
struct Trie{
    Node* root;

    void update(string str){
        Node* aux = root;
        for (auto c : str){
            if (aux->pont[c-'a'] == nullptr) aux->pont[c-'a'] = new Node();
            aux = aux->pont[c-'a'];
        }
        aux->end = true;
    }
    bool dfs(Node* node, const string& s, int pos, bool used){
        if (!node) return false;

        if (pos == s.size()) return node->end && used;

        for(int i=0; i < 3; i++){
            if(node->pont[i]){
                if ((i == s[pos] - 'a')) {
                    if (dfs(node->pont[i], s, pos+1, used))
                        return true;
                } else if(!used){
                    if (dfs(node->pont[i], s, pos+1, true))
                        return true;
                }
            }
        }
        return false;
    }
    string query(string str){
       return (dfs(root, str, 0, false)) ? "YES" : "NO";
    }
    Trie() {
        root = new Node();
    };
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    Trie trie;
    int u, q; cin >> u >> q;
    while (u--){
        string s; cin >> s;
        trie.update(s);
    }
    while (q--){
        string s; cin >> s;
        cout << trie.query(s) << endl;
    }

    return 0;
}