#ifndef SOLUTION_3
#define SOLUTION_3


#include <vector>
#include <string>
using std::vector;


class Solution_3{
protected:

public:
    Solution_3();
    std::string float_to_string(float value, int decimal_places);
    char *dtostrf(double val, signed char width, unsigned char prec, char *sout);
};


#endif //SOLUTION_3