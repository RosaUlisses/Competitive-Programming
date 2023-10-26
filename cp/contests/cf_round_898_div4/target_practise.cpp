#include <bits/stdc++.h>
#define cout(x) cout << x

using namespace std;

using ii = pair<int,int>;

bool is_edge(ii p, int start, int end) {
    if (p.first == p.second) return true;
    if (p.first == start && p.second == end) return true;
    if (p.first == end && p.second == start) return true;
    return false;
}

int get_round(int start, int end, vector<vector<char>>& matrix, int count) {
    if (start > end) return 0; 
    int sum = 0;
      

    if (matrix[start][end] == 'X') sum += count;
    if (matrix[end][start] == 'X') sum += count;
    if (matrix[start][start] == 'X') sum += count;
    if (matrix[end][end] == 'X') sum += count;
    
    for (int i = start; i <= end; ++i) {
       if (matrix[start][i] == 'X' && !is_edge({start, i}, start, end)) sum += count;
        if (matrix[end][i] == 'X' && !is_edge({end, i}, start, end)) sum += count;
        if (matrix[i][start] == 'X' && !is_edge({i, start}, start, end)) sum += count;
        if (matrix[i][end] == 'X' && !is_edge({i, end}, start ,end)) sum += count;
    } 
    
    return sum + get_round(start + 1, end - 1, matrix, count + 1);
}

void solve() {
    vector<vector<char>> matrix(10);
    for (int i = 0; i < 10; ++i) {
        matrix[i] = vector<char>(10);
        for (int j = 0; j < 10; ++j) {
            cin >> matrix[i][j];         
        } 
    }
    
    cout(get_round(0, 9, matrix, 1)) << "\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int nt;
	cin >> nt;

	while(nt--) {
		solve();
	}

	return 0;
}
