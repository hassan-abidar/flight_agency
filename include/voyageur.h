#ifndef VOYAGEUR_H
#define VOYAGEUR_H
using namespace std;

class voyageur
{
    private :
    string npassport;
    int age;
    string nom;
    string prenom;
    string telephone;

    public :

    voyageur();
    voyageur(string n,string p,string t, int age,string npass);
    void reservation();
    void affiche();
    string get_npass();
    int get_age();
    void modifier();
    void ecrire_fichier(fstream &fichier);
    void lire_fichier(fstream &fichier);
};
#endif // VOYAGEUR_H
