# V1.0 versijoje:
1) Vartojo yra pasiteiraujama: "Ar norite sugeneruoti 5 naujus failus su duomenimis apie studentus? T - jei norite, n - jei nenorite". Jei vartotojas nori sukurti naujus failus ir dirbti su jais taip apskaičiojant rūšiavimo strategijos nr. 1  ir rūšiavimo strategijos nr. 2 veikimo laiką dirbant su skirtingais konteineriais (list ir vector), turi įvesti t ar T. (šioje programos dalyje ir yra įgyventi pagrindiniai programos atnaujinimai, nes, jei pasirinksime n ar N, programa dirbs pagal v.02 versija, kur programa arba nuskaito iš failo ir išvedą atsakymus į kitą failą, arba įvedimo lange yra įvedame ir išvedami rezultati)
2) Vartotojo pasiteiraujama, kiek bus namų darbų. Turi įvesti namų darbų skaičių
3) Vartotojo pasiteiraujama: "Ar atsakyma noresite gauti su vidurkiu? Jei taip, veskite t, jei su mediana, vesikite n". Atitinkamai, jei vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu, veda raidę T ar t, jei nori, kad galutinisi balas būtų su mediana, veda raidę N ar n.
4) Sukuriami studentų failai su 1000, 10000, 100000, 1000000, 10000000 studentų ir atitinkamai išvedami sugaištas laikas jiems sukurti.
5) Su kiekvienu failu atliekami tokie žingsniai:
   * Tas pats failas nuskaitomas į vectorių, tada į listą. Sukuriamos iškart po 2 grupes;
   * Atliekamas rūšiavimas vectoriaus ir listo strategija nr. 1 (Su pirma grupe);
   * Atliekamas rūšiavimas vectoriaus ir listo strategija nr. 2. (vectoriaus rūšiavimas optimizuojamas naudojant algoritmus **std::partition ir std::remove_if**)(Su antra grupe);
   * Išvedimas vectoriuje esančių protingų ir tinginių studentų į atskirus failus;
   * Išvedimas liste esančių protingų ir tinginių studentų į atskirus failus. </br>
# Pvz. (ndsk = 2)

  



  
  

  ![naujas 2 nd](https://user-images.githubusercontent.com/90412167/142625562-d47a44ba-9893-4ced-978b-899cfd195ab2.jpg)<br/>
 # Išvados:
 * Matome, kad naudojant 1 strategiją su konteineriumi vectorius rūšiavimas įvyksta greičiau nei su konteineriumi listas;
 * Matome, kad naudojant 2 strategiją su konteineriumi vectorius ir naudojant algoritmus **std::partition ir std::remove_if** rūčiavimas įvyksta greičiau nei su konteineriumi listas;
 * Matome, kad iki 10 mln. studentų su konteineriumi vectorius efektyvesnė rūšiavimo strategiją nr. 2;
 * Matoma, kad nuo 1 mln. studentų su konteineriumi listas efektyvesnė rūšiavimo strategiją nr. 1.









