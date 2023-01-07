#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED
#include "date.h"
using namespace std;

class avion {
    private :
    string code ;
    string pilote;
    string modele;
    int nombre_places ;
    date date_fabrication;
    int nbVolsAssure;
    public :
    avion();
    avion(string c , string p,string m,int np,date df,int nbv);
    void ajouterAvion(string c);
    string getCode();
    string getModele();
    int getNbPlaces ();
    bool recherche(const vector<avion> &avions,string pos,int &index);
    void afficher ();
    void ecrire_fichier(std::fstream &fichier);
    void lire_fichier(std::fstream &fichier);



};



#endif // AVION_H_INCLUDED
