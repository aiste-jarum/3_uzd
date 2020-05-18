# 3_uzd

- myvector funkcijos (visi pavyzdžiai, pateikti https://en.cppreference.com/w/cpp/container/vector yra šiek tiek perrašyti, kadangi aprašytos ne visos vektoriaus funkcijos, tačiau pavydžių esmė nepakeista):
1. size (failas vector_size.cpp):
Gražina vektoriaus dydį. Atsakymas su pavyzdžiu sutampa.

2. max_size (failas vector_max_size.cpp):
Gražina vektoriaus maksimalų dydį. Atsakymas nuo pavyzdžio skirasi, nes vietoj string yra paimtas numatytasis vektoriaus dydis - 10.

3. at (failas vector_at.cpp):
Kadangi vektoriaus konteinerio aprašyme nėra at funkcijos pavydžio, yra aprašomas savarankiškai. Į myvector įrašomos 4 reikšmės (1,2,3,4) ir funkcijos at pagalba atspauzdinamos į ekraną.

4. pop_back (failas vector_pop_back.cpp, funkcijos pavadinimas pakeistas į the_pop_back):
Funkcija panaikina paskutinį vektoriaus elementą.

5. resize (failas vector_resize.cpp)
Funkcija pakeičia vektoriaus dydį (kiek vektorius laiko elementų).

- myvector vs. std::vector
Vektorių sparta lyginama pagal užduotyje pateikto kodo įvykdymo laiką.
Screenshot'us galima rasti failuose myvector.png ir vector_std.png.
  |myvector|std::vector|elementai |
  |--------|-----------|----------|
  |   0 s        |   0 s|10 000     |
  |   0.001997 s |   0.000994 s| 100 000   |
  |   0.010969 s |   0.016955 s| 1 000 000  |
  |   0.102732 s | 0.168549 s | 10 000 000|
  |   1.25054  s | 1.61451 s|100 000 000 |
