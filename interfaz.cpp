#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <complex.h>

#include "interfaz.h"

#define ROJO "\x1B[1;31m"
#define NORMAL "\x1B[0m"
#define AMARILLO "\x1B[1;33m"
#define VERDE "\x1B[1;32m"
#define AZUL "\x1B[1;34m"
#define NEGRITA "\x1B[1m"
#define AZULETE "\x1B[1;36m"

#define N 20

void barra(){

     system("clear");
     system("toilet --gay -fpagga CELUVITA\n\n");
     system("toilet -fpagga El juego de la vida\n");
     system("setterm -cursor off"); // OCULTA EL CURSOR
     sleep(2);

     for (int porcen  = 0; porcen <= 100; porcen++) {
          printf("\r");
            for (int progre = 0; progre <= porcen; progre++){
                 printf(AZUL "▬" NORMAL);
                 fflush(stdout);
                 usleep(100);
             }
      printf(AZUL "▶ " NORMAL NEGRITA"%i%%" NORMAL, porcen);
     }

     printf("\n\n");

     system("setterm -cursor on"); // MUESTRA EL CURSOR

}

void inicio(){

    system("setterm -cursor off"); // OCULTA EL CURSOR

    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);

    char output[128];
    strftime(output, 128, "%d/%m/%y a las %H:%M:%S", tlocal);

    system("clear");
    system("toilet --gay -fpagga RAYITRES\n\n");
    printf("\n");
    sleep(2);
    printf(AMARILLO "❱     Te damos la bienvenida ");
    printf("%s", getenv("USER"));
    printf("\n" NORMAL);
    sleep(1);
    printf(VERDE "❱     RAYITRES v1.0 · Versión 'ESTABLE'\n" NORMAL);
    sleep(1);
    printf(AZULETE "❱     Iniciada el %s\n" NORMAL,output);
    sleep(3);

    barra();
}

void jugadorDEF() {

  int jugador=1,error,empate=0,ganar=0;
  char c1='1',c2='2',c3='3',c4='4',c5='5',c6='6',c7='7',c8='8',c9='9',tiro,marca,respuesta='y';

  do{

       error=1;

       system("clear");

       system("toilet -fpagga RAYITRES\n");

       printf("┏━━━┳━━━┳━━━┓\n");
       printf("┃ %c ┃ %c ┃ %c ┃\n",c1,c2,c3);
       printf("┣━━━╋━━━╋━━━┫\n");
       printf("┃ %c ┃ %c ┃ %c ┃\n",c4,c5,c6);
       printf("┣━━━╋━━━╋━━━┫\n");
       printf("┃ %c ┃ %c ┃ %c ┃\n",c7,c8,c9);
       printf("┗━━━┻━━━┻━━━┛\n");


       if(jugador==1)
       {
        marca='X';
       }

       else
       {
        marca='O';
       }

       printf("Turno del Jugador %d\n",jugador);
       printf("\nEscribe la posicion donde colocas la ficha: ");

       fflush(stdin);

       scanf("%c",&tiro);

       if (tiro=='1' && c1=='1') {c1=marca;}
       else if (tiro=='2' && c2=='2') {c2=marca;}
       else if (tiro=='3' && c3=='3') {c3=marca;}
       else if (tiro=='4' && c4=='4') {c4=marca;}
       else if (tiro=='5' && c5=='5') {c5=marca;}
       else if (tiro=='6' && c6=='6') {c6=marca;}
       else if (tiro=='7' && c7=='7') {c7=marca;}
       else if (tiro=='8' && c8=='8') {c8=marca;}
       else if (tiro=='9' && c9=='9') {c9=marca;}
       else {printf("¡Error! Este movimiento no está permitido\n"); error=2;}

       if(c1=='X'||c1=='O')

       {

         if(c2==c1&&c3==c1)
          {
           ganar=1;
          }

         if(c4==c1&&c7==c1)
          {
           ganar=1;
          }
       }

       if(c5=='X'||c5=='O')
       {
                if (c1 == c5 && c9 == c5)
                        {ganar=1;}
                if (c2 == c5 && c8 == c5)
                        {ganar=1;}
                if (c4 == c5 && c6 == c5)
                        {ganar=1;}
                if (c3 == c5 && c7 == c5)
                        {ganar=1;}
         }

       if(c9=='X'||c9=='O')
       {
                  if (c6 == c9 && c3 == c9)
                          {ganar=1;}
                  if (c7 == c9 && c8 == c9)
                         {ganar=1;}
       }

       if ((c1 != '1' && c2 != '2' && c3 != '3' &&
           c4 != '4' && c5 != '5' && c6 != '6' &&
           c7 != '7' && c8 != '8' && c9 != '9') &&
           ganar == 0)
       {
           empate=1;
       }

       if (ganar==1||empate==1)
       {
           system("clear");

           system("toilet -fpagga RAYITRES\n");
           printf("\n");

           if (ganar==1)
           {
               printf("Jugador: %d ¡GANA!\n\n", jugador);
               printf("┏━━━┳━━━┳━━━┓\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n", c1,c2,c3);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n", c4,c5,c6);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n", c7,c8,c9);
               printf("┗━━━┻━━━┻━━━┛\n");
           }

           if (empate==1)
           {
               printf("Empate %c!\n", jugador);
               printf("┏━━━┳━━━┳━━━┓\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n",c1,c2,c3);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n",c4,c5,c6);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n",c7,c8,c9);
               printf("┗━━━┻━━━┻━━━┛\n");
           }

           printf("¿Quieres jugar de nuevo? (Y/N): ");
           scanf(" %c", &respuesta);

           if (respuesta=='y'||respuesta=='Y')
           {
                   empate=0;
                   jugador=2;
                   ganar=0;
                   c1='1';
                   c2='2';
                   c3='3';
                   c4='4';
                   c5='5';
                   c6='6';
                   c7='7';
                   c8='8';
                   c9='9';
           }
       }

       if(error==1){
           if (jugador==1){
            jugador=2;
           }else{
            jugador=1;
           }
       }

  }while(respuesta=='y'||respuesta=='Y');

}
