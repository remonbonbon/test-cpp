#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

void print_hex(const std::string &str) {
	for (std::string::size_type i=0; i<str.size(); i++) {
		printf("0x%02X ", static_cast<unsigned char>(str[i]));
	}
	printf("\n");
}

int main() {
	// Add int to std::string
	{
		std::string a("test");
		int b = 65;
		a += b;	// Caution: b is converted to char `A`.
		std::cout << a << std::endl;
	}

	// Binary string
	{
		char bin[] = {'A', 'B', '\0', 'C'};

		std::string a(bin, sizeof(bin));
		std::cout << "size: " << a.size() << std::endl;	// => size: 4
		std::cout << a << std::endl;	// => ABC
		print_hex(a);	// => 0x41 0x42 0x00 0x43

		// Copy
		std::string b = a;
		std::cout << "size: " << b.size() << std::endl;	// => size: 4
		std::cout << b << std::endl;	// => ABC
		print_hex(b);	// => 0x41 0x42 0x00 0x43

		// Concat
		b += a;
		std::cout << "size: " << b.size() << std::endl;	// => size: 8
		std::cout << b << std::endl;	// => ABCABC
		print_hex(b);	// => 0x41 0x42 0x00 0x43 0x41 0x42 0x00 0x43

		// std::stringstream
		std::stringstream ss;
		ss << a;
		std::cout << "size: " << ss.str().size() << std::endl;	// => size: 4
		std::cout << ss.str() << std::endl;	// => ABC
		print_hex(ss.str());	// => 0x41 0x42 0x00 0x43
		ss << a;
		std::cout << "size: " << ss.str().size() << std::endl;	// => size: 8
		std::cout << ss.str() << std::endl;	// => ABCABC
		print_hex(ss.str());	// => 0x41 0x42 0x00 0x43 0x41 0x42 0x00 0x43

		std::string c;
		ss >> c;
		std::cout << "size: " << c.size() << std::endl;	// => size: 8
		std::cout << c << std::endl;	// => ABCABC
		print_hex(c);	// => 0x41 0x42 0x00 0x43 0x41 0x42 0x00 0x43
	}
}
