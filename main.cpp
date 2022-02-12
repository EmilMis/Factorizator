#include <iostream>
#include <math.h>

using namespace std;
typedef unsigned long long big;
#define SQRT_MAGIC_F 0x5f3759df 

float sqrt2(big x)
{
	const float xhalf = 0.5f * x;
	union
	{
		float x;
		int i;
	} u;
	u.x = x;
	u.i = SQRT_MAGIC_F - (u.i >> 1);
	return x * u.x * (1.5f - xhalf * u.x * u.x);
}

int prime(big number) {
	int limit = round(sqrt2(number));
	for (int i = 2; i <= limit; i++)if (number % i == 0)return 0;
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
