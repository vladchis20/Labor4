#include <iostream>
#include "Medikament.h"
#include "MedikamentController.h"
#include "MedikamentRepository.h"
#include "MedikamentUI.h"

using namespace std;

int main()
{
    //Introducerea medicamentelor
    MedikamentRepository *m = new MedikamentRepository();
    //Name, Konzentration, Menge, Preis
    Medikament m1("Aspacardin", 250, 20, 15);
    m->add_Medikament(m1);
    Medikament m2("Nurofen", 150, 15, 10);
    m->add_Medikament(m2);
    Medikament m3("Paracetamol", 300, 56, 18);
    m->add_Medikament(m3);
    Medikament m4("Theraflu", 200, 23, 7);
    m->add_Medikament(m4);
    Medikament m5("ACC", 50, 0, 5);
    m->add_Medikament(m5);
    Medikament m6("Acc Junior", 20, 2, 20);
    m->add_Medikament(m6);
    Medikament m7("Aceclofen", 500, 200, 30);
    m->add_Medikament(m7);
    Medikament m8("Zyrtec", 25, 70, 5);
    m->add_Medikament(m8);
    Medikament m9("Ibuprofen", 75, 20, 15);
    m->add_Medikament(m9);
    Medikament m10("Strepsils", 10, 40, 35);
    m->add_Medikament(m10);

    Medikament med;
    MedikamentController *ctrl = new MedikamentController(m);
    MedikamentUI *ui = new MedikamentUI(ctrl);
    ui->Hauptmenu();
    return 0;
}
