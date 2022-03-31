#include <stdio.h>


int max(int i1, int i2) {
	return (i1 > i2) ? i1 : i2;
}

int min(int i1, int i2) {
	return (i1 < i2) ? i1 : i2;
}

int max5(int i1, int i2, int i3, int i4, int i5) {
	return max(max(max(i1, i2), max(i3, i4)), i5);
}

int min5(int i1, int i2, int i3, int i4, int i5) {
	return min(min(min(i1, i2), min(i3, i4)), i5);
}


int first(int i1, int i2, int i3, int i4, int i5) {
	return max5(i1, i2, i3, i4, i5);
}

int second(int i1, int i2, int i3, int i4, int i5) {
	int rem = first(i1, i2, i3, i4, i5);
    if (rem == i1)
	   i1 = 0;
    else if (rem == i2)
	   i2 = 0;
    else if (rem == i3)
	   i3 = 0;
    else if (rem == i4)
	   i4 = 0;
    else if (rem == i5)
	   i5 = 0;
	return first(i1, i2, i3, i4, i5);
}

int third(int i1, int i2, int i3, int i4, int i5) {
	int rem1 = first(i1, i2, i3, i4, i5);
   
    if (rem1 == i1)
	   i1 = 0;
    else if (rem1 == i2)
	   i2 = 0;
    else if (rem1 == i3)
	   i3 = 0;	   
    else if (rem1 == i4)
	   i4 = 0;	   
    else if (rem1 == i5)
	   i5 = 0;
   
	return second(i1, i2, i3, i4, i5);
}

int fourth(int i1, int i2, int i3, int i4, int i5) {
	int rem1 = first(i1, i2, i3, i4, i5);
   
    if (rem1 == i1)
	   i1 = 0;
    else if (rem1 == i2)
	   i2 = 0;
    else if (rem1 == i3)
	   i3 = 0;	   
    else if (rem1 == i4)
	   i4 = 0;	   
    else if (rem1 == i5)
	   i5 = 0;
   
	return third(i1, i2, i3, i4, i5);
}

int fifth(int i1, int i2, int i3, int i4, int i5) {
	return min5(i1, i2, i3, i4, i5);
}

    int main(int argc, char* argv[]) {

    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
    char c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;
    scanf("%d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c %d %c", &i1, &c1, &i2, &c2, &i3, &c3, &i4, &c4, &i5, &c5, &i6, &c6, &i7, &c7, &i8, &c8, &i9, &c9, &i10, &c10 );

//bug résolu

   int immaj1 = first( i1,  i2,  i3,  i4,  i5);
    int immaj2 = second( i1,  i2,  i3,  i4,  i5);
    int immaj3 = third( i1,  i2,  i3,  i4,  i5);
    int immaj4 = fourth( i1,  i2,  i3,  i4,  i5);
    int immaj5 = fifth( i1,  i2,  i3,  i4,  i5);
    int immaj6 = first( i6,  i7,  i8,  i9,  i10);
    int immaj7 = second( i6,  i7,  i8,  i9,  i10);
    int immaj8 = third( i6,  i7,  i8,  i9,  i10);
    int immaj9 = fourth( i6,  i7,  i8,  i9,  i10);
    int immaj10 = fifth( i6,  i7,  i8,  i9,  i10);

    if (immaj1 == 1){
        immaj1 = 14;
    }
    if (immaj2 == 1){
        immaj2 = 14;
    }
    if (immaj3 == 1){
        immaj3 = 14;
    }
    if (immaj4 == 1){
        immaj4 = 14;
    }
    if (immaj5 == 1){
        immaj5 = 14;
    }
    if (immaj6 == 1){
        immaj6 = 14;
    }
    if (immaj7 == 1){
        immaj7 = 14;
    }
    if (immaj8 == 1){
        immaj8 = 14;
    }
    if (immaj9 == 1){
        immaj9 = 14;
    }
    if (immaj10 == 1){
        immaj10 = 14;
    }

    int imaj1 = first( immaj1,  immaj2,  immaj3,  immaj4,  immaj5);
    int imaj2 = second( immaj1,  immaj2,  immaj3,  immaj4,  immaj5);
    int imaj3 = third( immaj1,  immaj2,  immaj3,  immaj4,  immaj5);
    int imaj4 = fourth( immaj1,  immaj2,  immaj3,  immaj4,  immaj5);
    int imaj5 = fifth( immaj1,  immaj2,  immaj3,  immaj4,  immaj5);
    int imaj6 = first( immaj6,  immaj7,  immaj8,  immaj9,  immaj10);
    int imaj7 = second( immaj6,  immaj7,  immaj8,  immaj9,  immaj10);
    int imaj8 = third( immaj6,  immaj7,  immaj8,  immaj9,  immaj10);
    int imaj9 = fourth( immaj6,  immaj7,  immaj8,  immaj9,  immaj10);
    int imaj10 = fifth( immaj6,  immaj7,  immaj8,  immaj9,  immaj10);


 
    if ((imaj1 == imaj6) && (imaj2 == imaj7) && (imaj3 == imaj8) && (imaj4 == imaj9) && (imaj5 == imaj10)){
        printf("Draw\n");
    }
// QuinteFlunsh : suite 5 cartes et dont la couleur même
    
    else if ((imaj2 == imaj1 -1) && (imaj3 == imaj2 -1) && (imaj4 == imaj3 -1) && (imaj5 == imaj4 -1) && ((c1 == c2) && (c2 == c3) && ( c3 == c4 ) && (c4 == c5))){
        printf("Player1 wins\n");
    }
    else if ((imaj7 == imaj6 -1) && (imaj8 == imaj7 -1) && (imaj9 == imaj8 -1) && (imaj10 == imaj9 -1) && ((c6 == c7) && (c7 == c8) && (c8 == c9) && ( c9 == c10))){
        printf("Player2 wins\n");
    }   
//Draw
else if (imaj1==imaj6 && imaj2==imaj7 && imaj3==imaj8 && imaj4==imaj9 && imaj5==imaj10){
    printf("Draw\n");
}

// Carré : 4 cartes de même valeur 

    else if (((imaj1 == imaj2 ) && (imaj2 == imaj3 ) && (imaj3 == imaj4) && (imaj4 != imaj5)) || 
        ((imaj1 == imaj2 ) && (imaj2 == imaj3 ) && (imaj3 != imaj4) && (imaj4 == imaj5)) || 
        ((imaj1 == imaj2 ) && (imaj2 != imaj3 ) && (imaj3 == imaj4) && (imaj4 == imaj5)) ||
        ((imaj1 != imaj2 ) && (imaj2 == imaj3 ) && (imaj3 == imaj4) && (imaj4 == imaj5)))
        {
        printf("Player1 wins\n");
    }
    else if (((imaj6 == imaj7 ) && (imaj7 == imaj8 ) && (imaj8 == imaj9) && (imaj9 != imaj10)) || 
        ((imaj6 == imaj7 ) && (imaj7 == imaj8 ) && (imaj8 != imaj9) && (imaj9 == imaj10)) || 
        ((imaj6 == imaj7 ) && (imaj7 != imaj8 ) && (imaj8 == imaj9) && (imaj9 == imaj10)) ||
        ((imaj6 != imaj7 ) && (imaj7 == imaj8 ) && (imaj8 == imaj9) && (imaj9 == imaj10)))
        {
        printf("Player2 wins\n");
    }

// brelan : 3 meme valeurs 

    else if (((imaj1 == imaj2) && (imaj2 == imaj3)) || ((imaj2 == imaj3) && (imaj3 == imaj4)) || ((imaj3 == imaj4) && (imaj4 = imaj5))){
    printf("Player1 wins\n");
}
else if (((imaj6 == imaj7) && (imaj7 == imaj8)) || ((imaj7 == imaj8) && (imaj8 == imaj9)) || ((imaj8 == imaj9) && (imaj9 = imaj10))){
    printf("Player2 wins\n");
}
// Double Paire : 2 fois 2 cartes de même valeur
else if  (((imaj1==imaj2 && imaj3==imaj4)  || (imaj1==imaj2 && imaj4==imaj5) || (imaj2==imaj3 && imaj4==imaj5)) && (( imaj1 > imaj6 ) || (imaj2 > imaj6) || (imaj3 > imaj7) || (imaj4 > imaj8) || (imaj5 > imaj10))) {
		printf("Player1 wins\n");
	} else if (((imaj6==imaj7 && imaj8==imaj9)  || (imaj6==imaj7 && imaj9==imaj10) || (imaj7==imaj8 && imaj9==imaj10)) && (( imaj1 < imaj6 ) || (imaj2 < imaj6) || (imaj3 < imaj7) || (imaj4 < imaj8) || (imaj5 < imaj10))){
		printf("Player2 wins\n");
	}
// Suite : 5 cartes valeurs se suivent  
    else if (((imaj2==imaj1-1) && (imaj3==imaj2-1) &&  (imaj4==imaj3-1) && (imaj5==imaj4-1)) && !((imaj7==i6-1) && (imaj8==i7-1) &&  (imaj9==imaj8-1) && (imaj10==imaj9-1))){
    printf("Player1 wins\n");}
           
else if (((imaj7==imaj6-1) && (imaj8==imaj7-1) &&  (imaj9==imaj8-1) && (imaj10==imaj9-1)) && !((imaj2==i1-1) && (imaj3==i2-1) &&  (imaj4==imaj3-1) && (imaj5==imaj4-1))){
    printf("Player2 wins\n");}
    
  // Paire : 2 Cartes de même valeur 
else if  ((((imaj1 == imaj2) && (imaj1 != imaj3) && (imaj1 != imaj4) && (imaj1 != imaj5)) ||
        ((imaj2 == imaj3) && (imaj2 != imaj1) && (imaj2 != imaj5) && (imaj2 !=imaj4)) ||
        ((imaj3 == imaj4) && (imaj3 !=imaj1) && (imaj3 !=imaj2) && (imaj3 != imaj5)) ||
        ((imaj4 == imaj5) && (imaj4 != imaj3) && (imaj4 !=imaj2) && (imaj4 != imaj1))) &&
        ((imaj6 != imaj5) && (imaj6 != imaj4 ) && (imaj6 != imaj3) && (imaj6 != imaj2) && (imaj6 != imaj1))){
    printf ("Player1 wins\n");
    }
    else if ((((imaj6 == imaj7) && (imaj6 != imaj8) && (imaj6 !=imaj9) && (imaj6 != imaj10)) ||
                ((imaj7 == imaj8) && (imaj7 != imaj6) && (imaj7 != imaj9) && (imaj7 != imaj10)) ||
                ((imaj8 == imaj9) && (imaj8 != imaj6) && (imaj8 != imaj7) && (imaj8 != imaj10)) ||
                ((imaj9 == imaj10) && (imaj9 != imaj8) && (imaj9 != imaj7) && (imaj9 != imaj6))) &&
                ((imaj1 != imaj2) && (imaj1 != imaj3) && (imaj1 != imaj4) && (imaj1 != imaj5) && (imaj1 != imaj6))){
    printf("Player2 wins\n");
    }
// Full : brelan ( trois cartes même valeur ) + une paire ( 2 cartes même valeurs )
else if ((((imaj1 == imaj2) && (imaj2 == imaj3)) || ((imaj2 == imaj3) && (imaj3 == imaj4)) || ((imaj3 == imaj4) && (imaj4 = imaj5))) && (imaj1 == imaj2 || imaj1 == imaj3 || imaj1 == imaj4 || imaj1 == imaj5 ||
        imaj2 == imaj3 || imaj2 == imaj4 || imaj2 == imaj5 ||
        imaj3 == imaj4 || imaj3 == imaj5 ||
        imaj4 == imaj5 )){
    printf("Player1 wins\n");
}
else if ((((imaj6 == imaj7) && (imaj7 == imaj8)) || ((imaj7 == imaj8) && (imaj8 == imaj9)) || ((imaj8 == imaj9) && (imaj9 = imaj10))) && (imaj6 == imaj7 || imaj6 == imaj8 || imaj6 == imaj9 || imaj6 == imaj10 ||
        imaj7 == imaj8 || imaj7 == imaj9 || imaj7 == imaj10 ||
        imaj8 == imaj9 || imaj8 == imaj10 ||
        imaj9 == imaj10 )){
    printf("Player2 wins\n");
}

    // Couleur : 5 cartes même couleur
    else if ((c1 == c2) && (c2 == c3) && (c3 == c4) && (c4 == c5)){
        printf("Player1 wins\n");
    }
    else if ((c6 == c7) && (c7 == c8) && (c8 == c9) && (c9 == c10)){
        printf("Player2 wins\n");
    }
// Carte Haute : Aucune des combinaisons suivantes
else if (( imaj1 > imaj6 ) || ( imaj2 > imaj7) || ( imaj3 > imaj8) || ( imaj4 > imaj9 ) || ( imaj5 >= imaj10)){
    printf("Player1 wins\n");
}
else if (( imaj6 > imaj1 ) || ( imaj7 > imaj2) || ( imaj8 > imaj3 ) || ( imaj9 > imaj4 )|| ( imaj10 >= imaj5)){
    printf("Player2 wins\n");
}
}

