#include "Set.h"
#include<iostream>
using namespace std;
#include <cmath>

template <class SetType>
Set<SetType>::Set(){//fara parametri
    n = 0;
    Max = 8;
    p = new SetType[Max];
}
template <class SetType>
Set<SetType>::Set(int N, int MAX){//cu parametri
    n = N;
    Max = MAX;
    p = new SetType[MAX];
}
template<class SetType>
Set<SetType>::~Set(){//destructor
    delete[]p;
}
template <class SetType>
Set<SetType>::Set(Set<SetType>& A){//de copiere
    (*this).n = A.n;
    (*this).Max = A.Max;
    for (int i = 0; i < n; ++i)
        (*this).p[i] = A.p[i];
}

template <class SetType>
    int Set <SetType>:: Search(SetType el)
{
    int sol = -1, left = 0, right = n;
    while(left <= right)
    {
        int mid = (left+right) / 2;
        if(p[mid] == el)
        {
            sol = mid;
            break;
        }
        if(p[mid] > el)
            right = mid - 1;
        if(p[mid] < el)
            left = mid + 1;
    }
    return sol;
}
template <class SetType>
    void Set <SetType>:: Insert(SetType el)
{
    //daca depaseste dimensiunea maxima
    if(n >= Max)
    {
        //copiez totul intr-un vector auxiliar
        SetType* m = new SetType[Max+4];
        Max += 4;
        for (int i = 0; i < n; i++)
            m[i] = p[i];
        delete[]p;
        p = m;
    }

    //folosesc metoda de cautare a unui element
    if(Search(el) == -1)//elementul nu se afla deja in multime
    {
        int i = n - 1;
        while(el <= p[i] && i >= 0)//pastrez elementele in ordine crescatoare
            p[i+1] = p[i],  i--;
        p[i+1] = el;
        n++;
    }
}
template <class SetType>
    void Set<SetType>:: Delete(SetType el)
{
    int poz=Search(el);
    if(poz != -1)
    {
        for(int j = poz; j < n; j++)
            p[j] = p[j+1];
        n--;
    }
    else return;//elementul nu se gaseste in multime si ies din metoda
}
template <class SetType>
    int Set<SetType>:: Sum()
{
    int s =  0;
    for(int i = 0; i < n; i++)
        s += p[i];
    return s;
}
template <class SetType>
    int Set<SetType>:: Cardinal()
{
    return n;
}
template <class SetType>
    Set<SetType> Set<SetType>:: Pare()
{
    Set<SetType> par;
    for(int i = 0; i < n; i++)
        if(p[i]%2==0)
            par.Insert(p[i]);
    return par;
}
template <class SetType>
    Set<SetType> Set<SetType>:: Impare()
{
    Set<SetType> impar;
    for(int i = 0; i < n; i++)
        if(p[i] % 2)
            impar.Insert(p[i]);
    return impar;
}
template <class SetType>
    Set<SetType>& Set<SetType>:: operator*(int k)
{
    for(int i = 0; i < n; i++)
        p[i] *= k;
    return *this;
}
template <class SetType>
    Set<SetType> Set<SetType>:: operator+(Set<SetType>& B)
{
    Set<SetType> reun;

    for(int i = 0; i < this->n; i++)
        reun.Insert((*this)[i]);

    for(int i = 0; i < B.n; i++)
    {
        int ok = 0;
        int j = 0;
        while(j < n && !ok)
            if(B[i] == (*this)[j]) ok=1;
            else j++;
        if(ok == 0)
        reun.Insert(B[i]);
    }
    return reun;
}
template <class SetType>
    Set<SetType>& Set<SetType>:: operator=(Set<SetType>& B)
{
    (*this).n = B.n;
    (*this).Max = B.Max;
    for (int i = 0; i < n; ++i)
        (*this).p[i] = B.p[i];

    return *this;
}
template <class SetType>
    SetType Set<SetType>:: operator[](int k)
{
    if(k >= 0 && k < n) //ma asigur ca exista pozitia ceruta
        return p[k];
}
template <class SetType>
    bool Set<SetType>:: operator<(Set<SetType>&B)
{
    if(this->n < B.n) return true;
    return false;
}
template <class SetType>
    bool Set<SetType>:: operator>(Set<SetType>& B)
{
    return !(*this < B);
}