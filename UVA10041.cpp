#include<iostream>
#include<sstream>
#include<cstdlib>
#include<string>
#include<vector>
#define swap(x, y, z) ((z)=(x), (x)=(y), (y)=(z))
using namespace std;
void sort(vector <int> & in) {
	bool f;
	int n = in.size() - 1, temp;
	for (int i = 0; i < n; ++i) {
		f = 0;
		for (int j = 0; j < n - i; ++j) {
			if (in[j] > in[j + 1]) {
				swap(in[j], in[j + 1], temp);
				f = 1;
			}
		}
		if (!f) return;
	}
}
int main() {
	int caseN, n, temp, med, sum;
	string buffer;
	vector <int> data;
	cin >> caseN;
	while (caseN--) {
		sum = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			data.push_back(temp);
		}
		sort(data);
		/*cout << "--";
		for (int i = 0; i < n; ++i)
			cout << data[i] << ',';
		cout << "--\n";*/
		if (--n % 2)
			med = (data[n / 2] + data[(n / 2) + 1]) / 2;
		else
			med = data[n / 2];
		//cout << "n : " << n << " med : " << med << '\n';
		for (int i = 0; i <= n; ++i)
			sum += (abs(med - data[i]));
		cout << sum << '\n';
		data.clear();
	}
}