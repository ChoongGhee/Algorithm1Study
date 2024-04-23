#include <iostream> 
#include <vector>
#include <algorithm>
#include <iomanip>
#include <algorithm>
using namespace std;

// W�� ���� ����
// i�� �������� 1-based index
int RecurZeroOneKnapsack(const vector<int>& weights, const vector<int>& values, int W, int i)
{
	cout << "W = " << W << ", i = " << i << endl;

	// weights[i - 1] : ������ i�� ���� 

	if (i == 0 || W == 0)
		return 0;

	//if ( TODO )
	//{
	// // �� ���� �� �ִ� ���� w�� �����ؼ� �� �ִ� ���
	// // i�� ���� �ʴ´ٴ� ���� 0 ~ i-1 ������ �ִ´ٴ� �ǹ�
	// return RecurZeroOneKnapsack(weights, values, TODO, TODO);
	//}
	//else
	//{
	// // ���� �� �ִ� ��Ȳ
	// // �־��� ���� ���� �ʾ��� ���� ��
	//	return max(
	//		RecurZeroOneKnapsack(weights, values, TODO, TODO),
	//		RecurZeroOneKnapsack(weights, values, TODO, TODO) + values[i - 1]
	//	);
	// }

	return 0; // TODO: ����
}

int ZeroOneKnapsack(vector<int> weights, vector<int> values, int W)
{
	// table������ 1-based, weights�� values������ 0-based ���

	// table[w][i] : ��ġ�� ��
	vector<vector<int> > table(W + 1, vector<int>(weights.size() + 1, 0));
	vector<vector<vector<int>>> items(W + 1, vector<vector<int>>(weights.size() + 1, vector<int>(weights.size(), 0)));

	// ������ i�� ���Դ� weights[i - 1] 
	// ������ i�� ��ġ�� values[i - 1]

	for (int w = 1; w <= W; w++)
	{
		// ���԰� w�� �� � ������ i�� �߰��ϴ� ���� ������ �ƴ��� ��������
		for (int i = 1; i <= weights.size(); i++)
		{
			//if (i == 0 || w == 0)
			//{
			//	table[w][i] = 0; // ���ʿ�
			//}

			//if ( TODO ) // ������ i�� ���԰� ���� �� �ִ� ��������
			//{
			//	// ������ i�� �ִ� ���� ������ �ƴϸ� ���� �ʴ� ���� ������ ��
			//	// ��Ʈ: table[w - weights[i - 1]][i - 1] ������ i�� ���� ������ �ִ� ������ �� ��ġ
			//	//       table[w - weights[i - 1]][i - 1] + values[i - 1] ������ i�� �־ ���Ը� w�� ������ ���� ��ġ
			//	if ( TODO )
			//	{
			//		// ������ i�� ���� �ʾ��� ��

			//		table[w][i] = TODO;

			//		items[w][i] = TODO; // ���縸
			//	}
			//	else
			//	{
			//		// ������ i�� �־��� ��

			//		table[w][i] = TODO;

			//		items[w][i] = TODO;
			//		items[w][i][i - 1] += 1; // ������ i �ϳ� ����
			//	}
			//}
			//else
			//{
			//	table[w][i] = table[w][i - 1];
			//	items[w][i] = items[w][i - 1];
			//}
		}
	}

	cout << table[W][weights.size()] << endl;
	for (int i = 0; i <= weights.size(); i++)
	{
		cout << i << ": ";
		for (int w = 0; w <= W; w++)
			cout << right << setw(4) << table[w][i];
		cout << endl;
	}
	cout << endl;

	cout << "Weight:";
	for (int w = 0; w <= W; w++)
		cout << right << setw(4) << w;
	cout << endl << endl;

	cout << "Items count" << endl;
	for (int i = 0; i <= weights.size(); i++)
	{
		cout << "Item " << i << ": ";
		for (int w = 0; w <= W; w++) {
			for (int j = 0; j < weights.size(); j++)
				cout << items[w][i][j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Values per item" << endl;
	for (int i = 0; i <= weights.size(); i++)
	{
		cout << "Item " << i << ": ";
		for (int w = 0; w <= W; w++) {
			for (int j = 0; j < weights.size(); j++)
				cout << items[w][i][j] * values[j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Weights per item" << endl;
	for (int i = 0; i <= weights.size(); i++)
	{
		cout << "Item " << i << ": ";
		for (int w = 0; w <= W; w++) {
			for (int j = 0; j < weights.size(); j++)
				cout << items[w][i][j] * weights[j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	return table[W][weights.size()];
}

int main()
{
	vector<int> values = { 6, 5, 3 };
	vector<int> weights = { 3, 2, 1 };
	int W = 5;

	cout << RecurZeroOneKnapsack(weights, values, W, int(weights.size())) << endl;
	cout << ZeroOneKnapsack(weights, values, W) << endl;

	return 0;
}
