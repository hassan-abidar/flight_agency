#ifndef DESTINATION_H
#define DESTINATION_H
using namespace std;

class destination
{
    string depart,arrivee;

    public :
    destination();
    destination(string dep,string arv);
    string get_depart();
    string get_arrivee();
    void dest();
    void afficher();
    void ecrire_fichier(std::fstream &fichier);
    void lire_fichier(std::fstream &fichier);
};

#endif // DESTINATION_H
