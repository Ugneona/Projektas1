#include "Skaiciavimai.h"

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