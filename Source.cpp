#include <iostream>
#include <iomanip> 
#include <string>
#include <algorithm>
#include <vector>
#include <stdlib.h>    
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <chrono>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::sort;
using std::vector;
using std::ifstream;
using std::cerr;
using std::getline;
using std::ofstream;
using std::stringstream;
using std::to_string;


struct studentas
{
    string vardas, pavarde;
    vector <double> nd;
    double egz;
    double galutinis_vidurkis;
    double galutinis_mediana;
};


bool check_string(string& str);
bool check_alpha(char& chr);
bool check_vma(char& chr);
double mediana(studentas& s);
double vidurkis(studentas& s);
void spausdinti_vector(char& atsakymas, vector <studentas>& grupe1);
void spausdinti_struct(char& atsakymas, studentas(&grupe)[100], int& studentuSkaicius);
void studentoUzpildymasVardPavardNdEgz(int& studentuSkaicius, studentas(&grupe)[100]);
void studentoUzpildymasRnd(int& studentuSkaicius, studentas(&grupe)[100]);
void failas();
void failuKurimas(vector <int>& v1, int& ndKiek);
void darbasSuFailu(vector <int>& v1, int& ndKiek, char& atsakymas);
void failoNuskaitymas(vector <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek);
void rusiavimas(vector <studentas>& grupe1, vector <studentas>& protingi, vector <studentas>& tinginiai, vector <double>& laikas, char& atsakymas);
void spausdinimas_protingi(int& v1, char& atsakymas, vector <studentas>& protingi, vector <double>& laikas);
void spausdinimas_tinginiai(int& v1, char& atsakymas, vector <studentas>& tinginiai, vector <double>& laikas);
char uzklausa_delFailuKurimu();
char uzklausa_delFailo();
char uzklausa_delAtsakymo();
char uzklausa_delGeneravimo();
char uzklausa_arNdSkaiciusZinomas();
char uzklausa_arBusDarPazymiu();
int uzklausa_kiekNdYra();
int studentuSkaiciausUzklausa();

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

        cout << "Ar atsakyma noresite gauti su vidurkiu? Jei taip, veskite t, jei ne, vesikite n" << endl;
        cin >> ats;

        while (isalpha(ats) == false || check_alpha(ats) == false)
        {
            cin.clear();
            cout << "Neatpazintas simbolis. Prasome ivesti t - jei su vidurkiu apskaiciuota, n - priesingu atveju" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }

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

char uzklausa_delFailuKurimu()
{
    char atsakymas;
    cout << "Ar norite sugeneruoti 5 naujus failus su duomenimis apie studentus? T - jei norite, n - jei nenorite" << endl;
    cin >> atsakymas;

    while (isalpha(atsakymas) == false || check_alpha(atsakymas) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei generuosime failus, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> atsakymas;
    }
    return atsakymas;
}

int studentuSkaiciausUzklausa()
{
    int studentSk;

    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> studentSk;

    while (studentSk <= 0 || cin.fail())
    {
        cin.clear();
        cout << "Nurodytas skaicius yra netinkamas, iveskite studentu skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> studentSk;
    }

    return studentSk;
}

char uzklausa_arNdSkaiciusZinomas()
{
    char ats;
    cout << "Ar namu darbu skaicius yra zinomas is anksto? t- jei taip, n- jei ne" << endl;
    cin >> ats;
    while (isalpha(ats) == false || check_alpha(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu skaicius zinomas, n - jei namu darbu skaicius nezinomas" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }
    return ats;
}

int uzklausa_kiekNdYra()
{
    int ndSkaicius;
    cout << "Iveskite, kiek bus namu darbu (1-10)" << endl;
    cin >> ndSkaicius;
    while (cin.fail() || ndSkaicius < 1 || ndSkaicius > 10)
    {
        cin.clear();
        cout << "Namu darbu skaicius yra netinkamas, iveskite skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> ndSkaicius;
    }
    return ndSkaicius;
}

char uzklausa_arBusDarPazymiu()
{
    char ats;
    cout << "Ar dar bus pazymiu is namu darbu? t - jei bus dar, n - jei nebebus" << endl;
    cin >> ats;

    while (isalpha(ats) == false || check_alpha(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu dar bus n - jei namu darbu nebebus" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }
    return ats;
}

char uzklausa_delFailo()
{
    char klsm;
    cout << "Ar duomenis skaitysime is failo? Jei skaitysime is failo, veskite t, jei neskaitysime, veskite n" << endl;
    cin >> klsm;
    while (isalpha(klsm) == false || check_alpha(klsm) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei skaitysime duomenis is failo, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> klsm;
    }
    return klsm;
}

char uzklausa_delAtsakymo()
{
    char ats;
    cout << "Ar noresite matyti atsakyma su vidurkiu ar mediana? Jei su vidurkiu, veskite v, jei su mediana, veskite m, jei abu, veskite a" << endl;
    cin >> ats;

    while (isalpha(ats) == false || check_vma(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Jei norite, kad isvestu vidurki veskite v, jei mediana veskite m, jei abu veskite a" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }
    return ats;
}

char uzklausa_delGeneravimo()
{
    char klsm;
    cout << "Ar duomenis vesite pats, ar norite, kad butu sugeneruoti automatiskai? Jei vesite pats veskite t, priesingu atveju veskite n" << endl;
    cin >> klsm;
    while (isalpha(klsm) == false || check_alpha(klsm) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei duomenis vesite pats, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> klsm;
    }
    return klsm;
}

bool check_string(string& str)
{
    int sum = 0;

    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) sum += 1;

    if (sum == str.length()) return true;
    else return false;
}

bool check_alpha(char& chr)
{
    if (chr == 't' || chr == 'T' || chr == 'n' || chr == 'N') return true;
    else return false;
}

bool check_vma(char& chr)
{
    if (chr == 'v' || chr == 'V' || chr == 'm' || chr == 'M' || chr == 'A' || chr == 'a') return true;
    else return false;

}

double mediana(studentas& s)
{
    sort(s.nd.begin(), s.nd.end());

    int ndKiek1 = s.nd.size();

    if (ndKiek1 % 2 == 0) return (double)(s.nd[(ndKiek1 / 2) - 1] + s.nd[ndKiek1 / 2]) / 2.0;
    else return (double)s.nd[ndKiek1 / 2];
}

double vidurkis(studentas& s)
{
    double sum = 0.;
    double kiekis = 0.;
    double vid = 0.;

    for (int i = 0; i < s.nd.size(); i++)
    {
        sum += s.nd.at(i);
        kiekis++;
    }

    vid = sum / kiekis;

    return vid;
}

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
    vector <studentas> protingi;
    vector <studentas> tinginiai;
    vector <studentas> grupe1;

    for (int i = 0; i < (v1.size()); i++)
    {
        laikas.reserve(4);

        auto start = std::chrono::high_resolution_clock::now();
        failoNuskaitymas(grupe1, v1.at(i), laikas, ndKiek);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        laikas.push_back(diff.count());

        rusiavimas(grupe1, protingi, tinginiai, laikas, atsakymas);

        spausdinimas_protingi(v1.at(i), atsakymas, protingi, laikas);
        spausdinimas_tinginiai(v1.at(i), atsakymas, tinginiai, laikas);

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
    }
}
void failoNuskaitymas(vector <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek)
{
    double temp;
    int i = 0;
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    ifstream nuskaitymas(failoPav);

    if (!nuskaitymas) {
        cerr << "Unable to open file datafile.txt";
        exit(1);
    }
    nuskaitymas.ignore(1000, '\n');

    while(i < v1)
    {
        studentas stu;
        
        nuskaitymas >> stu.vardas >> stu.pavarde;
        stu.nd.reserve(ndKiek);

        for (int k = 0; k < ndKiek; k++)
        {
            nuskaitymas >> temp;
            stu.nd.push_back(temp);
        }

        nuskaitymas >> stu.egz;

        double vid = vidurkis(stu);
        stu.galutinis_vidurkis = 0.4 * vid + 0.6 * stu.egz;

        double med = mediana(stu);
        stu.galutinis_mediana = 0.4 * med + 0.6 * stu.egz;

        grupe1.push_back(stu);
        stu.nd.clear();
        i++;
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
void spausdinimas_protingi(int& v1, char& atsakymas, vector <studentas>& protingi, vector <double>& laikas)
{
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    auto start = std::chrono::high_resolution_clock::now();
    ofstream rz("Rezultatai_Protingi_" + failoPav);

    if (atsakymas == 't' || atsakymas == 'T')
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : protingi)
        {
            rz << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_vidurkis << endl;
        }

    }
    else
    {
        rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        rz << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : protingi)
        {
            rz << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_mediana << endl;
        }

    }

    rz.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    laikas.push_back(diff.count());
}
void spausdinimas_tinginiai(int& v1, char& atsakymas, vector <studentas>& tinginiai, vector <double>& laikas)
{
    string failoPav = "Studentai " + to_string(v1) + ".txt";
    auto start = std::chrono::high_resolution_clock::now();
    ofstream rez("Rezultatai_Tinginiai_" + failoPav);

    if (atsakymas == 't' || atsakymas == 'T')
    {
        rez << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
        rez << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : tinginiai)
        {
            rez << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_vidurkis << endl;
        }

    }
    else
    {
        rez << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Med.)" << endl;
        rez << "-------------------------------------------------------------------------" << endl;

        for (const auto& stu : tinginiai)
        {
            rez << setw(20) << left << stu.pavarde << setw(20) << left << stu.vardas << setw(20) << left << fixed << setprecision(2) << stu.galutinis_mediana << endl;
        }

    }

    rez.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    laikas.push_back(diff.count());
}
