#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。
/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
//素数判定
int prime(unsigned int n) {
	if (n == 2) return 1;
	if (n <= 1 || n % 2 == 0) return 0;
	for (int i = 3; i*i <= n; i += 2) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
	int x = a;
	unsigned int cnt = 0;
	if(a % 2 == 0 && d % 2 == 0)return 0;
	while (cnt < n) {
		if (prime(x) == 1) {
			cnt++;
		}
		x += d;
	}
	return x-d;
};

int main() {
	std::cout << nth_prime(367, 186, 151) << std::endl;
	// 以下、同様に、入出力例通りになるか確認せよ。
	std::cout << nth_prime(179, 10, 203) << std::endl;
	std::cout << nth_prime(271, 37, 39) << std::endl;
	std::cout << nth_prime(103, 230, 1) << std::endl;
	std::cout << nth_prime(27, 104, 185) << std::endl;
	std::cout << nth_prime(253, 50, 85) << std::endl;
	std::cout << nth_prime(1, 1, 1) << std::endl;
	std::cout << nth_prime(9075, 337, 210) << std::endl;
	std::cout << nth_prime(307, 24, 79) << std::endl;
	std::cout << nth_prime(331, 221, 177) << std::endl;
	std::cout << nth_prime(259, 170, 40) << std::endl;
	std::cout << nth_prime(269, 58, 102) << std::endl;
	return 0;
}
