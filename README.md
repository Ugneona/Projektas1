# V1.0 versijoje:
1) Vartotojo yra pasiteiraujama: "Ar dirbsime su failais ir atliksime greicio tyrima? T - jei taip, n - jei neatliksime greicio tyrimo". Pasirinkus t ar T, pereisimo prie darbo su failais ir atliksime greicio tyrima. Pasirinkus n ar N, programa darys veiksmus pagal v0.2 versiją.</br>
2) Vartojo yra pasiteiraujama: "Ar norite sugeneruoti 5 naujus failus su duomenimis apie studentus? T - jei norite, n - jei nenorite dirbti jau su sugeneruotais". Pasirinkus t ar T, programa darys veiksmus pagal v0.4 versiją. Jei vartotojas nori dirbti su sukurtais failais ir apskaičiuoti rūšiavimo strategijos nr. 1  ir rūšiavimo strategijos nr. 2 veikimo laiką dirbant su skirtingais konteineriais (list ir vector), turi įvesti N ar n.</br>
3) Vartotojo pasiteiraujama: "Ar atsakyma noresite gauti su vidurkiu? Jei taip, veskite t, jei su mediana, vesikite n". Atitinkamai, jei vartotojas nori, kad galutinis balas būtų skaičiuojamas su vidurkiu, veda raidę T ar t, jei nori, kad galutinisi balas būtų su mediana, veda raidę N ar n.</br>
4) Su kiekvienu failu atliekami tokie žingsniai:
   * Tas pats failas nuskaitomas į vectorių, tada į listą. Išvedamas į ekraną sugaištas laikas;
   * Atliekamas rūšiavimas vectoriaus ir listo strategija nr. 1 (Su pirma grupe).Išvedamas į ekraną sugaištas laikas;
   * Išvedimas vectoriuje esančių protingų ir tinginių studentų į atskirus failus;
   * Išvedimas liste esančių protingų ir tinginių studentų į atskirus failus. 
   * Atliekamas rūšiavimas vectoriaus ir listo strategija nr. 2. (vectoriaus  ir listo rūšiavimas optimizuojamas naudojant algoritmus **std::partition**). </br>
## Pvz. (ndsk = 3)

  



  ![v1 0 rezultatai](https://user-images.githubusercontent.com/90412167/144485425-ac59d490-7b76-4fe7-8d1f-e95ccc242ae3.jpg)

  


 ## Išvados:
 * Atminties atžvilgiu laimime naudodami 1 rūšiavimo strategiją;
 * Matoma, kad nuskaitymas į konteinerį listas yra efektyvesnis nei į konteinerį vectorius;
 * Matome, kad naudojant 1 strategiją su konteineriumi vectorius rūšiavimas įvyksta greičiau nei su konteineriumi listas;
 * Matome, kad naudojant 2 strategiją su konteineriumi vectorius rūšiavimas įvyksta greičiau nei su konteineriumi listas, abiejiems konteineriams naudojant algoritmus **std::partition**, išskyrus su 10 mln.;
 * Matome, kad iki 10 mln. studentų su konteineriumi vectorius efektyvesnė rūšiavimo strategiją nr. 2;
 * Matome, kad studentų su konteineriumi listas efektyvesnė rūšiavimo strategija yra nr. 2.









