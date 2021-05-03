# autoszerviz
Felhasználói dokumentáció
A program egy autószerelő műhely mindennapjainak megkönnyítését hivatott ellátni. A program segítségével a dolgozók rendszerbe foglalhatják a vendégeik adatait, valamint az általuk elvégzett munkálatokat rendszerbe foglalni. 
Megjelenítés:
A programoz nem készült grafikus felület, így a menüt és az egyéb funkciókat Console-on keresztül jeleníti meg. 
Menü:
A program indításakor egy menüsor jelenik meg. Fontos megjegyeznünk, hogy a program a menüválasztás és a menüben elvégzett feladat után visszalép alaphelyzetbe, azaz megint megjeleníti a menüt.  Az adott szám beírásával a következő 7 db menüpont közül választhatunk:
 	Adatok rögzítése
 	Adatok törlése
 	Keresés
 	Javítások rögzítése
 	Szervíztörténet megjelenítése autó alapján
 	Közelben lejáró forgalmik megjelenítése
 	Kilépés
Adatok rögzítése:
Az első menüpont segítségével új autók adatait vehetjük fel a rendszerbe. Ekkor a következő paramétereket kell megadnunk:
 	Tulajdonos neve: A tulajdonos neve maximum 30 karakter hosszú lehet. A szóközök helyére „_” jelet kell tennünk a zavartalan működés érdekében.
 	Elérhetőség: Az elérhetőség lehet név, telefonszám, lakcím szintén maximum 30 karakter. A szóközök helyére „_” jelet kell tennünk a zavartalan működés érdekében.
 	Rendszám: Az autók egyedi azonosítója. A program általánosságban a Magyarországon használt formátum tárolására készült, azaz maximum 7 karakter hosszúak. A formátum tehát pl: AAA-111, ettől függetlenül más 7 karakter hosszú rendszám is eltárolható.
 	Típus: Megadhatjuk az autó márkáját és a márkán belüli típusát. A szóközök helyére „_” jelet kell tennünk a zavartalan működés érdekében.
 	Forgalmi vizsga: A forgalmi vizsga érvényességének rögzítéséhez az alábbi adatok megadása szükséges:
•	Forgalmi év: A forgalmi vizsga lejártának éve.
•	Forgalmi hónap: A forgalmi vizsga lejártának hónapja.
•	Forgalmi nap: A forgalmi vizsga lejártának napja.
Adatok törlése:
A menüpont segítségével törölhetjük az általunk eltárolt autókat és a hozzájuk tartozó adatokat. A törléshez csak az általunk törölni kívánt autó rendszámát kell megadnunk, ugyanis az az egyetlen biztos egyedi azonosító.
Keresés:
A menüpont segítségével kereshetünk az adatbázisban. A keresés lehetséges név vagy rendszám szerint, de akár név és rendszám szerint is kereshetünk. A nem kívánt keresési kritérium helyére „X” karaktert kell tennünk. Ha rendszám alapján keresünk, akkor csak egy adatot fogunk visszakapni. Ha név alapján keresünk, akkor több adatot is visszakaphatunk. Ha név és rendszám alapján keresünk, akkor szintén egy adatot fogunk visszakapni. Fontos hogy a keresési kritériumokra valós, az adatbázisban meglévő adatokat adjunk meg a zavartalan működés érdekében.
Javítások rögzítése:
Ebben a menüpontban a szerviz által elvégzett javításokat rögzíthetjük. Az adatok felvételéhet a következőket kell megadnunk:
 	Rendszám: Ugyanúgy maximum 7 karakter formában.
 	Javítás leírása: Maximum 30 karakter. A szóközök helyére „_” jelet kell tennünk a zavartalan működés érdekében.
 	Ár: A javítás bruttó ára.
 	Javítás dátuma:
•	Javítás éve
•	Javítás hónapja
•	Javítás napja
Szervíztörténet megjelenítése autó alapján:
Megjeleníti az adott autón végrehajtott javításokat a szervízben. A kereséshez mindössze elég megadnunk az autó rendszámát.
Közelben lejáró forgalmik megjelenítése:
A program bekéri tőlünk a mai dátumot külön év, hónap, nap. Ezek után megjeleníti a 15 napon belül lejáró vagy már lejárt forgalmival rendelkező autók rendszámát, típusát, tulajdonosuk nevét és a hátralévő napok számát
Kilépés:
A kilépés menüponttal állíthatjuk le a programot. A program végrehajtja az általunk végzett módosítások mentését. Fontos csak a kilépés menüponttal állítsuk le a programot, ugyanis más leállítási módszer az általunk rögzített adatok elvesztését okozza.
Összefoglaló:
A program a fentebb említett irányelvek mentén használva megkönnyítheti és leegyszerűsítheti egy autószervíz mindennapi adminisztrációs feladatait. Emellett rendszerbe foglalja és tárolja az adatokat, valamint egyszerűbb alternatívát nyújt az adatok közti keresésre és elemzésre.
 
