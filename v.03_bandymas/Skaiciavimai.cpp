#include "Skaiciavimai.h"

double mediana(studentas& s)
{
    int ndKiek1 = s.nd.size();
    try
    {
        if (ndKiek1 == 0) throw (ndKiek1);
    }
    catch (int ndKiek1)
    {
        cout << "Vektorius turi: " << ndKiek1 << " elementu" << endl;
    }

    sort(s.nd.begin(), s.nd.end());

    if (ndKiek1 % 2 == 0) return (double)(s.nd[(ndKiek1 / 2) - 1] + s.nd[ndKiek1 / 2]) / 2.0;
    else return (double)s.nd[ndKiek1 / 2];
}

double vidurkis(studentas& s)
{
    double sum = 0.;
    double kiekis = 0.;
    double vid = 0.;

    try
    {
        if (s.nd.size() == 0) throw (s.nd.size());
    }
    catch (int ndKiek)
    {
        cout << "Vektorius turi: " << ndKiek << " elementu" << endl;
    }

    for (int i = 0; i < s.nd.size(); i++)
    {
        sum += s.nd.at(i);
        kiekis++;
    }

    vid = sum / kiekis;

    return vid;
}