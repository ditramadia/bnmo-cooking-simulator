#include <stdio.h>
#include "time.h"

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsTIMEValid (int H, int M)
/* Mengirim true jika H,M,S dapat membentuk T yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return (((H >= 00) && (H <= 23)) && ((M >= 00) && (M <= 59)));
}

/* *** Konstruktor: Membentuk sebuah TIME dari komponen-komponennya *** */
void CreateTime (TIME * T, int DD, int HH, int MM)
/* Membentuk sebuah TIME dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
{
    DAY(*T) = DD;
    HOUR(*T) = HH;
    MINUTE(*T) = MM;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaTIME (TIME * T)
/* I.S. : T tidak terdefinisi */
/* F.S. : T terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk T */
/* yang valid. Tidak mungkin menghasilkan T yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika TIME tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh: 
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk TIME <1,3,4> */
{
    int D, H, M;
    scanf("%d %d %d", &D, &H, &M);

    while (!IsTIMEValid(H, M))
    {
        printf("Jam Tidak Valid\n");
        scanf("%d %d %d", &D, &H, &M);
    }
    
}

void TulisTIME (TIME T)
/* I.S. : T sembarang */
/* F.S. : Nilai T ditulis dg format DD:HH:MM */
/* Proses : menulis nilai setiap komponen T ke layar dalam format DD:HH:MM
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/ 
{
    printf("%d:%d:%d", DAY(T), HOUR(T), MINUTE(T));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long TIMEToDetik (TIME T)
/* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return ((3600*Hour(T)) + (60*Minute(T)) + (Second(T)));
}

TIME DetikToTIME (long N)
/* Mengirim  konversi detik ke TIME */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang 
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus: 
   N1 = N mod 86400, baru N1 dikonversi menjadi TIME */
{
    TIME T;
    N %= 86400;
    if (N < 0)
    {
        N+= 86400;
    }

    int H = N / 3600;
    N -= H*3600;

    int M = N / 60;
    N -= M*60;

    int S = N;

    CreateTime(&T, H, M, S);
    return T;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean TEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1=T2, false jika tidak */
{
    return ((DAY(T1) == DAY(T2)) && (HOUR(T1) == HOUR(T2)) && (MINUTE(T1) == MINUTE(T2)));
}

boolean TNEQ (TIME T1, TIME T2)
/* Mengirimkan true jika T1 tidak sama dengan T2 */
{
    return !TEQ(T1, T2);
}

boolean TLT (TIME T1, TIME T2)
/* Mengirimkan true jika T1<T2, false jika tidak */
{
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT (TIME T1, TIME T2)
/* Mengirimkan true jika T1>T2, false jika tidak */
{
    return !TLT && TNEQ;
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik (TIME T)
/* Mengirim 1 detik setelah T dalam bentuk TIME */
{
    long second = TIMEToDetik(T);
    second++;
    return DetikToTIME(second);
}

TIME NextNDetik (TIME T, int N)
/* Mengirim N detik setelah T dalam bentuk TIME */
{
    long second = TIMEToDetik(T);
    second += N;
    return DetikToTIME(second);
}

TIME PrevDetik (TIME T)
/* Mengirim 1 detik sebelum T dalam bentuk TIME */
{
    long second = TIMEToDetik(T);
    second--;
    return DetikToTIME(second);
}

TIME PrevNDetik (TIME T, int N)
/* Mengirim N detik sebelum T dalam bentuk TIME */
{
    long second = TIMEToDetik(T);
    second -= N;
    return DetikToTIME(second);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (TIME TAw, TIME TAkh)
/* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
/* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
{
    long beda = TIMEToDetik(TAw) - TIMEToDetik(TAkh);
    if (TGT(TAw, TAkh))
    {
        beda += 86400;
    }
    return beda;
}