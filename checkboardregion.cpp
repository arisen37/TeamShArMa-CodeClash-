#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {0, 0, -1, 1};

bool in(int x, int y) {
	if (x >= 0 && x < 10 && y >= 0 && y < 10) return true;

	return false;
}

void dfs(int x, int y, vector<string>& a, vector<vector<bool>>& vis, int& cnt) {
	vis[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; ++i) {
		int dupx = x + dx[i];
		int dupy = y + dy[i];

		if (in(dupx, dupy) && a[dupx][dupy] == '0' && !vis[dupx][dupy]) {
			dfs(dupx, dupy, a, vis, cnt);
		}
	}
}

int main() {

	vector<string> a(10, ".");

	for (int i = 0; i < 10; ++i) {
		cin >> a[i];
	}

	vector<bool> v(10, 0);
	vector<vector<bool>> vis(10, v);

	vector<int> b;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (a[i][j] == '0' && !vis[i][j]) {
				int cnt = 0;
				dfs(i, j, a, vis, cnt);
				b.push_back(cnt);
			}
		}
	}

	for (int i = 0 ; i < b.size() ; i++) {
		cout << b[i] << ' ';
	}

	return 0;
}
