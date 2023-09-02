# arduino_masin

## Robotun hisseleri
Ardunio NANO;
Robot kartı, uzerinde 2 eded motor surucu var ve 6 analoq pin, 2 digital pin, led və buzzer var;
3 dene FS-80;
1 dene TCS-3200;
1 dene 5v
2 dene DC motor
4 teker

## Robotun hisseleri nece qosulub

Robot karti nano'nun tam altina yerlesecek sekilde qoyulur.
Reng sensoru(TCS-3200) ucun:
-S0 D8
-S1 A5
-S3 A2
-S4 A1
-sensorOUT ise D12

Motorlar ucun:
Robot kartin motor hisseleri

Tekerler ucun:
DC motorlar

Baterya ucun:
Motorlarin ortasindaki baterya yeri.Musbete qirmizi, menfiye qara naqili qoyuruq.(DIQQET:Bateryani taxan vaxt musbetle menfi naqili toqqusdurmayin)

FS-80'lar ucun:
-Soldaki ucun A4
-Sagdaki ucun A3
-Ondeki ucun A0


## Isleme mentigi
Sensorlar ucun:

FN-80 qabaginda mane olub olmadigina baxir

Reng sensoru ise:
sensorOUT qarsisindakinin rengini oyrenmek ucun signal yolluyub-qebul eleme vezifesine sahibdi
S1 ve S0 tezliyi;
S2 ve S3 ise rengleri teyin edir.
Eger S2 ve S3 aktiv olanda YASIL filter;
Yalniz S3 aktiv S2 sonulu olarsa GOY filter;
Yalniz S3 ve S2 sonulu olarsa  QIRMIZI filter

Robotun isleme mentigi:

Ustundeki yandirma duymesi aktiv olunduqda, robot ise dusur. Qarsisindaki obyekte uygun olaraq(yasil/qirmizi mane ve border) reaksiyalar verir:
Qarsisindaki:
1. Qirmizi mane olanda saga;
2. Yasil mane olanda ise on tekerler sola firlanir. 3. Ehtimali uzun sekilde asagi yazmisiq
   
3. Border(serhed) olanda ise ilk once sensorlarin veziyetini oyrenmek meqsedile geriye gedilir. Eger sag sensor aktivdise sola,sol sensor aktivdise saga yonelir.
Yoneldikden sonra robot ireli gedir. Eger robot divarlara surtunmeye davam edirse sensorlar bunu Arduino"a(beyne) bildirir. Daha sonra borderdan uzaqlasma meqsediyle robot hemle edir. Uzaqlasma zaman eger ki, tezeden merkez/yan bordera yaxinlasarsa, yan sensorlar bunu bildirir. Ve yene buna uygun olaraq hemle eliyir.


## Robotun islemesi ucun neler etmek lazimdi

Sekiller ve verdiyimiz melumatlar esasinda robotun yigilmasindan sonra, kartin ustundeki yandirma duymesi aktiv edilir.
