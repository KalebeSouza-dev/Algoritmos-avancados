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
    Node* pont[26];

    Node(char v){
        valor = v;
        freq = 0;
        for(int i = 0; i < 26; i++)
            pont[i] = nullptr;
    }
    void setFreq() {freq++;}
    int getFreq() {return freq;}
};
struct Trie{
    Node* root;

    void update(string str){
        Node* aux = root;
        for (auto c : str){
            if (aux->pont[c-'a'] != nullptr){
                aux->pont[c-'a']->setFreq();
            } else {
                aux->pont[c-'a'] = new Node(c);
                aux->pont[c-'a']->setFreq();
            }
            aux = aux->pont[c-'a'];
        }
    }
    int query(string str){
        Node* aux = root;
        for (auto c : str){
            if (aux->pont[c-'a'] == nullptr) return 0;
            aux = aux->pont[c-'a'];
        }
        return aux->freq;
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
        cout << trie.query(s) << "\n";
    }

    return 0;
}