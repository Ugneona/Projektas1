#include "Patikrinimas.h"
#include "Uzpildymas.h"
#include "Skaiciavimai.h"
#include "Failas.h"
#include "Spausdinimas.h"


int main()
{
    int studentSk;
    vector <studentas> grupe;
    char ats, klsm, klsm_nr2;

    klsm = uzklausa_delFailuDarbo();
    cout << "\n";

    if (klsm == 't' || klsm == 'T')
    {
        klsm_nr2 = uzklausa_delFailuGeneravimo();
        cout << "\n";

        vector <int> v = { 1000, 10000, 100000, 1000000, 10000000 };

        if (klsm_nr2 == 't' || klsm_nr2 == 'T')
        {
            int namuDarbuSkaicius;

            namuDarbuSkaicius = uzklausa_kiekNdYra();
            cout << "\n";

            ats = Uzklausa_Ats();

            cout << "\n";

            failuKurimas(v, namuDarbuSkaicius);

            cout << "\n";

            darbasSuFailu_nr1(v, ats);

        }
        else
        {
            ats = Uzklausa_Ats();

            cout << "\n";

            darbasSuFailu(v, ats);

        }
    }
    else
    {
        klsm = uzklausa_delFailo();
        cout << "\n";

        if (klsm == 't' || klsm == 'T')
        {
            failas();
        }
        else
        {
            klsm = uzklausa_delGeneravimo();
            cout << "\n";

            if (klsm == 't' || klsm == 'T')
            {
                studentSk = studentuSkaiciausUzklausa();
                cout << "\n";

                studentoUzpildymasVardPavardNdEgz(studentSk, grupe);
            }
            else {
                studentSk = studentuSkaiciausUzklausa();
                cout << "\n";

                studentoUzpildymasRnd(studentSk, grupe);
            }

            cout << "\n";

            ats = uzklausa_delAtsakymo();

            cout << "\n";

            spausdinti_vector_nr2(ats, grupe);
        }
    }
    return 0;
}