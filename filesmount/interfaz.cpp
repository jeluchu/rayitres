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
  char posicion_1='1',posicion_2='2',posicion_3='3',posicion_4='4',posicion_5='5',posicion_6='6',posicion_7='7',posicion_8='8',posicion_9='9',tiro,marca,respuesta='y';

  do{

       error=1;

       system("clear");

       system("toilet -fpagga RAYITRES\n");

       printf("┏━━━┳━━━┳━━━┓\n");
       printf("┃ %c ┃ %c ┃ %c ┃\n",posicion_1,posicion_2,posicion_3);
       printf("┣━━━╋━━━╋━━━┫\n");
       printf("┃ %c ┃ %c ┃ %c ┃\n",posicion_4,posicion_5,posicion_6);
       printf("┣━━━╋━━━╋━━━┫\n");
       printf("┃ %c ┃ %c ┃ %c ┃\n",posicion_7,posicion_8,posicion_9);
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

       if (tiro=='1' && posicion_1=='1') {posicion_1=marca;}
       else if (tiro=='2' && posicion_2=='2') {posicion_2=marca;}
       else if (tiro=='3' && posicion_3=='3') {posicion_3=marca;}
       else if (tiro=='4' && posicion_4=='4') {posicion_4=marca;}
       else if (tiro=='5' && posicion_5=='5') {posicion_5=marca;}
       else if (tiro=='6' && posicion_6=='6') {posicion_6=marca;}
       else if (tiro=='7' && posicion_7=='7') {posicion_7=marca;}
       else if (tiro=='8' && posicion_8=='8') {posicion_8=marca;}
       else if (tiro=='9' && posicion_9=='9') {posicion_9=marca;}
       else {printf("¡Error! Este movimiento no está permitido\n"); error=2;}

       if(posicion_1=='X'||posicion_1=='O')

       {

         if(posicion_2==posicion_1&&posicion_3==posicion_1)
          {
           ganar=1;
          }

         if(posicion_4==posicion_1&&posicion_7==posicion_1)
          {
           ganar=1;
          }
       }

       if(posicion_5=='X'||posicion_5=='O')
       {
                if (posicion_1 == posicion_5 && posicion_9 == posicion_5)
                        {ganar=1;}
                if (posicion_2 == posicion_5 && posicion_8 == posicion_5)
                        {ganar=1;}
                if (posicion_4 == posicion_5 && posicion_6 == posicion_5)
                        {ganar=1;}
                if (posicion_3 == posicion_5 && posicion_7 == posicion_5)
                        {ganar=1;}
         }

       if(posicion_9=='X'||posicion_9=='O')
       {
                  if (posicion_6 == posicion_9 && posicion_3 == posicion_9)
                          {ganar=1;}
                  if (posicion_7 == posicion_9 && posicion_8 == posicion_9)
                         {ganar=1;}
       }

       if ((posicion_1 != '1' && posicion_2 != '2' && posicion_3 != '3' &&
           posicion_4 != '4' && posicion_5 != '5' && posicion_6 != '6' &&
           posicion_7 != '7' && posicion_8 != '8' && posicion_9 != '9') &&
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
               printf("┃ %c ┃ %c ┃ %c ┃\n", posicion_1,posicion_2,posicion_3);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n", posicion_4,posicion_5,posicion_6);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n", posicion_7,posicion_8,posicion_9);
               printf("┗━━━┻━━━┻━━━┛\n");
           }

           if (empate==1)
           {
               printf("Empate %c!\n", jugador);
               printf("┏━━━┳━━━┳━━━┓\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n",posicion_1,posicion_2,posicion_3);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n",posicion_4,posicion_5,posicion_6);
               printf("┣━━━╋━━━╋━━━┫\n");
               printf("┃ %c ┃ %c ┃ %c ┃\n",posicion_7,posicion_8,posicion_9);
               printf("┗━━━┻━━━┻━━━┛\n");
           }

           printf("¿Quieres jugar de nuevo? (Y/N): ");
           scanf(" %c", &respuesta);

           if (respuesta=='y'||respuesta=='Y')
           {
                   empate=0;
                   jugador=2;
                   ganar=0;
                   posicion_1='1';
                   posicion_2='2';
                   posicion_3='3';
                   posicion_4='4';
                   posicion_5='5';
                   posicion_6='6';
                   posicion_7='7';
                   posicion_8='8';
                   posicion_9='9';
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
