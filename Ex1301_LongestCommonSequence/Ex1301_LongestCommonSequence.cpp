#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// X���� ù m����, Y���� ù n���ڿ� ���� LCS�� ã�� �Լ�
string RecurLCS(const string& X, const string& Y, int m, int n)
{
	if (m == 0 || n == 0)
		return string("");

	/*
	if (X[m - 1] == Y[n - 1])
	{
		return TODO:
	}
	else
	{
		string s1 = TODO:
		string s2 = TODO:

		return s1.size() >= s2.size() ? s1 : s2;
	}
	*/

	return string(""); // TODO: ���ʿ�, ����
}

int RecurLengthLCS(const string& X, const string& Y, int m, int n)
{
	if (m == 0 || n == 0)
		return 0;

	/*
	if (X[m - 1] == Y[n - 1])
		return TODO
	else
		return max(TODO, TODO);
	*/

	return 0; // TODO: ���ʿ�, ����
}

void PrintLCS(const vector<vector<char>>& prev, const string& X, int i, int j)
{
	if (i == 0 || j == 0)
		return;

	if (prev[i][j] == '\\')
	{
		PrintLCS(prev, X, i - 1, j - 1);
		cout << X[i - 1]; // ����: -1
	}
	else if (prev[i][j] == '|')
	{
		PrintLCS(prev, X, i - 1, j);
	}
	else
	{
		PrintLCS(prev, X, i, j - 1);
	}
}

int BottomUpLCS(const string& X, const string& Y, int m, int n)
{
	// ����: ���ڿ��� table�� �ε��̿� �ϰ����� ��� �򰥸� �� �ֽ��ϴ�.
	//       table�� 1-base �ε���, X�� Y�� 0-base �ε���
	//       table[i][j]: X�� ���̰� i�̰� Y�� ���̰� j�� ��츦 �ǹ�
	//       table���� 1-base�� ����ϴ� ������ i�� j�� 0�� base case�鵵 ���Խ�Ű�� ���ؼ� �Դϴ�.

	// ����Ǯ���Ҷ��� ���� table ä���� �ִ� ���̸� ã�� ���� ��ǥ�Դϴ�.
	// �߰������� prev�� lcs�� �����ϴ� ������ ���ظ� ���� ���ؼ� �Դϴ�.
	vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
	vector<vector<char>> prev(m + 1, vector<char>(n + 1, ' '));

	vector<vector<string>> lcs(m + 1, vector<string>(n + 1, ""));
	// prev���� ���� ��Ʈ�� ȭ��ǥ�� ���ڷ� ����, PrintLCS() ����

	// ���⼭ i, j�� X�� Y�� ���̸� �ǹ� (1-base)
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			/*
			if (X[i - 1] == Y[j - 1]) // ����: i - 1, j - 1
			{
				table[i][j] = TODO;

				prev[i][j] = '\\'; // [i-1][j-1]���� �����Դٴ� �ǹ�
				lcs[i][j] = TODO;
			}
			else if (table[i - 1][j] >= table[i][j - 1])
			{
				table[i][j] = TODO;

				prev[i][j] = '|'; // [i-1][j]���� �����Դٴ� �ǹ�
				lcs[i][j] = TODO;
			}
			else
			{
				table[i][j] = TODO;

				prev[i][j] = '-'; // [i][j-1]���� �����Դٴ� �ǹ�
				lcs[i][j] = TODO;
			}
			*/
		}
	}

	// ���� ǥ(tabulation) Ȯ�ο�

	cout << table[m][n] << endl;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << left << setw(3) << table[i][j];
		cout << endl;
	}
	cout << endl;

	cout << lcs[m][n] << endl;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << setw(min(X.length(), Y.length())) << lcs[i][j];
		cout << endl;
	}
	cout << endl;

	PrintLCS(prev, X, m, n);
	cout << endl;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << setw(3) << prev[i][j];
		cout << endl;
	}
	cout << endl;

	return table[m][n]; // ���
}

int main()
{
	// CLRS 4th p.398 Fig 14.8 �׸��� ����
	string X = "ABCBDAB";
	string Y = "BDCABA";

	// CLRS 4th p.393 Ch14.4 ���Ժ� ���� (Recur �������δ� ���� �ɷ���)
	//string X = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
	//string Y = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
	// GTCGTCGGAAGCCGGCCGAA

	//string X = "ACCGGTCGAGT";
	//string Y = "GTCGTTCGGAA";
	// CGTCGA
	//6

	cout << RecurLCS(X, Y, 0, 0) << endl;
	cout << RecurLengthLCS(X, Y, int(X.size()), int(Y.size())) << endl;
	cout << BottomUpLCS(X, Y, int(X.size()), int(Y.size())) << endl;

	return 0;
}
