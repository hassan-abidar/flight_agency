#include <iostream>
#include<vector>
#include<string>
#include <ctime>
#include"vol.h"
#include "avion.h"
#include <fstream>



using namespace std;

int main()
{

    int choix;
    unsigned i=0;
    vector<vol> liste;
    vector<avion> avions;
    avion av;
    vol v;


      while(1)
    {

        system("cls");
    cout<<"                ___________________     [ M E N U ]      __________________ "<<endl;
    cout<<"               |                                                           |"<<endl;
    cout<<"               |  1  --------      Liste des Avions       --------------   |"<<endl;
    cout<<"               |  2  ------------   Liste des vols   --------------------  |"<<endl;
    cout<<"               |  3  -------  Liste des vols de Lendemain  --------------  |"<<endl;
    cout<<"               |  4  ----------   Enregister une avion  ----------------   |"<<endl;
    cout<<"               |  5  ------------   rechercher un vol  -----------------   |"<<endl;
    cout<<"               |  6  ------------- Enregistrer un vol ------------------   |"<<endl;
    cout<<"               |  7  ------------   Modifier un vol   ------------------   |"<<endl;
    cout<<"               |  8 ------------    Reserver un vol     ----------------   |"<<endl;
    cout<<"               |  9  ------------   Supprimer un vol     ---------------   |"<<endl;
    cout<<"               | 10  ------------  Recherche passager ------------------   |"<<endl;
    cout<<"               | 11  ------------  Modifier passager  ------------------   |"<<endl;
    cout<<"               | 12  ------   Recherche passager d'apres l'age ---------   |"<<endl;
    cout<<"               | 13  -------- Afficher la liste des passagers------------  |"<<endl;
    cout<<"               | 14 ------------         QUITTER       --------------------|"<<endl;
    cout<<"               |___________________________________________________________|"<<endl;

    cout<<"\n entrez votre choix :  ";
    cin>>choix;
    while(choix<1 || choix>14 )
    {   if (cin.fail()){
        cin.clear(); cin.ignore(512, '\n');
        cout << "Invalide !! Entrez un nombre !!\n";}
        cout<<"\n votre choix est erronne \a\a !!!!!!"<<endl;
        cout<<"reentrez votre choix :  ";
        cin>>choix;
    }
    switch(choix)
    {
        case 1 : {
              if(avions.empty())
                     cout<<" La liste des avions des vide !!!!"<<endl;

                else
                {
                 system("cls");
                 cout<<"  NbAvion \t Pilote \t Modele \t NbPlaces \t NbVolsAssure \t     DateFabrication \n\n";
                 for(i=0;i<avions.size();i++)
                 {
                     avions[i].afficher();
                 }
                 }
                 cout<<"\n\n";
                 system("pause");break;
            }
        case 2 :if(liste.empty())
                     cout<<" Aucun vol n'est disponible maintenant !!!!"<<endl;

                else
                {

                 cout<<"  NumeroVol \t Depart \t Arrivee \t Date \t\t\t Prix \t     ModeleAvion \n\n";

                 for(i=0;i<liste.size();i++)
                 {
                     liste[i].afficher();
                 }
                 }
                 cout<<"\n\n";
                 system("pause");break;
        case 3 :
            {
                 cout<<"                     ***********  Les vols disponibles de Lendemain  ************\n\n\n";
                time_t t = time(0);
                tm* now = localtime(&t);
                int day =now->tm_mday;
                int year =now->tm_year + 1900;
                int month = now->tm_mon + 1;
                if(day == 31 && month == 12 ){
                    day=1;year++;month=1;
                }
                else if (day == 31 && (month == 1 || month == 3 ||month == 5 || month == 7 ||month == 8 || month == 10 )){
                    day=1;
                    month++;
                }
                else if (day == 30 && (month == 2 || month == 4 ||month == 6 || month == 9 ||month == 11 )){
                    day=1;
                    month++;
                }
                else{
                    day++;}

                 for(i=0;i<liste.size();i++)
                 {
                     if(liste[i].getDate().getDay()==day && liste[i].getDate().getMonth()==month && liste[i].getDate().getYear()==year)
                        liste[i].afficher();


                 }
                 cout<<"\n\n";
                 system("pause");break;}
        case 4 :
            {
                 string ch;
                 int index;
                 cout<<"\n saisir le numero d'avion a ajouter : ";
                 cin>>ch;
                 bool i = av.recherche(avions,ch,index);
                 if(i==true)
                 cout<<"\n\n ce numero de vol existe dans la liste !! \n ";
                 else {
                 int nb;

                 av.ajouterAvion(ch);
                 avions.push_back(av);}
                 system("pause");
                 system("cli"); break;
            }
        case 5 :
            {
                  if(liste.empty())
                     cout<<" Aucun vol n'est disponible maintenant !!!!"<<endl;

                else
                {
                    int nm;
                    cout<<"entrez le num de vol que vous voulez chercher : ";
                    cin>>nm;
                 system("cls");
                 bool i = v.recherche(liste,nm);
                 if(i==false)
                 cout<<"\n\n ce vol n'existe pas dans la liste\n";
                 else
                  liste[nm].afficher();

                 }
                 cout<<"\n\n";
                 system("pause");break;
    }
        case 6 :
            {
                int ch,index;
                float prix;
                string code;
                int num;
                 cout<<"\n saisir le numero du vol a ajouter : ";
                 cin>>ch;
                 cout<<"\n saisir le prix du vol a ajouter : ";
                 cin>>prix;
                 bool i = v.recherche(liste,ch);
                 if(i==true)
                 cout<<"\n\n ce numero de vol existe dans la liste !! ";
                 else {
                 int nb;
                 cout<<"\n saisir le code d'avion : ";
                 cin>> code;
                 bool i = av.recherche(avions,code,index);
                 if(i==false)
                 cout<<"\n\n Cette avion n'existe pas \n";
                 else {
                 v.ajout_vol(ch,avions[index],prix);
                 liste.push_back(v);}}
                 system("pause");
                 system("cli"); break;
            }
        case 7 :
             if(liste.empty())
                      cout<<"\n \n Aucun vol n'est disponible maintenant !!!!"<<endl;


                else
                {
                    int nm;
                    cout<<"entrez le num de vol que vous voulez modifier : ";
                    cin>>nm;
                 system("cls");
                 bool i= v.recherche(liste,nm);
                 if(i==false)
                 cout<<"\n\n ce vol n'existe pas dans la liste\n";
                 else
                 {
                  liste[nm].modifier_vol();

                 }

                 }
                 cout<<"\n\n";
                 system("pause");break;

        case 8 :
            {
            int nm;
            cout<<"entrez le num de vol que vous voulez reserver : ";
            cin>>nm;
            system("cls");
                  bool i = v.recherche(liste,nm);
                 if(i==false)
                 cout<<"\n\n ce vol n'existe pas dans la liste\n";
                 else
                 {
                  liste[nm].reserver();
                 }
                 system("pause");break;}
        case 9 : {
        if(liste.empty())
                      cout<<"\n \n Aucun vol trouvee  !!!!"<<endl;


                else
                {
                    int nm;
                    cout<<"entrez le num de vol que vous voulez supprimer : ";
                    cin>>nm;
                 system("cls");
                 bool i= v.recherche(liste,nm);
                 if(i==false)
                 cout<<"\n\n ce vol n'existe pas dans la liste\n";
                 else
                 {
                  liste[nm]=liste[liste.size()-1];
                  liste.pop_back();

                 }

                 }
                 cout<<"\n\n";
                 system("pause");break;
        }
        case 10:
{
             if(liste.empty())
                      cout<<"\n \n Aucun vol n'est disponible maintenant !!!!"<<endl;


                else
                {
                    string ch;
                    cout<<"\n saisir le passport du passager :"<<endl;
                    cin>>ch;
                    cout<<"\n Les vols de ["<< ch << "] sont : " << endl;
                    cout << endl;
                    for(unsigned i=0;i<liste.size();i++){
                    if (liste[i].recherche_pass(ch)== true){
                    liste[i].afficher();
                    cout << endl;
                    cout << endl;}
                    }
                }


                 system("pause");break;
}
        case 11 :
                {
                     if(liste.empty())
                      cout<<"\n \n Aucun vol n'est disponible maintenant !!!!"<<endl;


                else
                {
                    string ch;
                    cout<<"\n saisir le passport du passager :"<<endl;
                    cin>>ch;
                    cout << endl;
                    for(unsigned i=0;i<liste.size();i++){
                    if (liste[i].recherche_pass(ch)== true){
                    liste[i].modifier_pass();
                    cout << endl;
                    cout << endl;}
                    }
                }


                 system("pause");break;
                }
        case 12 :
{
                int age ;
                int c=0;
                cout << "Entrez l'age maximale des passagers : " ;
                cin >> age ;
                    for(unsigned i=0;i<liste.size();i++){
                    liste[i].recherche_age(age);
                    c++;
                    }
                if(c==0)
                cout << "Aucun passager est moins de " << age << "ans !!"<< endl;
                 cout<<"\n\n";
                 system("pause");break;

}
        case 13 :
            {
                 if(liste.empty())
                      cout<<"\n \n Aucun vol n'est disponible maintenant !!!!"<<endl;


                else
                {
                    int nm;
                    cout<<"entrez le num de vol que vous voulez chercher : ";
                    cin>>nm;
                 system("cls");
                 bool i = v.recherche(liste,nm);
                 if(i==false)
                 cout<<"\n\n ce vol n'existe pas dans la liste\n";
                 else
                  liste[nm].afficher_pass();

                 }
                 cout<<"\n\n";
                 system("pause");break;

            }
            case 14 :
                {
                    {
			fstream f;//enregistrement de liste des voyages
			f.open("vol.txt", ios::in | ios::out | ios::trunc);
			if (!f.is_open()) cout << "erreur d'ouverture du fichier" << endl;
			else
				f.seekg(0);
            for(unsigned i=0;i<liste.size();i++)
			       liste[i].ecrire_fichier(f);
			f.close();
		}
			exit(-1);
		}
    }
    }
    return 0;
}

