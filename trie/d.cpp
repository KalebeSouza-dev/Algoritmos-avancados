#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define endl "\n"
#define pb push_back

const int MAXN = 1e5 + 100;
const ll INF = 1e12;

struct Node {
    int freq = 0;
    char valor;
    Node* pont[3];

    Node(char v){
        valor = v;
        freq = 0;
        for(int i = 0; i < 3; i++)
            pont[i] = nullptr;
    }
};
struct Trie{
    Node* root;

    void update(string str){
        Node* aux = root;
        for (auto c : str){
            if (aux->pont[c-'a'] == nullptr) aux->pont[c-'a'] = new Node(c);
            aux = aux->pont[c-'a'];
        }
    }
    bool query(string str){
        Node* aux = root;
        bool out = false;
        for (int i = 0; i < str.length(); i++){
            char c = str[i];
            if (aux->pont[c-'a']->valor == c) {
                aux = aux->pont[c-'a'];
            } else {
                Node* auxB = aux->pont[(c-'b') % 3];
                for (int j = i; j < str.length(); j++){
                    char c = str[j];
                    if (auxB->pont[c-'a'] == nullptr) break;
                    if (auxB->pont[c-'a']->valor == c) {
                        auxB = auxB->pont[c-'a'];
                    } else {
                        out = true;
                        break;
                    }
                }
                if (out) return out;

                Node* auxC = aux->pont[(c-'c') % 3];
                for (int j = i; j < str.length(); j++){
                    char c = str[j];
                    if (auxC->pont[c-'a'] == nullptr) break;
                    if (auxC->pont[c-'a']->valor == c) {
                        auxC = auxC->pont[c-'a'];
                    } else {
                        out = true;
                        break;
                    }
                }

                break;
            }
            
        }
        return false;
    }
    Trie() {
        root = new Node('0');
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
        if (trie.query(s)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}