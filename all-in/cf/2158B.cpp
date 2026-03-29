#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

void solve_tc(){
    int n; cin >> n;
    vector<int> arr(2*n+1);
    int x;
    rep(i, 0, 2*n) {cin >> x; arr[x]++;}
    sort(all(arr));
    vector<int> a, b;
    ll diff = 0;
    int ans = 0;
    for (auto x: arr){
        if (x == 0) continue;
        // cout << x << " ";
        if (x % 2 == 1){
            if (diff >= 0){
                a.push_back(x/2); b.push_back(x/2+1);
                diff--;
            } else {
                a.push_back(x/2+1); b.push_back(x/2);
                diff++;
            }
            ans++;
        } else if ((x / 2) % 2 == 0){
            if (diff > 0){
                a.push_back(x/2 - 1);
                b.push_back(x/2 + 1);
                diff-= 2;
            } else {
                a.push_back(x/2 + 1);
                b.push_back(x/2 - 1);
                diff+= 2;
            }
            ans+=2;
        } else {
            a.push_back(x/2);
            b.push_back(x/2);
            ans += 2;
        }
    }

    // cout << endl;
    // cout << "d" << diff << endl;
    // cout << "a "; for (auto x: a) cout << x << " "; cout << endl;
    // cout << "b "; for (auto x: b) cout << x << " "; cout << endl;
    // cout << "KATCHAU\n";

    if (diff != 0){
        if (diff < 0){
            diff *= -1;
            for (int i = a.size()-1; i >= 0; i--){
                if (diff == 0) break;
                if (diff >= 2){
                    while(b[i] > 2 && diff >= 4) {b[i]-=2; a[i]+=2; diff -=4;}
                    if (diff >= 2 && b[i] % 2 != a[i] % 2 && b[i] > 0 && a[i] > 0){
                        diff-=2;
                        b[i]--;
                        a[i]++;
                    }
                } else if (diff >= 2 && b[i] % 2 != a[i] % 2 && b[i] > 0 && a[i] > 0){
                        diff-=2;
                        b[i]--;
                        a[i]++;
                }else {
                    if (diff == 1) break;
                }
            }
        } else {
            for (int i = a.size()-1; i >= 0; i--){
                if (diff == 0) break;
                if (diff >= 2){
                    while(a[i] > 2 && diff >= 4) {cout <<"w";a[i]-=2;b[i]+=2; diff -=4;}
                    if (diff >= 2 && a[i] % 2 != b[i] % 2 && b[i] > 0 && a[i] > 0){
                        diff-=2;
                        a[i]--;
                        b[i]++;
                    }
                } else if (diff >= 2 && a[i] % 2 != b[i] % 2 && b[i] > 0 && a[i] > 0){
                        diff-=2;
                        a[i]--;
                        b[i]++;
                }else {
                    // if (diff == 1 && a[i] % 2 == 0 && a[i] > 0){
                    //     diff--;
                    //     a[i]--;
                    // }
                    if (diff == 1) break;
                }
            }
        }
    }

    // cout << "d" << diff << endl;
    // cout << "a "; for (auto x: a) cout << x << " "; cout << endl;
    // cout << "b "; for (auto x: b) cout << x << " "; cout << endl;

    if (diff == 0) cout << ans << endl;
    else cout << ans - diff << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int tc; cin >> tc;
    while(tc--) solve_tc();
    
    return 0;
}