#include <iostream>

using namespace std;

/*
 * 求 word1 ==> word2 的最短编辑距离
 * 每次只能增加、删除、修改一个字母
 * 如 horse ==> ros 需要 3 步
 * horse ==> rorse ==> rose ==> ros
 *
 * */

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length();
        int m = word2.length();

        int **dp = new int*[n+1];

        for(int i=0; i<n+1; i++)
        {
            int *col = new int[m+1];
            dp[i] = col;
            dp[i][0] = i;
        }
        for(int j=0; j<m+1; j++)
        {
            dp[0][j] = j;
        }

        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                int left = dp[i-1][j] + 1;
                int down = dp[i][j-1] + 1;
                int left_down = dp[i-1][j-1];

                if(word1[i-1] != word2[j-1]) left_down += 1;

                dp[i][j] = min(left, min(down, left_down));
            }
        }

        return dp[n][m];
    }
};

int main()
{
	Solution s;
	cout << s.minDistance("cout", "cin") << endl;
	return 0;
}
