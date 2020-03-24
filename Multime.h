#ifndef MULTIME_H
#define MULTIME_H
#include <iostream>
#include <vector>
using namespace std;

class Multime{
    int nr;
    vector<int> v;
    public:
        friend Multime operator+ (Multime a, Multime b);
        friend Multime operator* (Multime a, Multime b);
        friend Multime operator- (Multime a, Multime b);
        friend ostream &operator<< (ostream &os, Multime a);
        Multime(const Multime &a);
        Multime(int a[], int n);
        Multime(vector<int> a, int n);
        int operator[] (int x);
        int getnr();
        ~Multime();
};


#endif
