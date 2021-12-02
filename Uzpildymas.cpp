#include "Uzpildymas.h"

void studentoUzpildymasVardPavardNdEgz(int& studentuSkaicius, studentas(&grupe)[100])
{
    char ats;
    int ndSkaicius;
    double pazymys;

    ats = uzklausa_arNdSkaiciusZinomas();

    if (ats == 't' || ats == 'T')
    {
        ndSkaicius = uzklausa_kiekNdYra();

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> grupe[i].vardas;
            while (check_string(grupe[i].vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> grupe[i].pavarde;
            while (check_string(grupe[i].pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].pavarde;
            }

            cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
            for (int j = 0; j < ndSkaicius; j++)
            {
                cin >> pazymys;
                while (cin.fail() || pazymys < 1 || pazymys > 10)
                {
                    cin.clear();
                    cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
                    cin.ignore(256, '\n');
                    cin >> pazymys;
                }
                grupe[i].nd.push_back(pazymys);
            }

            cout << "Iveskite egzamino pazymi (1-10): " << endl;
            cin >> grupe[i].egz;
            while (cin.fail() || grupe[i].egz <= 0 || grupe[i].egz > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].egz;
            }
            double vid = vidurkis(grupe[i]);
            grupe[i].galutinis_vidurkis = 0.6 * grupe[i].egz + 0.4 * vid;

            double med = mediana(grupe[i]);
            grupe[i].galutinis_mediana = 0.6 * grupe[i].egz + 0.4 * med;

        }
    }
    else {

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> grupe[i].vardas;
            while (check_string(grupe[i].vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> grupe[i].pavarde;
            while (check_string(grupe[i].pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].pavarde;
            }

            cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
            cin >> pazymys;
            while (cin.fail() || pazymys < 1 || pazymys > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> pazymys;
            }
            grupe[i].nd.push_back(pazymys);

            ats = uzklausa_arBusDarPazymiu();

            while (ats == 'T' || ats == 't')
            {
                cout << "Iveskite sekanti pazymi is namu darbu" << endl;
                cin >> pazymys;
                while (cin.fail() || pazymys < 1 || pazymys > 10)
                {
                    cin.clear();
                    cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
                    cin.ignore(256, '\n');
                    cin >> pazymys;
                }
                grupe[i].nd.push_back(pazymys);

                ats = uzklausa_arBusDarPazymiu();

            }

            cout << "Iveskite egzamino pazymi (1-10): " << endl;
            cin >> grupe[i].egz;
            while (cin.fail() || grupe[i].egz <= 0 || grupe[i].egz > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].egz;
            }

            double vid = vidurkis(grupe[i]);
            grupe[i].galutinis_vidurkis = 0.6 * grupe[i].egz + 0.4 * vid;

            double med = mediana(grupe[i]);
            grupe[i].galutinis_mediana = 0.6 * grupe[i].egz + 0.4 * med;
        }
    }
}

void studentoUzpildymasRnd(int& studentuSkaicius, studentas(&grupe)[100])
{
    char atsakymas;
    int ndSkaicius;
    double paz;

    atsakymas = uzklausa_arNdSkaiciusZinomas();

    if (atsakymas == 't' || atsakymas == 'T')
    {
        ndSkaicius = uzklausa_kiekNdYra();

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> grupe[i].vardas;
            while (check_string(grupe[i].vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> grupe[i].pavarde;
            while (check_string(grupe[i].pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].pavarde;
            }

            srand(time(NULL));

            for (int j = 0; j < ndSkaicius; j++)
            {
                paz = rand() % 10 + 1;
                cout << j + 1 << " pazymys: " << paz << endl;
                grupe[i].nd.push_back(paz);
            }

            grupe[i].egz = rand() % 10 + 1;

            cout << "Egzamino pazymys: " << grupe[i].egz << endl;

            double vid = vidurkis(grupe[i]);
            grupe[i].galutinis_vidurkis = 0.6 * grupe[i].egz + 0.4 * vid;

            double med = mediana(grupe[i]);
            grupe[i].galutinis_mediana = 0.6 * grupe[i].egz + 0.4 * med;

        }
    }
    else {
        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> grupe[i].vardas;
            while (check_string(grupe[i].vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].vardas;
            }

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> grupe[i].pavarde;
            while (check_string(grupe[i].pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> grupe[i].pavarde;
            }

            srand(time(NULL));

            paz = rand() % 10 + 1;

            cout << "Pazymys is namu darbu: " << paz << endl;
            grupe[i].nd.push_back(paz);

            atsakymas = uzklausa_arBusDarPazymiu();


            while (atsakymas == 'T' || atsakymas == 't')
            {
                paz = rand() % 10 + 1;

                cout << "Pazymys is namu darbu: " << paz << endl;
                grupe[i].nd.push_back(paz);
                atsakymas = uzklausa_arBusDarPazymiu();
            }

            grupe[i].egz = rand() % 10 + 1;

            cout << "Egzamino pazymys: " << grupe[i].egz << endl;

            double vid = vidurkis(grupe[i]);
            grupe[i].galutinis_vidurkis = 0.6 * grupe[i].egz + 0.4 * vid;

            double med = mediana(grupe[i]);
            grupe[i].galutinis_mediana = 0.6 * grupe[i].egz + 0.4 * med;
        }
    }

}