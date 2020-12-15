// sample01.cpp
#include <iostream>
#include <string>
namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi 記法を解析するクラスです。
	*/
	/* --------------------------------------------------------------------- */
	
	class mcxi {
	private:
		char c[10];
		char z = '0';
		int m;
	public:
		int to_string();
		mcxi(std::string a) {
			int n = a.size();
			m = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] >= '2'&&a[i] <= '9') {
					switch (c[i + 1])
					{
					case 'm':
						m += (c[i + 1] - 'z') * 1000;
						break;
					case 'c':
						m += (c[i + 1] - 'z') * 100;
						break;
					case 'x':
						m += (c[i + 1] - 'z') * 10;
						break;
					case 'i':
						m += (c[i + 1] - 'z');
						break;
					default:
						break;
					}
				}
				else {
					switch (c[i])
					{
					case 'm':
						m += 1000;
						break;
					case 'c':
						m += 100;
						break;
					case 'x':
						m += 10;
						break;
					case 'i':
						m += 1;
						break;
					default:
						break;
					}
				}
			}
		}
		mcxi() : mcxi(){}
	};
	int mcxi::to_string() {

	}
} // namespace cpp2
int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	cpp2::mcxi result0 = a0 + b0;
	std::cout << "3x" << " " << result0.to_string() << std::endl;
	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	cpp2::mcxi result1 = a1 + b1;
	std::cout << "x" << " " << result1.to_string() << std::endl;
	cpp2::mcxi a2("c2x2i");
	cpp2::mcxi b2("4c8x8i");
	cpp2::mcxi result2 = a2 + b2;
	std::cout << "6cx" << " " << result2.to_string() << std::endl;
	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	cpp2::mcxi result3 = a3 + b3;
	std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;
	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	cpp2::mcxi result4 = a4 + b4;
	std::cout << "m" << " " << result4.to_string() << std::endl;
	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	cpp2::mcxi result5 = a5 + b5;
	std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;
	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	cpp2::mcxi result6 = a6 + b6;
	std::cout << "mi" << " " << result6.to_string() << std::endl;
	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	cpp2::mcxi result7 = a7 + b7;
	std::cout << "mi" << " " << result7.to_string() << std::endl;
	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	cpp2::mcxi result8 = a8 + b8;
	std::cout << "mx" << " " << result8.to_string() << std::endl;
	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	cpp2::mcxi result9 = a9 + b9;
	std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;
}
