#include <bits/stdc++.h>

#define endl ('\n')
#define print(x) cout << x << endl
#define print_s(x) cout << x << ' '

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

constexpr int inf = 3e5 + 100;
constexpr int mod = 1e9 + 7;
constexpr ll maxnum = 2e9 + 1;

ii maxday(vector<ii>& vec, int start, set<int>& peeked) {
    for (int i = start; i < sz(vec); ++i) {
        if (!has(peeked, vec[i].s)) {
            return vec[i];
        }
    }
    
    return {-1, -1};
}

bool comparevecless(vector<ii>& a, vector<ii>& b) {
    for (int i = 0; i < sz(a); ++i) {
        if (a[i].f < b[i].f) return true;
        if (a[i].f > b[i].f) return false;
        if (a[i].s == b[i].s) continue;     
    }
    
    return false;
}

pair<ii, char> peek_day(map<char, vector<ii>>& vecs, set<int>& peeked) {
    int maxval = -inf;
    vector<pair<ii, char>> maxes;
    fin(vec, vecs) {
       ii m = maxday(vec.s, 0, peeked);
       maxes.push_back({m, vec.f}); 
       maxval = max(m.f, maxval);
    }
    
    vector<pair<ii , char>> maxesf;
    fin(v, maxes) {
        if (v.f.f == maxval) maxesf.push_back(v);
    }

    if (sz(maxesf) == 1) {
       peeked.insert(maxesf[0].f.s);
       return maxesf[0];
    }
    
    else {
        pair<ii, char> minel = maxesf[0];
        for (int i = 1; i < sz(maxesf); ++i) {
            if (comparevecless(vecs[maxesf[i].s], vecs[minel.s])) {
               minel = maxesf[i];
            }     
        }

        peeked.insert(minel.f.s);
        return minel;
    }
}

void solve() {
    int n;
    cin >> n;
    map<char, vector<ii>> vecs = {{'a', vector<ii>(n)}, {'b', vector<ii>(n)}, {'c', vector<ii>(n)}};

    fin(vec, vecs) {
        for (int i = 0; i < n; ++i) {
            int val;  
            cin >> val;
            vec.s[i] = {val, i};
        } 
    }

    fin(vec, vecs) { 
       sort(all(vec.s), [](auto a, auto b) { return a.f > b.f; });
    }

    int ans = 0;
    set<int> peeked;
    for (int i = 0; i < 3; ++i) {
       auto peek = peek_day(vecs, peeked); 
       ans += peek.f.f;
       vecs.erase(peek.s);
    }

    print(ans);
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