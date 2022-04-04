/**
  Program v0.0 - ED01_E1
  @author: Fabiana Kraft
  @version: v0.0
  @date: 25/08/2019
*/
//Identificação do programa
/*
  Tarefa extra E1 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - definir e ler um valor real do teclado (A);
 - supor que esse valor informe a área de um quadrado,
 - calcular e mostrar o lado do mesmo (l).
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
     printf("%s\n", "Tarefa extra E1 - ED01: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double A = 0.0;
     double l = 0.0;
      //Input valor
     printf("Insira o valor da area do quadrado: ");
     scanf("%lf", &A);
     //verificar valor
      if (A<0)
      {
       printf("\n%s\n", "Valor negativo da area. Sera considerado o modulo.");
       A=A*(-1);
      }//fim if
      //Operações
      l=sqrt(A);
      //Output
     printf("\n%s%lf\n%s%lf","Area quadrado= ",A,"Lado do quadrado= ",l);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
N/A
---------------------------------------------- previsao de testes
a.) 4 (OK)
b.) 9.8765432 (OK)
c.) -123.456789 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19

---------------------------------------------- testes
Versao Teste
v0.0 ( OK ) ED01_10

*/

