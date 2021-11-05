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
void failoNuskaitymas_list(list <studentas>& grupe1, int& v1, vector <double>& laikas, int& ndKiek);
void rusiavimas(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, vector <studentas>& tinginiai_vector, list <studentas>& protingi_list, list <studentas>& tinginiai_list, vector <double>& laikas_vector, vector<double>& laikas_list, char& atsakymas);