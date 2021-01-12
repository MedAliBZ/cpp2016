#include "Responsable.h"


using namespace std;

Responsable::Responsable()
{
    prime=0;
}

Responsable::~Responsable()
{
    //dtor
}


Responsable::Responsable(string s,int i,float f,float p):Employe(s,i,f){
    prime=p;
}

void Responsable::afficher(){
    Employe::afficher();
    cout << "prime: " << prime << endl;
    cout << "employe: ";
    for(list<int>::iterator it=employes.begin();it!=employes.end();it++){
        cout << *it << ", ";
    }
    cout << endl;
}

void Responsable::ajoutEmp(int m){
    employes.push_back(m);
}
