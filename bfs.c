// BFS = Breadth First Search
// GKD = Gelintaran Kelebaran Dahulu / Gelintar Lebar Dahulu
// Rujuk: https://prpm.dbp.gov.my/Cari1?keyword=breadth+first+search&d=320368&#LIHATSINI

#include <stdio.h>
#include <stdlib.h>
#include "kamus.h"

#define JUMLAH_BUCU 100

// Diambil daripada:
// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/

// Struktur untuk melambangkan suatu nodus dalam senarai/lis kesebelahan (adjacency list)
struktur Nodus
{
    nom data;
    struk Nodus *seterusnya;
};

// Fungsi untuk cipta nodus baru
struk Nodus *cipta_nodus(nom data)
{
    struk Nodus *nodus_baru = (struk Nodus *)peruntuk_memori(saizuntuk(struk Nodus));
    nodus_baru->data = data;
    nodus_baru->seterusnya = NULL;
    return nodus_baru;
}

// Fungsi untuk tambah tepi (edge) kepada graf
kosong tambah_tepi(struk Nodus *lis_kesebelahan[], nom u, nom v)
{
    struk Nodus *nodus_baru = cipta_nodus(v);
    nodus_baru->seterusnya = lis_kesebelahan[u];
    lis_kesebelahan[u] = nodus_baru;
}

// Fungsi untuk jalankan algoritma Gelintaran Kelebaran Dahulu (GKD) (Breadth-First Search)
// ke atas sebuah graf yang dilambangkan lis kesebelahan
kosong gld(struk Nodus *lis_kesebelahan[], nom bucu_bucu,
           nom nodus_mula, nom sudah_dilawat[])
{
    // Cipta suatu baris gilir untuk GKD
    nom bg[JUMLAH_BUCU]; // bg == baris gilir (queue)
    nom kepala = 0, ekor = 0;

    // Tanda nodus terkini sebagai sudah dilawat
    // dan masukkan dalam baris gilir
    sudah_dilawat[nodus_mula] = 1;
    bg[ekor++] = nodus_mula;

    // Susuri baris gilir
    selagi (kepala != ekor)
    {
        // Keluarkan bucu daripada garis gilir dan cetak
        nom nodus_terkini = bg[kepala++];
        cetak("%d ", nodus_terkini);

        // Dapatkan semua bucu bersebelah dengan bucu yang dikeluarkan daripada baris gilir
        // Kalau ada bucu bersebelahan yang belum dilawat,
        // tanda ia sebagai sudah dilawat dan masukkan dalam baris gilir
        struk Nodus *seme = lis_kesebelahan[nodus_terkini]; // seme == sementara (temp)
        selagi (seme != NULL)
        {
            nom jiran = seme->data;
            if (!sudah_dilawat[jiran])
            {
                sudah_dilawat[jiran] = 1;
                bg[ekor++] = jiran;
            }
            seme = seme->seterusnya;
        }
    }
}

// Fungsi untuk bebaskan memori menggunakan algoritma Gelintaran Lebar Dahulu (GLD)
kosong bebaskan_memori_guna_gld(struk Nodus *lis_kesebelahan[], nom bucu_bucu,
           nom nodus_mula, nom sudah_dilawat[])
{
    // Cipta suatu baris gilir untuk GKD
    nom bg[JUMLAH_BUCU]; // bg == baris gilir (queue)
    nom kepala = 0, ekor = 0;

    // Tanda nodus terkini sebagai sudah dilawat
    // dan masukkan dalam baris gilir
    sudah_dilawat[nodus_mula] = 1;
    bg[ekor++] = nodus_mula;

    // Susuri baris gilir
    selagi (kepala != ekor)
    {
        // Keluarkan bucu daripada garis gilir dan cetak
        nom nodus_terkini = bg[kepala++];

        // Dapatkan semua bucu bersebelah dengan bucu yang dikeluarkan daripada baris gilir
        // Kalau ada bucu bersebelahan yang belum dilawat,
        // tanda ia sebagai sudah dilawat dan masukkan dalam baris gilir
        struk Nodus *seme = lis_kesebelahan[nodus_terkini]; // seme == sementara (temp)
        selagi (seme != NULL)
        {
            nom jiran = seme->data;
            struk Nodus* seterusnya = seme->seterusnya;
            if (!sudah_dilawat[jiran])
            {
                sudah_dilawat[jiran] = 1;
                bg[ekor++] = jiran;
            }
            bebas(seme);
            seme = seterusnya;
        }
    }
}

nom utama()
{
    // Jumlah bucu dalam graf
    nom bucu_bucu = 5;

    // Lis kesebelahan sebagai lambang kepada graf
    struk Nodus *lis_kesebelahan[bucu_bucu];
    untuk(nom i = 0; i < bucu_bucu; ++i)
        lis_kesebelahan[i] = NULL;

    // Tambah tepian kepada graf
    /*
    // 0 -- -- 1 -- 3
    //  \       \ 
    //   -- 2    -- 4
    //       \     /
    //        -- --
    */
    // Untuk sesiapa yang tertanya, kenapa senarai/lis kesebelahan
    // - ini nampak seperti graf, kerana ia memang graf. Lis kesebelahan
    // - hanya digunakan sebagai struktur data dasarnya.
    tambah_tepi(lis_kesebelahan, 0, 1);
    tambah_tepi(lis_kesebelahan, 0, 2);
    tambah_tepi(lis_kesebelahan, 1, 3);
    tambah_tepi(lis_kesebelahan, 1, 4);
    tambah_tepi(lis_kesebelahan, 2, 4);

    // Tanda semua bucu sebagai belum dilawat
    nom sudah_dilawat[bucu_bucu];
    untuk(nom i = 0; i < bucu_bucu; ++i)
        sudah_dilawat[i] = 0;

    // Jalankan algoritma Penyusuran Kelebaran Dahulu bermula daripada bucu 0
    cetak(
        "Penyusuran Kelebaran Dahulu bermula daripada bucu 0: ");
    gld(lis_kesebelahan, bucu_bucu, 0, sudah_dilawat);

    // Tanda semua bucu sebagai belum dilawat
    // - untuk digunakan dalam proses pembebasan memori
    untuk(nom i = 0; i < bucu_bucu; ++i)
        sudah_dilawat[i] = 0;

    // Bebaskan semua memori yang diperuntukkan
    // Untuk tidak adakan kebocoran memori
    bebaskan_memori_guna_gld(lis_kesebelahan, bucu_bucu, 0, sudah_dilawat);

    pulang 0;
}