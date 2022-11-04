#include "point.h"
#include <stdio.h>
#include <math.h>
#include "boolean.h"

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P) {
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2))); 
}

boolean NEQ (POINT P1, POINT P2){
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2))); 
}

boolean IsOrigin (POINT P){
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P){
    if((Absis(P) > 0) && (Ordinat(P) > 0)){
        return 1;
    }
    else if((Absis(P) < 0) && (Ordinat(P) > 0)){
        return 2;
    }
    else if((Absis(P) < 0) && (Ordinat(P) < 0)){
        return 3;
    }
    else if((Absis(P) > 0) && (Ordinat(P) < 0)){
        return 4;
    }  
}  

POINT NextX (POINT P){
    CreatePoint (&P, Absis(P) +1, Ordinat(P));
    return P;
}

POINT NextY (POINT P){
    CreatePoint (&P, Absis(P), Ordinat(P) +1);
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    CreatePoint (&P, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if(SbX){
        CreatePoint (&P, Absis(P), -Ordinat(P));
        return P;
    }
    else{
        CreatePoint (&P, -Absis(P), Ordinat(P));
        return P;
    }
}

float Jarak0 (POINT P){
    return sqrt((Absis(P)*Absis(P)) + (Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2){
    return sqrt(((Absis(P1) - Absis(P2))*(Absis(P1) - Absis(P2))) + ((Ordinat(P1) - Ordinat(P2)))*((Ordinat(P1) - Ordinat(P2))));
}

void Geser (POINT *P, float deltaX, float deltaY){
    CreatePoint (P, Absis(*P) + deltaX, Ordinat(*P) + deltaY);
}

void GeserKeSbX (POINT *P){
    CreatePoint (P, Absis(*P), 0);
}

void GeserKeSbY (POINT *P){
    CreatePoint (P, 0, Ordinat(*P));
}

void Mirror (POINT *P, boolean SbX){
    if(SbX && Ordinat(*P) != 0){
        CreatePoint (P, Absis(*P), -Ordinat(*P));
    }
    else if (!SbX && Ordinat(*P) != 0){
        CreatePoint (P, -Absis(*P), Ordinat(*P));
    }
}

void Putar (POINT *P, float Sudut){
    float X, Y, radian;
    radian = 3.14159265358979323846*Sudut / 180;
    X = cos(radian)*Absis(*P) + sin(radian)*Ordinat(*P);
    Y = -sin(radian)*Absis(*P) + cos(radian)*Ordinat(*P);
    CreatePoint (P, X, Y);
}