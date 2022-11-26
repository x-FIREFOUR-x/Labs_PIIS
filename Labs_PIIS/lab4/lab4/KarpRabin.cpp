#include "KarpRabin.h"

int KarpRabin::position_substr(string str, string substr)
{
    int hash_substr = hach_PJW32(substr.c_str());
    //int hash_substr = hach16(substr);

    for (int i = 0; i <= str.size() - substr.size(); i++)
    {
        string str_m = str.substr(i, substr.size());

        int hash_str = hach_PJW32(str_m.c_str());
        //int hash_str = hach16(str_m);

        if (hash_substr == hash_str)
            if (substr == str_m)
                return i;
    }

    return -1;
}

unsigned int KarpRabin::hach_PJW32(const char* str)
{
    unsigned int hash = 0;
    unsigned int test = 0;
    for (; *str; str++)
    {
        hash = (hash << 4) + (unsigned char)(*str);
        if ((test = hash & 0xf0000000) != 0)
        {
            hash = ((hash ^ (test >> 24)) & (0xfffffff));
        }
    }
    return hash;
}

unsigned int KarpRabin::hach16(string str)
{
    int number = stoi(str);

    return number % 16;
}
