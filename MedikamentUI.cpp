#include "MedikamentUI.h"
#include <iostream>
#include <string>
#include <vector>
#include <graphics.h>

#include "MedikamentController.h"
#include "MedikamentRepository.h"
#include "Medikament.h"

using namespace std;

MedikamentUI::MedikamentUI(MedikamentController* c)
{
    controller = c;
}

MedikamentUI::~MedikamentUI()
{

}

void MedikamentUI::Afisare_Exit()
{
    exit(7);
    cout<<"Exit";
}

void MedikamentUI::Afisare_Medikamente_hinzufugen(Medikament med) //aduagare medicamente
{
    string name;
    int konzentration, menge, preis;
    cout<<"Name: "; cin>>name;
    med.setName(name);
    cout<<"Konzentration: "; cin>>konzentration;
    med.setKonzentration(konzentration);
    cout<<"Menge: "; cin>>menge;
    med.setMenge(menge);
    cout<<"Preis: "; cin>>preis;
    med.setPreis(preis);
    controller->Medikament_hinzufugen(med);
}

void MedikamentUI::Afisare_Medikamente_loschen(Medikament med) //stergere medicamente
{
    string name;
    int konzentration, menge, preis;
    cout<<"Name: "; cin>>name;
    med.setName(name);
    cout<<"Konzentration: "; cin>>konzentration;
    med.setKonzentration(konzentration);
    controller->Medikament_loschen(med);
}

void MedikamentUI::Afisare_Medikamente_bearbeiten(Medikament med) //modificare medicamente
{
    string name;
    int konzentration, menge, preis;
    cout<<"Name: "; cin>>name;
    med.setName(name);
    cout<<"Konzentration: "; cin>>konzentration;
    med.setKonzentration(konzentration);
    controller->Medikament_bearbeiten(med);
}

void MedikamentUI::Punkt1(Medikament med) //meniu pentru cerintele de la punctul 1
{
    int opt1;
    cout<<endl;
    cout<<"Menu Punkt 1"<<endl;
    cout<<"Fur Medikamente hinzufugen => Taste 1"<<endl;
    cout<<"Fur Medikamente loschen => Taste 2"<<endl;
    cout<<"Fur Medikamente bearbeiten => Taste 3"<<endl;
    cout<<"Fur Hauptmenu => Taste 4"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt1;
        switch(opt1)
        {
            case 1: Afisare_Medikamente_hinzufugen(med); break;
            case 2: Afisare_Medikamente_loschen(med); break;
            case 3: Afisare_Medikamente_bearbeiten(med); break;
            case 4: Hauptmenu(med); break;
        }
    }while(true);
}

void MedikamentUI::verfugbare_Medikamente(Medikament med) //medicamente disponibile
{
    string name;
    int konzentration, menge, preis;
    //controller->verfugbaren_Medikamente(med);
}

void MedikamentUI::Punkt2(Medikament med) //meniu pentru cerintele de la punctul 2
{
    int opt2;
    cout<<endl;
    cout<<"Menu Punkt 2"<<endl;
    cout<<"Fur Medikamente hinzufugen => Taste 1"<<endl;
    cout<<"Fur Hauptmenu => Taste 2"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt2;
        switch(opt2)
        {
            case 1: verfugbare_Medikamente(med); break;
            case 2: Hauptmenu(med); break;
        }
    }while(true);
}

void MedikamentUI::Medikamente_kanpp_als_X(Medikament med) //medicamente mai putine decat X
{
    string name;
    int konzentration, menge, preis;
    //controller->Medikamente_knapp(med);
}

void MedikamentUI::Punkt3(Medikament med) //meniu pentru cerintele de la punctul 3
{
    int opt3;
    cout<<endl;
    cout<<"Menu Punkt 3"<<endl;
    cout<<"Fur Medikamente knapp als X => Taste 1"<<endl;
    cout<<"Fur Hauptmenu => Taste 2"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt3;
        switch(opt3)
        {
            case 1: Medikamente_kanpp_als_X(med); break;
            case 2: Hauptmenu(med); break;
        }
    }while(true);
}

void MedikamentUI::Medikamente_nach_Preis(Medikament med) //medicamente ordonate crescator dupa pret
{
    string name;
    int konzentration, menge, preis;
    cout<<"Die Medikamente geordnet nach Preis sind: "<<endl;
    //controller->Medikamente_nach_Preis(med);
}

void MedikamentUI::Punkt4(Medikament med) //meniu pentru cerintele de la punctul 4
{
    int opt4;
    cout<<endl;
    cout<<"Menu Punkt 4"<<endl;
    cout<<"Fur Medikamente nach Preis => Taste 1"<<endl;
    cout<<"Fur Hauptmenu => Taste 2"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt4;
        switch(opt4)
        {
            case 1: Medikamente_nach_Preis(med); break;
            case 2: Hauptmenu(med); break;
        }
    }while(true);
}

void MedikamentUI::Hauptmenu(Medikament med) //meniu principal
{
    int opt;
    cout<<endl;
    cout<<"Hauptmenu"<<endl;
    cout<<"Fur Punkt 1 => Taste 1"<<endl;
    cout<<"Fur Punkt 2 => Taste 2"<<endl;
    cout<<"Fur Punkt 3 => Taste 3"<<endl;
    cout<<"Fur Punkt 4 => Taste 4"<<endl;
    cout<<"Fur Beenden des Programms => Taste 5"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt;
        switch(opt)
        {
            case 1: Punkt1(med); break;
            case 2: Punkt2(med); break;
            case 3: Punkt3(med); break;
            case 4: Punkt4(med); break;
            case 5: Afisare_Exit(); break;
        }
    }while(true);
}
