/**
  Program v0.0 - ED01_E2
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Tarefa extra E2 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
- definir e ler um valor real do teclado;
- supor que esse valor represente o volume de uma esfera (V);
- calcular e mostrar o raio da esfera (R) e a área de sua superfície (A).
  ------------------------------------------------------------------------------------------------------------------------------
*/

// lista de dependencias
#include <stdio.h>     // para entradas e saida
#include <stddef.h>    // para definicoes basicas
#include <stdlib.h>    // para a biblioteca padrao
#include <string.h>    // para cadeias de caracteres
#include <stdarg.h>    // para tratar argumentos
#include <stdbool.h>   // para definicoes logicas
#include <ctype.h>     // para tipos padroes
#include <math.h>      // para definicoes matematicas
#include <time.h>      // para medir tempo

//função principal

int main()
 {
     //ID
     printf("%s\n", "Tarefa extra E2 - ED01: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double V = 0.0;
     double R = 0.0;
     double A = 0.0;
      //Input valor
     printf("Insira o valor do volume da esfera: ");
     scanf("%lf", &V);
     //verificar valor
      if (V<0)
      {
       printf("\n%s\n", "Valor negativo do volume. Sera considerado o modulo.");
       V=V*(-1);
      }//fim if
      //Operações
      R=pow(V*3.0/(4.0*M_PI),1.0/3.0);
      A=V*3.0/R;
      //Output
     printf("\n%s%lf\n%s%lf\n%s%lf","Volume da esfera= ",V,"Raio da esfera= ",R, "Area da esfera= ",A);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
Comentário (1): Ambos funcionam
1)  R=pow(V*3.0/(4.0*M_PI),1.0/3.0);
        ou
2)  R=cbrt(V*3.0/(4.0*M_PI));

Comentário (2): Ambos funcionam 
1)A=V*3.0/R
ou
A=(4.0/3.0)*M_PI*pow(R,3)     
---------------------------------------------- previsao de testes
a.) 10 (OK)
b.) 1.234567 (OK)
c.) -987.654 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED01_10

*/

