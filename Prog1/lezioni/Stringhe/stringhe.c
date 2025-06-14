#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
int main()
{

        

        /* ALLOCAZIONE */
        printf("\n\t\t---ALLOCAZIONE---\t\t\n");

        char s[] = "my_string";  //char s = "my string";  non funziona   
        
        printf("\n%s", s);

        s[0] = 'c' ; // funziona modifica il contenuto
        
        printf("\n%s\n", s);



        char *ps1 = "my_string"; 

        printf("\n%s", ps1);     //ps1[3] = 'k'; //da errore non puoi modificare il contenuto

        ps1 = "I Love Saro Messina";  // Valido, cambia l'indirizzo a cui punta ps1

        printf("\n%s\n", ps1);



        const char *ps2 = "my_string"; 

        printf("\n%s", ps2);   //ps2[3] = 'k'; //da errore non puoi modificare il contenuto

        ps2 = "I Love Saro Messina";  // Valido, cambia l'indirizzo a cui punta ps2

        printf("\n%s\n", ps2);   //ps2[3] = 'k'; //da errore non puoi modificare il contenuto

         /* RANDOM */
        printf("\n\t\t---RANDOM---\t\t\n");

        srand(time(NULL));

        char random[100];
        printf("\narray random: \n");
        for(int i = 0; i<100; i++)
        {
                random[i] = rand() % 26 + 'a';
                printf(" %c", random[i]);
        }



        /* SCRITTURA */
        printf("\n\t\t---SCRITTURA---\t\t\n");

        char name[15];

        strcpy(name , "pippo");

        printf("\n%s", name);

        size_t n = 5; //size_t = unsigned int 

        name[n];

        strncpy(name , "pippo" , n); //copia i primi n caratteri (contatore di lunghezza)

        printf("\n%s", name); 

        strncpy(name , "pippopazzo" , n); //restituisce pippo

        printf("\n%s\n", name); 


        /* COMPARAZIONE */
        printf("\n\t\t---COMPARAZIONE---\t\t\n");

        char s1[] = "pippo";
        char s2[] = "paperino";

       //  if(s1 == s2) errore

       int b = strcmp(s1 , s2);

       //restituisce <0 se s1 lessicograficamente minore di s2
       //restituisce >0 se s1 lessicograficamente maggiore di s
       //restituisce 0 se s1 uguale a s2

       printf("\n%d", b);

       b = strncmp(s1 , s2 , n); //limita il confronto ai primi n caratteri

       printf("\n%d\n", b); 

        /* RICERCA SOTTOSTRINGA */
        printf("\n\t\t---RICERCA SOTTOSTRINGA---\t\t\n");

         const char *str = "Cerca questa sottostringa";
         const char *sub = "questa";
    
         char *result = strstr(str, sub); //restituisce NULL se non trova la stringa //restituisce str se sub è vuota
    
                if (result != NULL) {
                        printf("\nSottostringa trovata: %s\n", result);
                } else {
                        printf("\nSottostringa non trovata.\n");
                }


        
        char cs[] = "CesareGiulio";
        char *found = strstr(cs , "are");    

                if (found != NULL) {
                
                printf("\n%s\n", found);
                } else {

                printf("\nSottostringa non trovata.\n");
                }


        /* CONVERSIONI --->  #include <stdlib.h> */ 
        printf("\n\t\t---ESTRAPOLAZIONE NUMERI---\t\t\n");

        const char *cnv = "22aabb"; // La stringa da convertire
        int tst;
        long l;
        long long ll;
        double tstdbl;

        // Conversione a int
        tst = atoi(cnv); // converte in int
        printf("\nValore int: %d", tst);
                                                        //tutti e 3 restituiscono la conversione dei PRIMI caratteri della stringa
        // Conversione a long                           //restituiscono '0' se la stringa non inizia con un numero
        l = atol(cnv); // converte in long                  
        printf("\nValore long: %ld", l);

        // Conversione a long long
        ll = atoll(cnv); // converte in long long
        printf("\nValore long long: %lld", ll);

        //conversione a double
        tstdbl = atof(cnv); // converte in double
        printf("\nValore double: %f\n", tstdbl);    


        printf("\n\t\t---CONVERSIONI---\t\t\n");          


        const char *str1 = "12345abc";
        char *end;
        long val = strtol(str1, &end, 10); //in base 10 //tipo di ritorno long
        printf("\nValore convertito: %ld", val);  // 12345
        printf("\nParte non convertita: %s", end); // "abc"

        const char *str2 = "3.14159abc";
        char *end1;
        double val1 = strtod(str2, &end1); //tipo di ritorno double
        printf("\nValore convertito: %f", val1);  // 3.141590
        printf("\nParte non convertita: %s", end1); // "abc"

        const char *str3 = "2.71828xyz";
        char *end2;
        float val2 = strtof(str3, &end2); // tipo di ritorno float
        printf("\nValore convertito: %f", val2);  // 2.718280
        printf("\nParte non convertita: %s", end2); // "xyz"

        const char *str4 = "1.2345678901234567e10xyz";
        char *end3;
        long double val3 = strtold(str4, &end3); //tipo di ritorno long double
        printf("\nValore convertito: %Lf", val3);  // 12345678901.234568
        printf("\nParte non convertita: %s\n", end3); // "xyz"

        /* SSCANF */ 
        printf("\n\t\t---sscanf---\t\t\n");

        //funziona come scanf ma invece di leggere da input di tastiera legge da una stringa passata in input

        char str5[] = "123 45.67 Ciao"; //stringa da cui leggere
        int i; 
        float f; //variabili da riempire
        char word[20]; 
        
        // Usando sscanf per estrarre valori dalla stringa
        int h = sscanf(str5, "%d %f %s", &i, &f, word); //I valori letti vengono memorizzati nelle variabili i, f, e word
        
        if (h == 3) {
                printf("\nIntero: %d\n", i);
                printf("\nVirgola mobile: %.2f\n", f);
                printf("\nStringa: %s\n", word);
        } else {
                printf("\nErrore nella lettura dei dati.\n");
        }

        int x;
        const char *str6 = "1234";
        sscanf(str6, "%d", &x); //lettura di un intero

        printf(" \nint: %d", x);

        sscanf(str6, "%2d", &x); //lettura di un intero //stampa12

        printf("\nint : %d", x); 

        float y;
        const char *str7 = "1234.56789";
        sscanf(str7, "%f", &y); //lettura di un float

        printf(" \nfloat: %lf", y);

        /* SPRINTF */ 
        printf("\n\t\t---sprintf---\t\t\n");

        int num1 = 42;
        float num2 = 3.14159;
        char str8[100];
    
        // Usando sprintf per formattare una stringa
        int num3 = sprintf(str8, "\nIl numero intero è: %d e il numero decimale è: %.2f", num1, num2); //I valori letti vengono memorizzati nelle variabili i, f,
                                                                                                       //in caso di errore restituisce valore negativo
        // Visualizzare la stringa formattata
        printf("\nStringa formattata: %s", str8);
        printf("\nNumero di caratteri scritti: %d\n", num3);


         /* is(function)--->#include <ctype.h> */ 
        printf("\n\t\t---is(function)---\t\t\n");

        char c;
        // Esempio di input da parte dell'utente
        printf("\nInserisci un carattere: \n");
        printf(" \n");
        c = getchar(); // Legge un singolo carattere

        // Verifica se il carattere è una lettera alfabetica
        if (isalpha(c)) {
                printf("\n'%c' è una lettera dell'alfabeto.\n", c);
        } else {
                printf("\n'%c' non è una lettera dell'alfabeto.\n", c);
        }

        // Verifica se il carattere è un numero (digit)
        if (isdigit(c)) {
                printf("'%c' è una cifra numerica.\n", c);
        } else {
                printf("'%c' non è una cifra numerica.\n", c);
        }

        // Verifica se il carattere è un carattere esadecimale valido
        if (isxdigit(c)) {
                printf("'%c' è un carattere esadecimale valido.\n", c);
        } else {
                printf("'%c' non è un carattere esadecimale valido.\n", c);
        }

        // Verifica se il carattere è stampabile
        if (isprint(c)) {
                printf("'%c' è un carattere stampabile.\n", c);
        } else {
                printf("'%c' non è un carattere stampabile.\n", c);
        }

        // Verifica se il carattere è un segno di punteggiatura
        if (ispunct(c)) {
                printf("'%c' è un carattere di punteggiatura.\n", c);
        } else {
                printf("'%c' non è un carattere di punteggiatura.\n", c);
        }

        // Verifica se il carattere è una lettera minuscola
        if (islower(c)) {
                printf("'%c' è una lettera minuscola.\n", c);
        } else {
                printf("'%c' non è una lettera minuscola.\n", c);
        }

        // Verifica se il carattere è una lettera maiuscola
        if (isupper(c)) {
                printf("'%c' è una lettera maiuscola.\n", c);
        } else {
                printf("'%c' non è una lettera maiuscola.\n", c);
        }

        // Verifica se il carattere è uno spazio bianco
        if (isspace(c)) {
                printf("'%c' è uno spazio bianco.\n", c);
        } else {
                printf("'%c' non è uno spazio bianco.\n", c);
        }

        
         // Trasforma il carattere in maiuscolo
        char upper = toupper(c);
        printf("\nIl carattere '%c' trasformato in maiuscolo è: '%c'\n", c, upper);

        // Trasforma il carattere in minuscolo
        char lower = tolower(c);
        printf("\nIl carattere '%c' trasformato in minuscolo è: '%c'\n", c, lower);



        printf(" \n ");


        
} 