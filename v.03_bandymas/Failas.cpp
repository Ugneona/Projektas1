#include "Failas.h"


void Failas()
{
    char ats;
    string sLine;
    int eilSk = 0;
    vector <studentas> grupe1;
    studentas stu;
    int zodziuSk = 0;
    string word;
    double temp;
    double med;
    double vid;

    ifstream indata("kursiokai.txt");

    try
    {
        if (!indata)
        {
            throw "Klaida. Neimanoma atidaryti failo";
        }
        else
        {
            cout << "Failas rastas ir atidarytas" << endl;
        }

    }
    catch (const char * e)
    {
        cerr << e << endl;

    }

    ats = uzklausa_delAtsakymo();

    while (true)
    {
        if (!indata.eof())
        {
            getline(indata, sLine);

            eilSk++;

            if (eilSk == 1)
            {

                stringstream s(sLine);
                while (s >> word)
                {
                    zodziuSk++;
                }
            }

            indata >> stu.vardas >> stu.pavarde;

            stu.nd.reserve(zodziuSk - 3);

            for (int i = 0; i < zodziuSk - 3; i++)
            {
                indata >> temp;
                stu.nd.push_back(temp);
            }
            indata >> stu.egz;

            vid = vidurkis(stu);
            stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

            med = mediana(stu);
            stu.galutinis_mediana = 0.4 * med + 0.6 * stu.egz;

            grupe1.push_back(stu);
            stu.nd.clear();

        }
        else break;
    }
    sort(grupe1.begin(), grupe1.end(), [](studentas a, studentas b)
        {
            return a.pavarde < b.pavarde;
        });
    indata.close();

    spausdinti_vector(ats, grupe1);
}