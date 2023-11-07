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
    cin >> n;
    ivec nums(n);
    int max = -inf;
    map<int,int> m; 
    
    for (int i = 0; i < n; ++i) {
       cin >> nums[i];
        if (nums[i] > max) max = nums[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        int start = i;
        while(i >= 0 && nums[i] == nums[i - 1]) {
            i--; 
        }
        
        m[nums[i]] = n - start;
    }
    
    ivec ff;
    for (int i = 1; i <= max; ++i) {
        ff.push_back(m[i]);
    }

    if(sz(ff) != sz(nums)) {
        print("NO");
        return;
    }

    for (int i = 0; i < n; ++i) {
        if(nums[n - 1 - i] != ff[i]) {
            print("NO");
            return;
        } 
    }

    print("YES");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nt;
    cin >> nt;

    while (nt--) {
        solve();
    }

    return 0;
}
