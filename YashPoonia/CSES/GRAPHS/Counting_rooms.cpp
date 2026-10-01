#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<vector<bool>> visited;
vector<vector<char>> grid;
vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j)
{
    visited[i][j] = true;
    for (auto d : dir)
    {
        int dx = d[0];
        int dy = d[1];
        int new_x = i + dx;
        int new_y = j + dy;
        if (new_x < n && new_x >= 0 && new_y < m && new_y >= 0 && visited[new_x][new_y] != true && grid[new_x][new_y] == '.')
        {
            dfs(new_x, new_y);
        }
    }
}

void solve()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                dfs(i, j);
                rooms++;
            }
        }
    }
    cout << rooms << endl;
}

int main()
{
    solve();
    return 0;
}