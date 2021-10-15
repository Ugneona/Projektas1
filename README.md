# V.04 versijoje:
* Leidžiame pasirinkti, ar kursime 5 naujus failus sudarytus iš 1000, 10000, 100000, 1000000, 10000000 studentų.
* Jei sutinkame:
  * Paklausiame, kiek norime, kad būtų namų darbų pažymių;
  * Visų pirma sugeneruojame penkis naujus failus su šabloniniais pavardais, pavardėmis, random sugeneruotais pažymiais iš namų darbų ir egzamino pažymiu;
  * Išvedame, kiek laiko truko kiekvienas failo generavimas;<br/>
  *PVZ: 1000 elementų užpildymas truko 0.0782213 s;<br/>
100000 elementu uzpildymas truko: 10.6467 s;<br/>
1000000 elementu uzpildymas truko: 111.068 s;<br/>
10000000 elementu uzpildymas truko: 853.149 s;*<br/>
  
  * Darbas su failais:
    * Tada nuskaitome pirmąjį failą, suskaičiuojame galutinį balą su mediana ar vidurkiu. Prieš tai vartotojas pasirenka su kuo norės matyti atsakymą. Išvedame nuskaitymo trukmę;
    * Surušiuojame studentus pagal galutinį pažymį ir suskirstome į dvi grupes "protingi", jei galutinis balas >= 5.00, "tinginiai", jei galutinis balas < 5.00. Išvedame, kiek truko studentų surūšiavimas;
    * Išvedame į atskirus failus "protingų" studentų sąrašus su galutiniais pažymiais ir "tinginių" sąrašus su galutiniais pažymiais. Išvedame, kiek užtruko kiekvieną failą sukurti.<br/>
*PVZ. 1000 studentu failo nuskaitymas truko: 0.0754329 s;<br/>
1000 studentu surusiavimas i dvi grupes truko: 0.357562 s;<br/>
1000 protingu studentu surasymas i failo truko: 0.0381508 s;<br/>
1000 tinginiu studentu surasymas i failo truko: 0.027 s;<br/>
10000 studentu failo nuskaitymas truko: 0.732695 s;<br/>
10000 studentu surusiavimas i dvi grupes truko: 3.45194 s;<br/>
10000 protingu studentu surasymas i failo truko: 0.364577 s;<br/>
10000 tinginiu studentu surasymas i failo truko: 0.22854 s;<br/>
100000 studentu failo nuskaitymas truko: 8.38677 s;<br/>
100000 studentu surusiavimas i dvi grupes truko: 38.1994 s;<br/>
100000 protingu studentu surasymas i failo truko: 3.55619 s;<br/>
100000 tinginiu studentu surasymas i failo truko: 2.4512 s*.<br/>
* Jei nesutinkame vykdome numatytus veiksmus iš programos V.02. 


