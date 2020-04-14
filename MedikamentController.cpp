#include "MedikamentController.h"
#include "MedikamentRepository.h"

#include <iostream>
#include <string>
#include <vector>
#include <graphics.h>

using namespace std;

MedikamentController::MedikamentController(MedikamentRepository* r)
{
    m_repo = r;
}

MedikamentController::~MedikamentController()
{

}

//Punkt1
//Funktion fur das Hinzufugen der Medikamente
void MedikamentController::Medikament_hinzufugen(Medikament med)
{
    if(m_repo->search_Medikament(med.getName(), med.getKonzentration()) == -1)
        m_repo->add_Medikament(med);
    else
        m_repo->update_Medikament(med.getName(), med.getKonzentration(), med.getMenge(), med.getPreis());
}

//Funktion fur das Loschen der Medikamente
void MedikamentController::Medikament_loschen(Medikament med) // Identificare dupa "Name" si "Konzentration"
{
    if(m_repo->search_Medikament(med.getName(), med.getKonzentration()) > 1) //daca am mai multe medicamente...modifica menge
        m_repo->update_Medikament(med.getName(), med.getKonzentration(), med.getMenge(), med.getPreis());
    else
        m_repo->delete_Medikament(med.getName(), med.getMenge()); //altfel...sterge medicamentul
}

//Funktion fur das Bearbeiten der Medikamente (modifici date legate de medicament(Menge si Preis))
void MedikamentController::Medikament_bearbeiten(Medikament med)
{

}

void verfugbaren_Medikamente(Medikament med)
{

}
//Punkt 3
void Medikamente_knapp(Medikament med, int X)
{

}
//Punkt 4
void Medikamente_nach_Preis(Medikament med)
{

}
