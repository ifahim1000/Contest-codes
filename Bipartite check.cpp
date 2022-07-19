bool dfs(int s, int par, vector<vector<int>> &graph, vector<int> &col, int color)
{
	col[s] = color;
	for (auto nbr : graph[s])
	{
		if (nbr != par)
		{
			if (col[nbr] == 0)
			{
				if (dfs(nbr, s, graph,col, 3 - color))
				{
					return true;
				}
			}
			else if (col[nbr] == color)
			{
				return true;
			}
		}
	}
	return false;
}

bool isBipartite(vector<vector<int>>& graph)
{
  // check n
	int n = graph.size();
	vector<int> col(n, 0);
	for (int i = 0; i < n; i++)  // change n according to constraints
	{
		if (col[i] == 0)
		{
			if(dfs(i, -1, graph, col, 1))
			{
				return false;
			}
		}
	}
	return true;
}
