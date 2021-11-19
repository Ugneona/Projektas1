# V1.0 versijoje:
1) Vartojo yra pasiteiraujama: "Ar norite sugeneruoti 5 naujus failus su duomenimis apie studentus? T - jei norite, n - jei nenorite". Jei vartotojas nori sukurti naujus failus ir dirbti su jais taip apskaičiojant rūšiavimo strategijos nr. 1  ir rūšiavimo strategijos nr. 2 veikimo laiką dirbant su skirtingais konteineriais (list ir vector), turi įvesti t ar T. (šioje programos dalyje ir yra įgyventi pagrindiniai programos atnaujinimai, nes, jei pasirinksime n ar N, programa dirbs pagal v.02 versija, kur programa arba nuskaito iš failo ir išvedą atsakymus į kitą failą, arba įvedimo lange yra įvedame ir išvedami rezultati)
2) Vartotojo pasiteiraujama, kiek bus namų darbų.
3) Vartotojo pasiteiraujama: "Ar atsakyma noresite gauti su vidurkiu? Jei taip, veskite t, jei su mediana, vesikite n". Atitinkamai, jei vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu, veda raidę T ar t, jei nori, kad galutinisi balas būtų su mediana, veda raidę N ar n.
4) Sukuriami studentų failai su 1000, 10000, 100000, 1000000, 10000000 studentų ir atitinkamai išvedami sugaištas laikas jiems sukurti.
5) Su kiekvienu failu atliekami tokie žingsniai:
   * Tas pats failas nuskaitomas į vectorių, tada į listą;
   * Atliekamas rūšiavimas vectoriaus ir listo strategija nr. 1;
   * Atliekamas rūšiavimas vectoriaus ir listo strategija nr. 2. (vectoriaus rūšiavimas optimizuojamas naudojant algoritmus **std::partition ir std::remove_if**);
   * Išvedimas vectoriuje esančių protingų ir tinginių studentų į atskirus failus;
   * Išvedimas liste esančių protingų ir tinginių studentų į atskirus failus.
Pvz. (ndsk = 2)

  



  ![laikas su 2nd](https://user-images.githubusercontent.com/90412167/142613789-d5f762d6-c7af-4a63-b528-5147a69ff665.jpg)
  
  **Išvados:**
  









