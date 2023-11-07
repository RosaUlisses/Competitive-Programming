#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define loop(x, y) for(int x = 0; x < y; x++)
#define fin(x, y) for(auto& x : y)
#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define minel(x) *min_element(all(x))
#define maxel(x) *max_element(all(x))
#define f first
#define s second


using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using imat = vector<vector<int>>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;


void solve() {
    int n;
    map<pair<int,int>, int> m;
    cin >> n;
    vector<str> tks(n);

    for (int i = 0; i < n; ++i) {
        str ss; 
        cin >> ss;
        
        tks[i] = ss;
        
        int sum = accumulate(all(ss), 0, [](int v, auto& v2) {
          return v + (v2 - '0'); 
        });
        
        ii p = {sum, sz(ss)};
        if(!has(m, p)) {
           m[p] = 1; 
        }
        else m[p]++;
    }
    
    
    ll ans = 0;
    
    fin(ss, tks) {
        int sum = accumulate(all(ss), 0, [](int v, auto& v2) {
            return v + (v2 - '0');
        });
        
        int left = sum;
        int left_sz = sz(ss);
        int right = 0;
        int right_sz = 0;

        for (int i = sz(ss) - 1; i >= 0; --i) {
            ll crr_sm;
            if(left_sz >= right_sz) {
                crr_sm = left - right;
            }
            else {
                crr_sm = right - left;
            }
            int crr_sz = abs(right_sz - left_sz);
            
            ii cp = {crr_sm, crr_sz};
            
            ans += m[cp];
            
            int val = (ss[i] - '0');
            left -= val; 
            right += val;
            left_sz--;
            right_sz++;
        }

    }
    
//    ans -= n;
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    solve();
    
    return 0;
}
