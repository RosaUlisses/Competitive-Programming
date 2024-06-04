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
    map<int,int> m;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if(!has(m,nums[i])) m[nums[i]] = 1;
        else m[nums[i]]++;
    }
    
    int sim = 0;
    vector<int> simples;
    fin(p, m) {
        if (p.s >= 2) {
            sim++; 
            simples.push_back(p.f);
        } 
    }
    
    if(sim < 2) {
        print(-1);
        return;
    }


    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == simples[0]) {
            if(count1 == 0 || count1 > 1) {
                nums[i] = 1;
            } 
            else nums[i] = 2; 
            count1++;
        }
        else if (nums[i] == simples[1]) {
            if(count2 == 0 || count2 > 1) {
                nums[i] = 2;
            }
            else nums[i] = 3;
            count2++;
        }
        else nums[i] = 1;
    }

    fin(v, nums) {
        print_s(v);
    }
    print("");
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
