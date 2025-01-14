//插入排序
/*
10
3 1 2 8 7 | 5 9 4 6 0
1 2 3 7 8 | 5 9 4 6 0

左边一定是有序的，右边没动
*/
//归并排序
/*
10
3 1 2 8 7 5 9 4 0 6
1 3 2 8 5 7 4 9 0 6
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int a[100], b[100], n;
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (i = 0; i < n; i++) {
		cin >> b[i];
	}
	//因为是中间序列所以找到已排序好的
	for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
	for (j = i + 1; j < n && a[j] == b[j]; j++);
	if (j == n) {
		cout << "Insertion Sort" <<endl;
		sort(a, a + i + 2); // 下一次的排序
	}
	else {
		cout << "Merge Sort" << endl;
		int k = 1, flag = 1; //归并排序
		while (flag) {
			flag = 0;
			for (i = 0; i < n; i++) {
				if (a[i] != b[i]) {
					flag = 1;
				}
			}
			k = k * 2;
			for (i = 0; i < n/k; i++) {
				sort(a + i * k, a + (i
					+ 1) * k);
			}
			sort(a + n / k * k, a + n);
		}
	}
	for (j = 0; j < n; j++) {
		if (j != 0) printf(" ");
		printf("%d", a[j]);
	}
	return 0;
}