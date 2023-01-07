#include <iostream>
#include "avion.h"
#include "date.h"
#include <string>
#include <fstream>
using namespace std;

avion::avion(){


}
avion::avion(string c , string p,string m,int np,date df,int nbv):code(c),pilote(p),modele(m),nombre_places(np),nbVolsAssure(nbv),date_fabrication(df){

}
void avion::ajouterAvion(string c){
    code=c;
    cout << "Entrez le pilote d'avion : ";
    cin >> pilote;
    cout << "Entrez le modele d'avion : ";
    cin >> modele;
    cout << "Entrez le nombres des places d'avion : ";
    cin >> nombre_places;
    cout << "Entrez le nombres des vols assure d'avion : ";
    cin >> nbVolsAssure;
    date_fabrication.amj_fabr();


}
string avion::getCode(){
    return code;
}
string avion:: getModele(){
    return modele;
}
int avion :: getNbPlaces (){
 return nombre_places;
}
bool avion::recherche(const vector<avion> &avions,string pos,int &index)
          {unsigned i=0;
           unsigned trouve=false;
           while(i<avions.size() && trouve==false)
           {
             if(avions[i].code==pos)
            {
               trouve=true;
                index=i;
               }
              else
                 i++;
             }
          return trouve;
}
void avion::afficher(){

 cout<<"  "<<code<<"\t\t"<<pilote<<"\t\t"<<modele<<"\t\t   "<<nombre_places <<"\t\t"<<nbVolsAssure << "\t\t"<<date_fabrication.getDay() <<"/"<<date_fabrication.getMonth()<<"/"<<date_fabrication.getYear()<<endl;

}
void avion::ecrire_fichier(fstream &fichier)
    {
    fichier<<code<<"\t"<<pilote<<"\t"<<modele<<"\t"<<nombre_places<<"\t"<<nbVolsAssure<<date_fabrication.getDay() <<"/"<<date_fabrication.getMonth()<<"/"<<date_fabrication.getYear();
    }

void avion::lire_fichier(fstream &fichier)
     {
          fichier>>code>>pilote>>modele>>nombre_places>>nbVolsAssure;
          }

