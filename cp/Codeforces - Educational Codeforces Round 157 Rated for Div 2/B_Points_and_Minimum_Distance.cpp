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

int absv(int val) {
    if(val < 0) return val * -1;
    return val;
}

void solve() {
    map<int,int> ms;
    int np;
    cin >> np;
    for (int i = 0; i < np * 2; ++i) {
        int val;
        cin >> val;
        if(!has(ms, val)) {
            ms.insert({val, 1});
        }
        else ms[val]++;
    }
    
    vector<ii> points;
    int dist = 0;
    ii last;
    bool sum = false;
    for (int i = 0; i < np; ++i) {
        int minv = (minel(ms)).f; 
        int maxv = (maxel(ms)).f; 
        
        points.push_back({minv, maxv});
        if(sum) {
            dist += (abs(last.f - minv) + abs(last.s + maxv)); 
            sum = false;
        }
        else {
            last = {minv, maxv};
            sum = true;
        }
        
        if(ms[minv] == 0) {
            ms.erase(minv); 
        }
        else {
            ms[minv]--;
        }
        
        if(ms[maxv] == 0) {
            ms.erase(maxv);
        }
        else {
            ms[maxv]--;
        }
    }

    print(dist);

    fin(point, points) {
        print_s(point.f);
        print(point.s);
    }
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
