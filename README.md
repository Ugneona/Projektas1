# V.02 versijoje:
* Pataisyta V.01 versija, kad struktūroje būtų saugoma ne galutinis išvestas pažymys su vidurkiu ir mediana, o galutinis išvestas pazymys su vidurkiu ir galutinis išvestas pažymys su mediana;
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
* Sukurta struktūra studentas, kuriame yra saugomas jo vardas, pavardė, namų darbų pažymiai, egzamino pažymis ir galutinis išvestas pažymys ir mediana;
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
    * Apskaičiuojamas galutinis paž, t.y. vidurkis, ir mediana;
* Pasirinkus automatinį:
  * Automatiškai sugeneruoja, kiek yra moksleivių:
  * Klausiame, ar žinome, kiek bus nd. iš anksto;
  * Jei taip:
    * Sugeneruojame nd. pažymius automatiškai ir įrašome į vectorių;
    * sugeneruojame egz. paž;
    * Apskaičiuojamas galutinis paž, t.y. vidurkis, ir mediana;
  * Jei nežinome:
    * Sugeneruojame nd. pažymį automatiškai ir vis klausiame, ar dar bus nd. ir įrašome į vectorių;
    * sugeneruoja egz. pažymį;
    * Apskaičiuojamas galutinis paž, t.y. vidurkis, ir mediana;
 * Pabaigoje klausiame, kokio norime atsakymo formato, ar su vidurkiu, ar su mediana, ar abudu.
  








