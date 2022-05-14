#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> connections;
vector<int> parents;
vector<int>circle;

void circleFinder(int target, int index) {
	circle.push_back(index);
	if (target != parents[index]) {
		circleFinder(target, parents[index]);
	}
	else {
		circle.push_back(target);
		int circ = circle.size();
		cout << circ << endl;

		for (int i : circle) {
			cout << i << " ";
		}
		exit(0);
	}
}

void dfs(int index, int parent) {
		parents[index] = parent;

		for (int i : connections[index])
		{
			if (parents[i] == -1) {
				dfs(i, index);
			}
			else if (i != parent) {
				circle.push_back(i);
				circleFinder(i, index);
			}
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

	for (int i = 1; i <= n; i++)
	{
		if (parents[i] == -1) {
			dfs(i, 0);
		}
	}
	cout << "IMPOSSIBLE"<<endl;
	return(0);
}