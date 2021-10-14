#include "Spausdinimas.h"


void spausdinti_vector(char& atsakymas, vector <studentas> grupe1)
{
    ofstream rz("rezultatai.txt");

    if (atsakymas == 'v' || atsakymas == 'V')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            try
            {
                grupe1.at(i);
            }
            catch (const std::out_of_range& e)
            {
                cout << "Nera tokio elemento." << endl;
            }

            rz << setw(20) << left << grupe1.at(i).pavarde << setw(20) << left << grupe1.at(i).vardas << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_vidurkis << endl;
        }
    }

    else if (atsakymas == 'm' || atsakymas == 'M')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            try
            {
                grupe1.at(i);
            }
            catch (const std::out_of_range& e)
            {
                cout << "Nera tokio elemento." << endl;
            }

            rz << setw(20) << left << grupe1.at(i).pavarde << setw(20) << left << grupe1.at(i).vardas << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_mediana << endl;
        }
    }
    else
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "--------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            try
            {
                grupe1.at(i);
            }
            catch (const std::out_of_range& e)
            {
                cout << "Nera tokio elemento." << endl;
            }

            rz << setw(20) << left << grupe1.at(i).pavarde << setw(20) << left << grupe1.at(i).vardas << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_vidurkis << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_mediana << endl;
        }

    }

    rz.close();
}

void spausdinti_struct(char& atsakymas, studentas(&grupe)[100], int& studentuSkaicius)
{
    if (atsakymas == 'v' || atsakymas == 'V')
    {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < studentuSkaicius; i++)
        {
            try
            {
                if (i < 0 || i >= studentuSkaicius) throw(std::out_of_range("Klaida. "));
            }
            catch (const std::out_of_range& e)
            {
                cout << e.what();
                cout << "Tokio elemento nera." << endl;
            }

            cout << setw(20) << left << grupe[i].pavarde << setw(20) << left << grupe[i].vardas << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_vidurkis << endl;
        }
    }
    else if (atsakymas == 'm' || atsakymas == 'M') {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Mediana)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < studentuSkaicius; i++)
        {
            try
            {
                if (i < 0 || i >= studentuSkaicius) throw(std::out_of_range("Klaida. "));
            }
            catch (const std::out_of_range& e)
            {
                cout << e.what();
                cout << "Tokio elemento nera." << endl;
            }

            cout << setw(20) << left << grupe[i].pavarde << setw(20) << left << grupe[i].vardas << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_mediana << endl;
        }

    }
    else {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << left << "Galutinis (Mediana)" << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < studentuSkaicius; i++)
        {
            try
            {
                if (i < 0 || i >= studentuSkaicius) throw(std::out_of_range("Klaida. "));
            }
            catch (const std::out_of_range& e)
            {
                cout << e.what();
                cout << "Tokio elemento nera." << endl;
            }

            cout << setw(20) << left << grupe[i].pavarde << setw(20) << left << grupe[i].vardas << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_vidurkis << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_mediana << endl;
        }
    }
}