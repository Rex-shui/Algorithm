#include <iostream>
#include <vector>

/*
 * 买卖股票的最佳时机
 *
 * 给定一个数组，代表股票每天的价格
 * 可存在多笔交易，但必须在再次购买前出售掉已有股票
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
 * */

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int (*dp)[2] = new int[n][2];

        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];

        for(int i=1; i<n; i++) {
            
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);

        }

        return dp[n-1][0];
    }
};

int main()
{
	Solution s;
	int p[] = {7, 1, 5, 3, 6, 4};
	vector<int> prices(p, p+6);

	cout << s.maxProfit(prices) << endl;
	
	return 0;
}
