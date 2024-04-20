#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <deque>
using namespace std;

constexpr double kInf = numeric_limits<double>::infinity();

template<typename T>
void Print(const vector<vector<T>>& dist)
{
	int V = dist.size();

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
			cout << setw(5) << dist[i][j];
		cout << endl;
	}
	cout << endl;
}

void Print(int i, int j, double w)
{
	cout << "(" << i << "," << j << "," << w << ")";
}

void PrintPaths(vector<int> prev)
{
	for (int i = 0; i < prev.size(); i++)
	{
		deque<int> path;
		path.push_front(i);
		int v = prev[i];
		while (v != -1)
		{
			path.push_front(v);
			v = prev[v];
		}

		for (auto v : path) {
			cout << v;
			if (v != path.back())
				cout << " -> ";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<double>> graph =
	{
		{0.0, 3.0, 8.0, kInf, -4.0},
		{kInf, 0.0, kInf, 1.0, 7.0},
		{kInf, 4.0, 0.0, kInf, kInf},
		{2.0, kInf, -5.0, 0.0, kInf},
		{kInf, kInf, kInf, 6.0, 0.0}
	};

	vector<vector<double>> dist = graph; // ���� �� ������Ʈ �ϴ� ���

	int V = graph.size();

	vector<vector<int>> prev(V, vector<int>(V));
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
		{
			if (i == j || graph[i][j] == kInf)
				prev[i][j] = -1;
			else
				prev[i][j] = i;
		}

	cout << "dist 0" << endl;
	Print(dist);
	cout << "prev 0" << endl;
	Print(prev);

	// ��Ʈ: ����-���带 ���� �� �ݺ��ϴ� ���
	//for (int s = 0; s < V; s++) // s�� ���� ����
	//{
	//	for (int v = 1; v < V; v++)
	//	{
	//		// CLRS ���翡���� Floyd-Warshall�� ������ �� �纻�� ���� ������Ʈ ����̶�
	//		// ���⼭�� ���ظ� ���� ���� Bellman-Ford�� ����ϰ� ������ �ٲ�ý��ϴ�.
	//		// �����, ��Ű�ǵ�ƿ����� �纻 ���� �ٷ� ����� in-place ����Դϴ�.
	//		auto dist_k = dist;
	//		auto prev_k = prev;

	//		// Bellman-Ford�� ���� ����Ʈ ��ſ� ���� ��� ���
	//		for (int i = 0; i < V; i++)
	//		{
	//			for (int j = 0; j < V; j++)
	//			{
	//				// TODO: grpah[][]�� dist[][]�� ����ؼ� dist_k�� prev_k ������Ʈ
	//			}
	//		}

	//		swap(dist_k, dist);
	//		swap(prev_k, prev);

	//		cout << "dist " << s + 1 << endl;
	//		Print(dist);
	//		cout << "prev " << s + 1 << endl;
	//		Print(prev);

	//		cout << "Paths " << s + 1 << endl;
	//		for (int i = 0; i < prev.size(); i++) {
	//			cout << "From " << i << " to others:" << endl;
	//			PrintPaths(prev[i]);
	//		}
	//	}
	//}

	for (int k = 0; k < V; k++)
	{
		auto dist_k = dist;
		auto prev_k = prev;

		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				// TODO: i -> j �� i -> k -> j ���ؼ� �ʿ��ϸ� ������Ʈ
			}
		}

		swap(dist_k, dist);
		swap(prev_k, prev);

		cout << "dist " << k + 1 << endl;
		Print(dist);
		cout << "prev " << k + 1 << endl;
		Print(prev);

		cout << "Paths " << k + 1 << endl;
		for (int i = 0; i < prev.size(); i++) {
			cout << "From " << i << " to others:" << endl;
			PrintPaths(prev[i]);
		}
	}
}
