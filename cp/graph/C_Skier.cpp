#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

#define midp(x, y) ((x + y) / 2)
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()
#define sz(x) (x.size())
#define lix(x) (x.size() - 1)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using ivec = vector<int>;
using str = string;

constexpr int inf = 2e9 + 1;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 3e5 + 100;

void solve() {
    str mvs; 
    cin >> mvs;
    
    ll acc = 0;
    set<pair<ii, ii>> v;
    ii curr = {0, 0};
    
    for (char m : mvs) {
        ii next; 
        if(m == 'N') {
            next = {curr.first + 1, curr.second};
        } 
        else if(m == 'S') {
            next = {curr.first - 1, curr.second};
        }
        else if(m == 'E') {
            next = {curr.first, curr.second + 1};
        }
        else if(m == 'W'){
            next = {curr.first, curr.second - 1};
        }
        
        pair<ii,ii> og = {curr, next};
        pair<ii,ii> rev = {next, curr};

        if(has(v, og) || has(v, rev)) {
            acc += 1;
        } 
        else {
            acc += 5;
            v.insert(og);
        }
        
        curr = next;
    }

    print(acc);
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
