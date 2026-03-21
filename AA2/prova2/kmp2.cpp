#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
#define all(x) (x).begin(),(x).end()

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    string s; cin >> s;
    int n = s.size();

    vector<int> arr;
    arr.push_back(0);
    int j = 0;
    for(int i = 1; i < n; i++){
        while(j > 0){
            if (s[j] != s[i]) j = arr[j-1];
            else break;
        }
        if (s[j] == s[i]) j++;
        arr.push_back(j);
    }

    vector<int> borders;
    int k = arr[n-1];
    while(k > 0){
        borders.push_back(k);
        k = arr[k - 1];
    }

    reverse(all(borders));
    for(int b : borders) cout << b << " ";
    cout << "\n";
    
    return 0;
}