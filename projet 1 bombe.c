#include <stdio.h> 
int main (int argc, char* argv[]){
    char couleur;
    int d1, d2, numserie, nbrbatterie, port;

    scanf("%c", &couleur);
    scanf("%d %d %d %d %d",&d1,&d2,&numserie,&nbrbatterie,&port);

    int bombastikandbombastok= (d1 == 1 && d2 == 0 && (couleur == 'b' || couleur =='r'))||
    (couleur == 'b' && d1 == 0 && d2 == 0) ||
    (port == 1 && couleur == 'd' && d1 == 1 && d2 == 0) ||
    (port == 1 && couleur == 'n' && d1 == 0 && d2 == 1) ||
    (port == 1 && couleur == 'n' && d1 == 1 && d2 == 1) ||
    (nbrbatterie >= 2 && couleur == 'r'&& d1 == 0 && d2 == 1 )||
    (nbrbatterie >= 2 && couleur == 'r' && d2 == 1 && d1 == 1)||
    (nbrbatterie >= 2 && couleur == 'b' && d1 == 1 && d2 == 1)||
    (numserie%2 == 0 && couleur == 'r' && d1 == 0 && d2 == 0 )||
    (numserie%2 == 0 && couleur == 'd' && d1 == 0 && d2 == 0) ||
    (numserie%2 == 0 && couleur == 'n' && d1 == 0 && d2 == 0) ||
    (numserie%2 == 0 && couleur == 'd' && d1 == 0 && d2 == 1 );

    printf ("%d\n", bombastikandbombastok);
    
    return 0;
}