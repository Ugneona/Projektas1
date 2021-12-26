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
void darbasSuFailu_nr1(vector <int>& v1, char& atsakymas)
{
    string failoPav;
    vector <double> laikas;
    vector <studentas> protingi;
    vector <studentas> tinginiai;
    vector <studentas> grupe1;
    string pavP = "Protingi";
    string pavT = "Tinginiai";

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas.reserve(4);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe1, v1.at(i), laikas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas.push_back(diff.count());

        rusiavimas(grupe1, protingi, tinginiai, laikas, atsakymas);

        spausdinimas_nr1(v1.at(i), atsakymas, protingi, laikas, pavP);
        spausdinimas_nr1(v1.at(i), atsakymas, tinginiai, laikas, pavT);

        int vieta = 0;

        cout << v1.at(i) << " studentu failo nuskaitymas truko: " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " studentu surusiavimas i dvi grupes truko: " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " protingu studentu surasymas i failo truko: " << laikas.at(vieta) << " s" << endl;
        vieta++;
        cout << v1.at(i) << " tinginiu studentu surasymas i failo truko: " << laikas.at(vieta) << " s" << endl;
        cout << "\n";

        laikas.clear();
        grupe1.clear();
        protingi.clear();
        tinginiai.clear();
    }
}
void darbasSuFailu(vector <int>& v1, char& atsakymas)
{
    string failoPav;
    vector <double> laikas_vector;
    vector <double> laikas_list;
    vector <studentas> protingi_vector;
    vector <studentas> tinginiai_vector;
    vector <studentas> grupe_vector;
    list <studentas> grupe_list;
    list <studentas> protingi_list;
    list <studentas> tinginiai_list;
    string pavP = "Protingi";
    string pavT = "Tinginiai";

    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << setw(46) << left << "| Atliktas darbas " << setw(25) << left << "| Laikas (s) su vektoriu " << setw(21) << left << "| Laikas (s) su list " << "|" << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas_vector.reserve(3);
        laikas_list.reserve(3);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_vector, v1.at(i), laikas_vector);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe_list, v1.at(i), laikas_list);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        laikas_list.push_back(diff1.count());

        int vieta = 40 - i;

        cout << "| " << v1.at(i) << setw(vieta) << " studentu nuskaitymas " << "| " << setw(23) << left << laikas_vector.at(0) << "| " << setw(19) << left << laikas_list.at(0) << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        
        rusiavimas_strategija_nr1(grupe_vector, grupe_list, protingi_vector, protingi_list, tinginiai_vector, tinginiai_list, laikas_vector, laikas_list, atsakymas);
        
        cout << "| " << v1.at(i) << setw(vieta) << " studentu surusiavimas 1 strategija " << "| " << setw(23) << left << laikas_vector.at(1) << "| " << setw(19) << left << laikas_list.at(1) << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
       
        spausdinimas(v1.at(i), atsakymas, protingi_vector, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai_vector, pavT);
        spausdinimas(v1.at(i), atsakymas, protingi_list, pavP);
        spausdinimas(v1.at(i), atsakymas, tinginiai_list, pavT);
        
        grupe_vector.clear();
        grupe_list.clear();
        protingi_vector.clear();
        protingi_list.clear();
        tinginiai_vector.clear();
        tinginiai_list.clear();

        failoNuskaitymas(grupe_vector, v1.at(i), laikas_vector);
        failoNuskaitymas(grupe_list, v1.at(i), laikas_list);

        rusiavimas_strategija_nr2(grupe_vector, grupe_list, protingi_vector, protingi_list, tinginiai_vector, tinginiai_list, laikas_vector, laikas_list, atsakymas);
        
        cout << "| " << v1.at(i) << setw(vieta) << " studentu surusiavimas 2 strategija " << "| " << setw(23) << left << laikas_vector.at(2) << "| " << setw(19) << left << laikas_list.at(2) << "|" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        
        grupe_vector.clear();
        grupe_list.clear();
        protingi_vector.clear();
        protingi_list.clear();
        tinginiai_vector.clear();
        tinginiai_list.clear();
        laikas_vector.clear();
        laikas_list.clear();
        
    }
}
void failoNuskaitymas(vector <studentas>& grupe1, int& v1, vector <double>& laikas)
{
    double temp;
    int i = 0;
    std::stringstream ss;
    string sLine;
    int zodziuSk = 0;
    string word;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);

    if (!nuskaitymas) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }

    getline(nuskaitymas, sLine);

    stringstream s(sLine);
    while (s >> word)
    {
        zodziuSk++;
    }

    int ndKiek = zodziuSk - 3;

    ss << nuskaitymas.rdbuf();

    while (i < v1)
    {
        studentas stu;

        ss >> stu.vardas >> stu.pavarde;
        stu.nd.reserve(ndKiek);

        for (int k = 0; k < (ndKiek); k++)
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
    nuskaitymas.close();
}

void failoNuskaitymas(list <studentas>& grupe1, int& v1, vector <double>& laikas)
{
    double temp;
    int i = 0;
    std::stringstream ss;
    string sLine;
    int zodziuSk = 0;
    string word;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);

    if (!nuskaitymas) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }

    getline(nuskaitymas, sLine);

    stringstream s(sLine);
    while (s >> word)
    {
        zodziuSk++;
    }

    int ndKiek = zodziuSk - 3;

    ss << nuskaitymas.rdbuf();

    while (i < v1)
    {
        studentas stu;

        ss >> stu.vardas >> stu.pavarde;
        stu.nd.reserve(ndKiek);

        for (int k = 0; k < (ndKiek); k++)
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
    nuskaitymas.close();

}
void rusiavimas_strategija_nr1(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, list <studentas>& protingi_list, vector <studentas>& tinginiai_vector, list <studentas>& tinginiai_list, vector <double>& laikas_vector, vector <double>& laikas_list, char& atsakymas)
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

        laikas_list.push_back(diff1.count());
    }
}
void rusiavimas_strategija_nr2(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, list <studentas>& protingi_list, vector <studentas>& tinginiai_vector, list <studentas>& tinginiai_list, vector <double>& laikas_vector, vector <double>& laikas_list, char& atsakymas)
{
    if (atsakymas == 't' || atsakymas == 'T')
    {
        auto start = std::chrono::high_resolution_clock::now();

        vector<studentas>::iterator it1;

        std::partition(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
            {
                return a.galutinis_vidurkis > 5;

            });

        auto itt = std::partition_point(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
            {
                return a.galutinis_vidurkis > 5;
            });

        for (it1 = itt; it1 != grupe_vector.end(); it1++)
        {
            tinginiai_vector.push_back(*it1);
        }
        //grupe_vector.erase(std::remove_if(grupe_vector.begin(), grupe_vector.end(), [](studentas a) {return (a.galutinis_vidurkis < 5); }), grupe_vector.end());
        //grupe_vector.erase(itt, grupe_vector.end());
        grupe_vector.assign(grupe_vector.begin(), itt);
        grupe_vector.resize(grupe_vector.size());

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();

        list<studentas>::iterator it;

        std::partition(grupe_list.begin(), grupe_list.end(), [](studentas a)
            {
                return a.galutinis_vidurkis > 5;

            });

        auto itt_l = std::partition_point(grupe_list.begin(), grupe_list.end(), [](studentas a)
            {
                return a.galutinis_vidurkis > 5;
            });

        for (it = itt_l; it != grupe_list.end(); it++)
        {
            tinginiai_list.push_back(*it);
        }

        grupe_list.assign(grupe_list.begin(), itt_l);
        grupe_list.resize(grupe_list.size());

        /* list<studentas>::iterator it = grupe_list.begin();
        grupe_list.sort([](studentas a, studentas b) {return a.galutinis_vidurkis < b.galutinis_vidurkis; });

        while (it != grupe_list.end())
        {
            if ((*it).galutinis_vidurkis < 5.00)
            {
                tinginiai_list_2.push_back(*it);
                it = grupe_list.erase(it);
            }
            else ++it;
        }*/

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
                return a.galutinis_mediana > 5;

            });

        auto itt = std::partition_point(grupe_vector.begin(), grupe_vector.end(), [](studentas a)
            {
                return a.galutinis_mediana > 5;

            });

        for (it1 = itt; it1 != grupe_vector.end(); it1++)
        {
            tinginiai_vector.push_back(*it1);
        }
        //grupe_vector.erase(grupe_vector.begin(), std::remove_if(grupe_vector.begin(), grupe_vector.end(), [](studentas a) {return (a.galutinis_mediana < 5); }));
        grupe_vector.assign(grupe_vector.begin(), itt);
        grupe_vector.resize(grupe_vector.size());

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas_vector.push_back(diff.count());

        auto start1 = std::chrono::high_resolution_clock::now();

        list<studentas>::iterator it;

        std::partition(grupe_list.begin(), grupe_list.end(), [](studentas a)
            {
                return a.galutinis_vidurkis > 5;

            });

        auto itt_l = std::partition_point(grupe_list.begin(), grupe_list.end(), [](studentas a)
            {
                return a.galutinis_vidurkis > 5;
            });

        for (it = itt_l; it != grupe_list.end(); it++)
        {
            tinginiai_list.push_back(*it);
        }

        grupe_list.assign(grupe_list.begin(), itt_l);
        grupe_list.resize(grupe_list.size());

        /*list<studentas>::iterator it = grupe_list.begin();

        grupe_list.sort([](studentas a, studentas b) {return a.galutinis_mediana < b.galutinis_mediana; });

        while (it != grupe_list.end())
        {
            if ((*it).galutinis_mediana < 5.00)
            {
                tinginiai_list_2.push_back(*it);
                it = grupe_list.erase(it);
            }
            else ++it;
        }*/

        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;

        laikas_list.push_back(diff1.count());
    }
}
void rusiavimas(vector <studentas>& grupe1, vector <studentas>& protingi, vector <studentas>& tinginiai, vector <double>& laikas, char& atsakymas)
{
    if (atsakymas == 't' || atsakymas == 'T')
    {
        auto start = std::chrono::high_resolution_clock::now();
        sort(grupe1.begin(), grupe1.end(), ([](studentas a, studentas b)
            {
                return a.galutinis_vidurkis < b.galutinis_vidurkis;
            }));

        for (const auto& stu : grupe1)
        {
            if (stu.galutinis_vidurkis >= 5.00)
            {
                protingi.push_back(stu);
            }
            else tinginiai.push_back(stu);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas.push_back(diff.count());
    }
    else
    {
        auto start = std::chrono::high_resolution_clock::now();
        sort(grupe1.begin(), grupe1.end(), ([](studentas a, studentas b)
            {
                return a.galutinis_mediana < b.galutinis_mediana;
            }));


        for (const auto& stu : grupe1)
        {
            if (stu.galutinis_mediana >= 5.00)
            {
                protingi.push_back(stu);
            }
            else tinginiai.push_back(stu);
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;

        laikas.push_back(diff.count());
    }
}