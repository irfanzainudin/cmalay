# Converts C syntax into Cmalay
'''C
Example:

=== BEFORE CONVERSION ===                                   |   === AFTER CONVERSION ===
                                                            |
#include <stdio.h>                                          |   #include <stdio.h>
#include "kamus.h"                                          |   #include "kamus.h"
                                                            |
int main() {                                                |   nom utama() {
  int nombor_bulat;                                         |       nom nombor_bulat;
  printf("Sila masukkan sebuah nombor bulat: ");            |       cetak("Sila masukkan sebuah nombor bulat: ");
  scanf("%d", &nombor_bulat);                               |       imbas("%d", &nombor_bulat);
                                                            |
  if (nombor_bulat == 3) {                                  |       kalau (nombor_bulat == 3) {
        printf("%d\n", nombor_bulat);                       |           cetak("%d\n", nombor_bulat);
    } else if (nombor_bulat % 2 == 0) {                     |       } atau kalau (nombor_bulat % 2 == 0) {
        printf("%d ialah genap!\n", nombor_bulat);          |           cetak("%d ialah genap!\n", nombor_bulat);
    } else {                                                |       } atau {
        int i = 0;                                          |           nom i = 0;
        while (i < nombor_bulat) {                          |           selagi (i < nombor_bulat) {
            printf("%d ialah ganjil!\n", nombor_bulat);     |               cetak("%d ialah ganjil!\n", nombor_bulat);
            i++;                                            |               i++;
        }                                                   |           }
    }                                                       |       }
                                                            |
    for (int j = 0; j < nombor_bulat; j++) {                |       untuk (nom j = 0; j < nombor_bulat; j++) {
        printf("%d\n", j);                                  |           cetak("%d\n", j);
    }                                                       |       }
                                                            |
    return 0;                                               |       pulang 0;
}                                                           |   }
'''

import sys
from tokenize import tokenize, untokenize

# // PRIMITIVE DATA TYPES
#define huruf char
#define aksara char         // synonym / sinonim
#define dua double
#define pecahan float
#define nombor int
#define nom int             // abbreviation / singkatan
#define panjang long
#define pjg long            // abbreviation / singkatan
#define pendek short
# // KEYWORDS
# // auto
#define keluar break
#define kes case
#define tetap const
#define malar const         // synonym / sinonim
#define langkau continue
#define lalai default
#define buat do
#define atau else
#define bancian enum
#define banci enum          // abbreviation / singkatan
#define pengangkaan         // synonym / sinonim
#define angka enum          // abbreviation / singkatan
#define perhitungan enum    // synonym / sinonim
#define hitung enum         // abbreviation / singkatan
# // extern
#define untuk for
#define gerak goto
#define pergi goto          // synonym / sinonim
#define kalau if
# // register
#define pulang return
# // signed
#define saizuntuk sizeof
#define statik static
#define kaku static         // synonym / sinonim
#define struktur struct
#define struk struct        // abbreviation / singkatan
#define tukar switch
# // typedef
# // union
# // unsigned
#define kosong void
# // volatile
#define selagi while
# // FUNCTIONS
#define utama main
#define cetak printf
#define imbas scanf
#define peruntuk_memori malloc
#define utkm malloc         // abbreviation / singkatan

swap = {
    'nombor': 'int',
    'pulang': 'return',
    'selagi': 'while',
    'utama': 'main',
    'untuk': 'for',
    'kalau': 'if',
    'atau': 'else',
    'cetak': 'printf',
    'imbas': 'scanf',
    'peruntuk_memori': 'malloc'
}

if len(sys.argv) != 2:
    print(f"USAGE: {sys.argv[1]} <C FILE>")
    exit(1)

filename = sys.argv[1] # error checking
with open(filename, 'rb') as src:
    tokens = []
    for token in tokenize(src.read):
        if token.type == 1 and token.string in swap:
            tokens.append((token.type, swap[token.string]))
        else:
            tokens.append((token.type, token.string))

# rebuild code from our "modified" tokens
code = untokenize(tokens).decode('utf-8')
with open(filename.split('.')[0] + ".malay.c", 'w') as dest:
    dest.write(code)
# print(code)
# exec(code)