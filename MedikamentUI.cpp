#include "MedikamentUI.h"
#include <iostream>
#include <string>
#include <vector>


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

void MedikamentUI::Undo()
{
    controller->undoOperation();
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Redo(){
    controller->redoOperation();
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Afisare_Medikamente_anzusehen() //functia de afisare a tuturor medicamentelor
{
    cout<<"Die existierende Medikamente sind: "<<endl;
    controller->Medikamente_anzusehen();
    cout<<"Bitte ihre nachste Option einfugen: "; //asa se pot efectua alte comenzi
}

void MedikamentUI::Afisare_Medikamente_hinzufugen()//aduagare medicamente
{
    string name;
    Medikament med;
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
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Afisare_Medikamente_loschen() //stergere medicamente
{
    string name;
    Medikament med;
    int konzentration, menge, preis;
    cout<<"Name: "; cin>>name;
    med.setName(name);
    cout<<"Konzentration: "; cin>>konzentration;
    med.setKonzentration(konzentration);
    controller->Medikament_loschen(med);
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Afisare_Medikamente_bearbeiten() //modificare medicamente
{
    string name;
    Medikament med;
    int konzentration, menge, preis;
    cout<<"Name: "; cin>>name;
    med.setName(name);
    cout<<"Konzentration: "; cin>>konzentration;
    med.setKonzentration(konzentration);
    cout<<"Die neue Menge ist: "; cin>>menge;
    med.setMenge(menge);
    cout<<"Der neue Preis ist: "; cin>>preis;
    med.setPreis(preis);
    controller->Medikament_bearbeiten(med);
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Punkt1() //meniu pentru cerintele de la punctul 1
{
    int opt1;
    cout<<endl;
    cout<<"Menu Punkt 1"<<endl;
    cout<<"Fur Medikamente hinzufugen => Taste 1"<<endl;
    cout<<"Fur Medikamente loschen => Taste 2"<<endl;
    cout<<"Fur Medikamente bearbeiten => Taste 3"<<endl;
    cout<<"Fur Undo => Taste 4"<<endl;
    cout<<"Fur Redo => Taste 5"<<endl;
    cout<<"Fur Hauptmenu => Taste 6"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt1;
        switch(opt1)
        {
            case 1: Afisare_Medikamente_hinzufugen(); break;
            case 2: Afisare_Medikamente_loschen(); break;
            case 3: Afisare_Medikamente_bearbeiten(); break;
            case 4: Undo(); break;
            case 5: Redo(); break;
            case 6: Hauptmenu(); break;
        }
    }while(true);
}

void MedikamentUI::verfugbare_Medikamente() //medicamente disponibile
{
    string name;
    int konzentration, menge, preis;
    controller->verfugbaren_Medikamente();
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Punkt2() //meniu pentru cerintele de la punctul 2
{
    int opt2;
    cout<<endl;
    cout<<"Menu Punkt 2"<<endl;
    cout<<"Fur verfugbare Medikamente => Taste 1"<<endl;
    cout<<"Fur Hauptmenu => Taste 2"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt2;
        switch(opt2)
        {
            case 1: verfugbare_Medikamente(); break;
            case 2: Hauptmenu(); break;
        }
    }while(true);
}

void MedikamentUI::Medikamente_kanpp_als_X() //medicamente mai putine decat X
{
    string name;
    int konzentration, menge, preis, X;
    cout<<"Fugen Sie bitte einen Wert ein: "; cin>>X;
    controller->Medikamente_knapp(X);
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Punkt3() //meniu pentru cerintele de la punctul 3
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
            case 1: Medikamente_kanpp_als_X(); break;
            case 2: Hauptmenu(); break;
        }
    }while(true);
}

void MedikamentUI::Medikamente_nach_Preis() //medicamente ordonate crescator dupa pret
{
    string name;
    int konzentration, menge, preis;
    cout<<"Die Medikamente geordnet nach Preis sind: "<<endl;
    controller->Medikamente_nach_Preis();
    cout<<endl<<"Bitte ihre nachste Option einfugen: ";
}

void MedikamentUI::Punkt4() //meniu pentru cerintele de la punctul 4
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
            case 1: Medikamente_nach_Preis(); break;
            case 2: Hauptmenu(); break;
        }
    }while(true);
}

void MedikamentUI::Hauptmenu() //meniu principal
{
    int opt;
    cout<<endl;
    cout<<"Hauptmenu"<<endl;
    cout<<"Fur Punkt 1 => Taste 1"<<endl;
    cout<<"Fur Punkt 2 => Taste 2"<<endl;
    cout<<"Fur Punkt 3 => Taste 3"<<endl;
    cout<<"Fur Punkt 4 => Taste 4"<<endl;
    cout<<"Fur Medikamente anzusehen => Taste 5"<<endl;
    cout<<"Fur Beenden des Programms => Taste 6"<<endl;
    cout<<"Ihre Option ist: ";
    do
    {
        cin>>opt;
        switch(opt)
        {
            case 1: Punkt1(); break;
            case 2: Punkt2(); break;
            case 3: Punkt3(); break;
            case 4: Punkt4(); break;
            case 5: Afisare_Medikamente_anzusehen(); break;
            case 6: Afisare_Exit(); break;
        }
    }while(true);
}
