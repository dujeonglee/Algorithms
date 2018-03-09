#include <cstdint>
#include <string>
#include <iostream>

int main()
{
    std::string str;
    char input = 0;
    uint32_t length = 0;

    char str_N = 0;
    char str_N_1 = 0;

    uint32_t dp_N_ONE = 0;
    uint32_t dp_N_TWO = 0;
    uint32_t dp_N_1_ONE = 0;
    uint32_t dp_N_1_TWO = 0;
    uint32_t dp_N_2_ONE = 0;
    uint32_t dp_N_2_TWO = 0;

    std::cin >> str;
    const uint32_t INPUT_LENGTH = str.size();

    for (uint32_t i = 0; i < INPUT_LENGTH; i++)
    {
        input = (str.c_str())[i];
        str_N_1 = str_N;
        str_N = input;

        length++;

        dp_N_2_ONE = dp_N_1_ONE;
        dp_N_2_TWO = dp_N_1_TWO;
        dp_N_1_ONE = dp_N_ONE;
        dp_N_1_TWO = dp_N_TWO;
        dp_N_ONE = 0;
        dp_N_TWO = 0;

        if (length == 1)
        {
            if (str_N == '0')
            {
                dp_N_ONE = 0;
            }
            else
            {
                dp_N_ONE = 1;
            }
            dp_N_TWO = 0;
        }
        else if (length == 2)
        {
            uint32_t two_numbers = (str_N_1 - '0') * 10 + (str_N - '0');
            if (str_N == '0')
            {
                dp_N_ONE = 0;
            }
            else
            {
                dp_N_ONE = 1;
            }
            dp_N_TWO = (two_numbers < 10 || two_numbers > 26 ? 0 : 1);
        }
        else
        {
            uint32_t two_numbers = (str_N_1 - '0') * 10 + (str_N - '0');
            if (str_N == '0')
            {
                dp_N_ONE = 0;
            }
            else
            {
                dp_N_ONE = (dp_N_ONE + dp_N_1_ONE) % 1000000;
                dp_N_ONE = (dp_N_ONE + dp_N_1_TWO) % 1000000;
            }

            if (two_numbers < 10 || two_numbers > 26)
            {
                dp_N_TWO = 0;
            }
            else
            {
                dp_N_TWO = (dp_N_TWO + dp_N_2_ONE) % 1000000;
                dp_N_TWO = (dp_N_TWO + dp_N_2_TWO) % 1000000;
            }
        }
    }
    std::cout << (dp_N_ONE + dp_N_TWO) % 1000000 << std::endl;

    return 0;
}