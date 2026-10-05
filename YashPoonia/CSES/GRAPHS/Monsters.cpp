#include <bits/stdc++.h>
using namespace std;

vector<char> directions = {'U', 'D', 'L', 'R'};
vector<int> dy = {0, 0, -1, 1};
vector<int> dx = {-1, 1, 0, 0};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    vector<vector<char>> parent(n, vector<char>(m));
    // vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> monster_time(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'M')
            {
                q.push({i, j});
                monster_time[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && monster_time[nx][ny] > monster_time[x][y] + 1)
            {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    pair<int, int> start, end = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }

    bool done = false;
    queue<pair<int, int>> q2;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    q2.push(start);
    visited[start.first][start.second] = true;
    while (!q2.empty() && !done)
    {
        auto curr = q2.front();
        q2.pop();
        int x = curr.first;
        int y = curr.second;
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            done = true;
            end = {x, y};
        }
        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#' && dist[x][y] + 1 < monster_time[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + 1;
                q2.push({nx, ny});
                parent[nx][ny] = directions[d];
                visited[nx][ny] = true;
            }
        }
    }

    if (!done)
    {
        cout << "NO" << endl;
        return 0;
    }

    string path = "";
    auto curr = end;
    while (curr != start)
    {
        int x = curr.first;
        int y = curr.second;
        int dir = parent[x][y];
        int idx = find(directions.begin(), directions.end(), dir) - directions.begin();
        path += dir;
        curr.first -= dx[idx];
        curr.second -= dy[idx];
    }
    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
}
