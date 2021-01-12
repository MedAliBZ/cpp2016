#include <iostream>
#include "Application.h"

using namespace std;

int main()
{
    Employe E("ali",1,5.4);
    Responsable R("yas",2,4.1,8.6);
    Employe E1("ali",3,5.4);
    Responsable R1("yas1",4,4.1,8.6);
    Application A;
    A.ajouterEmploye(E);
    A.ajouterEmploye(R);
    A.ajouterEmploye(E1);
    A.ajouterEmploye(R1);
    cout << "--------------------------" << endl;
    A.afficherEmpl();
    cout << "--------------------------" << endl;
    A.supprimerEmploye(2);
    A.afficherEmpl();
    cout << "--------------------------" << endl;
    A.ajoutEmpRes(3,4);
    A.ajoutEmpRes(4,4);
    A.afficherEmpl();
    cout << "--------------------------" << endl;
    A.Presponsable().afficher();

    return 0;
}
