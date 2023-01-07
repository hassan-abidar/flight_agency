#include<iostream>
#include<fstream>
#include<string>
#include "voyageur.h"
using namespace std;
    voyageur::voyageur()
    {
    }
voyageur::voyageur(string n,string p,string t, int ag,string npass)
       {
        nom=n;
        prenom=p;
        telephone=t;
        age=ag;
        npassport=npass;
        }
void voyageur::reservation()
     {
       cout<<"entrez le nom                     : ";
       cin>>nom;
       cout<<"entrez le prenom                  : ";
       cin>>prenom;
       cout<<"entrez  l'age                     : ";
       cin>>age;
       cout<<"entrez le numero de telephone     :";
       cin>>telephone;
       cout<<"entrez votre numero de passport   :";
       cin>>npassport;
     }

void voyageur::modifier(){

       cout<<"entrez nouveau nom                  : ";
       cin>>nom;
       cout<<"entrez nouveau prenom               : ";
       cin>>prenom;
       cout<<"entrez nouveau age                  : ";
       cin>>age;
       cout<<"entrez nouveau telephone            : ";
       cin>>telephone;
       cout<<"entrez nouveau numero de passport   : ";
       cin>>npassport;

}

void voyageur::affiche()
     {
      cout<<"nom        : "<<nom<<endl;
      cout<<"prenom     : "<<prenom<<endl;
      cout<<"Passport   : "<<npassport<<endl;
      cout<<"age        : "<<age<<endl;
      cout<<"telephone  : "<<telephone<<endl;
    }

string voyageur::get_npass()
     {
      return npassport;
     }
int voyageur::get_age()
     {
      return age;
     }
void voyageur::ecrire_fichier(fstream &fichier)
    {
    fichier<<nom<<"\t"<<prenom<<"\t"<<age<<"\t"<<telephone<<"\t"<<npassport<<endl;
    }

void voyageur::lire_fichier(fstream &fichier)
     {
          fichier>>nom>>prenom>>age>>telephone>>npassport;
          }
