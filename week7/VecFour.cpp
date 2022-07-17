#include "VecFour.h"

VecFour::VecFour(double a, double b, double c, double d)
{
    v = std::vector<double>(4);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d; 
}

VecFour::VecFour(const VecFour& rhs)
{
    *this = rhs;
}

VecFour& VecFour::operator=(const VecFour & rhs)
{
    auto* temp = &rhs;
    if(this != temp)
        v = rhs.v;
    return *this;
}

VecFour VecFour::operator*(double num){
    VecFour tmp;
    for (int i=0 ; i!=4; i++)
        tmp.v[i] = num * v[i];
    return tmp;
}

VecFour& VecFour::operator*= (const VecFour& vf){   
        for (int i=0; i!=4; i++)
            v[i] = v[i] * vf.v[i];
    return *this;
} 

/*
VecFour& operator*=(VecFour& lhs, const VecFour & rhs) //non member
{
    for (int i=0; i!=4; i++)
        lhs.v[i] = lhs.v[i] * rhs.v[i];
    return lhs;
}*/

/*
VecFour operator*(double num, const VecFour& vf) //non member
{
    VecFour tmp;
    for (int i=0 ; i!=4; i++)
        tmp.v[i] = num * vf.v[i];
    return tmp;
}*/

bool operator<(const VecFour& vf1, const VecFour& vf2)
{
    double sum1=0;
    double sum2=0;
    
    
    for (int i =0; i!=4; i++)
    {
        sum1 += vf1.v[i]*vf1.v[i];
        sum2 += vf2.v[i]*vf2.v[i];
    }
    return sum1 < sum2;
}