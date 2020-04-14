#include <iostream>
#include "Medikament.h"
#include "MedikamentController.h"
#include "MedikamentRepository.h"
#include "MedikamentUI.h"

using namespace std;

int main()
{
    Medikament med;
    MedikamentRepository *repo = new MedikamentRepository();
    MedikamentController *ctrl = new MedikamentController(repo);
    MedikamentUI *ui = new MedikamentUI(ctrl);
    ui->Hauptmenu(med);
    return 0;
}
