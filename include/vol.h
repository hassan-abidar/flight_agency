#ifndef VOL_H
#define VOL_H
#include"destination.h"
#include"date.h"
#include"voyageur.h"
#include"avion.h"
#include<windows.h>
using namespace std;
class vol
{


    int n_vol;
    avion m_avion;
    date m_date;
    float prix;
    destination m_destination;
    vector<voyageur> passager;

    public :
    vol();
    vol(int num);
    void ajout_vol(int num,avion &av,float p);
    bool recherche(const vector<vol> &vols,int &pos);
    bool recherche_pass(string nn);
    void recherche_age(int a);
    void modifier_vol();
    void annuller_reservation(int pos);
    void reserver();
    date getDate();
    void modifier_pass();
    void modifier_date();
    void modifier_heur();
    void afficher();
    void afficher_pass();
    bool controle_date(int a,int m,int j,int h,int mn);
    void ecrire_fichier(std::fstream &fichier);
    void lire_fichier(std::fstream &fichier);
};

#endif // VOL_H
