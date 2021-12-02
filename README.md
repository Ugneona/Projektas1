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
# Pvz. (ndsk = 3)
  ![v1 0 rezultatai](https://user-images.githubusercontent.com/90412167/144485425-ac59d490-7b76-4fe7-8d1f-e95ccc242ae3.jpg)
 # Išvados:
 * Atminties atžvilgiu laimime naudodami 1 rūšiavimo strategiją;
 * Matoma, kad nuskaitymas į konteinerį listas yra efektyvesnis nei į konteinerį vectorius;
 * Matome, kad naudojant 1 strategiją su konteineriumi vectorius rūšiavimas įvyksta greičiau nei su konteineriumi listas;
 * Matome, kad naudojant 2 strategiją su konteineriumi vectorius rūšiavimas įvyksta greičiau nei su konteineriumi listas, abiejiems konteineriams naudojant algoritmus **std::partition**, išskyrus su 10 mln.;
 * Matome, kad iki 10 mln. studentų su konteineriumi vectorius efektyvesnė rūšiavimo strategiją nr. 2;
 * Matome, kad studentų su konteineriumi listas efektyvesnė rūšiavimo strategija yra nr. 2.

# V.05 versija
Kompiuterio parametrai: Intel(R) Core(TM) i5-10210U CPU @ 1.60GHz   2.11 GHz
RAM 8 GB
512 GB SSD.</br>
Šioje versijoje lyginame vector ir list konteinerių spartą, saugodami juose strukt8rą studentas. Lyginame pagal nuskaitymo iš failo ir surašiavimo į dvi grupes aspektus. Bandymas vykdomas su 1000, 10000, 100000, 1000000, 10000000 studentų sąrašais, kuriuos programos pradžioje sukuriame, atsižvelgiant į pageidaujamą namų darbų kiekį.</br>
Rezultatai, kai ndsk=1:
![image](https://user-images.githubusercontent.com/90412167/140548534-3069a169-5586-4394-be03-35466ea7effc.png)

# V.04 versijoje:
* Leidžiame pasirinkti, ar kursime 5 naujus failus sudarytus iš 1000, 10000, 100000, 1000000, 10000000 studentų.
* Jei sutinkame:
  * Paklausiame, kiek norime, kad būtų namų darbų pažymių;
  * Visų pirma sugeneruojame penkis naujus failus su šabloniniais pavardais, pavardėmis, random sugeneruotais pažymiais iš namų darbų ir egzamino pažymiu;
  * Išvedame, kiek laiko truko kiekvienas failo generavimas;<br/>
  *PVZ(ndsk=1): 
1000 elementu uzpildymas truko: 0.0193545 s;<br/>
10000 elementu uzpildymas truko: 0.0911438 s;<br/>
100000 elementu uzpildymas truko: 0.728481 s;<br/>
1000000 elementu uzpildymas truko: 8.36599 s;<br/>
10000000 elementu uzpildymas truko: 84.5386 s;*<br/>
  
  * Darbas su failais:
    * Tada nuskaitome pirmąjį failą, suskaičiuojame galutinį balą su mediana ar vidurkiu. Prieš tai vartotojas pasirenka su kuo norės matyti atsakymą. Išvedame nuskaitymo trukmę;
    * Surušiuojame studentus pagal galutinį pažymį ir suskirstome į dvi grupes "protingi", jei galutinis balas >= 5.00, "tinginiai", jei galutinis balas < 5.00. Išvedame, kiek truko studentų surūšiavimas;
    * Išvedame į atskirus failus "protingų" studentų sąrašus su galutiniais pažymiais ir "tinginių" sąrašus su galutiniais pažymiais. Išvedame, kiek užtruko kiekvieną failą sukurti.<br/>
*PVZ(ndsk=1). 1000 studentu failo nuskaitymas truko: 0.0025905 s;<br/>
1000 studentu surusiavimas i dvi grupes truko: 0.001977 s;<br/>
1000 protingu studentu surasymas i failo truko: 0.0048662 s;<br/>
1000 tinginiu studentu surasymas i failo truko: 0.0034136 s;*<br/>

         *10000 studentu failo nuskaitymas truko: 0.024472 s;<br/>
         10000 studentu surusiavimas i dvi grupes truko: 0.0225502 s;<br/>
         10000 protingu studentu surasymas i failo truko: 0.0576111 s;<br/>
         10000 tinginiu studentu surasymas i failo truko: 0.0485264 s;*<br/>

        *100000 studentu failo nuskaitymas truko: 0.266832 s;<br/>
        100000 studentu surusiavimas i dvi grupes truko: 0.285846 s;<br/>
        100000 protingu studentu surasymas i failo truko: 0.664078 s;<br/>
        100000 tinginiu studentu surasymas i failo truko: 0.593419 s;*<br/>

        *1000000 studentu failo nuskaitymas truko: 2.98551 s;<br/>
        1000000 studentu surusiavimas i dvi grupes truko: 3.54141 s;<br/>
        1000000 protingu studentu surasymas i failo truko: 5.68257 s;<br/>
        1000000 tinginiu studentu surasymas i failo truko: 4.3027 s;*<br/>
        
        *10000000 studentu failo nuskaitymas truko: 21.2246 s;<br/>
10000000 studentu surusiavimas i dvi grupes truko: 38.2672 s;<br/>
10000000 protingu studentu surasymas i failo truko: 44.741 s;<br/>
10000000 tinginiu studentu surasymas i failo truko: 33.8542 s;*<br/>
* Jei nesutinkame vykdome numatytus veiksmus iš programos V.02. 

# V.03 versijoje:
* Panaudotos, kur galima išimtys (naudojau try&catch), vietoj įprastinių tikrinimų;
* Iškeltos funkcijos į atskirus cpp ir header failus, taip pat ir antraštiniai užrašymai iškelti (std ir include).

# V.02 versijoje:
* Kiekvienam įvedimui yra naudojamas patikrinimas, ar teisinga įvesta raidė ar skaičius;
* Klausiama, ar nuskaitysime duomenis iš failo "kursiokai.txt";
* Jei sutinkame:
  * klausiame, kokio norime atsakymo formato, ar su vidurkiu, ar su mediana, ar abudu.
  * Iš failo yra nuskaitoma pirma eilutė ir sužinoma, kiek yra stulpelių. Iš to sužinome, kiek yra namų darbų;
  * Eilutės duomenis įrašinėjame į struktūrą stu: vardą, pavardę, namų darbų pažymius, egzamino pažymį;
  * Suskaičiuojame galutinį išvestą pažymį su vidurkiu ir galutinį išvestą pažymį su mediana;
  * Išrikiuojame duomenis pagal pavardes abėcėlės tvarka;
  * Išvedame duomenis į naują failą "rezultatai.txt";
* Jei nesutinkame atliekame visus veiksmus iš V.01.

# V.01
Padaryta:
* Kiekvienam įvedimui yra naudojamas patikrinimas, ar teisinga įvesta raidė ar skaičius;
* Sukurta struktūra studentas, kuriame yra saugomas jo vardas, pavardė, namų darbų pažymiai, egzamino pažymis, galutinis išvestas pažymys su vidurkiu ir galutinis išvestas pažymys su mediana;
* Klausiame, ar žmogus pats įves duomenis, ar automatiškai generuosime, nuo to priklausys tolesnesni veiksmai;
* Pasirinkus mechaninį įvedimą:
  * Įvedamas studentų skaičius ir patikrinama, ar tai yra skaičius ir ar didesnis už 0;
  * Klausiame, ar žinome iš anksto, kiek bus namų darbų;
  * Jei žinome:
    * Įvedame nd. skaičių;
    * Įvedami nd. pažymiai ir saugomi vectoriuje;
    * Įvedamas egzamino pažymis;
    * Apskaičiuojamas galutinis paž, t.y. vidurkis, ir mediana;
  * Jei nežinome:
    * Įvedame nd. pažymį;
    * Teiraujamės, ar dar bus namų darbų. Jei bus, vedame, jei ne, pereiname į kitą žingsnį;
    * Įvedame egzamino pažymį;
    * Apskaičiuojamas galutinis paž. su vidurkiu ir mediana;
* Pasirinkus automatinį:
  * Automatiškai sugeneruoja, kiek yra moksleivių:
  * Klausiame, ar žinome, kiek bus nd. iš anksto;
  * Jei taip:
    * Sugeneruojame nd. pažymius automatiškai ir įrašome į vectorių;
    * sugeneruojame egz. paž;
    * Apskaičiuojamas galutinis paž. su vidurkiu ir mediana;
  * Jei nežinome:
    * Sugeneruojame nd. pažymį automatiškai ir vis klausiame, ar dar bus nd. ir įrašome į vectorių;
    * sugeneruoja egz. pažymį;
    * Apskaičiuojamas galutinis paž. su vidurkiu ir mediana;
 * Pabaigoje klausiame, kokio norime atsakymo formato, ar su vidurkiu, ar su mediana, ar abudu.
  






