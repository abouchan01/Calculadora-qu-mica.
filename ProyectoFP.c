//BouCo
#include <stdio.h>
#include <stdlib.h>
#include<math.h> 		   	   //Usado para las operaciones de mas adelante
void R(void);   		   	//Función usada mas debajo.
int main ()
{
	int r = 1 , el;                //Declaración de variables enteras
    float h,i,j,a,b,c;             //Declaración de variables flotantes

  while (r == 1){  												  //En esta línea comenzamos el bucle, para que el programa se repita cuando el usuario lo desee.
    printf("Proyecto Final Fundamentos de Programación\nEl programa nos permite realizar de una manera mas rapida y eficiente los calculos requeridos en el laboratorio de química.\n");
    printf("Equilibrio Quimico\n");
    puts("Por favor, de las siguientes opciones dime que operacion quieres realizar\n\n\n");
    printf(" 1  Obtencion de H+\n");
    printf(" 2  Obtencion de Ka (constante de acidez)\n");
    printf("Electroquimica: Electrolisis de disoluciones acuosas y constante de avogadro\n");
    printf(" 3 Tranformacion de minutos a segundos\n");
    printf(" 4  Promedio del amperaje\n");
    printf(" 5  Obtencion de la carga\n");
    printf(" 6  Obtencion de la masa teorica en gramos de H2\n");
    printf(" 7 Calculo del modelo matematico de una entalpia\n");
    scanf("%d",&el);               //Guardamos en memoria la elección del usuario.

    switch (el){                                                   //Comenzamos a ver que opción eligieron y ejeutamos la operación deseada.

      case 1: 
        printf("Dame el valor de tu PH\n");
        scanf("\n%f",&a);                                             //Guardamos valor del pH
        j=a*(-1);
        b= pow(10,j);        									    //elevación 10 a la j
        system("cls");                            //Limpiar pantalla
        printf("\nElvalor de H+ es:%f \n",b);                         //Imprimimos el valor final.
      break;
      
      case 2: 
        printf("Dame el valor de tu PH\n");
        scanf("\n%f",&a);
        printf("Dame el valor de tu concentraci%cn inicial\n",224);
        scanf("\n%f",&i);
        j=a*-1;
        b= pow(10,j);
        c=(b*b);
        h=c/i;
        system("cls");
        printf("\nLa constante de acidez es:\n");
        printf("\n%f",h);
      break;
      
      case 3: 
        printf("Dame el valor de tu tiempo en minutos\n");
        scanf("\n%f",&a);
        j=a*60;
        system("cls");
        printf("\nEl tiempo en segundo es:%f S\n",j);
      break;
      
      case 4: 
        printf("Dame tu primer valor de amperaje\n");
        scanf("\n%f",&a);
        printf("Dame tu segundo valor de amperaje\n");
        scanf("\n%f",&b);
        j=a+b;
        i=j/2;
        system("cls");
        printf("\nEl promedio de tu amperaje es:%f A\n",i);
      break; 
      
      case 5: 
        printf("Dame el valor de tu tiempo, en segundos\n");
        scanf("\n%f",&a);
        printf("Dame el valor de tu amperaje, en ampers\n");
        scanf("\n%f",&b);
        i=a*b;
        system("cls");
        printf("\nLa carga es:%f C\n",i);
      break;
      
      case 6: 
        printf("Dame el valor de tu carga\n");
        scanf("\n%f",&a);
        i=(a*4)/(96484.484*4);
        printf("Recuerda que tu formula es\n");
        printf("n(g)=I(A)*(1(F)/96484.484)*(1(mol)/4(F)*(32(gO2)))\n");
        printf("\nLa carga es:%f g de H2\n",i);
      break;
      
      case 7: 
	       R();          //Ejecutar función R
        break;
      
      //En caso de que la opción dada no sea valida 
       default: printf("\n\nNo ha seleccionado ninguna opcion valida.");
      break;

    }
    //Asegurarse de querer repetir el programa
    printf("\n\nSi desea volver a utilizar el programa digite 1, de lo contrario, digite cualquier otro numero: ");
    scanf("%d", &r);
    system("cls");

}

system("cls");

printf("Gracias por utilizar el programa");
printf("\n\n");

system("pause");
system("pause");

return 0;
}



//En esta funcion usamos el método de mínimos cuadrados para encontrar la regresión lineal de una entalpía
void R(void)
{
		double Ti,T1,T2,T3,T4,T5,T6,a,b,c,d,e,f,Tsuma,m1,m2,m3,m4,m5,m6,Msuma,mt1,mt2,mt3,mt4,mt5,mt6,sumaMP,mp1,mp2,mp3,mp4,mp5,mp6,MPsuma,P,B;
	printf("Escriba la temperatura inicial de tu sistema en (grados C)\n");
	scanf("%lf",&Ti);
	printf("Escriba las 6 temperaturas finales obtenidas de tu sistema en (°C) separadas por enter \n");
	scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);
	T1=a-Ti;
	T2=b-Ti;
	T3=c-Ti;
	T4=d-Ti;
	T5=e-Ti;
	T6=f-Ti;
	Tsuma=T1+T2+T3+T4+T5+T6; //y
	printf("Escriba los 6 valores totales en gramos de CaCl2  que se le adicionaron al sistema, separados por enter\n");
	scanf("%lf%lf%lf%lf%lf%lf",&m1,&m2,&m3,&m4,&m5,&m6);
	Msuma=m1+m2+m3+m4+m5+m6;   //x
	    
	mt1=m1*T1;
    mt2=m2*T2;
    mt3=m3*T3;
    mt4=m4*T4;
    mt5=m5*T5;
    mt6=m6*T6;
    sumaMP=mt1+mt2+mt3+mt4+mt5+mt6; //xy
    
	mp1=pow(m1,2);
    mp2=pow(m2,2);
    mp3=pow(m3,2);
    mp4=pow(m4,2);
    mp5=pow(m5,2);
    mp6=pow(m6,2);
    MPsuma=mp1+mp2+mp3+mp4+mp5+mp6; //x2
    
	P=((6*sumaMP)-(Msuma*Tsuma))/((6*MPsuma)-(pow(Msuma,2))); //m
    B=((Tsuma*MPsuma)-(sumaMP*Msuma))/((6*MPsuma)-(pow(Msuma,2)));  //b
    printf("El modelo matematico de entalpia es:T(C)=%lf(C/g)m(g)+%lf(C)",P,B);
}
