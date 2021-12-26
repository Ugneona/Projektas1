#pragma once
#include "Antraste.h"
#include "Studentas.h"
#include "Uzklausos.h"
#include "Skaiciavimai.h"
#include "Spausdinimas.h"

void failas();
void failuKurimas(vector <int>& v1, int& ndKiek);
void darbasSuFailu(vector <int>& v1, int& ndKiek, char& atsakymas);
void failoNuskaitymas(vector <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek);
void rusiavimas(vector <studentas>& grupe1, vector <studentas>& protingi, vector <studentas>& tinginiai, vector <double>& laikas, char& atsakymas);