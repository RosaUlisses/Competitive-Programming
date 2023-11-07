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
    
    fin(v, nums) {
        cin >> v;
    }

    int max_m = 0;
    int val = 1;
   
    while(val * 2 <= n) {
        max_m++;
        val *= 2;
    }

    if (val < sz(nums) - 1) {
        for (int i = val; i < sz(nums); ++i) {
            if(i + 1 >= sz(nums)) {
                break;
            }
            if(nums[i] > nums[i + 1]) {
                print("NO");
                return;
            }     
        } 
    }

    for (int i = 1; i <= max_m; ++i) {
        int start = pow(2, i);
        int end = 2 * start;
        for (int j = start; j < end - 1; ++j) {
            if (j + 1 >= sz(nums)) {
                break;
            }
            if (nums[j] > nums[j + 1]) {
                print("NO");
                return;
            } 
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
