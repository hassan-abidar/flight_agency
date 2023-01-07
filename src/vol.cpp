#include<string>
#include<iostream>
#include<vector>
#include<time.h>
#include"date.h"
#include"avion.h"
#include"avion.cpp"
#include"vol.h"
#include"destination.h"
#include"voyageur.h"
using namespace std;
vol::vol()
       {
      }
vol::vol(int num)
            {
    n_vol=num;
        }
void vol::annuller_reservation(int pos)
       {
          passager[pos]=passager[passager.size()-1];
           passager.pop_back();
       }
date vol :: getDate (){
return m_date;
}
bool vol::recherche(const vector<vol> &vols,int &pos)
          {unsigned i=0;
           unsigned trouve=false;
           while(i<vols.size() && trouve==false)
           {
             if(vols[i].n_vol==pos)
            {
               trouve=true;
                pos=i;
               }
              else
                 i++;
             }
          return trouve;
}
bool vol::recherche_pass(string nn)
      {unsigned i=0;
         unsigned trouve=false;
           while(i<passager.size() && trouve==false)
           {
             if(passager[i].get_npass()==nn)
             {
             trouve=true;
         }
               else
                 i++;
              }
          return trouve;
}
void vol::recherche_age(int a)
      {unsigned i=0;
           while(i<passager.size())
           {
             if(passager[i].get_age()<a)
             {
             passager[i].affiche();
             i++;
             cout << endl ;
             cout << endl ;
         }
               else
                 i++;
              }
}
void vol::modifier_vol()
         {
           time_t temps;
            struct tm * t;
               m_date.amj();
               m_date.heurs();
               temps=time(NULL);
                 t = localtime(&temps);
               while(!controle_date(t->tm_year,t->tm_mon,t->tm_mday,t->tm_hour,
                   t->tm_min))
                 {
                  cout<<" erreur !!!\a\a ce date est deja depasser !!!!"<<endl;
                  m_date.amj();
                 m_date.heurs();
                  temps=time(NULL);
                    t = localtime(&temps);
                   }
          }
void vol::ajout_vol(int num,avion &av,float p)
         {
            m_avion= avion(av);
           time_t temps;
            struct tm * t;
               n_vol=num;
               prix=p;
               m_date.amj();
               m_date.heurs();
               temps=time(NULL);
                 t = localtime(&temps);
               while(!controle_date(t->tm_year,t->tm_mon,t->tm_mday,t->tm_hour,
                   t->tm_min))
                 {
                  cout<<" erreur !!!\a\a ce date est deja depasser !!!!"<<endl;
                  m_date.amj();
                 m_date.heurs();
                  temps=time(NULL);
                    t = localtime(&temps);
                   }
                 m_destination.dest();
          }
void vol::modifier_date()
               {
              m_date.amj();
               }
void vol::modifier_heur()
            {
             m_date.heurs();
            }
void vol::afficher()
       {
           cout<<"  "<<n_vol<<"\t\t"<<m_destination.get_depart()<<"\t\t"<<m_destination.get_arrivee()<<"\t\t"<<m_date.afficher() <<"\t\t"<<prix << " Dhs\t\t"<<m_avion.getModele() <<endl;
       }
void vol :: modifier_pass(){

for(unsigned i=0;i<passager.size();i++){

                 passager[i].modifier();
                 cout << endl;
                 cout << endl;}


}
void vol::afficher_pass()
            {
             cout<<"numero de vol est :"<<n_vol<<endl;
              if(passager.empty())  // Si le tableau est vide.
                {
                  cout<<" aucun reservation !!!!!"<<endl;
                }
                else
                {
                 for(unsigned i=0;i<passager.size();i++){
                 passager[i].affiche();
                 cout << endl;
                 cout << endl;}
                  }
       }
void vol::reserver()
       {
                    voyageur xxx;
                    if(passager.size()==m_avion.getNbPlaces())
                    cout<<"vous ne pouvez pas reserver la vol est pleinne !!!!!!"<<endl;
                    else
                    {
                     passager.push_back(xxx);
                    passager[passager.size()-1].reservation();
                    }
       }
bool vol::controle_date(int a,int m,int j,int h,int mi)
       {
             return m_date.controle_date(a,m,j,h,m);
         }
void vol::ecrire_fichier(fstream &fichier)
         {
   fichier <<n_vol<<"\t"<<m_destination.get_depart()<<"\t"<<m_destination.get_arrivee()<<"\t"<<prix<<"\t";
        m_date.ecrire_fichier(fichier);
       for(unsigned i=0;i<passager.size();i++)
       passager[i].ecrire_fichier(fichier);
        }
void vol::lire_fichier(fstream &fichier)
        {
    voyageur vvv;
  fichier >>n_vol;
  m_destination.lire_fichier(fichier);
  fichier >>prix;
  m_date.lire_fichier(fichier);
  for(unsigned i=0;i<10;i++)
  {
      passager.push_back(vvv);
      passager[i].lire_fichier(fichier);
  }
}
