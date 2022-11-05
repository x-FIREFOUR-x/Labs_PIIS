#pragma once

#include <string>

using namespace std;
class KarpRabin
{

public:
	int position_substr(string str, string substr);

private:
	unsigned int hach_PJW32(const char* str);
	unsigned int hach16(string str);
};

