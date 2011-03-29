#ifndef ALGORITHM
#define ALGORITHM

#include "algo_implementation.h"

class Algorithm
{
 public:
    Algorithm(){}
    ~Algorithm(){}

    static double max(double a, double b)
    {
        return max_impl(a,b);
    }

    double operator()()
    {
        double param1 = 10;
        double param2 = 5;
        double param3 = max(param1, param2); //10
        return (param1+param2)*param3; //150
    }
 private:
    Algorithm(const Algorithm & algo){}
    Algorithm & operator=(const Algorithm & algo){}
};

#endif
