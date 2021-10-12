#include <iostream>
#include <iomanip> 
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>    
#include <time.h>
#include <fstream>
#include <cstdlib>
#include <sstream>


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



struct studentas
{
    string vardas, pavarde;
    vector <double> nd;
    double egz;
    double galutinis_vidurkis;
    double galutinis_mediana;
};

void vardPavard(studentas& s, int& ii);
void pild(studentas& s);
void pildrnd(studentas& s);
void pildnd(studentas& s, int& ii, int& ndSk1);
void pildndrnd(studentas& s, int& ii, int& ndSk1);
void spausdintiVid(studentas& s);
void spausdinti(studentas& s);
void spausdintiMed(studentas& s);
bool check_string(string& str);
bool check_alpha(char& chr);
bool check_vma(char& chr);
double mediana(studentas& s);
double vidurkis(studentas& s);


int main()
{
    int studentSk, ndSk;
    studentas grupe[100];
    char ats, klsm;
    string sLine;
    int studkiek = 0;
    int eilSk = 0;
    vector <studentas> grupe1;
    studentas stu;
    int zodziuSk = 0;
    string word;
    double temp;
    double med;
    double vid;

    cout << "Ar duomenis skaitysime is failo? Jei skaitysime is failo, veskite t, jei neskaitysime, veskite n" << endl;
    cin >> klsm;
    while (isalpha(klsm) == false || check_alpha(klsm) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei skaitysime duomenis is failo, n - priesingu atveju" << endl;
        cin.ignore(256, '\n');
        cin >> klsm;
    }
    if (klsm == 't' || klsm == 'T')
    {
        ifstream indata("kursiokai.txt");

        if (!indata) {
            cerr << "Unable to open file datafile.txt";
            exit(1);
        }

        cout << "Ar noresite matyti atsakyma su vidurkiu ar mediana? Jei su vidurkiu, veskite v, jei su mediana, veskite m, jei abu, veskite a" << endl;
        cin >> ats;

        while (isalpha(ats) == false || check_vma(ats) == false)
        {
            cin.clear();
            cout << "Neatpazintas simbolis. Jei norite, kad isvestu vidurki veskite v, jei mediana veskite m, jei abu veskite a" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }

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

        ofstream rz("rezultatai.txt");

        if (ats == 'v' || ats == 'V')
        {
            rz << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
            rz << "-------------------------------------------------------------------------" << endl;

            for (int i = 0; i < grupe1.size(); i++)
            {
                rz << setw(20) << left << grupe1.at(i).pavarde << setw(20) << left << grupe1.at(i).vardas << setw(20) << left << fixed << setprecision(2) << grupe1.at(i).galutinis_vidurkis << endl;
            }
        }

        else if (ats == 'm' || ats == 'M')
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
    else
    {
        cout << "Ar duomenis vesite pats, ar norite, kad butu sugeneruoti automatiskai? Jei vesite pats veskite t, priesingu atveju veskite n" << endl;
        cin >> klsm;
        while (isalpha(klsm) == false || check_alpha(klsm) == false)
        {
            cin.clear();
            cout << "Neatpazintas simbolis. Prasome ivesti t - jei duomenis vesite pats, n - priesingu atveju" << endl;
            cin.ignore(256, '\n');
            cin >> klsm;
        }
        if (klsm == 't' || klsm == 'T')
        {
            cout << "Iveskite studentu skaiciu: " << endl;
            cin >> studentSk;
            while (studentSk <= 0 || cin.fail())
            {
                cin.clear();
                cout << "Nurodytas skaicius yra netinkamas, iveskite studentu skaiciu didesni uz 0" << endl;
                cin.ignore(256, '\n');
                cin >> studentSk;
            }
            cout << "Ar namu darbu skaicius yra zinomas is anksto? t- jei taip, n- jei ne" << endl;
            cin >> ats;
            while (isalpha(ats) == false || check_alpha(ats) == false)
            {
                cin.clear();
                cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu skaicius zinomas, n - jei namu darbu skaicius nezinomas" << endl;
                cin.ignore(256, '\n');
                cin >> ats;
            }
            if (ats == 't' || ats == 'T')
            {
                cout << "Iveskite, kiek bus namu darbu (1-10)" << endl;
                cin >> ndSk;
                while (cin.fail() || ndSk < 1 || ndSk > 10)
                {
                    cin.clear();
                    cout << "Namu darbu skaicius yra netinkamas, iveskite skaiciu didesni uz 0" << endl;
                    cin.ignore(256, '\n');
                    cin >> ndSk;
                }
                for (int i = 0; i < studentSk; i++)
                {
                    vardPavard(grupe[i], i);
                    pildnd(grupe[i], i, ndSk);
                }
            }
            else {
                for (int i = 0; i < studentSk; i++)
                {
                    vardPavard(grupe[i], i);
                    pild(grupe[i]);
                }
            }
        }
        else {
            srand(time(NULL));
            cout << "Iveskite studentu skaiciu: " << endl;
            cin >> studentSk;
            while (studentSk <= 0 || cin.fail())
            {
                cin.clear();
                cout << "Nurodytas skaicius yra netinkamas, iveskite studentu skaiciu didesni uz 0" << endl;
                cin.ignore(256, '\n');
                cin >> studentSk;
            }
            cout << "Ar namu darbu skaicius yra zinomas is anksto? t- jei taip, n- jei ne" << endl;
            cin >> ats;
            while (isalpha(ats) == false || check_alpha(ats) == false)
            {
                cin.clear();
                cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu skaicius zinomas, n - jei namu darbu skaicius nezinomas" << endl;
                cin.ignore(256, '\n');
                cin >> ats;
            }
            if (ats == 't' || ats == 'T')
            {
                cout << "Iveskite, kiek bus namu darbu (1-10)" << endl;
                cin >> ndSk;
                while (cin.fail() || ndSk < 1 || ndSk > 10)
                {
                    cin.clear();
                    cout << "Namu darbu skaicius yra netinkamas, iveskite skaiciu didesni uz 0" << endl;
                    cin.ignore(256, '\n');
                    cin >> ndSk;
                }
                for (int i = 0; i < studentSk; i++)
                {
                    vardPavard(grupe[i], i);
                    pildndrnd(grupe[i], i, ndSk);
                }
            }
            else {
                for (int i = 0; i < studentSk; i++)
                {
                    vardPavard(grupe[i], i);
                    pildrnd(grupe[i]);
                }
            }
        }
        cout << "Norite, kad skaiciuotu vidurki ar mediana? Jei vidurki veskite v, jei mediana veskite m, jei abu veskite a" << endl;
        cin >> ats;
        while (isalpha(ats) == false || check_vma(ats) == false)
        {
            cin.clear();
            cout << "Neatpazintas simbolis. Jei norite, kad isvestu vidurki veskite v, jei mediana veskite m, jei abu veskite a" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }
        if (ats == 'v' || ats == 'V')
        {
            cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << endl;
            cout << "---------------------------------------------------------------" << endl;
            for (int i = 0; i < studentSk; i++)
            {
                spausdintiVid(grupe[i]);
            }
        }
        else if (ats == 'm' || ats == 'M') {
            cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Mediana)" << endl;
            cout << "---------------------------------------------------------------" << endl;
            for (int i = 0; i < studentSk; i++)
            {
                spausdintiMed(grupe[i]);
            }

        }
        else {
            cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << left << "Galutinis (Mediana)" << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            for (int i = 0; i < studentSk; i++)
            {
                spausdinti(grupe[i]);
            }
        }
    }
    return 0;
}
void vardPavard(studentas& s, int& ii)
{
    cout << "Iveskite " << ii + 1 << " studento varda: " << endl;
    cin >> s.vardas;
    while (check_string(s.vardas) == false)
    {
        cin.clear();
        cout << "Nurodytas vardas netinka, prasome dar karta ivesti varda" << endl;
        cin.ignore(256, '\n');
        cin >> s.vardas;
    }

    cout << "Dabar iveskite pavarde: " << endl;
    cin >> s.pavarde;
    while (check_string(s.pavarde) == false)
    {
        cin.clear();
        cout << "Nurodyta pavarde netinka, prasome dar karta ivesti pavarde" << endl;
        cin.ignore(256, '\n');
        cin >> s.pavarde;
    }
}
void pild(studentas& s)
{
    double sum = 0.;
    double paz;
    char ats;

    cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
    cin >> paz;
    while (cin.fail() || paz < 1 || paz > 10)
    {
        cin.clear();
        cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
        cin.ignore(256, '\n');
        cin >> paz;
    }
    s.nd.push_back(paz);
    sum += paz;

    cout << "Ar dar bus pazymiu is namu darbu? t - jei bus dar, n - jei nebebus" << endl;
    cin >> ats;

    while (isalpha(ats) == false || check_alpha(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu dar bus n - jei namu darbu nebebus" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }

    while (ats == 'T' || ats == 't')
    {
        cout << "Iveskite sekanti pazymi is namu darbu" << endl;
        cin >> paz;
        while (cin.fail() || paz < 1 || paz > 10)
        {
            cin.clear();
            cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
            cin.ignore(256, '\n');
            cin >> paz;
        }
        s.nd.push_back(paz);
        sum += paz;
        cout << "Ar dar bus pazymiu is namu darbu? t - jei bus dar, n - jei nebebus" << endl;
        cin >> ats;
        while (isalpha(ats) == false || check_alpha(ats) == false)
        {
            cin.clear();
            cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu dar bus n - jei namu darbu nebebus" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }
    }

    cout << "Iveskite egzamino pazymi (1-10): " << endl;
    cin >> s.egz;
    while (cin.fail() || s.egz <= 0 || s.egz > 10)
    {
        cin.clear();
        cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
        cin.ignore(256, '\n');
        cin >> s.egz;
    }

    s.galutinis_vidurkis = 0.6 * s.egz + 0.4 * (sum / s.nd.size());

    double med = mediana(s);
    s.galutinis_mediana = 0.6 * s.egz + 0.4 * med;
}
void pildrnd(studentas& s)
{
    double sum = 0.;
    double paz;
    char ats;
    srand(time(NULL));

    paz = rand() % 10 + 1;

    cout << "Pazymys is namu darbu: " << paz << endl;
    s.nd.push_back(paz);
    sum += paz;

    cout << "Ar dar bus pazymiu is namu darbu? t - jei bus dar, n - jei nebebus" << endl;
    cin >> ats;

    while (isalpha(ats) == false || check_alpha(ats) == false)
    {
        cin.clear();
        cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu dar bus n - jei namu darbu nebebus" << endl;
        cin.ignore(256, '\n');
        cin >> ats;
    }

    while (ats == 'T' || ats == 't')
    {
        paz = rand() % 10 + 1;
        cout << "Pazymys is namu darbu: " << paz << endl;
        s.nd.push_back(paz);
        sum += paz;
        cout << "Ar dar bus pazymiu is namu darbu? t - jei bus dar, n - jei nebebus" << endl;
        cin >> ats;
        while (isalpha(ats) == false || check_alpha(ats) == false)
        {
            cin.clear();
            cout << "Neatpazintas simbolis. Prasome ivesti t - jei namu darbu dar bus n - jei namu darbu nebebus" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }
    }

    s.egz = rand() % 10 + 1;

    cout << "Egzamino pazymys: " << s.egz << endl;

    s.galutinis_vidurkis = 0.6 * s.egz + 0.4 * (sum / s.nd.size());

    double med = mediana(s);
    s.galutinis_mediana = 0.6 * s.egz + 0.4 * med;
}
void spausdintiVid(studentas& s)
{
    cout << setw(20) << left << s.pavarde << setw(20) << left << s.vardas << setw(20) << left << fixed << setprecision(2) << s.galutinis_vidurkis << endl;
}

void spausdintiMed(studentas& s)
{
    cout << setw(20) << left << s.pavarde << setw(20) << left << s.vardas << setw(20) << left << fixed << setprecision(2) << s.galutinis_mediana << endl;
}
void spausdinti(studentas& s)
{
    cout << setw(20) << left << s.pavarde << setw(20) << left << s.vardas << setw(20) << left << fixed << setprecision(2) << s.galutinis_vidurkis << setw(20) << left << fixed << setprecision(2) << s.galutinis_mediana << endl;
}

bool check_string(string& str)
{
    int sum = 0;

    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) sum += 1;

    if (sum == str.length()) return true;
    else return false;
}


void pildnd(studentas& s, int& ii, int& ndSk1)
{
    double sum = 0.;
    double paz;

    cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
    for (int j = 0; j < ndSk1; j++)
    {
        cin >> paz;
        while (cin.fail() || paz < 1 || paz > 10)
        {
            cin.clear();
            cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
            cin.ignore(256, '\n');
            cin >> paz;
        }
        s.nd.push_back(paz);
        sum += paz;
    }

    cout << "Iveskite egzamino pazymi (1-10): " << endl;
    cin >> s.egz;
    while (cin.fail() || s.egz <= 0 || s.egz > 10)
    {
        cin.clear();
        cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
        cin.ignore(256, '\n');
        cin >> s.egz;
    }

    s.galutinis_vidurkis = 0.6 * s.egz + 0.4 * (sum / ndSk1);

    double med = mediana(s);
    s.galutinis_mediana = 0.6 * s.egz + 0.4 * med;
}

void pildndrnd(studentas& s, int& ii, int& ndSk1)
{
    double sum = 0.;
    double paz;

    srand(time(NULL));

    for (int j = 0; j < ndSk1; j++)
    {
        paz = rand() % 10 + 1;
        cout << j + 1 << " pazymys: " << paz << endl;
        s.nd.push_back(paz);
        sum += paz;
    }

    s.egz = rand() % 10 + 1;

    cout << "Egzamino pazymys: " << s.egz << endl;

    s.galutinis_vidurkis = 0.6 * s.egz + 0.4 * (sum / ndSk1);

    double med = mediana(s);
    s.galutinis_mediana = 0.6 * s.egz + 0.4 * med;
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