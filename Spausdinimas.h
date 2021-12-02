#pragma once
#include "Antraste.h"
#include "Studentas.h"

void spausdinti_vector(char& atsakymas, vector <studentas>& grupe1);
void spausdinti_vector_nr2(char& atsakymas, vector <studentas>& grupe1);

void spausdinimas(int& v1, char& atsakymas, vector <studentas>& sarasas, string& pav);
void spausdinimas(int& v1, char& atsakymas, list <studentas>& sarasas, string& pav);

void spausdinimas_nr1(int& v1, char& atsakymas, vector <studentas>& sarasas, vector <double>& laikas, string& pav);