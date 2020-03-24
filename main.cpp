//  Tema 11
#include <iostream>
#include "Multime.h"

using namespace std;

int main()
{
    int c[] = {10, 30, -9, -29, 79, 49, 10};
    int d[] = {-100, -110, -310, -550, -5000, 10};
    Multime b(c, sizeof(c)/sizeof(*c));
    Multime e(d, sizeof(d)/sizeof(*d));
    cout<<"Multimea 1: "<<b;
    cout<<"Multimea 2: "<<e;
    cout<<"Reuniune: "<<b+e;
    cout<<"Intersectie: "<<b*e;
    cout<<"Diferenta: "<<b-e;
    cout<<"Diferenta: "<<e-b;
    return 0;
}
