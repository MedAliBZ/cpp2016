#include "Employe.h"

using namespace std;

Employe::Employe()
{
    nom="";
    matricule=0;
    indice=0;
}

Employe::~Employe()
{
    //dtor
}


Employe::Employe(string n,int m,float s){
    nom=n;
    matricule=m;
    indice=s;
}

void Employe::afficher(){
    cout << "nom: " << nom << " matricule: " << matricule << " indice salaire: " << indice << endl;
}
