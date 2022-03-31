#include <stdio.h>

int main(int argc, char* argv[]) {

    int a, b, c, d, e, f; /* joueurs */ 
    int v1, v2, v3, v4, v5, v6; /* valeurs à mettre dans l'ordre */ 

    
    scanf("%d %d %d %d %d %d", & v1, & v2, & v3, & v4, &v5, & v6);
   
   /* joueur 1 */ 
    
  if ( (v1 <= v2 && v1 <=v3) && (v2 <= v3) ){
        a = v1;
        b = v2;
        c = v3;
    }
    else if ((v1 <= v2 && v1 <= v3) && (v3 <= v2)) {
        a = v1;
        b = v3;
        c = v2;
    }
    else if ((v2 <= v1 && v2<= v3) && (v1 <= v3)) {
        a = v2;
        b = v1;
        c = v3;
    }
    else if ((v2 <= v1 && v2<= v3) && (v3 <= v1)) {
        a = v2;
        b = v3;
        c = v1;
    }
    else if ((v3 <= v1 && v3 <= v2) && (v1 <= v2)) {
        a = v3;
        b = v1;
        c = v2;
    }
    else if ((v3 <= v1 && v3 <= v2) && (v2 <= v1)) {
        a = v3;
        b = v2;
        c = v1; 
    }

    // Joueur 2

   if ( (v4 <= v5 && v4 <=v6) && (v5 <= v6) ){
        d =  v4;
        e = v5;
        f = v6;
    }
    else if ((v4 <= v5 && v4 <= v6) && (v6 <= v5)) {
        d = v4;
        e = v6;
        f = v5;
    }
    else if ((v5 <= v4 && v5<= v6) && (v4 <= v6)) {
        d = v5;
        e = v4;
        f = v6;
    }
    else if ((v5 <= v4 && v5<= v6) && (v6 <= v4)) {
        d = v5;
        e = v6;
        f = v4;
    }
    else if ((v6 <= v4 && v6 <= v5) && (v4 <= v5)) {
        d = v6;
        e = v4;
        f = v5;
    }
    else if ((v6 <= v4 && v6 <= v5) && (v5 <= v4)) {
        d = v6;
        e = v5;
        f = v4;
    }
    
    if ((a == d) && (b == e) && (c == f)) {
        printf("Draw\n");

    }
    else {
    /* Le 421 */
            if ((a == 1 && b == 2 && c ==4) &&  !(d == 1 && e == 2 && f == 4)){
            printf("Player1 wins\n");
            }
            else if ((d == 1 && e == 2 && f == 4) && !(a == 1 && b == 2 && c ==4)){
            printf("Player2 wins\n");}

                /*jcrois y'a un problème donc changer et enlever les ! si bug */ 

    /* Le triplet */
        else if ((a == b && b == c) && !(d == e && e == f)){
            printf( "Player1 wins\n");
        }
        else if ((d == e && e == f) && !(a == b && b == c)){
            printf("Player2 wins\n");
        }

    /* La fiche */
        else if (((a == 1) && (b == 1) && ( c!= 1)) && !((d == 1) && (e == 1) && (f!= 1))){
            printf("Player1 wins\n");
        }
        else if (((d == 1) && (e == 1) && ( f!= 1)) && !((a == 1) && (b == 1) && (c!= 1))){
            printf("Player2 wins\n");
        }

    /* La suite */ 
        else if (((b==a+1) && (c==b+1)) && !((e==d+1 && f==e+1))){
            printf("Player1 wins\n");}
           
        else if ((e==d+1 && f==e+1) && !(b==a+1 && c==b+1)){
            printf("Player2 wins\n");}
        

    /* Sont toutes les deux des fiches */ 
        else if (((a == 1) && (b == 1) && ( c!= 1)) && ((d == 1) && (e == 1) && (f!= 1)) && ( c > f )) {
            printf("Player1 wins\n");
        }
        else if (((d == 1) && (e == 1) && ( f!= 1)) && !((a == 1) && (b == 1) && (c!= 1)) && ( f > c )) {
                printf("Player2 wins\n");
        }
        
        

    /* Sont toutes les deux des triplets */
        else if ((( a== b && b == c ) && ( d == e && e == f)) && ( a > d )){
            printf("Player1 wins\n");
        }
        else if ((( a== b && b == c ) && ( d == e && e == f)) && ( d > a )){
            printf("Player2 wins\n");
        }

    /* aucune combinaison meilleur */ /* à améliorer ici */ 
        else if (( a > d ) || ( b > e) || ( c >= f)){
            printf("Player1 wins\n");
        }
        else if (( d > a ) || ( e > b) || ( f >= c)){
            printf("Player2 wins\n");
        }
        else if (( a == d ) && ( b == e ) && ( c == f )){
            printf("Draw\n");
        }
    }
    return 0;
}