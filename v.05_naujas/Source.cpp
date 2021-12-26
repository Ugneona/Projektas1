#include "Patikrinimas.h"
#include "Uzpildymas.h"
#include "Skaiciavimai.h"
#include "Failas.h"
#include "Spausdinimas.h"

int main()
{
    int studentSk;
    studentas grupe[100];
    char ats, klsm;

    klsm = uzklausa_delFailuKurimu();

    if (klsm == 't' || klsm == 'T')
    {
        int namuDarbuSkaicius;
        vector <int> v = { 1000, 10000, 100000, 1000000, 10000000 };

        namuDarbuSkaicius = uzklausa_kiekNdYra();

        ats = Uzklausa_Ats();

        cout << "\n";

        failuKurimas(v, namuDarbuSkaicius);

        cout << "\n";

        darbasSuFailu(v, namuDarbuSkaicius, ats);
    }
    else
    {
        klsm = uzklausa_delFailo();

        if (klsm == 't' || klsm == 'T')
        {
            failas();
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
    }
    return 0;
}