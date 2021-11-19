#include "Failas.h"
#include <sstream>


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
    std::stringstream ss;
    for (int i = 0; i < (v1.size()); i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        failoPav = "Studentai " + to_string(v1.at(i)) + ".txt";

        ofstream isvedimas(failoPav);

        ss << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas";

        for (int j = 0; j < ndKiek; j++)
        {
            ss << setw(10) << left << "Nd" + to_string(j + 1);
        }

        ss << setw(10) << left << "Egzaminas" << endl;
        srand(time(NULL));

        for (int k = 0; k < v1.at(i); k++)
        {
            ss << setw(20) << left << "Pavarde" + to_string(k + 1) << setw(20) << left << "Vardas" + to_string(k + 1);
            for (int kk = 0; kk < ndKiek; kk++)
            {
                pazymys = rand() % 10 + 1;
                ss << setw(10) << left << pazymys;
            }
            pazymys = rand() % 10 + 1;
            ss << setw(10) << left << pazymys << endl;
        }
        isvedimas << ss.str();
        isvedimas.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        cout << v1.at(i) << " elementu uzpildymas truko: " << diff.count() << " s" << endl;
    }
}

void darbasSuFailu(vector <int>& v1, int& ndKiek, char& atsakymas)
{
    string failoPav;
    vector <double> laikas_vector;
    vector <double> laikas_list;
    vector <studentas> protingi_vector;
    vector <studentas> tinginiai_vector_1;
    vector <studentas> tinginiai_vector_2;
    vector <studentas> grupe_vector;
    vector <studentas> grupe_vector_2;
    list <studentas> grupe_list;
    list <studentas> grupe_list_2;
    list <studentas> protingi_list;
    list <studentas> tinginiai_list_1;
    list <studentas> tinginiai_list_2;
    string pavP = "Protingi";
    string pavT = "Tinginiai";

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << setw(46) << left << "| Atliktas darbas " << setw(25) << left << "| Laikas (s) su vektoriu " << setw(21) << left << "| Laikas (s) su list " << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas_vector.reserve(2);
        laikas_list.reserve(2);

        failoNuskaitymas(grupe_vector, grupe_vector_2, v1.at(i), ndKiek);
        failoNuskaitymas_list(grupe_list, grupe_list_2, v1.at(i), ndKiek);

        rusiavimas_strategija1(grupe_vector, grupe_list, protingi_vector, tinginiai_vector_1, protingi_list, tinginiai_list_1, laikas_vector, laikas_list, atsakymas);
        rusiavimas_strategija2(grupe_vector_2, grupe_list_2, tinginiai_vector_2, tinginiai_list_2, laikas_vector, laikas_list, atsakymas);

        int vieta = 40 - i;

        cout << "| " << v1.at(i) << setw(vieta) << " studentu surusiavimas 1 strategija " << "| " << setw(23) << left << laikas_vector.at(0) << "| " << setw(19) << left << laikas_list.at(0) << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "| " << v1.at(i) << setw(vieta) << " studentu surusiavimas 2 strategija " << "| " << setw(23) << left << laikas_vector.at(1) << "| " << setw(19) << left << laikas_list.at(1) << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;

        spausdinimas(v1.at(i), atsakymas, protingi_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai_vector_1, pavT);

        spausdinimas(v1.at(i), atsakymas, protingi_list, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai_list_1, pavT);

        grupe_list.clear();
        grupe_vector.clear();
        laikas_vector.clear();
        laikas_list.clear();
    }
}

void failoNuskaitymas_list(list <studentas>& grupe1, list <studentas>& grupe2, int& v1, int& ndKiek)
{
    double temp;
    int i = 0;
    std::stringstream ss;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);

    if (!nuskaitymas) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }

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
        grupe2.push_back(stu);
        stu.nd.clear();
        i++;
    }
    nuskaitymas.close();
}
void failoNuskaitymas(vector <studentas>& grupe1, vector <studentas>& grupe2, int& v1, int& ndKiek)
{
    double temp;
    int i = 0;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);
    std::stringstream ss;

    if (!nuskaitymas) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }

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
        grupe2.push_back(stu);
        stu.nd.clear();
        i++;
    }
    nuskaitymas.close();
}
void rusiavimas_strategija1(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, vector <studentas>& tinginiai_vector, list <studentas>& protingi_list, list <studentas>& tinginiai_list, vector <double>& laikas_vector, vector<double>& laikas_list, char& atsakymas)
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

        laikas_vector.push_back(diff.count());

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

        laikas_list.push_back(diff1.count());

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

        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();
        grupe_list.sort([](studentas a, studentas b) {return a.galutinis_mediana < b.galutinis_mediana; });

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

        laikas_list.push_back(diff1.count());
    }
}

void rusiavimas_strategija2(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& tinginiai_vector_2, list <studentas>& tinginiai_list_2, vector <double>& laikas_vector, vector<double>& laikas_list, char& atsakymas)
{
    if (atsakymas == 't' || atsakymas == 'T')
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<studentas>::iterator it1;

        std::partition(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
            {
                return a.galutinis_vidurkis < 5;

            });

        auto itt = std::partition_point(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
            {
                return a.galutinis_vidurkis < 5;

            });

        for (it1 = grupe_vector.begin(); it1 != itt; it1++)
        {
            tinginiai_vector_2.push_back(*it1);
        }

        grupe_vector.erase(std::remove_if(grupe_vector.begin(), grupe_vector.end(), [](studentas a) {return (a.galutinis_vidurkis < 5); }), grupe_vector.end());

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();

        list<studentas>::iterator it = grupe_list.begin();

        grupe_list.sort([](studentas a, studentas b) {return a.galutinis_vidurkis < b.galutinis_vidurkis; });

        while (it != grupe_list.end())
        {
            if ((*it).galutinis_vidurkis < 5.00)
            {
                tinginiai_list_2.push_back(*it);
                it = grupe_list.erase(it);
            }
            else ++it;
        }

        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;

        laikas_list.push_back(diff1.count());

    }
    else
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<studentas>::iterator it1;

        std::partition(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
            {
                return a.galutinis_mediana < 5;

            });

        auto itt = std::partition_point(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
            {
                return a.galutinis_mediana < 5;

            });

        for (it1 = grupe_vector.begin(); it1 != itt; it1++)
        {
            tinginiai_vector_2.push_back(*it1);
        }

        grupe_vector.erase(std::remove_if(grupe_vector.begin(), grupe_vector.end(), [](studentas a) {return (a.galutinis_mediana < 5); }), grupe_vector.end());

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();

        list<studentas>::iterator it = grupe_list.begin();

        grupe_list.sort([](studentas a, studentas b) {return a.galutinis_mediana < b.galutinis_mediana; });

        while (it != grupe_list.end())
        {
            if ((*it).galutinis_mediana < 5.00)
            {
                tinginiai_list_2.push_back(*it);
                it = grupe_list.erase(it);
            }
            else ++it;
        }

        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;

        laikas_list.push_back(diff1.count());
    }

}