#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> connections;
vector<int> parents;


void dfs(int index, int parent) {
	if (parents[index] == -1) {
		parents[index] = parent;

		for (int i : connections[index])
		{
			dfs(i, index);
		}
	}
	else {

	}
}

int main() {
	int n; int m;
	cin >> n >> m;
	connections.resize(n + 1);
	parents.resize(n + 1, -1);

	for (int i = 0; i < m; i++) {
		int a; int b;
		cin >> a >> b;
		a; b;
		connections[a].push_back(b);
		connections[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		if (parents[i] == -1) {
			dfs(i, 0);
		}
	}

}