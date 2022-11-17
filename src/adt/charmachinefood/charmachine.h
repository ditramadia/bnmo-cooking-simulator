/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../boolean/boolean.h"
#include "../../../config/config.h"

// #define MARK '.'
/* State Mesin */
extern char currentChar;
extern boolean EoP;

static int retval;

void STARTFOOD();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EoP akan padam (false)
          Jika currentChar = MARK maka EoP akan menyala (true) */

void ADVFOOD();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EoP akan menyala (true) */

#endif