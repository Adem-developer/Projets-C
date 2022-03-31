#include <stdio.h>
#include <string.h>

void soustraction(int res[], int nb1[], int nb2[], int taille);

int nigatif(int nb[], int taille){
    int i = 0;
    
    for (i = 0; i < taille; i++){
    if (nb[i] < 0){
        return 1;
    }
    }
    return 0;
}

int degres_nb(int tab[], int taille){
    int i;
    for (i = 0; i < taille; i++){
        if (tab[i] != 0){
            return i;
        }
    }
}

void conversion(int nb[], int taille){
    int degres = degres_nb(nb, 1000);
    nb[degres] = nb[degres]*-1;
}

int comparateur(int nb1[], int nb2[], int taille){
    int i;

    for (i = 0 ; i < taille ; ++i)
        {
        if ( nb1[i] > nb2[i] )
            {
            return 1;
            }
        else if ( nb1[i] < nb2[i] )
        {
            return 2;
        }
    }
    return 3;
}

char flush_space(){
    char c;
    scanf("%c", & c );
    while ( c == ' ')
    scanf("%c", & c );
    return c;
}

void shift(int tab[], int taille_tab, int taille_nb ){
    int i;
    for ( i = 0; i < taille_nb ; i++){
        tab[taille_tab-i-1] = tab [taille_nb-i-1];
        tab[taille_nb-i-1]=0;
    }
}

int is_num(char c){
    return c >= '0' && c <= '9';
}

int convert(char c){
    return c-'0';
}

int detecter(int nb[], int taille){
    int i;
    int negativite = 0;
    for (i=0; i<taille; i++){
        if (nb[i]<0){
            return 2;
        }
    }
    return 1;
}

char lire_nombre(int tab[], int taille){
    char cur = 0; int minus = 0; int i = 0;
    cur = flush_space();

    if (cur =='-'){
    minus = 1;
    cur = flush_space();
    }
    tab[0] = minus ?-convert(cur) : convert(cur);
    scanf("%c", & cur);
    for ( i = 1; is_num(cur); ++i){
    tab[i] = convert (cur);
    scanf("%c", & cur);
    }
    shift(tab, taille, i);

    if (cur == ' ')
    return flush_space();
    else
    return cur;
}

void display(int tab[], int taille){
    int i = 0;
    for(i=0; i<taille && tab[i]==0; i++)
    ;
    for(;i<taille;i++)
        printf("%d", tab[i]);
    printf("\n");
}

void addition(int res[], int nb1[], int nb2[], int taille){
    int nigatif1 = nigatif(nb1,1000);
    int nigatif2 = nigatif(nb2,1000);
    int comp = comparateur(nb1,nb2,1000);
    int ret=0;
    int cur=0;
    int i = 0;
    int dizaine, unite;

    if(nigatif1 == 0 && nigatif2 == 0){
        for(i=0; i<taille; i++){
        cur=nb1[taille-i-1]+nb2[taille-i-1]+ret;
        dizaine=cur/10;
        unite=cur%10;
        res[taille-i-1]=unite;
        ret=dizaine;
    }
    }
    else if (nigatif1 == 0 && nigatif2 == 1){
        conversion(nb2,1000);
        soustraction(res, nb1, nb2, taille);
        }
    else if (nigatif1 == 1 && nigatif2 == 0){
        conversion(nb1,1000);
        soustraction(res,nb1,nb2, 1000);
        conversion(res, 1000);
    }
    else if (nigatif1 == 1 && nigatif2 == 1){
        conversion(nb2,1000); conversion(nb1,1000);
        addition(res, nb1, nb2, taille);
        conversion(res,1000);

    }

    }

void soustraction_basique(int res[], int nb1[], int nb2[], int taille){
    int i = 0;
    int cur = 0;
     
        for (i = 0; i < taille; i++)
            {
            if (nb1[taille-i-1] < nb2[taille-i-1]){
             nb1[taille-i-1] = nb1[taille-i-1]+10;
             nb2[taille-i-2] = nb2[taille-i-2]+1;
             cur = nb1[taille-i-1] - nb2[taille-i-1];
            }
    else {cur = nb1[taille-i-1] - nb2[taille-i-1];}

    res[taille-i-1] = cur;
        }    
    
}

void soustraction_contre(int res[], int nb1[], int nb2[], int taille){
    int i, dizaine, unite;
    int ret = 0;
    int cur = 0;
    for (i = 0; i < taille; ++i){
        if (nb2[taille-i-1] < nb1[taille-i-1])
        {
            nb2[taille-i-1] = nb2[taille-i-1]+10;

            nb1[taille-i-2] = nb1[taille-i-2]+1;

            cur = nb2[taille-i-1] - nb1[taille-i-1];
        }
        else
            {
                cur = nb2[taille-i-1] - nb1[taille-i-1];
            }

        res[taille-i-1] = cur; 

    }

    conversion(res, 1000);
}

void soustraction(int res[], int nb1[], int nb2[], int taille){
    //modifier
    int comp = comparateur(nb1,nb2,1000);
    int neg1 = nigatif(nb1,1000);
    int neg2 = nigatif(nb2,1000);
    if(neg1 == 0 && neg2 == 0){
    if (comp == 1){
        soustraction_basique(res, nb1, nb2, taille);
    }
    else if (comp == 2){
        soustraction_contre(res, nb1, nb2, taille);
    }
    }

    else if (neg1 == 1 && neg2 == 1)
    {
        conversion(nb2,1000);
        addition(res, nb1, nb2, taille);
    }
    else if (neg1 == 1 && neg2 == 0)
    {
        conversion(nb1,1000);
        addition(res, nb1, nb2, taille);
        conversion(res,1000);
    }
    else if(neg1 == 0 && neg2 == 1)
    {
        conversion(nb2,1000);
        addition(res, nb1, nb2, taille);
    }

}

int chiffre(int tab[], int tailletab){
    int i;
    for(i=0; i<tailletab && tab[i]==0; i++);
    return tailletab-i;
}

void decalage(int nb[1000], int decaler){
    int i;
    int nc = chiffre(nb, 1000);
    for (i=0; i<=nc; i++){
        nb[1000-nc-decaler+i]=nb[1000-nc+i];
    }
    for (i=0; i<decaler; i++){
        nb[1000-i-1]=0;
    }
}

void multi(int resf[], int nb1[], int nb2[], int taille){
    int i;
    int j;
    int nc = chiffre(nb2, taille);
    for (i=0; i<nc; i++){
        int rest[1000] = {0};
        for (j=1; j<=nb2[taille-i-1]; j++){
            addition(rest, rest, nb1, 1000);
        }
        decalage(rest, i);
        addition(resf, resf, rest, 1000);
    }
}

void multiplication(int res[], int nb1[], int nb2[], int taille){

    int neg1 = nigatif(nb1,1000);
    int neg2 = nigatif(nb2,1000);

    if (neg1 == 0 && neg2 == 0){
        multi(res,nb1,nb2,1000);
    }
    else if (neg1 == 0 && neg2 == 1){
        conversion(nb2, 1000);
        multi(res,nb1,nb2,1000);
        conversion(res,1000);
    }
    else if (neg1 == 1 && neg2 == 1){
        conversion(nb2, 1000); conversion(nb1, 1000);
        multi(res,nb1,nb2,1000);
    }
    else if (neg1 == 1 && neg2 == 0){
        conversion(nb1, 1000);
        multi(res,nb1,nb2,1000);
        conversion(res,1000);
    }

}


void soustraction_div(int res[], int nb1[], int nb2[], int taille){
    int i=0;
    int cur=0, C1=0, C2=0, ret=0;
    for(i=0; i<taille; i++){
        C1=nb1[taille-i-1];
        C2=nb2[taille-i-1]+ret;
        if (C1<C2){
            ret=1;
            cur=10+C1-C2;
        }
        else {
            ret=0;
            cur=C1-C2;
        }
        res[taille-i-1]=cur;
    }
}

void division(int res[], int nb1[], int nb2[], int taille){
    int i, y;
    int ademoooo = 0;
    int unite[1000] = {0}; 
    int tabalt[1000]= {0}; 
    int resf[1000]= {0};
    unite[999] = 1;
    int degnb1 = chiffre(nb1, 1000);
    int degnb2 = chiffre(nb2, 1000);
    int ecart = degnb1 - degnb2 ;
    int detecter1 = detecter(nb1, 1000);
    int detecter2 = detecter(nb2, 1000);
    if (detecter1==2 && detecter2==1){
    conversion(nb1, 1000);
    for (i=0; i<taille; i++){
        tabalt[i]=nb2[i];
    }
    for(i=ecart; i >= 0; i--){
      decalage(nb2, i);
      ademoooo = comparateur(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (ademoooo == 1 || ademoooo==3){
            soustraction_div(nb1, nb1, nb2, 1000);
            addition(resf, resf, unite, 1000);
            ademoooo = comparateur(nb1, nb2, 1000);
       }
        decalage(resf, i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++){
             nb2[y]=tabalt[y];
    }
    }
    conversion(res, 1000);
    }
    else if (detecter1==1 && detecter2==2){
        conversion(nb2, 1000);
        for (i=0; i<taille; i++)tabalt[i]=nb2[i];

    for(i=ecart; i >= 0; i--){
      decalage(nb2, i);
      ademoooo = comparateur(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (ademoooo == 1 || ademoooo==3){
            soustraction_div(nb1, nb1, nb2, 1000);
            addition(resf, resf, unite, 1000);
            ademoooo = comparateur(nb1, nb2, 1000);
       }
        decalage(resf, i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=tabalt[y];
    }
    conversion(res, 1000);
    }
    else if (detecter1==2 && detecter2==2){
        conversion(nb1, 1000);
        conversion(nb2, 1000);
        for (i=0; i<taille; i++)tabalt[i]=nb2[i];

    for(i=ecart; i >= 0; i--){
      decalage(nb2, i);
      ademoooo = comparateur(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (ademoooo == 1 || ademoooo==3){
            soustraction_div(nb1, nb1, nb2, 1000);
            addition(resf, resf, unite, 1000);
            ademoooo = comparateur(nb1, nb2, 1000);
       }
        decalage(resf, i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=tabalt[y];
    }
    }
    else {
        for (i=0; i<taille; i++)tabalt[i]=nb2[i];

    for(i=ecart; i >= 0; i--){
      decalage(nb2, i);
      ademoooo = comparateur(nb1, nb2, 1000);
      for (y=0; y<taille; y++) resf[y]=0;

      while (ademoooo == 1 || ademoooo==3){
            soustraction_div(nb1, nb1, nb2, 1000);
            addition(resf, resf, unite, 1000);
            ademoooo = comparateur(nb1, nb2, 1000);
       }
        decalage(resf, i);
        addition(res, res, resf, 1000);
        for (y=0; y<taille; y++) nb2[y]=tabalt[y];
    }
    }
}

void modulo(int res[], int nb1[], int nb2[], int taille){
    int i, y;
    int res1[1000] = {0};
    int res2[1000] = {0};
    int nb1vrai[1000] = {0};
    int detecter1 = detecter(nb1, 1000);
    int detecter2 = detecter(nb2, 1000);
    if (detecter1 == 2 && detecter2 == 1){
        conversion(nb1, 1000);
        for ( i = 0; i < taille; i++){
            nb1vrai[i] = nb1[i];
        }
        division(res1, nb1, nb2, taille);
        multiplication(res2, res1, nb2, taille);
        for ( y = 0; y < taille; y++){
            nb1[y] = nb1vrai[y];
        }
        soustraction(res, nb1, res2, taille);
        conversion(res, 1000);
    }

    else if ( detecter1 == 1 && detecter2 == 2){
        conversion(nb2, 1000);
        for ( i = 0; i < taille; i++){
            nb1vrai[i] = nb1[i];
        }
        division(res1, nb1, nb2, taille);
        multiplication(res2, res1, nb2, taille);
        for ( y = 0; y < taille; y++){
            nb1[y] = nb1vrai[y];
        }
        soustraction(res, nb1, res2, taille);
    }

    else if ( detecter1 == 2 && detecter2 == 2){
        conversion(nb1, 1000);
        conversion(nb2, 1000);
        for ( i = 0; i < taille; i++){
            nb1vrai[i] = nb1[i];
        }
        division(res1, nb1, nb2, taille);
        multiplication(res2, res1, nb2, taille);
        for ( y = 0; y < taille; y++){
            nb1[y] = nb1vrai[y];
        }
        soustraction(res, nb1, res2, taille);
        conversion(res, 1000);
    }

    else {
        for ( i = 0; i < taille; i++){
            nb1vrai[i] = nb1[i];
        }
        division(res1, nb1, nb2, taille);
        multiplication(res2, res1, nb2, taille);
        for ( y = 0; y < taille; y++){
            nb1[y] = nb1vrai[y];
        }
        soustraction(res, nb1, res2, taille);
    }

}

int poubelle(int res[], int taille){
    int i;
    int vide[1000] = {0};
    int bizarretruc = comparateur(vide, res, 1000);
    for ( i = 0; i < taille; i++){
        if (bizarretruc == 3){
            printf("0");
            return 0;
        }
    }
}

int main (){
    int nb1[1000] = {0}; int res1[1000] = {0};
    int nb2[1000] = {0}; int res2[1000] = {0};
    int nb3[1000] = {0};

    char op1, op2;

    op1 = lire_nombre(nb1, 1000);
    op2 = lire_nombre(nb2, 1000);
    
    if(op2 =='\n'){
    if(op1 == '+')
    {
        addition(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }
    else if (op1 == '-')
    {
        soustraction(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }

    else if ( op1 == '*')
    {
        multiplication(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }

    else if ( op1 == '/')
    {
        division(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }

    else if ( op1 == '%')
    {
        modulo(res1, nb1, nb2, 1000);
        poubelle(res1, 1000);
        display(res1, 1000);
    }
    }

    

    if ( op2 != '\n')
    {
        lire_nombre(nb3,1000);

    if ( op1 == '+' && op2 == '+')
    {
        addition(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '+' && op2 == '-')
    {
        addition(res1, nb1, nb2, 1000);
        soustraction(res2,res1,nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '-' && op2 == '+')
    {
        soustraction(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '+' && op2 == '/')
    {
        division(res1, nb2, nb3, 1000);
        addition(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '+' && op2 == '*')
    {
        multiplication(res1, nb2, nb3, 1000);
        addition(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    
    else if ( op1 == '+' && op2 == '%')
    {
        modulo(res1, nb2, nb3, 1000);
        addition(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '-' && op2 == '*')
    {
        multiplication(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
        
    }
    else if ( op1 == '-' && op2 == '/')
    {
        division(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    
    else if ( op1 == '-' && op2 == '%')
    {
        modulo(res1, nb2, nb3, 1000);
        soustraction(res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '*')
    {
        multiplication(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '+')
    {
        multiplication(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '-')
    {
        multiplication(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '/')
    {
        multiplication(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '%')
    {
        multiplication(res1, nb1, nb2, 1000);
        modulo(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '/')
    {
        division(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '*')
    {
        division(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '-')
    {
        division(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '+')
    {
        division(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '/' && op2 == '%')
    {
        division(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000); 
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '%')
    {
        modulo(res1, nb1, nb2, 1000);
        modulo(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '*')
    {
        modulo(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '/')
    {
        modulo(res1, nb1, nb2, 1000);
        division(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '+')
    {   
        modulo(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '%' && op2 == '-')
    {
        modulo(res1, nb1, nb2, 1000);
        soustraction(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '-' && op2 == '-')
    {
        soustraction(res1, nb1, nb2, 1000);
        soustraction(res2,res1,nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '*')
    {
        multiplication(res1, nb1, nb2, 1000);
        multiplication(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '+')
    {
        multiplication(res1, nb1, nb2, 1000);
        addition(res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '*' && op2 == '-')
    {
        multiplication(res1, nb1, nb2, 1000);
        soustraction (res2, res1, nb3, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    else if ( op1 == '+' && op2 == '*')
    {
        multiplication(res1, nb2, nb3, 1000);
        addition(res2,nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    
    else if ( op1 == '-' && op2 == '*')
    {
        multiplication(res1, nb2, nb3, 1000);
        soustraction (res2, nb1, res1, 1000);
        poubelle(res2, 1000);
        display(res2, 1000);
    }
    }
}