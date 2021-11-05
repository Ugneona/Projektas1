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


