
#include "Utilities.h"
//================================================================
time_t conventDataFormat(int d){
    auto timeptr = std::tm{0};
    timeptr.tm_year = d%10 + ((d/10)%10)*10 + ((d/100)%10)*100 + ((d/1000)%10)*1000 - 1900;
    timeptr.tm_mon = (d/10000)%10 + ((d/100000)%10)*10;
    timeptr.tm_mday = (d/1000000)%10 + ((d/10000000)%10)*10 ;
    time_t timeSinceEpoch = mktime(&timeptr);
    return timeSinceEpoch;
}
//------------------------------------------------------------
int numLength(uint32_t num){
    int number_of_digits = 0;
    
    do {
        ++number_of_digits;
        num /= 10;
    } while (num);
    
    return number_of_digits;
}
