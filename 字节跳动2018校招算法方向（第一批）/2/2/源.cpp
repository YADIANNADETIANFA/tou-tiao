//数组是不允许排序打乱的；这道题为leetcode 84题，区别就在于，这里每个矩形是不等宽的，但是丝毫不影响
#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n+2);
		vector<int> cusum(n+2);
		stack<int> stk;
		nums[0] = 0;//如果vector<int> nums不设定初始大小，这里会报错，超出vector范围！！！！
		for (int i = 1; i <= n; ++i)
		{
			cin >> nums[i];//直接读进来，不要二传手！！！！！！
		}
		nums[++n] = 0;//n改变了这里
		stk.push(0);
		cusum[0] = nums[0];
		for (int i = 1; i <= n; ++i)
			cusum[i] = cusum[i - 1] + nums[i];//不等宽的原因，用它是为了计算宽度时使用
		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			while (nums[i] < nums[stk.top()])
			{
				int height = nums[stk.top()];
				stk.pop();
				int weight = cusum[i - 1] - cusum[stk.top()];
				res = max(res, height*weight);
			}
			stk.push(i);
		}
		cout << res << endl;
	}
	return 0;
}