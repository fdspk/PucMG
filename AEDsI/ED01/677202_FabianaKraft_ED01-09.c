/**
  Program v0.1 - ED01_09
  @author: Fabiana Kraft
  @version: v0.1
  @date: 25/08/2019
*/
//Identifica��o do programa
/*
  Exerc�cio 09 Lista ED01

  -------------------Objetivos--------------------------------------------------------------------------------------------------
 - definir e ler um valor real do teclado;
 - supor que esse valor represente o raio de um c�rculo (r),calcular e mostrar a �rea do mesmo (A).
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

//fun��o principal

int main()
 {
     //ID
     printf("%s\n", "Exerc�cio 09 - ED01: v0.1" );
     printf("%s\n", "Autora: Fabiana Kraft 677262");
     printf("\n");
     //Principal

      //Declarar Variaveis
     double r = 0.0;
     double A = 0.0;
      //Input valor
     printf("Insira o valor raio do circulo: ");
     scanf("%lf", &r);
     //verificar valor
      if (r<0)
      {
       printf("\n%s\n", "Valor negativo do raio. Sera considerado o modulo.");
       r=r*(-1);
      }//fim if
      //Opera��es
     A=M_PI*pow(r,2);
      //Output
     printf("\n%s%lf\n%s%lf","Raio do circulo=",r,"Area do circulo= ",A);
     //Terminar
     printf ( "\n\nApertar ENTER para terminar." );
    fflush ( stdin ); // limpar a entrada de dados
    getchar( ); // aguardar por ENTER
    return ( 0 ); // voltar ao SO (sem erros)

 } // fim main

 /*
---------------Documentacao complementar----------------------------------------------------------------------------------------

---------------------------------------------- notas / observacoes / comentarios
- Obs1: pi n�o considera. Tem que colocar M_PI
---------------------------------------------- previsao de testes
a.) 10 (OK)
b.) 9.8765432 (OK)
c.) -0.1234567 (OK)
---------------------------------------------- historico
Versao Data Modificacao

v0.0 - 25/08/19
v0.1 - 25/08/19 (ver Obs1)


---------------------------------------------- testes
Versao Teste
v0.1 ( OK ) ED01_09

*/

