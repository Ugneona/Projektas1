#include "Failas.h"


void failas()
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

    if (!indata) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
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

void failuKurimas(vector <int>& v1, int& ndKiek)
{
    string failoPav;
    double pazymys;
    for (int i = 0; i < (v1.size()); i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        failoPav = "Studentai " + to_string(v1.at(i)) + ".txt";

        ofstream isvedimas(failoPav);

        isvedimas << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas";

        for (int j = 0; j < ndKiek; j++)
        {
            isvedimas << setw(10) << left << "Nd" + to_string(j + 1);
        }

        isvedimas << setw(10) << left << "Egzaminas" << endl;
        srand(time(NULL));

        for (int k = 0; k < v1.at(i); k++)
        {
            isvedimas << setw(20) << left << "Pavarde" + to_string(k + 1) << setw(20) << left << "Vardas" + to_string(k + 1);
            for (int kk = 0; kk < ndKiek; kk++)
            {
                pazymys = rand() % 10 + 1;
                isvedimas << setw(10) << left << pazymys;
            }
            pazymys = rand() % 10 + 1;
            isvedimas << setw(10) << left << pazymys << endl;
        }

        isvedimas.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        cout << v1.at(i) << " elementu uzpildymas truko: " << diff.count() << " s" << endl;
    }
}

void darbasSuFailu(vector <int>& v1, int& ndKiek, char& atsakymas)
{
    string failoPav;
    vector <double> laikas;
    vector <studentas> protingi_vector;
    vector <studentas> tinginiai_vector;
    vector <studentas> grupe_vector;
    list <studentas> grupe_list;
    list <studentas> protingi_list;
    list <studentas> tinginiai_list;
    string pavP = "Protingi";
    string pavT = "Tinginiai";

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas.reserve(4);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_vector, v1.at(i), laikas, ndKiek);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_list, v1.at(i), laikas, ndKiek);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        laikas.push_back(diff1.count());

        rusiavimas(grupe_vector, grupe_list, protingi_vector, protingi_list, tinginiai_vector, tinginiai_list, laikas, atsakymas);

        spausdinimas(v1.at(i), atsakymas, protingi_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai_vector, pavT);
        spausdinimas(v1.at(i), atsakymas, protingi_list, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai_list, pavT);

        int vieta = 0;

        cout << v1.at(i) << " studentu failo nuskaitymas truko (vector): " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " studentu failo nuskaitymas truko (list): " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " studentu surusiavimas i dvi grupes truko (vector): " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " studentu surusiavimas i dvi grupes truko (list): " << laikas.at(vieta) << " s" << endl;
        cout << '\n';
        
        laikas.clear();
        grupe_vector.clear();
        grupe_list.clear();
        protingi_vector.clear();
        protingi_list.clear();
        tinginiai_vector.clear();
        tinginiai_list.clear();
    }
}
void failoNuskaitymas(vector <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek)
{
    double temp;
    int i = 0, eilSk = 0, zodziuSk = 0;;
    string sLine, word;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);
    studentas stu;
    std::stringstream ss;

    nuskaitymas.ignore(1000, '\n');
    ss << nuskaitymas.rdbuf();

    while (i < v1)
    {
        studentas stu;

        ss >> stu.vardas >> stu.pavarde;
        stu.nd.reserve(ndKiek);

        for (int k = 0; k < ndKiek; k++)
        {
            ss >> temp;
            stu.nd.push_back(temp);
        }

        ss >> stu.egz;

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

        double med = mediana(stu);
        stu.galutinis_mediana = 0.4 * med + 0.6 * stu.egz;

        grupe1.push_back(stu);
        stu.nd.clear();
        i++;
    }

}

void failoNuskaitymas(list <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek)
{
    double temp;
    int i = 0, eilSk = 0, zodziuSk = 0;;
    string sLine, word;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);
    studentas stu;
    std::stringstream ss;

    nuskaitymas.ignore(1000, '\n');
    ss << nuskaitymas.rdbuf();

    while (i < v1)
    {
        studentas stu;

        ss >> stu.vardas >> stu.pavarde;
        stu.nd.reserve(ndKiek);

        for (int k = 0; k < ndKiek; k++)
        {
            ss >> temp;
            stu.nd.push_back(temp);
        }

        ss >> stu.egz;

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

        double med = mediana(stu);
        stu.galutinis_mediana = 0.4 * med + 0.6 * stu.egz;

        grupe1.push_back(stu);
        stu.nd.clear();
        i++;
    }

}
void rusiavimas(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, list <studentas>& protingi_list, vector <studentas>& tinginiai_vector, list <studentas>& tinginiai_list, vector <double>& laikas, char& atsakymas)
{
    if (atsakymas == 't' || atsakymas == 'T')
    {
        auto start = std::chrono::high_resolution_clock::now();
        sort(grupe_vector.begin(), grupe_vector.end(), ([](studentas a, studentas b)
            {
                return a.galutinis_vidurkis < b.galutinis_vidurkis;
            }));

        for (const auto& stu : grupe_vector)
        {
            if (stu.galutinis_vidurkis >= 5.00)
            {
                protingi_vector.push_back(stu);
            }
            else tinginiai_vector.push_back(stu);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();
        grupe_list.sort([](studentas a, studentas b) {return a.galutinis_vidurkis < b.galutinis_vidurkis; });

        for (const auto& stu : grupe_list)
        {
            if (stu.galutinis_vidurkis >= 5.00)
            {
                protingi_list.push_back(stu);
            }
            else tinginiai_list.push_back(stu);
        }

        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;

        laikas.push_back(diff1.count());
    }
    else
    {
        auto start = std::chrono::high_resolution_clock::now();
        sort(grupe_vector.begin(), grupe_vector.end(), ([](studentas a, studentas b)
            {
                return a.galutinis_mediana < b.galutinis_mediana;
            }));

        for (const auto& stu : grupe_vector)
        {
            if (stu.galutinis_mediana >= 5.00)
            {
                protingi_vector.push_back(stu);
            }
            else tinginiai_vector.push_back(stu);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();
        grupe_list.sort([](studentas a, studentas b) {return a.galutinis_vidurkis < b.galutinis_vidurkis; });

        for (const auto& stu : grupe_list)
        {
            if (stu.galutinis_mediana >= 5.00)
            {
                protingi_list.push_back(stu);
            }
            else tinginiai_list.push_back(stu);
        }

        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;

        laikas.push_back(diff1.count());
    }
}
