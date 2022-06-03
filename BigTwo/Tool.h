#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#ifndef TOOL_H
#define TOOL_H

class Tool
{
public:
    Tool();
    void arrange(double*, int);
    void postZero(double*, int);
    void copyDouble_arr(double [], double [], int);
    void Print(double*, int);
};

#endif
