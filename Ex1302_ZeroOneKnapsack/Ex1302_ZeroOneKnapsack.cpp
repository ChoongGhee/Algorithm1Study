#include <iostream> 
#include <vector>
#include <algorithm>
#include <iomanip>
#include <algorithm>
using namespace std;

// �뷮 W�� n������ ���������� ä�� ��� ���� �� �ִ� �� ��ġ�� �ִ밪 ��ȯ
// n������ �������̶�� ���� �ǹ̴� ������ 1, 2, ..., n �� ������ ������ ����ߴٴ� �ǹ�
// W�� �� ���� ���, n�� �� ���� ��쿡 ���� ���ȣ���ϴ� ���� -> ǥ ���鶧�� �ݴ� ������ W�̳� n�� �� ���� ������ ä�������� �ȴٴ� �ǹ�

int RecurZeroOneKnapsack(const vector<int>& weights, const vector<int>& values, int W, int n)
{
	cout << "W = " << W << ", n = " << n << endl;

	// �ε��� ����
	// weights[n-1] n��° �������� ����
	// values[n-1]  n��° �������� ��ġ(����)

	if (n == 0 || W == 0)
	{
		return 0;
	}

	/*
	if ( TODO: �뷮 W�� �����ؼ� weights[n - 1]�� ���� �� ���ٸ� )
	{
		return TODO: n��° �������� ���� �ʴ� ����Ʈ���� ������ (�뷮�� �״��)
	}
	else
	{
		// n��° �������� ���� �ʴ� ���� �ִ� ��� �� �� ū ��
		// Case 1. ���� �ʴ� ���: n-1���� �����۸� ����ϴ� ��쿡 ���� ���ȣ��
		// Case 2. �ִ� ���: n��° �������� �� �뷮�� �̸� ������ (Ȯ���س���) n-1���� �����۸� ����ϴ� ��쿡 ���� ���ȣ��
		//                   ���ȣ�� ����� �״�� ����ϸ� �ȵǰ� ���� ������� �մϴ�.

		return max(
			TODO, // Case 1
			TODO, // Case 2
		);
	}
	*/

	return 0; // TODO: ����
}

int ZeroOneKnapsack(vector<int> weights, vector<int> values, int W)
{
	//����: table������ 1-based, weights�� values������ 0-based ���
	//     ������ i�� ���Դ� weights[i - 1] 
	//     ������ i�� ��ġ�� values[i - 1]
	//     table[w][n] : ���԰� w�̰� �������� n������ ������� �� ��ġ�� �� (������ n�� ����ߴٴ� ���� �ƴ϶� 1, ..., n�� ��� ����ߴٴ� �ǹ�)

	vector<vector<int> > table(W + 1, vector<int>(weights.size() + 1, 0)); // ��� 0���� �ʱ�ȭ (�Ʒ� �������� w = 0 �Ǵ� n = 0�� ��� ����)
	vector<vector<vector<int>>> items(W + 1, vector<vector<int>>(weights.size() + 1, vector<int>(weights.size(), 0))); // ����� �����, ��� ���� ����

	//��Ʈ: RecurZeroOneKnapsack()�ϰ� ������� �����غ�����.

	for (int w = 1; w <= W; w++)
	{
		for (int n = 1; n <= weights.size(); n++)
		{
			// ��Ʈ: ���ȣ�� �ϴ� ��ſ� ���� ���Ǿ table�� ����Ǿ� �ִ� �� ���

			/*
			if ( TODO ) // ������ weights[n - 1]�� �뷮�ʰ��� ���� �� ���� ���
			{
				table[w][n] = TODO
				items[w][n] = TODO
			}
			else
			{
				if (table[w][n - 1] > table[w - weights[n - 1]][n - 1] + values[n - 1]) // Case 1: ���� �ʴ� ���
				{
					table[w][n] = table[w][n - 1];
					items[w][n] = items[w][n - 1];
				}
				else // Case 2: �ִ� ���
				{
					table[w][n] = TODO
					items[w][n] = items[w - weights[n - 1]][n - 1];
					items[w][n][n - 1] += 1; // �ȳ�: ���� ������ [n-1]�� 0-based indexing�̶� -1 �߰�
				}
			}
			*/
		}
	}

	using std::cout;

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

	// ��ü �뷮 W�� ���� ��� �������� ����ϴ� n = weights.size()�� ���ȣ�� ����
	std::cout << RecurZeroOneKnapsack(weights, values, W, int(weights.size())) << endl;

	std::cout << ZeroOneKnapsack(weights, values, W) << endl;

	return 0;
}
