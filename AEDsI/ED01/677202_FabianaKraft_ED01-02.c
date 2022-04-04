/**
  Program v0.0 - ED01_02
  @author: Fabiana Kraft
  @version: v0.0
  @date: 21/08/2019
*/
//Identificação do programa
/*
  Exercício 02 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
  - definir e ler um valor inteiro do teclado;
  - supor que esse valor represente o lado de um quadrado (a), calcular e mostrar a área (A) e o perímetro do mesmo (P).
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
     printf("%s\n", "Exercício 02 - ED01: v0.0" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     int a = 0;
     int A = 0;
     int P = 0;
      //Input valor
     printf("Insira o valor inteiro do lado do quadrado:");
     scanf("%d", &a);
     //verificar valor
      if (a<0)
      {
       printf("\n%s\n", "Valor negativo. Sera considerado o modulo.");
       a=a*(-1);
      } //fim if
      //Operações
     A=a*a;
     P=4*a;
      //Output
     printf("%s%d\n%s%d\n%s%d","Lado do quadrado=",a, "Area do quadrado=",A, "Perimetro do quadrado=",P);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
a.) 2 (OK)
b.) 7 (OK)
c.)33 (OK)
d.)675 (OK)
e.)-7 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 21/08/19


---------------------------------------------- testes
Versao Teste
v0.1 ( OK ) ED01_02

*/

