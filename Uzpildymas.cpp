#include "Uzpildymas.h"

void studentoUzpildymasVardPavardNdEgz(int& studentuSkaicius, vector <studentas>& grupe)
{
    char ats;
    int ndSkaicius;
    double pazymys;
    studentas stu;

    ats = uzklausa_arNdSkaiciusZinomas();
    cout << "\n";

    if (ats == 't' || ats == 'T')
    {
        ndSkaicius = uzklausa_kiekNdYra();
        cout << "\n";

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> stu.vardas;
            while (check_string(stu.vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> stu.vardas;
            }

            cout << "\n";

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> stu.pavarde;
            while (check_string(stu.pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> stu.pavarde;
            }

            cout << "\n";

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
                stu.nd.push_back(pazymys);
            }

            cout << "\n";

            cout << "Iveskite egzamino pazymi (1-10): " << endl;
            cin >> stu.egz;

            while (cin.fail() || stu.egz <= 0 || stu.egz > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> stu.egz;
            }
            double vid = vidurkis(stu);
            stu.galutinis_vidurkis = 0.6 * stu.egz + 0.4 * vid;

            double med = mediana(stu);
            stu.galutinis_mediana = 0.6 * stu.egz + 0.4 * med;

            grupe.push_back(stu);
            stu.nd.clear();

        }
    }
    else {

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> stu.vardas;
            while (check_string(stu.vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> stu.vardas;
            }
            cout << "\n";

            cout << "Dabar iveskite pavarde: " << endl;
            cin >> stu.pavarde;
            while (check_string(stu.pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> stu.pavarde;
            }
            cout << "\n";

            cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
            cin >> pazymys;
            while (cin.fail() || pazymys < 1 || pazymys > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> pazymys;
            }
            stu.nd.push_back(pazymys);
            cout << "\n";

            ats = uzklausa_arBusDarPazymiu();
            cout << "\n";

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
                stu.nd.push_back(pazymys);

                cout << "\n";

                ats = uzklausa_arBusDarPazymiu();

                cout << "\n";
            }

            cout << "Iveskite egzamino pazymi (1-10): " << endl;
            cin >> stu.egz;
            while (cin.fail() || stu.egz <= 0 || stu.egz > 10)
            {
                cin.clear();
                cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
                cin.ignore(256, '\n');
                cin >> stu.egz;
            }

            double vid = vidurkis(stu);
            stu.galutinis_vidurkis = 0.6 * stu.egz + 0.4 * vid;

            double med = mediana(stu);
            stu.galutinis_mediana = 0.6 * stu.egz + 0.4 * med;

            grupe.push_back(stu);
            stu.nd.clear();
        }
    }
}

void studentoUzpildymasRnd(int& studentuSkaicius, vector <studentas>& grupe)
{
    char atsakymas;
    int ndSkaicius;
    double paz;
    studentas stu;

    atsakymas = uzklausa_arNdSkaiciusZinomas();
    cout << "\n";

    if (atsakymas == 't' || atsakymas == 'T')
    {
        ndSkaicius = uzklausa_kiekNdYra();
        cout << "\n";

        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << "Iveskite " << i + 1 << " studento varda: " << endl;
            cin >> stu.vardas;
            while (check_string(stu.vardas) == false)
            {
                cin.clear();
                cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
                cin.ignore(256, '\n');
                cin >> stu.vardas;
            }
            cout << "\n";
            cout << "Dabar iveskite pavarde: " << endl;
            cin >> stu.pavarde;
            while (check_string(stu.pavarde) == false)
            {
                cin.clear();
                cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
                cin.ignore(256, '\n');
                cin >> stu.pavarde;
            }

            cout << "\n";
            srand(time(NULL));

            for (int j = 0; j < ndSkaicius; j++)
            {
                paz = rand() % 10 + 1;
                cout << j + 1 << " pazymys: " << paz << endl;
                stu.nd.push_back(paz);
            }

            stu.egz = rand() % 10 + 1;

            cout << "Egzamino pazymys: " << stu.egz << endl;
            cout << "\n";

            double vid = vidurkis(stu);
            stu.galutinis_vidurkis = 0.6 * stu.egz + 0.4 * vid;

            double med = mediana(stu);
            stu.galutinis_mediana = 0.6 * stu.egz + 0.4 * med;

            grupe.push_back(stu);
            stu.nd.clear();
        }
    }
    else {
    for (int i = 0; i < studentuSkaicius; i++)
    {
        cout << "Iveskite " << i + 1 << " studento varda: " << endl;
        cin >> stu.vardas;
        while (check_string(stu.vardas) == false)
        {
            cin.clear();
            cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
            cin.ignore(256, '\n');
            cin >> stu.vardas;
        }
        cout << "\n";

        cout << "Dabar iveskite pavarde: " << endl;
        cin >> stu.pavarde;
        while (check_string(stu.pavarde) == false)
        {
            cin.clear();
            cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
            cin.ignore(256, '\n');
            cin >> stu.pavarde;
        }
        cout << "\n";

        srand(time(NULL));

        paz = rand() % 10 + 1;

        cout << "Pazymys is namu darbu: " << paz << endl;
        stu.nd.push_back(paz);
        cout << "\n";

        atsakymas = uzklausa_arBusDarPazymiu();
        cout << "\n";

        while (atsakymas == 'T' || atsakymas == 't')
        {
            paz = rand() % 10 + 1;

            cout << "Pazymys is namu darbu: " << paz << endl;
            stu.nd.push_back(paz);
            cout << "\n";
            atsakymas = uzklausa_arBusDarPazymiu();
            cout << "\n";
        }

        stu.egz = rand() % 10 + 1;

        cout << "Egzamino pazymys: " << stu.egz << endl;
        cout << "\n";

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.6 * stu.egz + 0.4 * vid;

        double med = mediana(stu);
        stu.galutinis_mediana = 0.6 * stu.egz + 0.4 * med;

        grupe.push_back(stu);
        stu.nd.clear();
    }
    }
}