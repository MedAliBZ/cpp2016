#ifndef APPLICATION_H
#define APPLICATION_H


#include "Responsable.h"

using namespace std;

class Application
{
    public:
        Application();
        virtual ~Application();
        Application(const Application&);
        Application& operator=(const Application&);
        list<Employe*>::iterator rechercheEmploye(int);
        void ajouterEmploye(const Employe&);
        void ajouterEmploye(const Responsable&);
        void supprimerEmploye(int);
        void afficherEmpl();
        void ajoutEmpRes(int,int);
        Responsable Presponsable();



    protected:
        list<Employe*> emp;
};

#endif // APPLICATION_H
