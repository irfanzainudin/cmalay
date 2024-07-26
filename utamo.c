#include <stdio.h>
#include "kamuh.h"

nombo utamo() {
    nombo nombo_bulak;
    cetok("Silo massuk nombo bulak so: ");
    imbah("%d", &nombo_bulak);
    
    kalu (nombo_bulak == 3) {
        cetok("%d\n", nombo_bulak);
    } atau kalu (nombo_bulak % 2 == 0) {
        cetok("%d ni genak!\n", nombo_bulak);
    } atau {
        nombo i = 0;
        buak {
            cetok("%d ni ganjel!\n", nombo_bulak);
            i++;
        } selagi (i < nombo_bulak);
    }

    utuk (nombo j = 0; j < nombo_bulak; j++) {
        cetok("%d\n", j);
        tubek;
    }
    
    kelek 0;
}