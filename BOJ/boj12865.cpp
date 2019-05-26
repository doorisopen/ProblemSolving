/*
 * ����� �賶����
 *
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[102][100002];
int v[102];
int w[102];
int main() {

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> w[i] >> v[i];

	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - w[i] >= 0) {
				// v[i]: ���� ������ ����
				// arr[i-1][j-w[i]]: [��������][�賶�� ���� - ���� ������ ����]
				// arr[i-1][j]: ���� �賶�� ����
				arr[i][j] = max(v[i] + arr[i-1][j - w[i]], arr[i - 1][j]);
				cout << "arr[" << i << "][" << j <<"]" << arr[i][j] << endl;
			}
			else
			{
				arr[i][j] = arr[i - 1][j];
			}

		}
	}
	cout << arr[N][K] << endl;

	return 0;
}