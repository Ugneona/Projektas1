#include "Uzklausos.h"


int studentuSkaiciausUzklausa()
{
    int studentSk;

    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> studentSk;

    do
    {
        try
        {
            if (studentSk <= 0 || cin.fail())
            {
                throw (std::runtime_error("Neatpazintas simbolis arba studentu skaicius yra netinkamas\n"));
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cout << "Prasome ivesti skaiciu didesni uz 0" << endl;
            cin.ignore(256, '\n');
            cin >> studentSk;
        }

    } while (studentSk <= 0 || cin.fail());

    return studentSk;
}

char uzklausa_arNdSkaiciusZinomas()
{
    char ats;
    cout << "Ar namu darbu skaicius yra zinomas is anksto? t- jei taip, n- jei ne" << endl;
    cin >> ats;

    do
    {
        try
        {
            if (isalpha(ats) == false || check_alpha(ats) == false)
            {
                throw (std::runtime_error("Neatpazintas simbolis\n"));
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cout << "Prasome ivesti t - jei namu darbu skaicius zinomas, n - jei namu darbu skaicius nezinomas" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }

    } while (isalpha(ats) == false || check_alpha(ats) == false);

    return ats;
}

int uzklausa_kiekNdYra()
{
    int ndSkaicius;
    cout << "Iveskite, kiek bus namu darbu (1-10)" << endl;
    cin >> ndSkaicius;

    do
    {
        try
        {
            if (cin.fail() || ndSkaicius < 1 || ndSkaicius > 10)
            {
                throw (std::runtime_error("Neatpazintas simbolis arba namu darbu skaicius yra netinkamas\n"));
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cout << "Prasome ivesti skaiciu didesni uz 0, bet nedidesnis uz 10" << endl;
            cin.ignore(256, '\n');
            cin >> ndSkaicius;
        }

    } while (cin.fail() || ndSkaicius < 1 || ndSkaicius > 10);

    return ndSkaicius;
}

char uzklausa_arBusDarPazymiu()
{
    char ats;
    cout << "Ar dar bus pazymiu is namu darbu? t - jei bus dar, n - jei nebebus" << endl;
    cin >> ats;

    do
    {
        try
        {
            if (isalpha(ats) == false || check_alpha(ats) == false)
            {
                throw (std::runtime_error("Neatpazintas simbolis\n"));
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cout << "Prasome ivesti t - jei namu darbu dar bus n - jei namu darbu nebebus" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }

    } while (isalpha(ats) == false || check_alpha(ats) == false);

    return ats;
}

char uzklausa_delFailo()
{
    char klsm;
    cout << "Ar duomenis skaitysime is failo? Jei skaitysime is failo, veskite t, jei neskaitysime, veskite n" << endl;
    cin >> klsm;
    do
    {
        try
        {
            if (isalpha(klsm) == false || check_alpha(klsm) == false)
            {
                throw (std::runtime_error("Neatpazintas simbolis\n"));
            }
        }
        catch (const std::runtime_error &e)
        {
            cout << e.what();
            cin.clear();
            cout << "Prasome ivesti t - jei skaitysime duomenis is failo, n - priesingu atveju" << endl;
            cin.ignore(256, '\n');
            cin >> klsm;
        }

    } while (isalpha(klsm) == false || check_alpha(klsm) == false);
 
    return klsm;
}

char uzklausa_delAtsakymo()
{
    char ats;
    cout << "Ar noresite matyti atsakyma su vidurkiu ar mediana? Jei su vidurkiu, veskite v, jei su mediana, veskite m, jei abu, veskite a" << endl;
    cin >> ats;

    do
    {
        try
        {
            if (isalpha(ats) == false || check_vma(ats) == false)
            {
                throw (std::runtime_error("Neatpazintas simbolis\n"));
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cout << "Jei norite, kad isvestu vidurki veskite v, jei mediana veskite m, jei abu veskite a" << endl;
            cin.ignore(256, '\n');
            cin >> ats;
        }

    } while (isalpha(ats) == false || check_vma(ats) == false);

    return ats;
}

char uzklausa_delGeneravimo()
{
    char klsm;
    cout << "Ar duomenis vesite pats, ar norite, kad butu sugeneruoti automatiskai? Jei vesite pats veskite t, priesingu atveju veskite n" << endl;
    cin >> klsm;

    do
    {
        try
        {
            if (isalpha(klsm) == false || check_alpha(klsm) == false)
            {
                throw (std::runtime_error("Neatpazintas simbolis\n"));
            }
        }
        catch (const std::runtime_error& e)
        {
            cout << e.what();
            cin.clear();
            cout << "Prasome ivesti t - jei duomenis vesite pats, n - priesingu atveju" << endl;
            cin.ignore(256, '\n');
            cin >> klsm;
        }

    } while (isalpha(klsm) == false || check_alpha(klsm) == false);

    return klsm;
}
