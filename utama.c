#include <stdio.h>
#include "kamus.h"

nom utama() {
    nom nombor_bulat;
    cetak("Sila masukkan sebuah nombor bulat: ");
    imbas("%d", &nombor_bulat);
    
    kalau (nombor_bulat == 3) {
        cetak("%d\n", nombor_bulat);
    } atau kalau (nombor_bulat % 2 == 0) {
        cetak("%d ialah genap!\n", nombor_bulat);
    } atau {
        nom i = 0;
        selagi (i < nombor_bulat) {
            cetak("%d ialah ganjil!\n", nombor_bulat);
            i++;
        }
    }

    untuk (nom j = 0; j < nombor_bulat; j++) {
        cetak("%d\n", j);
    }
    
    pulang 0;
}