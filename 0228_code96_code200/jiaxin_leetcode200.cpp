#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int width;
    int height;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y]='0';
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<height&&xx>=0&&yy<width&&yy>=0&&grid[xx][yy]=='1')
            dfs(grid,xx,yy);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (!grid.size())
            return 0;
        height = grid.size();
        width = grid[0].size();
        int island_size = 0;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                if (grid[i][j] == '1')
                {
                    island_size++;
                    dfs(grid, i, j);
                }
            }
        return island_size;
    }
};