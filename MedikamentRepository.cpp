#include "MedikamentRepository.h"
#include "Medikament.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

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
    elem = 0;
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

bool MedikamentRepository::delete_Medikament(string Name, int Konzentration)
{

    int i;
    int indexMedikament = search_Medikament( Name, Konzentration); // indexMedicament stocheaza indexul in array-ul elem

    if(indexMedikament !=-1)  // daca ai gasit medicamentul
    {
        sizeRepo--; // decremetezi dimensiuena repo-ului pentru ca o sa stergi un medicament
        for(int j = indexMedikament; j < sizeRepo; j++) // stergi medicamentul din repo (shiftezi la stanga in array-ul)
            elem[j] = elem[j+1];
    }
    return true;
}

bool MedikamentRepository::update_Medikament(string Name, int Konzentration, int Menge, int Preis,int neues_Menge, int neues_Preis)
{

    int indexMedikament = search_Medikament(Name, Konzentration); // indexMedicament stocheaza indexul in array-ul

    if(indexMedikament !=-1) // daca ai gasit medicamentul
    {
        // setezi noile campuri
        elem[indexMedikament].setMenge(neues_Menge);
        elem[indexMedikament].setPreis(neues_Preis);
    }

    return false;
}

int compMedikamentPries (const void * a, const void * b)
{
    // functie care compara medicamentele dupa pret
    // primeste ca param 2 pointeri de tipul void: void*
    // fac conversia de la void* la Medikament *
    const Medikament* m1 = static_cast<const Medikament*>(a);
    const Medikament* m2 = static_cast<const Medikament*>(b);
    int order = (m1->getPreis() - m2->getPreis());
    return order;
}

void MedikamentRepository::displaySortedByPrice()
{
    int sz = sizeRepo;
    // facem deep copy pentru elemente
    Medikament* sorted = new Medikament[sz];
    //copiem elementele in vectorul sorted
    memcpy(sorted, elem, sizeof(Medikament)*sizeRepo);
    // il sortam folosind qsort
    qsort((void*)sorted, sz, sizeof(sorted[0]), compMedikamentPries);


    // afisam
    for(int i = 0; i < sz; i++)
    {
        cout<<sorted[i].getName()<<" "<<sorted[i].getPreis()<<"\n";
    }
    // steregem memoria alocata ca sa nu avem memory leak
    delete[] sorted;
}

void MedikamentRepository::displayMedikamentMengeNonZero()
{
    // parcurgem toate elementele din repository
    for(int i=0; i<sizeRepo; i++)
    {
        // verifcam faptul ca medicamentul de pe pozitia curenta i are menge >0
        if(elem[i].getMenge() > 0)
        {
            // doar daca aceasta conditie este indeplinita, afisam medicamentul
            cout<<elem[i]<<"\n";
        }

    }

}

void MedikamentRepository::displayMedikamentMengeKleinerX(int X)
{
    for(int i=0; i<sizeRepo; i++)
    {
        // verifcam faptul ca medicamentul de pe pozitia curenta i are menge < X
        if(elem[i].getMenge() < X)
        {
            // doar daca aceasta conditie este indeplinita, afisam medicamentul
            cout<<elem[i]<<"\n";
        }

    }
}
