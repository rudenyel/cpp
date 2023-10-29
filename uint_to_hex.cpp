#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// It is not a universal solution.
// For 32-bit systems you should change uint64_t to uint32_t
// It works with negative numbers too

string uint_to_hex(uint64_t a)
{
	string num = "";
	string number = "";
	while (a != 0)
	{
		char ch;
		int k = 0;
		k = a % 16;
		if (k < 10) { ch = k + 48; }
		else { ch = k + 55; }
		num = num + ch;
		a = a / 16;
	}
	for (int i = num.size() - 1; i >= 0; i--)
		number = number + num[i];
	return number;
}

int main()
{
	uint64_t a = 0;
	cin >> a;
	
	cout << uint_to_hex(a);

	return 0;
}
