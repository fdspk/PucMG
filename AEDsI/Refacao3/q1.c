#include "io.h"
/*
677262
FABIANA KRAFT
Q1 PROVA 3
AEDS1
T2 MANHA
*/

#define  l 25
#define r 5
# define c 5

typedef struct array
{
   int size;
   int data[l];
}s_array;

typedef struct matriz
{
   int L;
   int C;
   int dado[r][c];
}s_matrix;



void copiarpara(s_array a, s_matrix m)
{
   if(m.L!=m.C || m.L<=0 || m.C<=0 || m.L>r || m.C> c)
   {
      printf("\nERRO: verificar se matriz e quadrada e se esta preenchida\n");
   }
   else
   {
      
      a.size=(((m.L*m.L)-m.L)/2)+m.L;
      
   
      if (a.size>l)
      {
         printf("\nERRO: nao ha espaco no vetor\n");
      }
      else
      {
         int i=0;
         int x=0;
         int j=0;
         int k=0;
         int p=m.L-1;
      
         for(i=0;i<m.L;i++)
         {
            for(j=p; j<m.L; j++)
            {
               a.data[k]=m.dado[i][j];
               x=a.data[k];
               k=k+1;
            }
            p=p-1;
         }
      
      }
   }
 
    for (int i=0; i<a.size; i++)
   {
      
         printf("%d\t", a.data[i]);
     
   }
   printf("\n");
}


void printmat (s_matrix m)
{
   for (int i=0; i<m.L; i++)
   {
      for (int j=0; j<m.C; j++)
      {
         printf("%d\t", m.dado[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}


int main()
{
   s_array a;
   s_array a1;
   s_matrix m;
   s_matrix m1;
   //dados m
   m.L=3;
   m.C=3;
   //preencher m
   m.dado [0][0] = 1; m.dado [0][1] = 2; m.dado [0][2] = 3;
   m.dado [1][0] = 4; m.dado [1][1] = 5; m.dado [1][2] = 6;
   m.dado [2][0] = 7; m.dado [2][1] = 8; m.dado [2][2] = 9;
  
 
   //para m
   printmat (m);
   copiarpara(a,m);
   printf("\n\n");
  
   //dados m1
   m1.L=4;
   m1.C=4;
     //preencher m1
    m1.dado [0][0] = 1; m1.dado [0][1] = 2; m1.dado [0][2] = 3; m1.dado [0][3] = 4;
   m1.dado [1][0] = 5; m1.dado [1][1] = 6; m1.dado [1][2] = 7; m1.dado [1][3] = 8;
   m1.dado [2][0] = 9; m1.dado [2][1] = 10; m1.dado [2][2] = 11; m1.dado [2][3] = 12;
   m1.dado [3][0] = 13; m1.dado [3][1] = 14; m1.dado [3][2] = 15; m1.dado [3][3] = 16;
   //para m1
    printmat (m1);
   copiarpara(a1,m1);
  
   
   
   return(0);
}