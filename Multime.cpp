#include "Multime.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

Multime::Multime(const Multime &a){
    nr=a.nr;
    for(unsigned int i=0; i<a.v.size(); i++)
        v.push_back(a.v[i]);}

Multime::Multime(int a[], int n){
    if(n<1){
        nr=0;
        return;}
    nr=1;
    sort(a, a+n);
    int mx=a[0];
    v.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(a[i]>mx){
            mx=a[i];
            v.push_back(mx);
            nr++;}}}

Multime::Multime(vector<int> a, int n){
    if(n<1){
        nr=0;
        return;}
    nr=1;
    sort(a.begin(), a.end());
    int mx=a[0];
    v.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(a[i]>mx){
            mx=a[i];
            v.push_back(mx);
            nr++;}}}

int Multime::operator[] (int x){
    return v[x];}

int Multime::getnr(){
    return nr;}

Multime::~Multime(){
    while(v.size())
        v.pop_back();}

Multime operator+(Multime a, Multime b){
    int i=0, j=0, x=a.getnr(), y=b.getnr();
    if(x==0)
        return b;
    if(y==0)
        return a;
    vector<int> v;
    while(i<x || j<y)
    {
        while((j==y || a[i]<=b[j]) && i<x)
        {
            v.push_back(a[i]);
            i++;
        }
        while((i==x || a[i]>b[j]) && j<y)
        {
            v.push_back(b[j]);
            j++;
        }
    }
    Multime rez(v, v.size());
    return rez;
}

Multime operator*(Multime a, Multime b){
    int i=0, j=0, x=a.getnr(), y=b.getnr();
    if(x==0)
        return a;
    if(y==0)
        return b;
    vector<int> v;
    while(i<x || j<y)
    {
        while(a[i]==b[j] && i<x && j<y)
        {
            v.push_back(a[i]);
            i++;
            j++;
        }
        while((j==y || a[i]<b[j]) && i<x)
            i++;
        while((i==x || a[i]>b[j]) && j<y)
            j++;
    }
    Multime rez(v, v.size());
    return rez;
}

Multime operator-(Multime a, Multime b){
    int i=0, j=0, x=a.getnr(), y=b.getnr();
    if(x==0 || y==0)
        return a;
    vector<int> v;
    while(i<x)
    {
        while(a[i]>b[j] && j<y)
            j++;
        while(((a[i]<b[j] && i<x) || j==y) && i<x)
        {
            v.push_back(a[i]);
            i++;
        }
        while(a[i]==b[j] && i<x)
            i++;
    }
    Multime rez(v, v.size());
    return rez;
}

ostream &operator<<(ostream &os, Multime x){
    if(x.getnr()==0)
    {
        cout<<"Multime vida"<<endl<<endl;
        return os;
    }
    cout<<x.getnr()<<endl<<"{";
    for(int i=0; i<x.getnr()-1; i++)
        cout<<x[i]<<", ";
    cout<<x[x.getnr()-1];
    cout<<"}"<<endl<<endl;
    return os;
}
