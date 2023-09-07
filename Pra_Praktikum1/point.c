#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include  <math.h>

void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P){
    float x;
    float y;
    scanf("%f %f", &x, &y);
    CreatePoint(P,x ,y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)",Absis(P), Ordinat(P));
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

    if(Absis(P) > 0){
        if(Ordinat(P)>0){
            return 1;
        }
        else if(Ordinat(P) < 0){
            return 4;
        }
    }
    else if (Absis(P) < 0){
        if(Ordinat(P) > 0){
            return 2;
        }
        else if (Ordinat(P) < 0){
            return 3;
        }
    }
}
    
POINT NextX(POINT P){
    Absis(P) += 1;
    return P;
}

POINT NextY(POINT P){
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    POINT delta_point;
    CreatePoint(&delta_point, Absis(P) + deltaX, Ordinat(P) + deltaY);
    return delta_point;
}

POINT MirrorOf (POINT P, boolean SbX){
    POINT mirror_point;
    if(SbX){
        CreatePoint(&mirror_point,Absis(P),Ordinat(P) * (-1));
    }
    else{
        CreatePoint(&mirror_point,Absis(P) * (-1) ,Ordinat(P));
    }
    return mirror_point;
}

float Jarak0 (POINT P){
     return sqrt(pow(Absis(P),2) + pow(Ordinat(P),2));
}

float Panjang (POINT P1, POINT P2){
    return sqrt(pow(Absis(P1) - Absis(P2),2) + pow(Ordinat(P1) - Ordinat(P2),2));
}


void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P){
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
    if(SbX){
        Ordinat(*P) = Ordinat(*P) * -1;
    }
    else{
        Absis(*P) = Absis(*P) * -1;
    }
}

void Putar (POINT *P, float Sudut){
    float current_x = P -> X;
    float current_y = P -> Y;
    float radian_angle = -1 * Sudut * (M_PI / 180);
    float new_X = ((cos(radian_angle) * current_x)-(sin(radian_angle) * current_y));
    float new_Y = ((sin(radian_angle) * current_x)+(cos(radian_angle)* current_y));
    Absis(*P) = new_X;
    Ordinat(*P) = new_Y;
    
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    if(Absis(P2)-Absis(P1)!=0){
        int a;
        int b;
        a = (Ordinat(P2)-Ordinat(P1))/(Absis(P2)-Absis(P1));
        /*y = ax + b, b = -a * (X1)+Y1 */
        b = Ordinat(P1) -(a * Absis(P1)) ;

        printf("(%d,%d)",a,b); 
    }       
   
}
