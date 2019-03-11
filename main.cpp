#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
    Set <char> A;
    cout<<"Introduceti elementele multimii urmate de Enter.\n";

    cin>>A;

    cout<<"Introduceti numarul operatiei.\n";
    cout<<"1.Afisare multime\n2.Cautare element\n3.Inserare element\n4.Suma elementelor\n";
    cout<<"5.Cardinalul multimii\n6.Elementele pare\n7.Elementele impare\n8.Inmultire cu un scalar\n";
    cout<<"9.Accesarea unui element\n10.Reuniunea cu o alta multime\n11.Compararea cardinalului cu cel al unei alte multimi\n";
    cout<<"0.Finalizare\n";

    int input, poz;
    char c, sc;

    while(true)
    {
        cin>>input;
        Set<char> B, C, D;
        switch(input)
        {
        case 0://Iesire
            return 0;

        case 1:
            cout<<A;
            break;

        case 2:
            cout<<"Elementul cautat: ";

            cin>>c;

            if(A.Search(c)!=-1) cout<<"Se afla pe pozitia "<<A.Search(c)<<". (indexarea in multime incepe de la 0)\n";
            else cout<<"Nu se gaseste in multime.\n";
            break;

        case 3:
            cout<<"Elementul de inserat: ";

            cin>>c;

            A.Insert(c);

            cout<<A<<endl;
            break;

        case 4:
            cout<<A.Sum()<<endl;
            break;

        case 5:
            cout<<A.Cardinal()<<endl;
            break;

        case 6:
            cout<<A.Pare()<<endl;
            break;

        case 7:
            cout<<A.Impare()<<endl;
            break;

        case 8:
            cout<<"Introduceti scalar: ";

            cin>>sc;
            B=A; //Salvez multimea pentru inmultirea cu scalar
            B=B*sc;

            cout<<B<<endl;
            break;

        case 9:
            cout<<"Introduceti pozitia (indexarea incepe de la 0): ";

            cin>>poz;

            cout<<A[poz]<<endl;
            break;

        case 10:
            cout<<"Introduceti elementele multimii urmate de Enter: ";
            cin>>C;
            cout<<A+C<<endl;

            break;

        case 11:
            cout<<"Introduceti elementele multimii urmate de Enter: ";
            cin>>D;

            if(A.Cardinal()==D.Cardinal()) cout<<"Au acelasi cardinal.\n";
            else
            {
                if(A > D) cout<<"Prima multime are cardinalul mai mare.\n";
                if (A < D) cout<<"A doua multime are cardinalul mai mare\n";
            }
            break;

        default:
            cout<<"Eroare.\n";
            break;
        }
    }
    return 0;
}
