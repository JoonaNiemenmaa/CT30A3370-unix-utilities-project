# Projekti II: Unix Utilities

Tämä on ensimmäinen projekti jonka valitsin. Kommentteja en lähdekoodiin ole lisännyt, koska en katsonut niille olevan mitään tarvetta.

Projektina oli rakentaa neljä komentoriviltä käytettävää työkälua.

Ensimmäinen ohjelma on my-cat. Se emuloi ’cat’ työkalua, mikä usein löytyy Linux:ista. Alla kuva ohjelman ajosta. Kuvassa ohjelma tulostaa sen lähdekooditiedoston sisällön.

<img width="797" height="894" alt="image" src="https://github.com/user-attachments/assets/d1461e22-88b3-4b60-bb8d-27b4073de692" />


Seuraava ohjelma on my-grep, joka taas on kopio grep:istä. Alla kuva siitä, kun my-grep:illä etsitään ’void’ avainsanaa my-cat:in lähdekoodista.

<img width="616" height="100" alt="image" src="https://github.com/user-attachments/assets/9e97e008-a4fd-43a0-9454-166a980c9e50" />


Viimeisenä vielä my-zip ja my-unzip. Näillä pystyt kompressoimaan ja dekompressoimaan tiedostoja RLE:llä.

Tiedoston kompressointi ja dekompressointi:

<img width="670" height="196" alt="image" src="https://github.com/user-attachments/assets/3a23a976-032a-4bd5-b7e5-45c81c32fd2c" />


## Käyttö

Ohjelmat käännetään gcc:llä seuraavalla komennolla

```console
foo@bar:~$ gcc <lähdekooditiedosto> -o <binääri> -Wall -Werror
```
Ohjelmat ajetaan komentotulkilta kuten mikäkin muu binääritiedosto

```console
foo@bar:~$ ./<binääri>
```

