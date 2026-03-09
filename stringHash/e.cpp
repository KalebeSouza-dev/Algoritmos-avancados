#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()


int main(){
    cin.tie(0)->sync_with_stdio(0);

    string s; cin >> s;
    vector<int> freq(26);

    for (auto x : s){
        freq[x - 'A']++;
    }   
    bool ehimpar = false;
    string out = "";
    string meio = "";
    for (int i = 0; i < 26; i++){
        if (freq[i] % 2 == 1){
            if (ehimpar) {
                cout << "NO SOLUTION\n";
                exit(0);
            }
            else ehimpar = true;
            meio = string(freq[i], char(i + 'A'));
        }
        else {
            out += string(freq[i] / 2, char(i + 'A'));
        }
    }

    cout << out;
    cout << meio;
    reverse(all(out));
    cout << out << endl;

    return 0;
}