#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable: 4996)
int n, m;
vector<int> v;

int main() {
	scanf("%d", &n);
	int tmp;
	while (n--) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());// �������� ����

	scanf("%d", &m);
	while (m--) {
		scanf("%d", &tmp);
		printf("%d ", binary_search(v.begin(), v.end(), tmp) ? 1 : 0);// ���� Ž��
	}

	return 0;
}
