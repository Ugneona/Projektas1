#pragma once
#include "Antraste.h"
#include "Studentas.h"

void spausdinti_vector(char& atsakymas, vector <studentas>& grupe1);
void spausdinti_struct(char& atsakymas, studentas(&grupe)[100], int& studentuSkaicius);

void spausdinimas(int& v1, char& atsakymas, vector <studentas>& sarasas, string& pav);
void spausdinimas(int& v1, char& atsakymas, list <studentas>& sarasas, string& pav);