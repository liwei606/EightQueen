#include <iostream>
#include <cmath>

using namespace std;

const int n = 8;
int a[8];
int answers = 0;
bool exist[8];
bool back = 0;

bool ok(int r, int c) {
	for (int i = 0; i < r; ++i) {
		if (a[i] == c || (abs(c - a[i]) == abs(r - i))) return false;
	}
	return true;
}

int main() {
	for (int i = 0; i < n; ++i) {
		a[i] = -1;
		exist[i] = 0;
	}
	int r = 0, c = 0;
	while (r < n) {
		while (c < n) {
			if (ok(r, c)) {
				a[r] = c;
				c = 0;
				break;
			}
			else ++c;
		}
		if (a[r] == -1) {
			if (r == 0) break;
			else {
				--r;
				c = a[r] + 1;
				a[r] = -1;
				continue;
			}
		}
		if (r == n - 1) {
			++answers;
			cout << "\nThe NO. " << answers << " answer\n";
			cout << "row\tcolumn\n";
			for (int i = 0; i < n; ++i) {
				cout << i << '\t' << a[i] << endl;
			}
			c = a[r] + 1;
			a[r] = -1;
			continue;
		}
		++r;
	}
	return 0;
}
