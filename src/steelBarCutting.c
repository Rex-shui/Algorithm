#include <stdio.h>

//给定一段长度为n的钢条，求钢条切割方案，使销售收益最大
//长度1~10的钢铁价格
int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int max(int a, int b)
{
	return a>b?a:b;
}

int steelBarCutting(int *r, int n)
{
	for(int i=0; i<n; i++)
	{
		int q = price[i];
		for(int j=0; j<i/2+1; j++)
		{
			q = max(q, r[j] + r[i-j-1]);
		}
		r[i] = q;
	}
	return r[n-1];
}

int main()
{
	int r[10] = {0};
	printf("%d\n", steelBarCutting(r, 10));
	for(int i=0; i<10; i++) {
		printf("%d  ", r[i]);
	}
	printf("\n");
	return 0;
}
