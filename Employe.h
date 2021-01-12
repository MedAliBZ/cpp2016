#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <iostream>
#include <string>


using namespace std;

class Employe
{
    public:
        Employe();
        virtual ~Employe();
        Employe(string,int,float);
        virtual void afficher();
        int getMatricule()const{return matricule;}
        float getIndice()const{return indice;}
        string getNom()const{return nom;}

    protected:
        string nom;
        int matricule;
        float indice;
};

#endif // EMPLOYE_H
