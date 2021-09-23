#include <iostream>
#include <iomanip> 
#include <string>
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;


struct studentas
{
    string vardas, pavarde;
    int nd[10]{};
    int egz;
    double galutinis;
};

void pild(studentas& s, int& sk1, int& ii);
void spausdinti(studentas& s);
bool check_string(string& str);


int main()
{
    int n, sk;
    studentas grupe[10];
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> n;
    while (n <= 0 && isdigit(n) == false)
    {
        cin.clear();
        cout << "Nurodytas skaicius yra netinkamas, iveskite studentu skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> n;
    }

    cout << "Iveskite, kiek bus namu darbu (1-10)" << endl;
    cin >> sk; 
    while (isdigit(sk) == false && (sk < 1 || sk > 10))
    {
        cin.clear();
        cout << "Namu darbu skaicius yra netinkamas, iveskite skaiciu didesni uz 0" << endl;
        cin.ignore(256, '\n');
        cin >> sk;
    }
 
    for (int i = 0; i < n; i++)
    {
        pild(grupe[i], sk, i);
    }
    cout << setw(20) << left << "Pavarde" << setw(20) << left << "Vardas" << setw(16) << left << "Galutinis (Vid.)" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        spausdinti(grupe[i]);
    }

    return 0;
}
void pild(studentas& s, int& sk1, int& ii)
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
    for (int j = 0; j < sk1; j++)
    {
        cin >> s.nd[j];
        while ((isdigit(s.nd[j]) == false)&&( s.nd[j] < 1 || s.nd[j] > 10))
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
    while (isdigit(s.egz) == false && (s.egz <= 0 || s.egz > 10))
    {
        cin.clear();
        cout << "Neteisingai ivedete egzamino pazymi, prasome dar karta ivesti (1-10)" << endl;
        cin.ignore(256, '\n');
        cin >> s.egz;
    }
    s.galutinis = 0.6 * s.egz + 0.4 * (sum / sk1);
}
void spausdinti(studentas& s)
{
    cout << setw(20) << left << s.pavarde << setw(20) << left << s.vardas << setw(16) << left << fixed << setprecision(2) << s.galutinis << endl;

}

bool check_string(string& str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false) sum += 1;
    if (sum == str.length()) return true;
    else return false;
}

