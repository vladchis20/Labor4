#include "MedikamentController.h"
#include "MedikamentRepository.h"

#include <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

MedikamentController::MedikamentController(MedikamentRepository* r)
{
    m_repo = r;
}

MedikamentController::~MedikamentController()
{

}

//aici trebuie afisate toate medicamentele existente
void MedikamentController::Medikamente_anzusehen()
{
    m_repo->display_repo();
}

//Punkt1
//Funktion fur das Hinzufugen der Medikamente
void MedikamentController::Medikament_hinzufugen(Medikament med)
{
    if(m_repo->search_Medikament(med.getName(), med.getKonzentration()) == -1)
    {
        m_repo->add_Medikament(med);
        cout<<"Ein neues Medikament wurde eingefugt";
        m_undoStack.push(std::pair<Medikament, int>(med, 0));
    }
    else
    {
        m_repo->update_Medikament(med.getName(), med.getKonzentration(), med.getMenge(), med.getPreis(), med.getNeuesMenge(), med.getNeuesPreis());
        cout<<"Die Menge von "<<med.getName()<<" ist grosser geworden";
    }

}

//Funktion fur das Loschen der Medikamente
void MedikamentController::Medikament_loschen(Medikament med) // Identificare dupa "Name" si "Konzentration"
{
    if(m_repo->search_Medikament(med.getName(), med.getKonzentration()) > 1) //daca am mai multe medicamente...modifica menge
    {
        m_repo->update_Medikament(med.getName(), med.getKonzentration(), med.getMenge(), med.getPreis(), med.getNeuesMenge(), med.getNeuesPreis());
        cout<<"Die Menge von "<<med.getName()<<" ist kleiner geworden";
    }
    else
        if(m_repo->search_Medikament(med.getName(), med.getKonzentration()) == 1) //daca mai e un singur medicament pe stoc
        {
            m_repo->delete_Medikament(med.getName(), med.getMenge()); //sterge medicamentul
            cout<<"Das Medikament wurde geloscht";
            m_undoStack.push(std::pair<Medikament, int>(med, 1));
        }

        else
            if(m_repo->search_Medikament(med.getName(), med.getKonzentration()) == -1) //daca nu exista medicamentul cautat
                cout<<"Dieses Medikament existiert nicht. Bitte loschen Sie einen existierenden Medikament";
}

//Funktion fur das Bearbeiten der Medikamente (modifici date legate de medicament(Menge si Preis))
void MedikamentController::Medikament_bearbeiten(Medikament med)
{
    if(m_repo->search_Medikament(med.getName(), med.getKonzentration()) == -1) //daca medicamentul cautat nu este gasit
        cout<<"Dises Medikament existiert nicht! Bitte suchen Sie einen anderen Medikament."; //mesaj de eroare
    else //altfel...modific datele medicamentului
    {


        m_repo->update_Medikament(med.getName(), med.getKonzentration(), med.getMenge(), med.getPreis(), med.getNeuesMenge(), med.getNeuesPreis());
        cout<<"Das Medikament wurde bearbeitet";
    }

}

void MedikamentController::verfugbaren_Medikamente() //afisez medicamentele existente pe stoc (Menge > 0)
{
    m_repo->displayMedikamentMengeNonZero();
}
//Punkt 3
void MedikamentController::Medikamente_knapp(int X) //afisez doar medicamentele in cantitate mai mica decat X
{
    m_repo->displayMedikamentMengeKleinerX(X);
}
//Punkt 4
void MedikamentController::Medikamente_nach_Preis() //afisare in ordine crescatoare dupa pret
{
    m_repo->displaySortedByPrice();
}

void  MedikamentController::undoOperation()
{
    if(m_undoStack.empty()){
      cout<<"empty undo stack";
      return;
    }
   std::pair<Medikament, int> op = m_undoStack.top();

   m_undoStack.pop();

   if(op.second == 0)// op type a fost add
      m_repo->delete_Medikament(op.first.getName(), op.first.getMenge());

   if(op.second == 1)// op type a fost add
      m_repo->add_Medikament(op.first);

  m_redoStack.push(op);
}

void  MedikamentController::redoOperation()
{
    if(m_redoStack.empty()){
      cout<<"empty redo stack";
      return;
    }
   std::pair<Medikament, int> op = m_undoStack.top();

   m_undoStack.pop();

   if(op.second == 0)// op type a fost add
      m_repo->add_Medikament(op.first);

   if(op.second == 1)// op type a fost add
      m_repo->delete_Medikament(op.first.getName(), op.first.getMenge());

  m_redoStack.push(op);
}
