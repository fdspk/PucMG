/*
Refacao da 2a prova
AED1 T2 Manha
Fabiana Dinelli Salvático de Paula Kraft - 677262
31-10-2019
*/

//incluir biblioteca
#include "io.h"

//metodos

void metodo0()
{
//parar
}//fim metodo0

/*
Questao 1
*/

int funcao01a (int x, int y)
{
   int resultado=0;
   if (y<0)
   {
      resultado=10000+funcao01a(x, -y);
   }//fim if
   else
   {
      if (y>0)
      {
         resultado = funcao01a(x*2, y/2)*10+y%2;
      
      }//fim if
   }//fim else
   
   //controle
   printf(" x = %d\t y = %d\t resultado = %d\n", x, y, resultado);
   
   return (resultado);
}//fim funcao01a

void metodo1()
{
//id
   IO_id("Questao 1");
   
   //resultado
   printf ("\nf(x)=%d\n", funcao01a(1, 11) );

//terminar
   IO_pause("Aperte enter para continuar");

}//fim metodo1

/*
Questao 2
*/
bool funcao2 (char*palavra)
{
//variaveis internas
   int i=0;
   bool teste = true;
//testar se existe
   if (palavra == NULL)
   {
      printf("\nERRO: palavra invalida");
   }//fim if
   else
   {
      int tamanho= strlen(palavra);
   
      for (i=0; i<tamanho; i++)
      {
         if (i< (tamanho-2) && !isdigit(palavra[i]))
         {
            teste=false;
            i=tamanho;
         }//fim if
         else if( !isdigit(palavra[i]) && tolower(palavra[i])!='x')
         {
            teste=false;
            i=tamanho;
         }//fim else if
         if (tamanho>2 && tolower(palavra[tamanho-2])=='x' && tolower(palavra[tamanho-1])==tolower(palavra[tamanho-2]))
         {
            teste=false;
            i=tamanho;
         }//fim if
      }//fim for
   }//fim else
   
   //retorno
   return(teste);

}//fim funcao2

void metodo2()
{
//id
   IO_id("Questao 2");
   //objetivo
   printf("\nObjetivo - testar se cadeia de caracteres:",
       "\n1)Contem apenas digitos",
       "\n2)e/ou letra x (maiuscula ou minuscula) uma vez, na ultima ou penultima posicao\n");
   printf("\n 0 = falso \t!=0 = verdadeiro\n");
   
   //decalar variavel
   char*palavra=(char*)malloc(80*sizeof(char));
   palavra[0]='\0';
   //input
   printf("\nInserir palavra: ");
   scanf("%s", palavra);
  
   //funcao
   printf("\n Resultado do teste = %d", funcao2(palavra));
   

//terminar
   IO_pause("Aperte enter para continuar");
}//fim metodo2

/*
Questao 3
*/
int contarlinhas(char*filename)
{
//variaveis da funcao contarlinhas
   int cont=0;
   double x = 0.0;

//abrir arquivo
   FILE*arq=fopen(filename, "rt");

//testar se existe
   if(arq==NULL)
   {
      printf("\nERRO: arquivo nao encontrado");
      fclose(arq);
   }//fim if
   else
   {
   //ler primeiro
      fscanf(arq, "%lf", &x);
   //contar e ler o resto
      while(!feof(arq))
      {
         cont=cont+1;
         fscanf(arq, "%lf", &x);
      }//fim while
   
   //fechar arquivo
      fclose(arq);
      //controle
      printf("\nContarlinhas: tamanho de linhas do arquivo= %d", cont);
   //retorna tamanho
      return(cont);
   }//fim else
}//fim contarlinhas

int funcao03 (char*filename, double delta, int size)
{
//variaveis da funcao03
   int cont=0;
   int i=0;
   double x=0.0;
   double valor=0.0;
   
   //abrir arquivo
   FILE*arq=fopen(filename, "rt");
   //testar se existe
   if(arq==NULL)
   {
      printf("\nERRO: arquivo nao encontrado");
      fclose(arq);
   }//fim if
   else
   {
   //pegar valor da primeira linha
      fscanf(arq, "%lf", &valor);
      //controle
      printf("\n valor= %lf", valor);
   
   //descartar primeiro 1/3
      for (i=1; i<(size/3); i++)
      {
         fscanf(arq, "%lf", &x);
         printf("\n descarta= %lf", x);
      }//fim for
   
   //ler primeiro valor do segundo terco
      fscanf(arq, "%lf", &x);
   //testar se esta dentro do intervalo delta
      while(!feof(arq))
      {
         if( (x-valor)<=delta && (x-valor)>=-delta)
         {
            cont=cont+1;
         //controle
            printf("\nvalor=%lf\tquantidade=%d", x, cont); 
         }//fim if
         fscanf(arq, "%lf", &x);
      }//fim while
      //fechar
      fclose(arq);
      //retornar
      return(cont);
   }//fim else

}

void metodo3()
{
//id
   IO_id("Questao 3");
   /*
   FILE* arq = fopen("DADOS.TXT", "wt");
   double j = 0.0;
   int k=0;
   while(k<9)
   {
   printf("\n%d) ", k);
   scanf("%lf",&j);
      fprintf(arq, "%lf\n", j);
      k=k+1;
   }
   fclose(arq);   
   */
   
   //tamanho
   int size=contarlinhas("DADOS.TXT");
   double delta = 0.025;
   //funcao
   printf("\nresultado= %d", funcao03("DADOS.TXT", delta, size));

//terminar
   IO_pause("Aperte enter para continuar");
}//fim metodo3

/*
Questao 4
*/
void q04 (int v[])
{
//variavies
   int i=0; //posicao
   int maior=0; //maior valor do vetor
   int j=0; // contar de 0 a maior
   int countp=0; //frequencia
   int valor=0; //moda
   int counth=0; //guarda maior frequencia
   //pegar maior valor
   while (v[i]!=0)
   {
      if (maior<v[i])
      {
         maior = v[i];
      }//fim if
      i=i+1;
   }//fim while
   //contar frequencia
   for (j=0; j<=maior; j++)
   {
      i=0;
      
      while (v[i]!=0)
      {
         if (v[i]==j)
         {
            countp= countp+1;
            //controle
            printf("\nValor= %d\tvezes que aparece= %d", j, countp);
         }//fim if
         i=i+1;
      }//fim while
      if (countp>counth)
      {
         counth=countp;
         valor=j;
         //controle
         printf("\n1.Novo valor= %d\tvezes que aparece= %d", valor, counth);
      
      }//fim if
      else if (countp==counth)
      {
         if (j>valor)
         {
            valor=j;
            counth=countp;
            //controle
            printf("\n2.Novo valor= %d\tvezes que aparece= %d", valor, counth);
         }//fim if
      }//fim else if
      countp=0;   
   }//fim for
   //arquivo
   FILE*arq=fopen("FILTRADOS.TXT", "at");
   //gravar
   i=0;
   while(v[i]!=0)
   {
      if (v[i]<valor)
      {
         fprintf(arq, "%d\n", v[i]);
      }//fim if
      i=i+1;
   
   }//fim while
   //separar os valores dos vetores
   i=0;
   fprintf(arq, "%d\n", i);
   //fechar
   fclose(arq);
   //terminar
   IO_pause("Aperte enter para continuar");   
   
}//fim q04

void metodo4( )
{
//id
   IO_id("Questao 4");
   int v1[]= {1,1,1,2,3,7,9,9,9,0};
   int v2[]= {10,20,30,40,50,60,70,80,90,0};
   int v3[]= {1,2,2,4,0,5,6,7,8,9};
   
   q04(v1);
   q04(v2);
   q04(v3);
   

//terminar
   IO_pause("Aperte enter para continuar");
}//fim metodo4

/*
Menu
*/

int main ()
{
//variaveis
   int x=0;
//repeticao
   do
   {
   //identificar
      IO_id("Prova 02 AEDs1 T2 Manha");
      printf("\nMenu de exercicios");
      printf("\n%s\t%s\n%s\t%s\n%s\n", "0 - parar", "1 - Questao1", "2 - Questao2", "3 - Questao3", "4 - Questao 4");
   //inserir
      printf("\nSelecionar questao: ");
      scanf("%d", &x);
   //switch-case
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
               metodo3();
               break;
            }
         case 4:
            {
               metodo4();
               break;
            }
         default:
            {
               IO_pause ( "Favor inserir numero ente 0 e 4. Aperte enter para continuar" );
            }
      
      }//fim switch
   
   }//fim do
   while (x!=0);
    //finalizar
   IO_pause("Aperte enter para terminar");

}
