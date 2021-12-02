#pragma once
#include "Antraste.h"
#include "Studentas.h"
#include "Uzklausos.h"
#include "Skaiciavimai.h"
#include "Spausdinimas.h"

void failas();
void failuKurimas(vector <int>& v1, int& ndKiek);
void darbasSuFailu_nr1(vector <int>& v1, char& atsakymas);
void darbasSuFailu(vector <int>& v1, char& atsakymas);
void failoNuskaitymas(vector <studentas>& grupe1, int& v1);
void failoNuskaitymas_list(list <studentas>& grupe1, int& v1);
void rusiavimas_strategija1(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& protingi_vector, vector <studentas>& tinginiai_vector, list <studentas>& protingi_list, list <studentas>& tinginiai_list, vector <double>& laikas_vector, vector<double>& laikas_list, char& atsakymas);
void rusiavimas_strategija2(vector <studentas>& grupe_vector, list <studentas>& grupe_list, vector <studentas>& tinginiai_vector_2, list <studentas>& tinginiai_list_2, vector <double>& laikas_vector, vector<double>& laikas_list, char& atsakymas);
void rusiavimas(vector <studentas>& grupe1, vector <studentas>& protingi, vector <studentas>& tinginiai, vector <double>& laikas, char& atsakymas);