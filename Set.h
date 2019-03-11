#ifndef SET_H
#define SET_H
#include <iostream>
#include <cmath>
using namespace std;
template <class SetType>
class Set
{
    SetType *p;
    int n, Max;//Max := dimensiunea maxima

public:
    //constructori si destructor
    Set();
    Set(int, int);
    Set(Set<SetType>& A);
    ~Set();

    //metode
    int Search(SetType); //o folosesc in urmatoarele doua
    void Insert(SetType);
    void Delete(SetType);
    int Sum();
    int Cardinal();
    Set <SetType> Pare();
    Set <SetType> Impare();

    //supraincarea operatorilor
    Set <SetType>& operator*(int);
    Set <SetType> operator+(Set<SetType>& B);
    Set <SetType>& operator=(Set<SetType>& B);
    SetType operator[](int);
    bool operator>(Set <SetType>&);
    bool operator<(Set <SetType>&);

    //supraincarcare operator afisare
    friend ostream& operator<<(ostream&out, const Set <SetType>&A){
    for(int i = 0; i < A.n; i++)
        out<<A.p[i]<<" ";
    out<<endl;
    return out;
}
    //supraincarcare operator citire
    friend istream& operator>>(istream&in, Set <SetType>&A){
    SetType x;
    int ok = -1;
    while(ok)
    {
        in>>x;
        A.Insert(x);
        if(cin.get()=='\n') break;
    }
    return in;
}

};
#endif // SET_H
