#include <iostream>
#include <vector>

using namespace std;

/*
 * 八皇后问题：将8个棋子摆在8×8的棋盘上，确保行、列、斜线上不相交
 *
 * 思路：
 * 1、按行顺序摆放棋子
 * 2、设置列、斜线、反斜线安全状态位
 * 3、递归调用，而后恢复状态位
 * */



vector<int> lineNum(8, 0);
vector<int> colSafe(8, 1);
vector<int> slashSafe1(15, 1);	//斜线    /     i+j = (i-1) + (j+1)
vector<int> slashSafe2(15, 1);	//反斜线  \     i-j = (i+1) - (j+1)
vector<vector<int>> all;

int count = 0;

void position(int row)
{
	if(row == 8)
	{
		all.push_back(lineNum);
		count++;
		return;
	}
	
	for(int i=0; i<8; i++)
	{
		if(colSafe[i] && slashSafe1[row + i] && slashSafe2[row - i + 7])
		{
			lineNum[row] = i;
			colSafe[i] = slashSafe1[row + i] = slashSafe2[row - i + 7] = 0;
			position(row + 1);
			colSafe[i] = slashSafe1[row + i] = slashSafe2[row - i + 7] = 1;
		}
	}
}

int main()
{
	position(0);
	for(int i=0; i<all.size(); i++)
	{
		for(int j=0; j<all[i].size(); j++)
		{
			cout << all[i][j] << " ";
		}
		cout << endl;
	}
	cout << count << endl;
	return 0;
}
