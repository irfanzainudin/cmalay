# cmalay

I wanted to code in Malay but too busy (read: lazy) to write up my own compiler so I used C instead :)

## Getting started

If you want to use cmalay as well, all you have to do is copy [`kamus.h`](https://github.com/irfanzainudin/cmalay/blob/main/kamus.h) into your local directory/folder then `#include` it into your C file.

For example, let's say you have a folder called `projek`. Inside that folder, you have `utama.c`. Copy `kamus.h` into your `projek` folder and in your `utama.c`, you need to have this line of code:

```c
#include "kamus.h"
```

And voila! You can immediately start using cmalay.

## Code example

Compulsory introduction program:

```c
#include <stdio.h>

nom utama() {
    cetak("Salam, dunia!");

    pulang 0;
}
```

From [utama.c](https://github.com/irfanzainudin/cmalay/blob/main/utama.c):

```c
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
```