// sample01.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	private:
		int value_;
		int unit(char c) {
			if (c == 'm') {
				return 1000;
			}
			else if (c == 'c') {
				return 100;
			}
			else if (c == 'x') {
				return 10;
			}
			else if (c == 'i') {
				return 1;
			}
		}
	public:
		mcxi() {};
		mcxi operator+(const mcxi& rhs) {
			mcxi num;
			num.value_ = this->value_ + rhs.value_;
			return num;
		};
				std::string to_string()const {
			std::stringstream ss;
			int q = value_ / 1000;
			int r = (value_ - (q * 1000)) / 100;
			int s = (value_ - (q * 1000 + r * 100)) / 10;
			int t = value_ - (q * 1000 + r * 100 + s * 10);
			if (q == 1) {
				ss << 'm';
			}
			else if (q >= 2) {
				ss << q;
				ss << 'm';
			}
			if (r == 1) {
				ss << 'c';
			}
			else if (r >= 2) {
				ss << r;
				ss << 'c';
			}
			if (s == 1) {
				ss << 'x';
			}
			else if (s >= 2) {
				ss << s;
				ss << 'x';
			}
			if (t == 1) {
				ss << 'i';
			}
			else if (t >= 2) {
				ss << t;
				ss << 'i';
			}
			return ss.str();
		};
		mcxi(const std::string& s) : value_(0) {
			int digit = 0;
			for (auto pos = s.begin(); pos != s.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					digit = *pos - '0';
				}
				else {
					auto u = unit(*pos);
					value_ += std::max(digit, 1) * u;
					digit = 0;
				}
			}
		}
	};
} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;

	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	auto result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
OAOAOA
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
OAOAOA	auto result9 = a9 + b9;
OAOAOA	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}
