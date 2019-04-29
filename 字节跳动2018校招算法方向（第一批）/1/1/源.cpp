/*P为给定的二维平面整数点集。定义 P 中某点x，如果x满足 P 中任意点都不在 x 的右上方区域内（横纵坐标都大于x），则称其为“最大的”。求出所有“最大的”点的集合。（所有点的横坐标和纵坐标都不重复, 坐标轴范围在[0, 1e9) 内）
如下图：实心点为满足条件的点的集合。请实现代码找到集合 P 中的所有 ”最大“ 点的集合并输出。*/
//该代码超时，通过50%
/*#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct node
{
	int position_x;
	int position_y;
};

bool compare(node pos1, node pos2)
{
	return pos1.position_x < pos2.position_x;
}

int main()
{
	vector<node> position;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			node Node;
			int x;
			cin >> x;
			int y;
			cin >> y;
			Node.position_x = x;
			Node.position_y = y;
			position.push_back(Node);
		}
		sort(position.begin(), position.end(),compare);
		for (int i = 0; i < position.size()-1; ++i)
		{
			for (int j = i + 1; j <= position.size(); ++j)
			{
				if (j == position.size())
				{
					cout << position[i].position_x << ' ' << position[i].position_y << endl;
					break;
				}
				if (position[j].position_y > position[i].position_y)
					break;
			}
		}
		cout << position[n - 1].position_x << ' ' << position[n - 1].position_y << endl;

	}
	return 0;
}*/
/*#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 500010;
struct node
{
	int position_x;
	int position_y;
}Node[MAX];

bool compare(node pos1, node pos2)
{
	return pos1.position_x < pos2.position_x;
}

int main()
{
	//vector<node> position;
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			//node Node;
			int x;
			cin >> x;
			int y;
			cin >> y;
			Node[i].position_x = x;
			Node[i].position_y = y;
			//position.push_back(Node);
		}
		sort(Node, Node+n, compare);
		//int len = position.size();
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (j == n)
				{
					cout << Node[i].position_x << ' ' <<Node[i].position_y << endl;
					break;
				}
				if (Node[j].position_y >Node[i].position_y)
					break;
			}
		}
		cout << Node[n - 1].position_x << ' ' << Node[n - 1].position_y << endl;

	}
	return 0;
}*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstdio>

using namespace std;

const int MAX = 500000 + 10;
struct node
{
	int position_x;
	int position_y;
}Node[MAX];

bool compare(node pos1, node pos2)
{
	return pos1.position_x > pos2.position_x;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			int y;
			cin >> y;
			Node[i].position_x = x;
			Node[i].position_y = y;
		}
		sort(Node, Node+n, compare);

		stack<node> s;

		int maxy = -1;
		for (int i = 0; i < n; ++i)
		{
			if (maxy <= Node[i].position_y)
			{
				maxy = Node[i].position_y;
				s.push(Node[i]);
			}
		}
		node tmp;
		while (!s.empty())
		{
			tmp = s.top();
			s.pop();
			printf("%d %d\n", tmp.position_x, tmp.position_y);//麻痹的printf要快于并且case通过率好于cout！！！！
		}
	}
	return 0;
}
