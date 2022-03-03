#include <iostream>
#include <math.h>

using namespace std;
typedef unsigned long long big;

int prime(big number) {
	for (int i = 2; i*i < number; i++)if (number % i == 0)return 0;
	return 1;
}

int main(void) {
	big n;
	cout << "> ";
	cin >> n;
	printf("%llu = ", n);
	while (n > 1) {
		if (prime(n)) { cout << n << "\n"; exit(0); }
		for (int i = 2; i <= n; i++) {
			if (prime(i) && n % i == 0) {
				printf("%d * ", i);
				n /= i;
				break;
			}
		}
	}
	cout << "\n";
	return 0;
}
