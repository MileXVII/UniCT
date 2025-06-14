#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int conta_vocali(const char *s) {
    int count = 0;

    while (*s) {
        char c = tolower(*s); 
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++; 
        }
        s++; 
    }

    return count; 
}

typedef union {
    unsigned short z;
    char y;
} UNI;

typedef struct {
    double a;
    char b;
    char *s;
    char *w;
} Record;

typedef enum {
    VOWELS,
    THREE
} ENU;

typedef struct {
    int ID;
    Record s1;
    ENU flag;
    UNI Flag_data;
} Data;

int function(Record *p) {   
    srand(time(NULL));

    Record *rec = (Record *) malloc(sizeof(Record));
    if (rec == NULL) {
        printf("Errore di allocazione della memoria!\n");
        return 1;
    }

    p->a = 1 + (rand() / (double)RAND_MAX) * 99;

    printf("\ndouble: %f\n", p->a);
    p->b = 'a' + rand() % 26;
    printf("\nchar: %c\n", p->b);

    p->s = (char*)malloc(11 * sizeof(char));
    p->w = (char*)malloc(11 * sizeof(char));
    for(int i = 0; i < 10; i++) {
        p->s[i] = 'a' + rand() % 26;
        p->w[i] = 'a' + rand() % 26;
    }

    for(int i = 0; i< 10; i++) {
        printf("%c", p->s[i]);
    }

    printf("\n");
        
    for(int i = 0; i< 10; i++) {
        printf("%c", p->w[i]);
    }

    free(rec);

    return 0;
}

void function_data(Data A[]) {
    srand(time(NULL));

    int k = 1 + rand() % 10;
    int n;
    for(int i = 0; i < k; i++) {   
        do {
            A[i].ID = rand() % 100000;
            for(int j = 0; j < i; j++) {
                n = 0;
                if(A[i].ID == A[j].ID) {
                    n = 1;
                }
            }
        } while(n == 1);
        printf("\n%d", A[i].ID);
    }
    if(k < 10) {
        A[k].ID = -1;
    }
}

void function_data2(Data A[]) {   
    int vocali = 0;
    int divisible3 = 0;
    int N = 10;

    for (int i = 0; i < N; i++) {
        A[i].s1.s = (char*)malloc(N * sizeof(char));
        A[i].s1.w = (char*)malloc(N * sizeof(char));
        for (int j = 0; j < N - 1; j++) {
            A[i].s1.s[j] = 'a' + rand() % 26;
            A[i].s1.w[j] = 'a' + rand() % 26;
        }
        A[i].s1.s[N - 1] = '\0';
        A[i].s1.w[N - 1] = '\0';
    }

    for (int i = 0; i < N; i++) {
        vocali = conta_vocali(A[i].s1.s);
        divisible3 = 0;

        for (int j = 0; j < N - 1; j++) {
            if ((A[i].s1.w[j] - 'a') % 3 == 0) {
                divisible3++;
            }
        }

        if (vocali < divisible3) {
            A[i].flag = VOWELS;
        } else {
            A[i].flag = THREE;
        }
    }

    for (int i = 0; i < N; i++) {
        free(A[i].s1.s);
        free(A[i].s1.w);
    }
}

void function_data3(Data A[]) {
    int N = 10;
    for(int i = 0; i < N; i++) {
        int num = -1, num1 = -1;

        for(int j = 0; j < 10; j++) {
            if (A[i].s1.s[j] == 'a' || A[i].s1.s[j] == 'e' || A[i].s1.s[j] == 'i' || A[i].s1.s[j] == 'o' || A[i].s1.s[j] == 'u') {
                num = j;
                break;
            }
        }

        for(int d = 0; d < 10; d++) {
            if ((A[i].s1.w[d] - 'a') % 3 == 0) {
                num1 = d;
                break;
            }
        }

        if (A[i].flag == VOWELS && num != -1) {
            A[i].Flag_data.y = A[i].s1.s[num];
        } else if (num1 != -1) {
            A[i].Flag_data.z = A[i].s1.w[num1];
        }
    }
}

int main() {
    Record *p = (Record *)malloc(sizeof(Record));

    function(p);

    int N = 10;
    Data A[N];

    function_data(A);

    free(p);

    function_data2(A);

    function_data3(A);

}
