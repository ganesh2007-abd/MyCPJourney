#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<char>> grid;
vector<vector<bool>> visited;

vector<char> dir = {'U', 'D', 'L', 'R'};
vector<int> row = {-1, 1, 0, 0};
vector<int> col = {0, 0, -1, 1};
vector<vector<char>> prevdir;

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));
    prevdir.resize(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);

    int found = false;

    while (!q.empty() && !found)
    {
        auto curr = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int newrow = curr.first + row[d];
            int newcol = curr.second + col[d];
            if (newrow < n && newrow >= 0 && newcol < m && newcol >= 0 && grid[newrow][newcol] != '#' && !visited[newrow][newcol])
            {
                visited[newrow][newcol] = true;
                q.push(make_pair(newrow, newcol));
                prevdir[newrow][newcol] = dir[d];

                if (grid[newrow][newcol] == 'B')
                {
                    found = true;
                    break;
                }
            }
        }
    }

    if (!visited[end.first][end.second])
    {
        cout << "NO" << endl;
        return 0;
    }
    string path = "";
    pair<int, int> curr = end;
    while (curr != start)
    {
        auto d = prevdir[curr.first][curr.second];
        int idx = find(dir.begin(), dir.end(), d) - dir.begin();
        curr.first -= row[idx];
        curr.second -= col[idx];
        path += d;
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.length() << endl;
    cout << path << endl;
}