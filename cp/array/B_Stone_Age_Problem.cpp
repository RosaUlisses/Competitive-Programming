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
    int n, nq;
    cin >> n >> nq;
    
    ivec nums; 
    int sum = 0;
    map<int,int> alt;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        alt.insert({i, nums[i]});
    }
    
    bool equal = false;

    int eq = -1;
    
    for (int i = 0; i < nq; ++i) {
        int q; 
        cin >> q;
        if (q == 1) {
           int ix, num; 
           cin >> ix >> num;
            
           if(equal) {
               sum = sum - (eq - num);
               alt.insert({ix, num});
               equal = false;
           }

            else {
                if(has(alt, ix)) {
                    sum = sum - (alt[ix] - num);
                    alt.insert({ix, num});
                }
                else {
                    sum = sum - (eq - num);
                    alt.insert({ix, num});
                }
            } 
           
        }
        else if(q == 2) {
            int num;
            cin >> num;
            equal = true;
            sum = num * n;
            print(sum);
            eq = num;
            alt = {};
        }

        print(sum);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
