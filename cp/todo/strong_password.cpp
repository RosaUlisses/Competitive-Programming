#include <bits/stdc++.h>
#include <chrono>
#include <random>

#define RED ("\033[31m")
#define WHITE ("\033[0m")
#define reset() cout << WHITE
#define print(x) cout << RED << x
#define cout(x) cout << x
#define endl ('\n')
#define pb push_back
#define add insert
#define has(x, y) (x.find(y) != x.end())
#define all(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int,int>;

constexpr int inf = 2e9+1;
constexpr int mod = 1e9+7;
constexpr ll maxnum = 3e5+100;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

int to_int(char c) {
    return c - '0';
}

bool db_contains(map<char,vector<int>>& indexes, string& s, int index) {
}

bool in_data_base(string& db, string& l, string& r, string current, int index, map<char, vector<int>>& indexes) {
    int li = to_int(l[index]);
    int ri = to_int(r[index]);

    if (current.size() == r.size()) {
        for (auto c : current) {
            if (has(indexes, c)) {
                
            } 
        } 
    }


    
    for (int i = li; i <= ri; ++i) {
        if (in_data_base(db, l, r, current + to_string(i), index + 1, indexes)) {
            return true;
        }    
    }
    
    return false;
}

void solve() {
    string db;
    int n;
    cin >> db >> n;
    string l, r;
    cin >> l >> r;
    
    map<char,vector<int>> indexes;

    for (int i = 0; i < db.size(); ++i) {
        if (!has(indexes, db[i])) {
            indexes.insert({db[i], {i}});
        } 
        else indexes[db[i]].push_back(i);
    }

    if (in_data_base(db, l, r, "", 0, indexes)) {
        print("YES\n");
    }
    else print("NO\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int nt;
	cin >> nt;

	while(nt--) {
        reset(); 
		solve();
	}

	return 0;
}
