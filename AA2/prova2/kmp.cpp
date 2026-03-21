#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

ll kmp (string str, int n){
    vector<int> arr;
    arr.push_back(0);
    int j = 0; ll out = 0;
    for(int i = 1; i < str.length(); i++){
        while(j > 0){
            if (str[j] != str[i]) j = arr[j-1];
            else break;
        }
        if (str[j] == str[i]) j++;
        if (j >= n) {
            out++;
            j = arr[j-1];
        }
        arr.push_back(j);
    }
    return out;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string a, b; cin >> a >> b;
    cout << kmp(b + "#" + a, b.size()) << endl;
    
    return 0;
}