#include <cstdint>
#include <iostream>

int main()
{
    int32_t cnt_zero[41] = {-1};
    int32_t cnt_one[41] = {-1};
    cnt_zero[0] = 1;
    cnt_zero[1] = 0;
    cnt_one[0] = 0;
    cnt_one[1] = 1;
    
    uint32_t TESTS = 0;
    uint32_t number = 0;
    std::cin >> TESTS ;

    for (uint32_t run = 0 ; run < TESTS ; run++)
    {
        std::cin >> number;
        if(number == 0)
        {
            std::cout<<"1 0"<<std::endl;
        }
        else if(number == 1)
        {
            std::cout<<"0 1"<<std::endl;
        }
        else
        {
            for(uint32_t i = 2 ; i <= number ; i++)
            {
                cnt_zero[i] = cnt_zero[i-1] + cnt_zero[i-2];
                cnt_one[i] = cnt_one[i-1] + cnt_one[i-2];
            }
            std::cout<<cnt_zero[number]<<" "<<cnt_one[number]<<std::endl;
        }
    }
    return 0;
}
