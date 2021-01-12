#ifndef RESPONSABLE_H
#define RESPONSABLE_H

#include "Employe.h"
#include <list>

using namespace std;

class Responsable : public Employe
{
    public:
        Responsable();
        virtual ~Responsable();
        Responsable(string,int,float,float);
        void afficher();
        float getPrime()const{return prime;}
        void ajoutEmp(int);
        int nbEmp(){return employes.size();}

    protected:
        float prime;
        list<int> employes;
};

#endif // RESPONSABLE_H
