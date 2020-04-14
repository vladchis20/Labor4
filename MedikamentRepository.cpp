#include "MedikamentRepository.h"
#include "Medikament.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

MedikamentRepository::MedikamentRepository()
{
    capRepo = 1;
    sizeRepo = 0;
    elem = new Medikament[capRepo];
}

MedikamentRepository::~MedikamentRepository()
{
    delete[] elem;
    elem = nullptr;
    capRepo = 0;
    sizeRepo = 0;
}

bool MedikamentRepository::add_Medikament(Medikament m)
{
    if(sizeRepo >= capRepo)
    {
        Medikament* elem_l;
        elem_l = new Medikament[2*capRepo];
        capRepo = 2*capRepo;
        for(int i=0; i<sizeRepo; i++)
        {
            elem_l[i] = elem[i];
        }
        delete[] elem;
        elem = elem_l;
    }
    elem[sizeRepo] = m;
    sizeRepo++;
    return true;
}

int MedikamentRepository::search_Medikament(string x, int y)
{
    int i;
    bool found = false;
    for(i=0; i<sizeRepo; i++)
    {
        Medikament m = elem[i];
        if( (x==m.getName()) && (y==m.getKonzentration()) )
        {
            found = true;
            return i;
        }
    }
    //in cazul in care ai ajuns pana aici, inseamna ca nu ai gasit elementul si returnezi -1
    return -1;
}

bool MedikamentRepository::delete_Medikament(string Name, int Menge)
{

    int i;
    int indexMedikament = search_Medikament( Name, Menge); // indexMedicament stocheaza indexul in array-ul elem

    if(indexMedikament !=-1){ // daca ai gasit medicamentul
        sizeRepo--; // decremetezi dimensiuena repo-ului pentru ca o sa stergi un medicament
        for(int j = indexMedikament; j < sizeRepo; j++) // stergi medicamentul din repo (shiftezi la stanga in array-ul)
            elem[j] = elem[j+1];
    }
    return true;
}

bool MedikamentRepository::update_Medikament(string Name, int Menge, int neue_Menge, int neues_Preis)
{

    int indexMedikament = search_Medikament(Name, Menge); // indexMedicament stocheaza indexul in array-ul

    if(indexMedikament !=-1) // daca ai gasit medicamentul
    {
        // setezi noile campuri
        elem[indexMedikament].setMenge(neue_Menge);
        elem[indexMedikament].setPreis(neues_Preis);
    }

    return false;
}
