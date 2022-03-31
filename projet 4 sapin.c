#include <stdio.h>
#include <stdlib.h>


void SapinDroite (){
    //Sapin Droit
    int N = -1;
    int i, j;
    printf("Hauteur ?\n");
    scanf(" %d", &N);

    while (N <= 0){
        printf("Erreur de saisie. Hauteur ?\n");
        scanf("%d", &N);
        } 
    for (i = 0; i < N; i++){
        for (j = 0; j < i; j++){
        printf("*");
        }
    printf("*\n");
    }
    printf("\n");
    printf("Autre choix ?\n");
    
    }



void SapinGauche (){
    //Sapin Gauche 
    int N = -1;
    int i,j,c;

    printf("Hauteur ?\n");
    scanf("%d", &N);

    while (N <= 0){
        printf("Erreur de saisie. Hauteur ?\n");
        scanf("%d", &N);
        } 
    for (i = 0; i < N; ++i){
        for (c = N-(i+1); c > 0; c--){
         printf(" ");
        }
        for (j = 0; j < i; ++j){
          printf("*");
        }
      printf("*\n");
    }
    printf("\n");
    printf("Autre choix ?\n");
    }
    

void SapinComplet (){
    //Sapin Complet
    int N;
    int i, v, j ;
    printf("Hauteur ?\n");
    scanf("%d",&N);

    while (N <= 0){
        printf("Erreur de saisie. Hauteur ?\n");
        scanf("%d", &N);
        }
    for(i = 0; i < N; i++){
        for(v = ( N-i ) -1 ; v > 0 ;v--)
            {
                printf(" ");
            }

        for(j = ( 2*i ) +1 ; j > 0 ;j--)
        {
            printf("*");
        }

        printf("\n");
        }

        for (i = 0; i <N-1; i++){
            printf(" ");
        }    
        printf("*\n");
        printf("\n");
        printf("Autre choix ?\n");
        }
        


void Carre (){
    // Carré 
    int N;
    int i, j;
    printf("Cote ?\n");
    scanf("%d",&N);

    while (N < 0){
        printf("Erreur de saisie. Cote ?\n");
        scanf("%d", &N);
        }
    for (i = 1; i <= N  ; i++){
        for(j = 1; j <= N; j++){
            if (i == 1 || j == 1 || i == N  || j == N)
            printf("*");
            else
            printf(" ");
        }
        printf("\n");
        
    }
    printf("\n");
    printf("Autre choix ?\n");
    }



void Losange (){
    //Losange 
    int N;
    int i, j;
    
    printf("Cote ?\n");
    scanf("%d", &N);

    while (N <= 0){
        printf("Erreur de saisie. Cote ?\n");
        scanf("%d", &N);
        }
    for ( i = 0; i < N; i++){
        for (j = i+1; j < N; j++){
            printf(" ");
        }
        printf("/");
        for (j = 1 ; j < 1+2*i; j++){
            printf(" ");
        }
        printf("\\\n");
        }
        
        
    for (i = 0; i < N; i++){
        for (j = 0; j < i; j++){
        printf(" ");
        }
        printf("\\");
    for (j = 1; j < 2*N - 2*i -1; j++){
        printf(" ");
    }
        printf("/\n");}
        printf("\n");
    printf("Autre choix ?\n");
    }
     



void Cinq (){
    //Cinq
    int i, j;
    int N;
    printf("Taille ?\n");
    scanf("%d", &N);

    while (N < 3){
        printf("Erreur de saisie. Taille ?\n");
        scanf("%d", &N);
        }
    for (i = 1 ; i < N ; i++){
        printf("*");
    }
    printf("*\n");

    for (i = (N-2); i > 0; i--){
        printf("*\n");
    }
    for (i = 1; i < N ; i++){
        printf("*");
    }
    printf("*\n");


    for (i = (N-2); i > 0; i--){
        for (j = 1; j < N; j++){
        printf(" ");}
    printf("*\n");}
    
    

    for (i = 0; i < N; i++){
       printf("*");
    }
    printf("\n");
    printf("\n");  
    printf("Autre choix ?\n");
    }
    
   
    


void Instructions (){
    //Instuctions
    printf("Instructions:\n"  
    "   Afficher sapin droite (a)\n"  
    "   Afficher sapin gauche (b)\n"  
    "   Afficher sapin complet (c)\n"  
    "   Afficher carre (d)\n"  
    "   Afficher losange (e)\n"  
    "   Afficher cinq (f)\n"  
    "   Afficher instructions (h)\n"  
    "   Quitter (q)\n\n");
    printf("Votre choix ?\n");
    }


void Quitter(){
    return;
}


int main (){

    Instructions();
    
    char choix;
    while ( choix != 'q'){
        scanf(" %c" , & choix);

    

    if (  choix == 'a' ){
        // SapinDroite
        SapinDroite();

    }


    else if (  choix == 'b' ){
        //SapinGauche
        SapinGauche();

    }


    else if (  choix == 'c' ){
        //Sapin complet
        SapinComplet();


    }


    else if (  choix == 'd' ){
        //Carre
        Carre();

    }


    else if (  choix == 'e' ){
        //Losange
        Losange();

    } 


    else if (  choix == 'f' ){
        //Cinq
        Cinq();

    }


    else if (  choix == 'h' ){
        //instructions
        Instructions();
    }

    else if ( choix == 'q'){
        Quitter();
    }
    
    else  
    printf("Erreur de saisie. Votre choix ?\n");
    }
    /*else if (  choix == 'q' ){
        //quitter
        return 0;
    }*/
}
