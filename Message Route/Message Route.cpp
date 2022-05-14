#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dist;
vector<int> visited;
vector<vector<int>> connections;
queue<int> sor;
vector<int> parent;
vector<int> route;
int n, m;



void bfs(int index) {
	while (sor.size()<0) {
		for (int i : connections[index]) {
			if (visited[i] == 0)
			{
				parent[i] = index;
				
				dist[i] = dist[index] + 1;
				sor.push(i);
				sor.pop();
				visited[i] = 1;
			}
		}
	}
}


int main()
{
    cin >> n >> m;
	connections.resize(n + 1); visited.resize(n + 1, 0); dist.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		connections[a].push_back(b);
		connections[b].push_back(a);
	}
	sor.push(1);
	bfs(1);

	cout << dist[n]<<endl;
	int tracker = 0;
	cout << n << " ";
	for (int i = 0; i < dist[n]; i++)
	{
		cout << parent[tracker]<<" ";
		tracker = parent[tracker];
	}

}