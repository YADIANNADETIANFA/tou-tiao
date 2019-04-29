//�����ǲ�����������ҵģ������Ϊleetcode 84�⣬��������ڣ�����ÿ�������ǲ��ȿ�ģ�����˿����Ӱ��
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
		nums[0] = 0;//���vector<int> nums���趨��ʼ��С������ᱨ������vector��Χ��������
		for (int i = 1; i <= n; ++i)
		{
			cin >> nums[i];//ֱ�Ӷ���������Ҫ�����֣�����������
		}
		nums[++n] = 0;//n�ı�������
		stk.push(0);
		cusum[0] = nums[0];
		for (int i = 1; i <= n; ++i)
			cusum[i] = cusum[i - 1] + nums[i];//���ȿ��ԭ��������Ϊ�˼�����ʱʹ��
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