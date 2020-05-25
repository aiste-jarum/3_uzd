# 3_uzd (Perdarytas release)

- myvector tikrinamos funkcijos ( https://en.cppreference.com/w/cpp/container/vector), visas galima rasti main faile:
1. Operator[]:
Pavyzdyje reikšmės deklaruojamos naudojant std::vector<x> X {...}; būdą (viskas deklaruojama laužtiniuose sklaiustuose), kuris neveikia parašytoje klasėje, todėl reikšmės deklaruojamos naudojant push_back funkciją.  Atsakymas su pavyzdžiu sutampa.

2. Size:
Pavyzdyje reikšmės deklaruojamos naudojant std::vector<x> X {...}; būdą (viskas deklaruojama laužtiniuose sklaiustuose), kuris neveikia parašytoje klasėje, todėl reikšmės deklaruojamos naudojant push_back funkciją.  Atsakymas su pavyzdžiu sutampa.

3. Operatorius ==:
Kadangi vektoriaus konteinerio aprašyme nėra operatoriaus == pavydžio, yra aprašomas savarankiškai. Rezultatai grąžinami teisingi.

4. Operatorius !=:
Kadangi vektoriaus konteinerio aprašyme nėra operatoriaus != pavydžio, yra aprašomas savarankiškai. Rezultatai grąžinami teisingi.

3. Operatorius <=:
Kadangi vektoriaus konteinerio aprašyme nėra operatoriaus <= pavydžio, yra aprašomas savarankiškai. Rezultatai grąžinami teisingi.

- sukurta vektoriaus klase vs. std::vector
Vektorių sparta lyginama pagal užduotyje pateikto kodo įvykdymo laiką.
Screenshot'us galima rasti failuose myvector.png ir vector_std.png.
  |vektoriaus klase|std::vector|elementai |
  |--------|-----------|----------|
  |   0.000997 s        |   0 s|10 000     |
  |   0.00114 s |   0.002014 s| 100 000   |
  |   0.011965 s |   0.0159338 s| 1 000 000  |
  |   0.121663 s | 0.237874 s | 10 000 000|
  |   1.03478  s | 1.7192 s|100 000 000 |
