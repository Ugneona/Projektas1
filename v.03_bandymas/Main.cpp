#include "Antraste.h"
#include "Studentas.h"
#include "Uzklausos.h"
#include "Skaiciavimai.h"
#include "Spausdinimas.h"
#include "Uzpildymas.h"
#include "Failas.h"


int main()
{
    int studentSk;
    studentas grupe[100];
    char ats, klsm;

    klsm = uzklausa_delFailo();

    if (klsm == 't' || klsm == 'T')
    {
        Failas();
    }
    else
    {
        klsm = uzklausa_delGeneravimo();

        if (klsm == 't' || klsm == 'T')
        {
            studentSk = studentuSkaiciausUzklausa();

            studentoUzpildymasVardPavardNdEgz(studentSk, grupe);
        }
        else {
            studentSk = studentuSkaiciausUzklausa();

            studentoUzpildymasRnd(studentSk, grupe);
        }
        ats = uzklausa_delAtsakymo();

        spausdinti_struct(ats, grupe, studentSk);
    }
    return 0;
}
