struct Node {
    int prefix_count = 0;  // quantas palavras passam por este nó
    Node* pont[26] = {};
};
struct Trie {
    Node* root = new Node();


    void update(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (!cur->pont[i])
                cur->pont[i] = new Node();
            cur = cur->pont[i];
            cur->prefix_count++;  // incrementa em TODOS os nós do caminho
        }
    }


    int query(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int i = c - 'a';
            if (!cur->pont[i]) return 0;
            cur = cur->pont[i];
        }
        return cur->prefix_count;  // já tem a contagem acumulada
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    Trie trie;
    int u, q;
    cin >> u >> q;