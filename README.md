Dasovenau Teodora 
324AA
Am implementat intregul enunt al temei.

Am creat un magazin ce include fisiere sursa si header-e pentru
Produse, ce sunt de doua tipuri, alimentare si nealimentare, derivate din clasa de baza Produs. Produsele nealimenatare la randul lor sunt o clasa parinte pentru produsele cu reduceri si cele returnate. Produsele resigilate sunt atat reduse, cat si returnate. Aici apare problema Dead diamound pe care o evitam prin virtualizarea claselor parinte, adica cea pentru produsele reduse si cea cu produsele returnate. Astfel trebuie sa apelam constructorii si metodele specifice pentru atributele din produse nealimentare pentru manevrarea unui obiect de timp produs resigilat. 
Ierarhia utilizatorilor cuprinde clasa agregata Adresa, ce cuprinde datele de localizare, ce se gaseste in clasa utilizatorului general, in care se afla detalii pentru achizitionare. Sunt doua tipuri de utilizatori, unul Basic ce trebuie sa isi plateasca costul transportului si altul ce are reduceri si nu trebuie sa plateasca transportul, dar care trebuie sa plateasca un abonament, premiumSubscription.

In caruciorul de cumparaturi avem un container in care adugam produse, acestea sunt indentificate printr-o cheie ce reprezinta id-ul produsului ce se gaseste in clasa Produs.
Tot aici am adaugat optiuni de scoaterea unui obiect din carucior sau adaugarea sa: lowerQuantity si raiseQuantity. In momentul in care vrem sa scoatem un obiect din cos folosim  deleteProduct.

Clasa Server leaga toate operatiile, contine lista de produse si de utilizatori si un container pentru indentificarea caruciorului fiecarui utilizator.
Aici se remarca functiile de adaugare si de stergere a produselor din carucior.

In principiu am ales sa parcurg caruciorul si sa sa caut daca am vreo cheie ce este id-ul cautat. Daca am gasit-o, testez sa vad daca am produsul respectiv valabil in server si daca pot efectua asupra lui operatiile necesare.
Pentru a verifica daca un utilizator nu este gasit, respectiv un produs, am ales sa incrementez un contor de cate ori id-urile nu corespund.
Astfel, daca un id nu apare niciodata, numarul ocurentelor va fi maxim, adica numarul produselor/id-urilor din server, deci returnez fals.

Query Solver este o clasa cu ajutorul careia facem interogari asupra 
datelor din server, in mare parcurg listele, testez conditiile necesare, sortez lista unde este cazul.
Cel mai interesant a fost sa observam cum functioneaza un dynamic cast, putem apela metode pentru un obiect derivat ce se afla intr-o lista neomogena de pointeri la tipul clasa parinte.

In lucrul cu LRU cahe cea mai importanta este implementarea processRequests in care construiesc vectorul lru de capacitatea data si fac permutari succesive, asigurandu-ma ca cifrele nu se repeta pentru a a crea id-urile corespunzatoare request-urilor

In clasa utility am implementat cele necesare diferitelor tipuri de soratri ale listelor, am implementat functii de comparare dintre doua produse sau doi utilizatori.

In rest pentru toate clasele din Ierarhiile Produs, User, din Server, LRU cache, Shopping Cart  am implementat get-erele si set-erele, cat si operatorii necesari pentru o mai buna manipulare.

Consider ca tema este utila pentru lucrul cu containere si descoperirea  metodelor puse deja la dispozitie de acestea, o gestionare mai rapida a informatiilor si este mai putin de implementat multumita acestora. Dezvolta si lucrul in echipa, pentru ca aveam deja implementat scheletul proiectului, noi a trebuit s aintelegm ce trebuie implementat.

Consider implementarea eficienta pentru ierarhiile produs si user, Lru cache, Shopping Cart.

Pentru bonus, cred ca era mai eficienta o modularizare, sa creem separat interogari pentru starea obiectului din cos, pe care le combinam in final in obtinerea functiei. Au fost cateva metode ajutatoare implementate in Produs si Shopping Cart, dar cred isi mai aveau locul niste interogari separate de tipul exista userul in lista, de cate ori, pe ce pozitie, dar produsul.

Am intampinat dificultati cu precadere la BONUS, am refacut de trei ori algoritmul, probabil ca sunt o gramada de modaliati in care putem testa, mie asa mi s-a parut cel mai usor de inteles.

Nu am intampinat corner cases sau alte lipsuri. La inceput am avut  problema pentru 3.f, ca nu mi-am dat seama ca  in server sunt mai multi useri cu acelasi id, deci e bine sa verificam mai des ocw-ul cand avem proiecte, laboratoare de facut.
