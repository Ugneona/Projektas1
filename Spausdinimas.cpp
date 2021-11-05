#include "Spausdinimas.h"

void spausdinti_vector(char& atsakymas, vector <studentas>& grupe1)
{
    ofstream rz("rezultatai.txt");

    if (atsakymas == 'v' || atsakymas == 'V')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            rz << setw(20) << left << grupe1.at(i).pavarde << setw(20) << left << grupe1.at(i).vardas << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_vidurkis << endl;
        }
    }

    else if (atsakymas == 'm' || atsakymas == 'M')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
            rz << setw(20) << left << grupe1.at(i).pavarde << setw(20) << left << grupe1.at(i).vardas << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_mediana << endl;
        }
    }
    else
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "--------------------------------------------------------------------------------------------" << endl;

        for (int i = 0; i < grupe1.size(); i++)
        {
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
            cout << setw(20) << left << grupe[i].pavarde << setw(20) << left << grupe[i].vardas << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_vidurkis << endl;
        }
    }
    else if (atsakymas == 'm' || atsakymas == 'M') {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Mediana)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << setw(20) << left << grupe[i].pavarde << setw(20) << left << grupe[i].vardas << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_mediana << endl;
        }

    }
    else {
        cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << left << "Galutinis (Mediana)" << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < studentuSkaicius; i++)
        {
            cout << setw(20) << left << grupe[i].pavarde << setw(20) << left << grupe[i].vardas << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_vidurkis << setw(20) << left << fixed << setprecision(2) << grupe[i].galutinis_mediana << endl;
        }
    }
}


void spausdinimas(int& v1, char& atsakymas, vector <studentas>& sarasas, vector <double>& laikas, string &pav)
{
    string failoPav = pav + "_Studentai " + to_string(v1) + ".txt";
    auto start = std::chrono::high_resolution_clock::now();
    ofstream rz("Rezultatai" + failoPav);

    if (atsakymas == 't' || atsakymas == 'T')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : sarasas)
        {
            rz << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_vidurkis << endl;
        }

    }
    else
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : sarasas)
        {
            rz << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_mediana << endl;
        }

    }

    rz.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    laikas.push_back(diff.count());
}
