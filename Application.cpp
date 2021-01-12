#include "Application.h"
#include <typeinfo>
#include <fstream>

using namespace std;


Application::Application()
{
    //ctor
}

Application::~Application()
{
    for(list<Employe*>::iterator it=emp.begin();it!=emp.end();it++){
        delete (*it);
    }
}


Application::Application(const Application& A){
    if(&A!=this){
        Employe* E;
        for(list<Employe*>::const_iterator it=A.emp.begin();it!=A.emp.end();it++){
            if(typeid(**it)==typeid(Employe)){
                E=new Employe(static_cast<const Employe&>(**it));
            }
            else if(typeid(**it)==typeid(Responsable)){
                E=new Responsable(static_cast<const Responsable&>(**it));
            }
            emp.push_back(E);
        }
    }
}

Application& Application::operator=(const Application& A){
    if(&A!=this){
        for(list<Employe*>::const_iterator it=emp.begin();it!=emp.end();it++){
            delete (*it);
        }
        emp.clear();
        Employe* E;
        for(list<Employe*>::const_iterator it=A.emp.begin();it!=A.emp.end();it++){
            if(typeid(**it)==typeid(Employe)){
                E=new Employe(static_cast<const Employe&>(**it));
            }
            else if(typeid(**it)==typeid(Responsable)){
                E=new Responsable(static_cast<const Responsable&>(**it));
            }
            emp.push_back(E);
        }
    }
    return *this;
}

list<Employe*>::iterator Application::rechercheEmploye(int m){
    for(list<Employe*>::iterator it=emp.begin();it!=emp.end();it++){
        if((*it)->getMatricule()==m)
            return it;
    }
    return emp.end();
}

void Application::ajouterEmploye(const Employe& E){
    if(rechercheEmploye(E.getMatricule())==emp.end())
        emp.push_back(new Employe(E));
}


void Application::ajouterEmploye(const Responsable& R){
    if(rechercheEmploye(R.getMatricule())==emp.end())
        emp.push_back(new Responsable(R));
}

void Application::supprimerEmploye(int m){
    list<Employe*>::iterator empl=rechercheEmploye(m);
    if(empl!=emp.end()){

        ofstream MyFile("undo_delete.txt", ios_base::app);
        try{
            if(MyFile.is_open()){
                if(typeid(**empl)==typeid(Employe))
                    MyFile << (*empl)->getNom() << " " << (*empl)->getMatricule() << " " << (*empl)->getIndice() << endl;
                else if(typeid(**empl)==typeid(Responsable)){
                    Responsable* res=new Responsable(static_cast<Responsable&>(**empl));
                    MyFile << (*empl)->getNom() <<  " " << (*empl)->getMatricule() <<  " " << (*empl)->getIndice() <<  " " << res->getPrime() << endl;
                    delete (res);
                }
                delete (*empl);
                emp.erase(empl);
                MyFile.close();
            }
            else
                throw(404);
        }
        catch (int err){
            cout << "problem opening file!" << endl;
        }
    }
    else
        cout << "employe invalide!" << endl;
}


void Application::afficherEmpl(){
    float charge=0;
    for(list<Employe*>::iterator it=emp.begin();it!=emp.end();it++){
        (*it)->afficher();
        charge+=(*it)->getIndice();
    }
    cout << "charge salariaire: " << charge << endl;
}

void Application::ajoutEmpRes(int e,int r){
    list<Employe*>::iterator res=rechercheEmploye(r);
    list<Employe*>::iterator empl=rechercheEmploye(e);

    if(res!=emp.end() && typeid(**res)==typeid(Responsable)){
        if(empl!=emp.end()){
            Responsable &R=static_cast<Responsable&>(**res);
            R.ajoutEmp((*empl)->getMatricule());
        }
        else
            cout << "employe invalide!" << endl;
    }
    else
        cout << "responsable invalide!" << endl;
}



Responsable Application::Presponsable(){
    Responsable R;
    int nb=0;

    for(list<Employe*>::iterator it=emp.begin();it!=emp.end();it++){
        if(typeid(**it)==typeid(Responsable)){
            Responsable &r=static_cast<Responsable&>(**it);
            if(r.nbEmp()>nb){
                R=r;
            }
        }
    }
    return R;
}
