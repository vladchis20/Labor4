#ifndef MEDIKAMENTCONTROLLER_H
#define MEDIKAMENTCONTROLLER_H
#include "MedikamentRepository.h"

class MedikamentController
{
    public:
        MedikamentController(MedikamentRepository* r);
        ~MedikamentController();

        //Punkt 1
        void Medikament_hinzufugen(Medikament med);

        void Medikament_loschen(Medikament med);

        void Medikament_bearbeiten(Medikament med);
        //Punkt 2
        void verfugbaren_Medikamente(Medikament med);
        //Punkt 3
        void Medikamente_knapp(Medikament med, int X);
        //Punkt 4
        void Medikamente_nach_Preis(Medikament med);
        /*
        //Punkt 5
        void Undo(Medikament med);

        void Redo(Medikament med);
        */

    private:
        MedikamentRepository* m_repo;
};

#endif // MEDIKAMENTCONTROLLER_H
