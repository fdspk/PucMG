#include "io.h"
/*
677262
FABIANA KRAFT
Q2 PROVA 3
AEDS1
T2 MANHA
*/

bool testarmatriz (int L, int C, int m[][C])
{
   bool teste = true;
   if(L!=C)
   {
      printf("\nERRO: matriz nao quadrada\n");
   }
   else
   {
      for (int i=0; i<L; i++)
      {
         for (int j=i; j<L-1; j++)
         {
            if (i==j && m[j][j]>m[j+1][j+1])
            {
               teste=false;
            }
            if (m[i][j]>m[i][j+1])
            {
               teste= false;
            }
            if (m[j][i]>m[j+1][i])
            {
               teste=false;
            }
         }
      }
   }
   return teste;
}

int main()
{
   printf("\n NOME DO ARQUIVO: ");
   char p[80];
   p[0]='\0';
   scanf("%s",p);
   printf("%s", p);
   FILE*arq=fopen(p, "rt");
   if (arq==NULL)
   {
      printf("\n ERRO: nao foi possivel abrir o arquivo");
   }
   else
   {
      int L=0;
      int C=0;
      int cont=0;
      fscanf(arq, "%d", &L);
      fscanf(arq, "%d", &C);
      if (L<=0 || C<=0)
      {
         printf("\n ERRO: dimensoes invalidas");
      }
      else
      {
         int matriz[L][C];
         int i=0;
         int j=0;
         while (i<L && !feof(arq))
         {
            j=0;
            while (j<C && !feof(arq))
            {
               fscanf(arq, "%d", &matriz[i][j]);
               cont=cont+1;
               j=j+1;
            }
            i=i+1;
         }
         if (cont<L*C)
         {
            printf("\n ERRO: arquivo contendo menor num de dados que o informado");
         }
         else
         {
            bool resposta=testarmatriz(L,C,matriz);
            printf("\n RESPOSTA= %d", resposta);
         }
      }
   }
   fclose(arq);
}