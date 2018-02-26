#include <cstdint>
#include <iostream>

uint32_t result[10] = {0};
uint32_t cnt_end_with[10] = {0};
uint32_t tmp[10] = {0};

int main()
{
    cnt_end_with[0] = 0;
    cnt_end_with[1] = 1;
    cnt_end_with[2] = 1;
    cnt_end_with[3] = 1;
    cnt_end_with[4] = 1;
    cnt_end_with[5] = 1;
    cnt_end_with[6] = 1;
    cnt_end_with[7] = 1;
    cnt_end_with[8] = 1;
    cnt_end_with[9] = 1;
    uint32_t n;
    std::cin >> n;
    for(uint32_t i = 1  ; i < n ; i++)
    {
        tmp[0] = (                  cnt_end_with[1]) % 1000000000;
        tmp[1] = (cnt_end_with[0] + cnt_end_with[2]) % 1000000000;
        tmp[2] = (cnt_end_with[1] + cnt_end_with[3]) % 1000000000;
        tmp[3] = (cnt_end_with[2] + cnt_end_with[4]) % 1000000000;
        tmp[4] = (cnt_end_with[3] + cnt_end_with[5]) % 1000000000;
        tmp[5] = (cnt_end_with[4] + cnt_end_with[6]) % 1000000000;
        tmp[6] = (cnt_end_with[5] + cnt_end_with[7]) % 1000000000;
        tmp[7] = (cnt_end_with[6] + cnt_end_with[8]) % 1000000000;
        tmp[8] = (cnt_end_with[7] + cnt_end_with[9]) % 1000000000;
        tmp[9] = (cnt_end_with[8]                  ) % 1000000000;
        cnt_end_with[0] = tmp[0];
        cnt_end_with[1] = tmp[1];
        cnt_end_with[2] = tmp[2];
        cnt_end_with[3] = tmp[3];
        cnt_end_with[4] = tmp[4];
        cnt_end_with[5] = tmp[5];
        cnt_end_with[6] = tmp[6];
        cnt_end_with[7] = tmp[7];
        cnt_end_with[8] = tmp[8];
        cnt_end_with[9] = tmp[9];
    }
    uint32_t result = 0;
    for(uint32_t i = 0 ; i < 10 ; i++)
    {
        result  = (result + cnt_end_with[i])%1000000000;
    }
    std::cout<< result<< std::endl;
    return 0;
}
