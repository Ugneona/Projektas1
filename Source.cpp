#include <iostream>
#include <iomanip> 
#include <string>
#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::sort;


struct studentas
{
    string vardas, pavarde;
    double nd[10]{};
    int egz;
    double galutinis;
    double mediana;
};

void pild(studentas& s, int& ndSk1, int& ii);
void spausdinti(studentas& s);
bool check_string(string& str);
double med(studentas& s, int& ndSk1);


int main()
{
    int studentSk, ndSk; 
    studentas grupe[10];
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> studentSk;
    while (studentSk <= 0 || cin.fail())
    {
        cin.clear();
        cout << "Nurodytas skaicius yra netinkamas, iveskite studentu skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> studentSk;
    }

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
        pild(grupe[i], ndSk, i);
    }
    cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(20) << left << "Galutinis (Vid.)" << left << "Galutinis (Mediana)" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i < studentSk; i++)
    {
        spausdinti(grupe[i]);
    }

    return 0;
}
void pild(studentas& s, int& ndSk1, int& ii)
{
    float sum = 0.;
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

    cout << "Iveskite gautus pazymius is namu darbu (1-10): " << endl;
    for (int j = 0; j < ndSk1; j++)
    {
        cin >> s.nd[j];
        while (cin.fail() || s.nd[j] < 1 || s.nd[j] > 10)
        {
            cin.clear();
            cout << "Neteisingai ivedete pazymi, prasome dar karta ivesti (1-10)" << endl;
            cin.ignore(256, '\n');
            cin >> s.nd[j];
        }
        sum += s.nd[j];
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
    s.galutinis = 0.6 * s.egz + 0.4 * (sum / ndSk1);
    s.mediana = med(s, ndSk1);
}
void spausdinti(studentas& s)
{
    cout << setw(20) << left << s.pavarde << setw(20) << left << s.vardas << setw(20) << left << fixed << setprecision(2) << s.galutinis << fixed << setprecision(2) << s.mediana << endl;

}

bool check_string(string& str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) sum += 1;
    if (sum == str.length()) return true;
    else return false;
}

double med(studentas& s, int& ndSk1)
{
    sort(s.nd, s.nd + ndSk1);
    int vid = ndSk1 / 2;
    if (ndSk1 % 2 == 0) return (double)(s.nd[vid - 1] + s.nd[vid]) / 2.0;
    else return (double)s.nd[vid];
}

