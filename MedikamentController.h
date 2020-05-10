#ifndef MEDIKAMENTCONTROLLER_H
#define MEDIKAMENTCONTROLLER_H
#include "MedikamentRepository.h"

#include <stack>

using namespace std;

class MedikamentController
{
    public:
        MedikamentController(MedikamentRepository* r);
        ~MedikamentController();

        void Medikamente_anzusehen();

        //Punkt 1
        void Medikament_hinzufugen(Medikament med);

        void Medikament_loschen(Medikament med);

        void Medikament_bearbeiten(Medikament med);
        //Punkt 2
        void verfugbaren_Medikamente();
        //Punkt 3
        void Medikamente_knapp(int X);
        //Punkt 4
        void Medikamente_nach_Preis();
        //Punkt 5
        void undoOperation();

        void redoOperation();

    private:
        // pair: Medikamentul adaugat/sters din repo
        // int = 0 - add, 1 - remove
        stack<pair<Medikament, int>> m_undoStack;
        stack<pair<Medikament, int>> m_redoStack;
        MedikamentRepository* m_repo;
};

#endif // MEDIKAMENTCONTROLLER_H
