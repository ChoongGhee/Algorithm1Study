#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int RecurFibonacci(int n)
{
	cout << "RecurFibonacci(" << setw(2) << n << ")" << endl;

	if (n == 0) return 0;
	if (n == 1) return 1;

	return RecurFibonacci(n - 2) + RecurFibonacci(n - 1);
}

// �޸� vector ��ſ� unordered_map�� ����ϴ� ��쵵 �ֽ��ϴ�.
int MemoizedTopDownFibonacciHelper(int n, std::vector<int>& memo)
{
	// TODO:

	for (auto& t : memo) cout << setw(4) << t; cout << endl;

	return memo[n];
}

int MemoizedTopDownFibonacci(int n)
{
	vector<int> memo(n + 1, -1); // -1�� �ʱ�ȭ
	memo[0] = 0;
	memo[1] = 1;

	return MemoizedTopDownFibonacciHelper(n, memo);
}

int BottomUpFibonacciTabulation(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;

	vector<int> table(n + 1, -1);
	table[0] = 0;
	table[1] = 1;

	// for ( TODO )
	{
		// TODO:

		for (auto& t : table) cout << setw(4) << t; cout << endl;
	}

	return table[n]; // The N-th Fibonacci number
}

// ��̷� �迭 ���� �����غ���
int BottomUpFibonacci(int n)
{
	if (n == 0 || n == 1)
		return n;

	int a = 0;
	int b = 1;

	// TODO:

	return b; // The N-th Fibonacci number
}

int main()
{
	int n = 7; // ���ڰ� ũ�� �ܼ� ��� ������ ���� �����ϴ�.

	cout << RecurFibonacci(n) << endl;

	cout << MemoizedTopDownFibonacci(n) << endl;

	cout << BottomUpFibonacciTabulation(n) << endl;

	cout << BottomUpFibonacci(n) << endl;

	return 0;
}


