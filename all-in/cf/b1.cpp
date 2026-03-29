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

    while(n--){
        string s; cin >> s;

        bool RX = true;
        for(int j = 0; j < s.size(); j++) {
            if(j != 0) {
                if(s[j] >= 'A' && s[j] <= 'Z' && s[j - 1] >= '0' && s[j - 1] <= '9') {
                    RX = false;
                }
            }
        }

        if (RX){
            // BC23 -> R23C55
            string letras_str = "", num_str = "";

            for (auto c : s) {
                if (isupper(c)) letras_str += c;
                else num_str += c;
            }

            int out = 0;
            int pt = 1;
            for(int i = letras_str.size() - 1; i >= 0; i--) {
                out += (letras_str[i] - 'A' + 1) * pt;
                pt *= 26;
            }
            int out2 = 0;
            pt = 1;
            for(int i = num_str.size() - 1; i >= 0; i--) {
                out2 += (num_str[i] - '0') * pt;
                pt *= 10;
            }
            cout << "R" << out2 << "C" << out << endl;
        } else {
            // R23C55 -> BC23

            int i = 1;
            string row = "", col_str = "";

            while (isdigit(s[i])) {
                row += s[i];
                i++;
            }
            i++;

            while (i < s.size()) {
                col_str += s[i];
                i++;
            }

            ll num = stoll(col_str);

            string col = "";
            while (num > 0) {
                num--;
                col += char('A' + (num % 26));
                num /= 26;
            }

            reverse(all(col));

            cout << col << row << endl;
        }
    }

    return 0;
}