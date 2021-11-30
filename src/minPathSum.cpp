#include <iostream>
#include <vector>

using namespace std;

//给定一个 m × n 的矩阵
//求左上角到右下角的最短距离


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(i == 0 && j != 0) grid[i][j] = grid[i][j] + grid[i][j-1];
                else if(i !=0 && j == 0) grid[i][j] = grid[i][j] + grid[i-1][j];
                else if(i == 0 && j == 0) grid[i][j] = grid[i][j];
                else grid[i][j] = min(grid[i][j] + grid[i-1][j], grid[i][j] + grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];
    }
};

int main()
{
	Solution a;
	vector<vector<int>> grid = {{1,3,1}, {1,5,1}, {4,2,1}};
	cout << a.minPathSum(grid) << endl;
	for(int i=0 ; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
