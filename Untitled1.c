#include<stdio.h>
#include<stdlib.h>

typedef struct{

    int id;
    char cor;
    float coordX;
    float coordY;

} Ponto;

Ponto registraPonto();
int lePonto(FILE *f, Ponto *p);
int escrevePonto(FILE *f);

int main(){

    char filename[20] = "ponto.txt";
    int n;
    FILE *f;
    Ponto p;

    f = fopen(filename, "a+");
    if(f == NULL){
        printf("Erro ao abrir o arquivo...");
        exit(1);
    }
    printf("Lendo pontos salvos...\n");

    while(lePonto(f, &p)> -1){
        printf("%d %c %f %f\n",p.id, p.cor, p.coordX, p.coordY);
    }

    printf("\n\n----------Cdastrando pontos -----------\n\n");
    printf("Quantos pontos voce deseja cadrastrar? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        escrevePonto(f);
    }

    fclose(f);

    return 0;
}

Ponto registraPonto(){

 Ponto p;

 printf("ID: ");
 scanf("%d", &p.id);
 getchar();

 printf("Cor: ");
 scanf("%c", &p.cor);

 printf("Cordenada X: ");
 scanf("%f", &p.coordX);

 printf("Cordenada Y: ");
 scanf("%f", &p.coordY);

 return p;
}

int lePonto(FILE *f, Ponto *p){
    return fscanf(f, "%d %c %f %f", &p->id, &p->cor, &p->coordX, &p->coordY);
}

int escrevePonto(FILE *f){
    Ponto p = registraPonto();
    return fprintf(f, "%d %c %f %f\n", p.id, p.cor, p.coordX, p.coordY);
}
