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

void dfs(map<int, ivec>& tree, int vertex, set<int>& visited, vector<vector<int>>& paths, vector<int>& curr) {
    visited.insert(vertex); 
    curr.push_back(vertex);
    
    if(tree[vertex].empty()) {
        paths.push_back(curr);
        curr.clear();
        return;
    }

    fin(v, tree[vertex]) {
        if(has(visited, v)) continue;
        dfs(tree, v, visited, paths, curr);
    }
}

void solve() { 
    int n;
    cin >> n;
    
    int root;
    map<int, ivec> tree;

    for (int i = 0; i < n; ++i) {
        int val; 
        cin >> val;
        if(i == val) root = i;
        if (!has(tree, i)) {
            tree[val] = { i };
        }
        else tree[val].push_back(i);
    }
    
    vector<vector<int>> paths;
    vector<int> curr;
    set<int> visited;

    dfs(tree, root, visited, paths, curr);

    print(sz(paths));
    
    fin(p, paths) {
        print(sz(p));
        fin(v, p) {
            print_s(v);
        }
        print("");
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
