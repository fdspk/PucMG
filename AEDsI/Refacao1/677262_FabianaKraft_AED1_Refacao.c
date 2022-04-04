/*
AEDs1 - 677272 - Fabiana Kraft
Refação da prova
*/

#include "io.h"

void metodo0 ()
{
//nada
}

/*
Questao 1
(teste:ok)
*/

int pulse (int x)
{
   int y=0; 
   if (x>=4)
   {
      y=(x/4)*10;
   }//fim if
   return (y);
}//fim pulse

int step (int x)
{
   return (2*((x%4)+1));
}//fim step


void metodo1 ()
{
   IO_id("Questao 1");
   int x =0;
   for (x=0; x<=16; x=x+1)
   {
      printf("\n%i\t%i",x, pulse(x)+step(x));
   }
  //terminar
   IO_pause("Aperte enter para terminar"); 
}

  /*
Questao 2
teste: (21-ok)
*/

void metodo2 ()
{
   IO_id("Questao 2");
 //variaveis
   int quantidade=0;
   int posicao=0;
   int sequencia=0;
 
 //input
   printf("Insira valor da quantidade: ");
   scanf("%d", &quantidade); 

 //teste
   do
   {
      if (quantidade<=0)
      {
         printf("Valor invalido, favor inserir inteiro maior que zero: ");
         scanf("%d", &quantidade); 
      }
   }
   while(quantidade<=0);
   
   //outputs
   
   for (posicao=1; posicao<=quantidade; posicao=posicao+1)
   {
   
   // de 1 a 3
      if (posicao <4)
      {
         sequencia=sequencia+1;
      }// fim if
      
      // para 4a
      else if (posicao==4)
      {
         sequencia=6;
      }//fim else if
      else
      {
      //posicoes impares apos 4a
         if ((posicao%2)==1)
         {
            sequencia=sequencia+1;
         }// fim if
         
         //posicao com valor multiplo de 5 recebe +11
         else if (sequencia%5==0)
         { 
            sequencia=sequencia+11;
         }//fim else if
         
         //posicao par recebe +5
         else
         {
            sequencia=sequencia+5;
         }//fim else
      }// fim else
      printf("%d\t", sequencia);
   }// fim for
  //terminar
   IO_pause("Aperte enter para terminar"); 

}//fim metodo 2

 /*
Questao 3
teste: TESTE, 20 - ok; aaaaaaaaaaa, 1 - ok; aa, 0 - ok.
*/

char* center (char* p , int x)
{
// testar
   if (x<=strlen(p) || p==NULL || x<=0)
   {
    return("ERRO, favor inserir dados validos");  
   }

//variaveis internas
   char* c= (char*)malloc(80*sizeof(char));
    c[0]='\0';
   int y =0;
   int z=0;
   // colocar '-'
   for (y=0; y<x; y=y+1)
   {
      c [y] = '-';
      c[y+1]='\0';
   }// fim for
   y=((strlen(c)-strlen(p))/2);
   while ( z<strlen(p))
   {
   c[y]=p[z];
   z=z+1;
   y=y+1;
   }
return(c);

}// fim center

void metodo3 ()
{
//identificar
   IO_id("Questao 3");
   // declarar
   int x=0;
   char* p=(char*)malloc(80*sizeof(char));
   p[0]='\0';
   
   //inputs
   printf ("\nInsira uma palavra: ");
   scanf ("%s", p);
   printf ("\nInsira uma quantidade: ");
   scanf("%d", &x);
   
   
   //outputs
  printf("\n%s", center(p, x));

//terminar
   IO_pause ("Aperte enter para terminar");
}

int main ()
{
   int x = 0;
   do
   {
      printf("%s\n%s\n", "Refacao da prova", "Selecione a questao: ");
      printf("%s\n%s\n%s\n%s\n", "0 - parar", "1 - questao 1","2 - questao 2","3 - questao 3");
      printf("Inserir valor:");
      scanf("%d", &x);
      switch (x)
      {
         case 0:
            {
               metodo0();
               break;
            }
         case 1:
            {
               metodo1();
               break;
            }
         case 2:
            {
               metodo2();
               break;
            }
         case 3:
            {
               metodo3 ();
               break;
            }
         default:
            printf("\n%s(%d)\n", "Valor inserido diferente do intervalo [0,3] = ", x);
            printf("\n%s\n", "Favor reinserir valor.");
      }//fim switch
   }//fim do
   while (x!=0);

   IO_pause ("Aperte enter para terminar");
   return(0);
}
