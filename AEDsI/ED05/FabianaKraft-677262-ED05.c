/**
Lista ED05 - T2 manha - AEDsI
Fabiana Kraft - 677262
*/

//incluir bibliotecas
#include "io.h"

void metodo0 ()
{
//metodo para parar
}//fim metodo0

/**
Metodo 1 - executa o Metodo1a - Mostrar certa quantidade de valores.
@param x - quantidade de valores a serem mostrados
*/
void metodo1a ( int x )
{
// definir dado local
   int y = 1;
// controle
// repetir enquanto controle menor que a quantidade desejada
   while ( y <= x )
   {
   // mostrar valor
      IO_printf ( "%s%d\n", "Valor = ", y );
   // passar ao proximo
      y = y + 1;
   } // fim se
} // fim metodo01a( )

/**
Metodo01.
Teste: 0k
*/

void metodo1 ()
{
// identificar
   IO_id ( "EXEMPLO0501 - Metodo1 - v0.0" );
// executar o metodo auxiliar
   metodo1a ( 5 );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo1


/**
Metodo02a - Mostrar certa quantidade de valores pares.
@param x - quantidade de valores a serem mostrados
*/
void metodo02a ( int x )
{
// definir dado local
   int y = 1; // controle
   int z = 2;
// repetir enquanto controle menor que a quantidade desejada
   while ( y <= x )
   {
   // mostrar valor
      IO_printf ( "%d: %d\n", y, z );
   // passar ao proximo par
      z = z + 2;
   // passar ao proximo valor controlado
      y = y + 1;
   } // fim se
} // fim metodo02a( )

/**
Metodo02.
Teste: 0k
*/
void metodo2 ()
{
// identificar
   IO_id ( "EXEMPLO0501 - Metodo - v0.0" );
// encerrar
// executar o metodo auxiliar
   metodo02a ( 5 );
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo2

/**
Metodo03a - Mostrar certa quantidade de valores pares.
@param x - quantidade de valores a serem mostrados
*/
void metodo03a ( int x )
{
// definir dado local
   int y = 1; // controle
   int z = 0;
// repetir enquanto controle menor que a quantidade desejada
   while ( y <= x )
   {
   // vincular o valor a ser mostrado ao controle
      z = 2 * y;
   // mostrar valor
      IO_printf ( "%d: %d\n", y, z );
   // passar ao proximo valor controlado
      y = y + 1;
   } // fim se
} // fim metodo03a( )

/**
Metodo03.
Teste:ok
*/

void metodo3 ()
{
// identificar
   IO_id ( "EXEMPLO0503 - Metodo03 - v0.0" );
// executar o metodo auxiliar
   metodo03a ( 5 );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}//fim metodo3

/**
Metodo04a - Mostrar certa quantidade de valores pares.
@param x - quantidade de valores a serem mostrados
*/
void metodo04a ( int x )
{
// definir dado local
   int y = x; // controle
   int z = 0;
// repetir enquanto controle menor que a quantidade desejada
   while ( y > 0 )
   {
   // vincular o valor a ser mostrado ao controle
      z = 2 * y;
   // mostrar valor
      IO_printf ( "%d: %d\n", y, z );
   // passar ao proximo valor controlado
      y = y - 1;
   } // fim se
} // fim metodo04a( )

/**
Metodo04.
Teste:ok
*/

void metodo4 ()
{
// identificar
   IO_id ( "EXEMPLO0504 - Metodo04 - v0.0" );
// executar o metodo auxiliar
   metodo04a ( 5 );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo4

/**
Metodo05a - Mostrar certa quantidade de valores pares.
@param x - quantidade de valores a serem mostrados
*/
void metodo05a ( int x )
{
// definir dado local
   int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
   for ( y = x; y > 0; y = y-1 )
   {
   // mostrar valor
      IO_printf ( "%d: %d\n", y, (2*y) );
   } // fim se
} // fim metodo05a( )

/**
Metodo05.
Teste:ok
*/

void metodo5 ()
{
// identificar
   IO_id ( "EXEMPLO0505 - Metodo05 - v0.0" );
// executar o metodo auxiliar
   metodo05a ( 5 );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo5

/**
somarValores - funcao para somar certa quantidade de pares.
@return soma dos valores
@param x - quantidade de valores a serem mostrados
*/
int somarValores ( int x )
{
// definir dados locais
   int soma = 1;
   int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
   for ( y = x-1; y > 0; y = y-1 )
   {
   // mostrar valor
      IO_printf ( "%d: %d\n", y, (2*y) );
   // somar valor
      soma = soma + (2*y);
   } // fim se
// retornar resultado
   return ( soma );
} // fim somarValores ( )

/**
Metodo06 
Teste :ok (obs: n funciona se x=6 por exemplo. Deve-se colocar um if x%2!=0 -> y=x-1; else y=x);
*/

void metodo6 ()
{
// definir dado
   int soma = 0;
// identificar
   IO_id ( "EXEMPLO0506 - Metodo06 - v0.0" );
// chamar e receber resultado da funcao
   soma = somarValores ( 5 );
// mostrar resultado
   IO_printf ( "soma de pares = %d\n", soma );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo6

/**
somarFracao - funcao para somar certa quantidade de fracoes.
@return soma dos valores
@param x - quantidade de valores a serem mostrados
*/
double somarFracao ( int x )
{
// definir dados locais
   double soma = 1.0;
   double numerador = 0;
   double denominador = 0;
   int y = 0 ; // controle
// repetir enquanto controle menor que a quantidade desejada
   for ( y = x-1; y > 0; y = y-1 )
   {
   // calcular numerador
      numerador = 1.0;
   // calcular denominador
      denominador = 2.0*y;
   // mostrar valor
      IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n",
         y, numerador, denominador, (numerador/denominador) );
   // somar valor
      soma = soma + (1.0)/(2.0*y);
   } // fim se
// retornar resultado
   return ( soma );
} // fim somarFracao ( )

/**
Metodo07.
Teste:ok
*/

void metodo7 ()
{
// definir dado
   double soma = 0.0;
// identificar
   IO_id ( "EXEMPLO0507 - Metodo07 - v0.0" );
// chamar e receber resultado da funcao
   soma = somarFracao ( 5 );
// mostrar resultado
   IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo7

/**
somarFracaod - funcao para somar certa quantidade de fracoes.
@return soma dos valores
@param x - quantidade de valores a serem mostrados
*/
double somarFracaod ( int x )
{
// definir dados locais
   double soma = 1.0;
   double numerador = 0;
   double denominador = 0;
   int y = 0 ; // controle
// mostrar primeiro valor
   IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma );
// repetir enquanto controle menor que a quantidade desejada
   for ( y = 1; y <= (x-1); y = y+1 )
   {
   // calcular numerador
      numerador = 2.0*y-1;
   // calcular denominador
      denominador = 2.0*y;
   // mostrar valor
      IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n",
         y, numerador, denominador, (numerador/denominador) );
   // somar valor
      soma = soma + (2.0*y-1)/(2.0*y);
   } // fim se
// retornar resultado
   return ( soma );
} // fim somarFracao ( )


/**
Metodo08.
Teste: ok
*/
void metodo8 ()
{
// definir dado
   double soma = 0.0;
// identificar
   IO_id ( "EXEMPLO0508 - Metodo08 - v0.0" );
// chamar e receber resultado da funcao
   soma = somarFracaod ( 5 );
// mostrar resultado
   IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo8

/**
somarFracao2 - funcao para somar certa quantidade de fracoes.
@return soma dos valores
@param x - quantidade de valores a serem mostrados
*/
double somarFracao2 ( int x )
{
// definir dados locais
   double soma = 1.0;
   int y = 0 ; // controle
// mostrar primeiro valor
   IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma );
// repetir enquanto controle menor que a quantidade desejada
   for ( y = 1; y <= (x-1); y = y+1 )
   {
   // mostrar valor
      IO_printf ( "%d: %7.4lf/%7.4lf = %7.4lf\n",
         y+1, (2.0*y+1), (2.0*y), ((2.0*y+1)/(2.0*y)) );
   // somar valor
      soma = soma + (2.0*y+1)/(2.0*y);
   } // fim se
// retornar resultado
   return ( soma );
} // fim somarFracao2 ( )

/**
Metodo09.
Teste:ok
*/

void metodo9 ()
{
// definir dado
   double soma = 0.0;
// identificar
   IO_id ( "EXEMPLO0509 - Metodo09 - v0.0" );
// chamar e receber resultado da funcao
   soma = somarFracao2 ( 5 );
// mostrar resultado
   IO_printf ( "soma de fracoes = %lf\n", soma );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo9

/**
multiplicarValores - funcao para multiplicar certa quantidade de valores pares.
@return produto de valores
@param x - quantidade de valores
*/
int multiplicarValores ( int x )
{
// definir dados locais
   int produto = 1;
   int y = 0; // controle
// repetir enquanto controle menor que a quantidade desejada
   for ( y = 1; y <= x; y = y+1 )
   {
   // mostrar valor
      IO_printf ( "%d: %d\n", y, (2*y-1) );
   // somar valor
      produto = produto * (2*y-1);
   } // fim se
// retornar resultado
   return ( produto );
} // fim multiplicarValores ( )

/**
Metodo10.
Teste:ok
*/
void metodo10 ()
{
// identificar
   IO_id ( "EXEMPLO0510 - Metodo10 - v0.0" );
// mostrar produto de valores
   IO_printf ( "%s%d\n", "produto = ", multiplicarValores ( 5 ) );
// encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}//fim metodo10


/*
EXEMPLO0511 - METODO11
Objetivos: Incluir função e método em um programa (Exemplo0511) para:
para ler uma quantidade inteira do teclado e, mediante um método,
mostrar essa quantidade em valores múltiplos de 2 em ordem crescente.
Testes: 20 (ok); 21 (ok); 33 (ok);
*/

void f_11 (int x)
{
   int y=2;
   int i =0;
   while (y<=x)
   {
    
      printf("\n%d",y);
      y=y+2;
   }
}//fim f_11

void metodo11 ()
{
// identificar
   IO_id ( "EXEMPLO0511 - Metodo10 - v0.0" );
//declarar variaveis
   int q=0;
//inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
// outputs
   printf("\n%s%d\n%s", "Quantidade: ", q, "Multiplos de 2: ");
   f_11(q);

// encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}// fim metodo11


/*
E0512 - METODO12
Objetivos: Incluir função e método em um programa (Exemplo0512) para:
para ler uma quantidade inteira do teclado e, mediante um método
mostrar essa quantidade em valores pares múltiplos de 3 em ordem crescente.
Testes: 20 (ok); 18 (ok); 36 (ok)
*/

void f_12 (int x)
{
   int y =0;
   for (y=1; y<=x; y++)
   {
      if (y%6==0)
      {
         printf("\n%d", y);
      }//fimif
   }//fimfor
}//fim f_12

void metodo12 ()
{
// identificar
   IO_id ( "EXEMPLO0512 - Metodo10 - v0.0" );
 //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
// outputs
   printf("\n%s%d\n%s", "Quantidade: ", q, "Multiplos de 2: ");
   f_12(q);
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
ED0513 - Metodo13
Incluir função e método em um programa (Exemplo0513) para:
para ler uma quantidade inteira do teclado e, mediante um método,
mostrar essa quantidade em valores ímpares múltiplos de 3 em ordem decrescente.
Testes: 55 (ok); 20 (ok); 13 (ok);

*/
void f_13 (int x)
{
   int y =0;
   for (y=x; y>=3; y--)
   {
      if (y%3==0 && y%2!=0)
      {
         printf("\n%d", y);
      }//fimif
   }//fimfor
}

void metodo13 ()
{
   // identificar
   IO_id ( "EXEMPLO0513 - Metodo10 - v0.0" );
 //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
// outputs
   printf("\n%s%d\n%s", "Quantidade: ", q, "Multiplos de 3 pares: ");
   f_13(q);
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
Incluir função e método em um programa (Exemplo0514) para:
para ler uma quantidade inteira do teclado e, mediante um método,
mostrar essa quantidade em valores crescentes nos denominadores
(sequência dos inversos) múltiplos de 2: 1/2 1/4 1/6 1/8 1/10 ...
Teste: 10 (ok); 20 (ok); 15 (ok); 1 (0k);
*/
void f_14 (int x)
{
   int denom=2;
   while (denom<=x)
   {
      printf("\n1/%d", denom);
      denom=denom+2;
   }
}

void metodo14 ()
{
// identificar
   IO_id ( "EXEMPLO0514 - Metodo10 - v0.0" );
   //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
// outputs
   printf("\n%s%d\n%s", "Quantidade: ", q, "Inversos multiplos de 2: ");
   f_14(q);   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
Incluir função e método em um programa (Exemplo0515) para:
para ler um valor real real (x) do teclado;
para ler uma quantidade inteira do teclado e, mediante um método,
mostrar essa quantidade em valores crescentes nos denominadores
da sequência: 1 1/x 1/x2 1/x3 ...
DICA: Usar da biblioteca <math.h> a função pow ( x, y ) para calcular a potência.
Teste: 0,3 e 5(ok);  5,5 e 4 (ok);
*/

void f_15 (double R, int x)
{
   double j =R;
   int n=0;
   for (n=0; n<=x; n++)
   {
      j= pow(R, (-n));
      printf("\n n= %d - 1/(%lf^%d) = %lf", n, R, n, j);
   }
}

void metodo15 ()
{
// identificar
   IO_id ( "EXEMPLO0515 - Metodo10 - v0.0" );
   //declarar variaveis
   int q=0;
   double r =0;
   //inputs
   printf("\n%s", "Insira um numero real: ");
   scanf("%lf", &r);
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
    // outputs
   printf("\n%s%d\n%s", "Quantidade: ", q, "Multiplos de 2: ");
   f_15(r, q);   
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
06.) Incluir função e método em um programa (Exemplo0516) para
calcular a soma dos primeiros valores pares positivos começando em 2
e não múltiplos de 5.
Testar essa função para quantidades diferentes.
Teste: 10 (ok), 11 (ok), 25 (ok)
*/

void f_16 (int x)
{
   int y=0;
   int soma=2;
   for (y=4; y<=x; y++)
   {
      if (y%5!=0 && y%2==0)
      {
         printf ("\n soma = %d", soma);
         soma = soma+ y;
         printf (" + %d = %d", y, soma);
      }//fim if
   }//fim for
}

void metodo16 ()
{
// identificar
   IO_id ( "EXEMPLO0516 - Metodo10 - v0.0" );
     //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
    // outputs
   printf("\n%s%d\n%s", "Quantidade: ", q, "Soma pares nao divisiveis por 5: ");
   f_16(q);  
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
Incluir função e método em um programa (Exemplo0517) para
calcular a soma dos inversos (1/x) dos primeiros valores pares positivos,
começando em 2 e não múltiplos de 5.
Testar essa função para quantidades diferentes.
teste: 20 (ok), 15 (ok)
*/

int f_17 (int x)
{
   int y=2;
   double soma=(1.0/2.0);
   printf ("\n soma = 1/%d = %lf", y, soma);
   for (y=4; y<=x; y++)
   {
      if (y%5!=0 && y%2==0)
      {
         printf ("\n soma = %lf", soma);
         soma = soma+ (1.0/y);
         printf (" + 1/%d = %lf", y, soma);
      }//fim if
   }//fim for
}

void metodo17 ()
{
// identificar
   IO_id ( "EXEMPLO0517 - Metodo10 - v0.0" );
        //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
    // outputs
   printf("\n%s%d\n%s", "Quantidade: ", q, "Soma pares nao divisiveis por 5: ");
   f_17(q);  
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
Incluir função e método em um programa (Exemplo0518) para
calcular a soma dos primeiros números naturais começando em 1.
Testar essa função para quantidades diferentes de valores.
Testes: 5 (ok), 10 (ok)
*/

int f_18 (int x)
{
   int soma =0;
   int y=1;
   while (y<=x)
   {
      printf ("\n%d+%d=", soma, y);
      soma = soma + y;
      printf ("%d",soma);
      y=y+1;
   }
   return (soma);
}

void metodo18 ()
{
// identificar
   IO_id ( "EXEMPLO0518 - Metodo10 - v0.0" );
         //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
    // outputs
   printf("\n%s%d\n%s%d", "Quantidade: ", q, "Soma dos inteiros: ", f_18(q)); 
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
Incluir função e método em um programa (Exemplo0519) para
calcular a soma dos quadrados dos primeiros números naturais começando em 1.
Testar essa função para quantidades diferentes de valores.
Teste: 5 (ok); 
*/
int f_19 (int x)
{
   int soma =5;
   int y=3;
   printf("1 + 2^2 = 5");
   while (y<=x)
   {
      printf ("\n%d + (%d^2)=", soma, y);
      soma = soma + (y*y);
      printf ("%d",soma);
      y=y+1;
   }
   return (soma);

}

void metodo19 ()
{
// identificar
   IO_id ( "EXEMPLO0519 - Metodo10 - v0.0" );
       //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
   if (q<0)
   {
      q=q*(-1);
      printf("Valor negativo. Sera considerado o modulo\n");
   }
    // outputs
   printf("\n%s%d\n%s%d", "Quantidade: ", q, "Soma dos quadrados: ", f_19(q)); 
   

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
Incluir função e método em um programa (Exemplo0520) para
calcular a soma dos inversos dos primeiros números naturais começando em 1.
Testar essa função para quantidades diferentes de valores.
Teste: 5 (ok)
*/

double f_20 (int x)
{
   int y=1;
   double soma=1.0;
   printf ("\n soma = 1/%d = %lf", y, soma);
   for (y=2; y<=x; y++)
   {
      printf ("\n soma = %lf", soma);
      soma = soma + (1.0/y);
      printf (" + 1/%d = %lf", y, soma);
   }//fim for
   return (soma);
}

void metodo20 ()
{
// identificar
   IO_id ( "EXEMPLO0520 - Metodo10 - v0.0" );
    //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
   if (q<0)
   {
      q=q*(-1);
      printf("Valor negativo. Sera considerado o modulo\n");
   }
    // outputs
   printf("\n%s%d\n%s%lf", "Quantidade: ", q, "Soma dos inversos: ", f_20(q));    
 
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}

/*
Incluir função e método em um programa (Exemplo0521)
para ler um número inteiro do teclado e,
mediante o uso da função, calcular e mostrar o fatorial desse valor:
n! = n * (n-1) * (n-2) * ... * 3 * 2 * 1 se n>0
teste: 7 (ok). 5 (ok), -5 (ok)
*/

int f_21 (int x)
{
   int y=0;
   int fatorial=1;
   for (y=x; y>=1; y--)
   {
      fatorial=fatorial*y;
   }
   return (fatorial);
}

void metodo21 ()
{
// identificar
   IO_id ( "EXEMPLO0521 - Metodo10 - v0.0" );
      //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
   if (q<0)
   {
      q=q*(-1);
      printf("Valor negativo. Sera considerado o modulo\n");
   }
    // outputs
   printf("\n%s%d\n%s%d", "Quantidade: ", q, "Fatorial: ", f_21(q));    
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

/*
Incluir função e método em um programa (Exemplo0522)
para ler uma quantidade inteira do teclado e,
mediante o uso da função, calcular e mostrar o resultado de
f ( n ) = (1+2/3!) * (1+3/4!) * (1+4/5!) * ...
teste: 1 (ok), 2 (ok), 3 (ok), 4 (ok)
*/
double f_22 (int x)
{
double f=1;
int y= 1;
for (y=1; y<=x; y++)
{
f= f*(1+((double)(y+1)/(f_21(y+2))));
printf("\n%lf", f);
} 
return f;
}

void metodo22 ()
{
// identificar
   IO_id ( "EXEMPLO0522 - Metodo10 - v0.0" );
     //declarar variaveis
   int q=0;
   //inputs
   printf("\n%s", "Insira uma quantidade: ");
   scanf("%d", &q);
   if (q<0)
   {
      q=q*(-1);
      printf("Valor negativo. Sera considerado o modulo\n");
   }
    // outputs
   printf("\n%s%d\n%s%lf", "Quantidade: ", q, "Funcao: ", f_22(q));   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );

}

// MAIN
int main ()
{
//declarar variavel
   int x=0;
   do
   {
      printf ("\n%s", "Escolha o exercÃ­cio: ");
      printf ("\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s", 
         "0- PARAR","1 - EX01", "2 - EX02","3 - EX03", "4 - EX04", "5 - EX05",
         "6 - EX06","7 - EX07","8 - EX08","9 - EX09","10 - EX10",
         "11 - EX11","12 - EX12","13 - EX13","14 - EX14","15 - EX15",
         "16 - EX16","17 - EX17","18 - EX18","19 - EX19","20 - EX20",
         "21 - EX21","22 - EX22");
        
   
   
   // input
      printf("\n%s", "Entrar com um valor: ");
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
               metodo3();
               break;
            }
         case 4:
            {
               metodo4();
               break;
            }
         case 5:
            {
               metodo5();
               break;
            }
         case 6:
            {
               metodo6();
               break;
            }
         case 7:
            {
               metodo7();
               break;
            }
         case 8:
            {
               metodo8();
               break;
            }
         case 9:
            {
               metodo9();
               break;
            }
         case 10:
            {
               metodo10();
               break;
            }
         case 11:
            {
               metodo11();
               break;
            }
         case 12:
            {
               metodo12();
               break;
            }
         case 13:
            {
               metodo13();
               break;
            }
         
         case 14:
            {
               metodo14();
               break;
            }
         case 15:
            {
               metodo15();
               break;
            }
         case 16:
            {
               metodo16();
               break;
            }
         case 17:
            {
               metodo17();
               break;
            }
         case 18:
            {
               metodo18();
               break;
            }
         case 19:
            {
               metodo19();
               break;
            }
         case 20:
            {
               metodo20();
               break;
            }
         case 21:
            {
               metodo21();
               break;
            }
         case 22:
            {
               metodo22();
               break;
            }
         default:
            {
               printf("\n%s\n", "Valor inserido fora do intervalo [0,22]");
               IO_pause ( "Apertar ENTER para retornar" );
               break;
            }
      }//fim switch
   
   }//fim do
   while (x!=0);
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );   
        
}//fim MAIN