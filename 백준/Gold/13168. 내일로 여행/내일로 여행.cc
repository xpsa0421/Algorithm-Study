#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string, int> cityToIdx;
vector<int> route;
unordered_set<string> freeTypes = { "Mugunghwa", "ITX-Saemaeul", "ITX-Cheongchun" };
unordered_set<string> halfTypes = { "S-Train", "V-Train" };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// Input
	int n, r;
	cin >> n >> r;

	// Cities
	int cityIdx = 0;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if (cityToIdx.find(s) == cityToIdx.end())
		{
			cityToIdx[s] = cityIdx;
			cityIdx++;
		}
	}
	
	// Route
	int m; cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s; cin >> s;
		route.push_back(cityToIdx[s]);
	}

	// Update distance
	const double INF = 20000000;
	int numCities = cityToIdx.size();
	vector<vector<double>> normalDist(numCities, vector<double>(numCities, INF));
	vector<vector<double>> saleDist(numCities, vector<double>(numCities, INF));

	int k; cin >> k;
	for (int i = 0; i < k; i++)
	{
		string type, s, e; double c;
		cin >> type >> s >> e >> c;
		int start = cityToIdx[s], end = cityToIdx[e];
		
		normalDist[start][end] = min(normalDist[start][end], c);
		normalDist[end][start] = min(normalDist[end][start], c);

		if (freeTypes.find(type) != freeTypes.end())
		{
			saleDist[start][end] = 0;
			saleDist[end][start] = 0;
		}
		else if (halfTypes.find(type) != halfTypes.end())
		{
			saleDist[start][end] = min(saleDist[start][end], c / 2.0);
			saleDist[end][start] = min(saleDist[end][start], c / 2.0);
		}
		else
		{
			saleDist[start][end] = min(saleDist[start][end], c);
			saleDist[end][start] = min(saleDist[end][start], c);
		}
	}

	// Floyd	
	for (int k = 0; k < numCities; k++)
	{
		for (int i = 0; i < numCities; i++)
		{
			for (int j = 0; j < numCities; j++)
			{
				if (normalDist[i][k] != INF && normalDist[k][j] != INF)
					normalDist[i][j] = min(normalDist[i][j], normalDist[i][k] + normalDist[k][j]);

				if (saleDist[i][k] != INF && saleDist[k][j] != INF)
					saleDist[i][j] = min(saleDist[i][j], saleDist[i][k] + saleDist[k][j]);
			}
		}
	}

	// Calculate cost
	double normalCost = 0, saleCost = r;
	for (int i = 1; i < route.size(); i++)
	{
		normalCost += normalDist[route[i - 1]][route[i]];
		saleCost += saleDist[route[i - 1]][route[i]];
	}

	// Print
	if (saleCost < normalCost) cout << "Yes";
	else cout << "No";
}