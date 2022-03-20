 
#include  <LiquidCrystal.h> /*# work to LCD*/
#include <Ticker.h> /* work to serial all times sensors variables */

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);/* AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA */

#define PIN_MOC 22 /* Este pin corresponde a la conmutacion general de data tower*/

/*En esta seccion se crean las variables que guardaran os bits para dibujar el logo
 * 0b000 = B Bytes para el logo del sistema  */
  byte One[8]={B11111,B10000,B10000,B10111,B10100,B10100,B10100,B10100,};
  byte Two[8]={B11111,B00000,B00000,B00000,B00000,B00011,B00110,B00100,};
  byte Three[8]={B11111,B00000,B00000,B00000,B00000,B00011,B00110,B00100,};
  byte Four[8]={B11111,B00001,B00001,B11101,B00101,B00101,B00101,B00101,};
  byte Five[8]={B10100,B10100,B10100,B10100,B10111,B10000,B10000,B11111,};
  byte Six[8]={B00100,B01100,B11000,B00000,B00000,B00000,B00000,B11111,};
  byte Seven[8]={B00100,B01100,B11000,B00000,B00000,B00000,B00000,B11111,};
  byte Eight[8]={B00101,B00101,B00101,B00101,B11101,B00001,B00001,B11111,};


const int pin_on = 6 ;
const int pin_led = 13 ;
int estado_on = HIGH;

/* ---------------------------------------------------------------- Funciones de lectura de los sensores de forma independiente y escritura en LCD -------------------------------------------------------------------------------------- */


float sensitive = 0.185; /* sensibilidad del sensor de corriente, esta se da en V/A */
/*
 * Si tenemos un sensor de nA tendremos una sensibilidad de n Voltios por Amperio
 * 5A -> 185 mV/A  -> 0.185 v/A
 * 20A -> 100 mV/A -> 0.100 v/A
 * 30A -> 66 mV/A -> 0.066 v/A
 * 
 * siendo m a sensiblidad
 * 
 * V = I*m + 2.5 
 * 
 * despejando la ecuacion queda
 * 
 * I = (v - 2.5)/m
*/

/* cada una de las siferentes funciones, salvo la recursiba de corriente (obtenerCorriente), poseen una logica On/Off , donde dependiendo del estado en "High" o en "Low" de la variable de entrada "estado_on" 
 *  cambiara entre la pantalla de la lcd 1 y la pantalla de la lcd 2 , donde se mostrara la lectura de los sensores de temperatura y el consumo electrico respectivamente
 */
 
/*-------------------- Funcion de la obtener corriente---------------------- */
float obtenerCorriente(){
  float voltajeSensor;
  float corriente = 0;
  float voltaje = 0;
  float current = 0;
  long tiempo = millis();
  float Imax = 0;
  float Imin = 0;

  while((millis() - tiempo) < 25)
  {
    voltaje = analogRead(A7);
    voltajeSensor = voltaje * (5.0 / 1023.0); /*lectura del dato de corriente*/

    current = ( (voltajeSensor-2.5)/sensitive );
    /*Debido a la contruccion del mismo sensor se obtienen lecturas oscilantes de una misma medida por tal razon se aplica un filtro pasa bajos*/
    corriente = 0.9*corriente+0.1*current; /*Ecuacion para obtener corriente*/

    if(corriente>Imax){      Imax = corriente;    }
    if(corriente<Imin){      Imin = corriente;    }

  }
  return ( (Imax-Imin)/2 ); /* retorna la corriente pico del sensor */
}
/*-------------------- Funcion current 1 ---------------------- */
/* Se deja la visualizacion en la lcd en una sola funcion pero la transmision serial de cada variable de corriente por aparte debido a problemas con el refrescamiento en la lcd */
void function_current_1(){
    float Ip = obtenerCorriente(); /*este valor es traido de la funcion de corriente que nos retorna la corriente pico */
    float Irms = Ip * 0.707; /* corriente RMS = Ipico / (2^{1/2})*/
    float p = Irms * 122.0; /* P = I*V formula de potencia dada en watts */
        
    if (estado_on == HIGH)/* si el estado es "HIGH" cambiara a "segunda pantalla" en lcd, esto es limpiar la lcd y mostrar la lectura de corriente*/
    {
      delay(50);
      if(estado_on == HIGH){
        digitalWrite(pin_led,HIGH);
        lcd.clear();

        lcd.setCursor ( 0 , 0); lcd.print("V "); 
        lcd.setCursor ( 6 , 0); lcd.print("122.00 VAc");
              
        lcd.setCursor ( 0 , 1); lcd.print("Ip "); 
        lcd.setCursor ( 8 , 1); lcd.print(Ip,2); lcd.print(" A");
        
        lcd.setCursor ( 0 , 2); lcd.print("Irms "); 
        lcd.setCursor ( 8 , 2); lcd.print(Irms,2); lcd.print(" A");
        
        lcd.setCursor ( 0 , 3); lcd.print("P "); 
        lcd.setCursor ( 8 , 3); lcd.print(p,2); lcd.print(" W");
      }
  }
  Serial.println("Ip," + String(Ip,2));
}
/*-------------------- Funcion current 2 ---------------------- */
void function_current_2(){
    float Ip = obtenerCorriente();     float Irms = Ip * 0.707;    float p = Irms * 122.0;

    Serial.println("Irms," + String(Irms,2));
}
/*-------------------- Funcion current 3 ---------------------- */
void function_current_3(){
    float Ip = obtenerCorriente();     float Irms = Ip * 0.707;     float p = Irms * 122.0; 

    Serial.println("P," + String(p,2));
}
/* ------------- funcion de Temperatura 1------------------------*/
void function_temp(){
  unsigned int val1 = analogRead(A15);
  float millivolts = (val1 / 1024.0) * 5000;
  float temp1 = millivolts / 10;     

  /* Se pregunta doblemente el estado para tener una lectura confiable de los sensores que no corresponda a sobre picos en los pines de entrada del arduino */
  
  if ( estado_on == LOW)/* Si el estado es "LOW" estara en "pantalla uno" , es decir mostrar en pantalla la lectura correspondiente a temperatura*/
    {
      delay(50);
      if(estado_on == LOW)    {
            digitalWrite(pin_led,LOW);
            
            lcd.setCursor( 8,0);            lcd.print("   ");/*tres espacios para en ves de borrar la pantalla LCD por boton, imprimir espacios para evitar refresco violento de medidas en la pantalla*/
            lcd.setCursor( 8,1);            lcd.print("   ");
            lcd.setCursor( 8,2);            lcd.print("   ");
            lcd.setCursor( 8,3);            lcd.print("   ");
            
            lcd.home();
            lcd.print("T1 ");
            lcd.setCursor ( 3 , 0);
            lcd.print(temp1,2);    
      }
    }
  Serial.println("T1," + String(temp1,2)); /* enviar el dato por puerto serial  */
}
/*---------- funcion temperatura 2 --------------------*/
void function_temp2(){
  unsigned int val2 = analogRead(A14);
  float millivolts_2 = (val2 / 1024.0) * 5000;
  float temp2 = millivolts_2 / 10;

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW) {
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 0 , 1);
          lcd.print("T2 ");
          lcd.setCursor ( 3 , 1);
          lcd.print(temp2,2);
    }
  }
   Serial.println("T2," + String(temp2,2)); 
}
/*---------- funcion temperatura 3 --------------------*/
void function_temp3 (){
  unsigned int val3 = analogRead(A13);
  float millivolts_3 = (val3 /1024.0)*5000;
  float temp3 = (millivolts_3/10);
  
  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
        digitalWrite(pin_led,LOW);
        lcd.setCursor ( 0 , 2);
        lcd.print("T3 ");
        lcd.setCursor ( 3 , 2);
        lcd.print(temp3,2);
    }
  }
  Serial.println("T3," + String(temp3,2));
}
/*---------- funcion temperatura 4 --------------------*/
void function_temp4 (){
  unsigned int val4 = analogRead(A12);
  float millivolts_4 = (val4/1024.0)*5000;
  float temp4 = (millivolts_4/10);
  
  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 0 , 3);
          lcd.print("T4 ");
          lcd.setCursor ( 3 , 3);
          lcd.print(temp4,2);
    }
  }
  Serial.println("T4," + String(temp4,2));
}
/*---------- funcion temperatura 5 --------------------*/
void function_temp5 (){
   unsigned int val5 = analogRead(A11);
   float millivolts_5 = (val5/1024.0)*5000;
   float temp5 = (millivolts_5/10);
  
  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 0);
          lcd.print("T5 ");
          lcd.setCursor ( 14 , 0);
          lcd.print(temp5,2);
    }
  }
  Serial.println("T5," + String(temp5,2));
}
/*---------- funcion temperatura 6 --------------------*/
void function_temp6 (){
  unsigned int val6 = analogRead(A10);
  float millivolts_6 = (val6 / 1024.0)*(5000);
  float temp6 = (millivolts_6 / 10);

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 1);
          lcd.print("T6 ");
          lcd.setCursor ( 14 , 1);
          lcd.print(temp6,2);
    }
  }
  Serial.println("T6," + String(temp6,2));
}
/*---------- funcion temperatura 7 --------------------*/
void function_temp7 (){
  unsigned int val7 = analogRead(A9);
  float millivolts_7 = (val7 / 1024.0)*(5000);
  float temp7 = (millivolts_7 / 10);

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 2);
          lcd.print("T7 ");
          lcd.setCursor ( 14 , 2);
          lcd.print(temp7,2);
    }
  }
  Serial.println("T7," + String(temp7,2));
}
/*---------- funcion temperatura 8 --------------------*/
void function_temp8 (){
  unsigned int val8 = analogRead(A8);
  float millivolts_8 = (val8 / 1024.0)*(5000);
  float temp8 = millivolts_8 / 10;

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 3);
          lcd.print("T8 ");
          lcd.setCursor ( 14 , 3);
          lcd.print(temp8,2); 
    }
  }
  Serial.println("T8," + String(temp8,2));
}
/*---------- crear una variable de tipo Ticker que inicie la funcion en un rango de tiempo dado en milisegundos --------------------*/
  Ticker ticTemp1 ( function_temp ,  50);
  Ticker ticTemp2 ( function_temp2 , 75);
  Ticker ticTemp3 ( function_temp3 , 100);
  Ticker ticTemp4 ( function_temp4 , 125);
  Ticker ticTemp5 ( function_temp5 , 150);
  Ticker ticTemp6 ( function_temp6 , 175);
  Ticker ticTemp7 ( function_temp7 , 200);
  Ticker ticTemp8 ( function_temp8 , 225);
  Ticker ticAmp1 ( function_current_1 , 250);
  Ticker ticAmp2 ( function_current_2 , 275);
  Ticker ticAmp3 ( function_current_3 , 300);

/*-------------------------------------------------------------------------------------------------- Configuracion Inicial del programa --------------------------------------------------------------------------------------------------*/
void setup()
{
  pinMode(PIN_MOC, OUTPUT); /* configurar el pin del accionador como pin de salida */
  digitalWrite(PIN_MOC , 0); /* iniciqliza el pin en apagado*/
  
  pinMode(pin_on , INPUT);
  pinMode(pin_led , OUTPUT);

  /*Inicializar las variable ( las funciones en un tiempo dado en milisegundos )*/
    ticTemp1.start();
    ticTemp2.start();
    ticTemp3.start();
    ticTemp4.start();
    ticTemp5.start();
    ticTemp6.start();
    ticTemp7.start();
    ticTemp8.start();
    ticAmp1.start();
    ticAmp2.start();
    ticAmp3.start();
  
  Serial.begin(9600);/* velocidad del puerto serie de 9600 baudios */
  delay(50); /* este patra evitar errores por instantaneadad en los datos del puerto  serie ( picos altos en el pin de entrada )*/
  
  lcd.begin(20, 4); /* INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 20X4 */
  lcd.home(); /* MOVER EL CURSOR A LA PRIMERA POSICION DE LA PANTALLA (0, 0) */

 /*Inicializar el dibujo en la pantalla*/
    lcd.createChar (1, One);
    lcd.createChar (2, Two);
    lcd.createChar (3, Three);
    lcd.createChar (4, Four);
    lcd.createChar (5, Five);
    lcd.createChar (6, Six);
    lcd.createChar (7, Seven);
    lcd.createChar (8, Eight);
   
  lcd.clear(); /*Inicializacion en blanco forzado, realmente limpia la pantalla */ 

  /* dibujar en la lcd el logo de OnRuiso */
    lcd.write(byte(1));
    lcd.write(byte(2));
    lcd.write(byte(3));
    lcd.write(byte(4));
    lcd.setCursor(0,1);
    lcd.write(byte(5));
    lcd.write(byte(6));
    lcd.write(byte(7));
    lcd.write(byte(8));

  /* Escribir en pantalla los mensajes correspondientes */
    lcd.setCursor ( 5, 1 );
    lcd.print("OnRuiso Art");
    lcd.setCursor ( 5, 2 );
    lcd.print("Unidad de");
    lcd.setCursor ( 3, 3 );
    lcd.print("Almacenamiento");

  /* inicializar un contador que se mostrara en pantalla (cuenta regresiba de 5 a 0) , esquina inferior derecha */
    int contador = 5;
    for (int i=5 ; i>=0 ; i--){
      lcd.setCursor (19,4);
      lcd.print(contador);
      contador --;
      delay(1000);
    }
    
   /*Limpiar la pantalla antes entrar a la lectura de los sensores y la transmision serial*/
   lcd.clear();
}

/* ---------------------------------------------------------------------------- While infinito, parte del programa que se va repitiendo, leer siempre el pin ---------------------------------------------------------------------------- */
String cadenaRecibida;
int valorMOC = 0;

void loop()
{
  /* Siempre estara preguntado por el estado del pin para cambiar de pantalla a pantalla
      Siempre estara subiendo las variables correspondientes, esto es , imprimir por pantalla y enviar el dato por comunicacion serial al equipo */
      
  estado_on = digitalRead(pin_on);
  
  ticTemp1.update();
  ticTemp2.update();
  ticTemp3.update();
  ticTemp4.update();
  ticTemp5.update();
  ticTemp6.update();
  ticTemp7.update();
  ticTemp8.update();
  ticAmp1.update();
  ticAmp2.update();
  ticAmp3.update();

  /* Recibe un String por comunicacion serial */
  if(Serial.available()) {
     /* guarda el dato recibido por comunicacion serial 
     y lo reenvia luego a python nuevamente para rectificar lo que se envio */
    cadenaRecibida = Serial.readString();
    valorMOC = cadenaRecibida.toInt();

    /* comprobacion del dato dado por monitor serie , para que no me coja todo+
     *  numero mayor a 0 como encendido, solamente un "1"
     *  Se debe luego comprobar que lo que se envie desde python sea un 
     *  ENTERO y no un string y este sea un UNO o un CERO
     */
    switch(valorMOC)
    {
      default:
          Serial.println("MCU N:" + cadenaRecibida);
          break;
       case 0:
          Serial.println("MCU 0:" + cadenaRecibida);
          digitalWrite(PIN_MOC,valorMOC);
          break;
       case 1:
          Serial.println("MCU 1:" + cadenaRecibida);
          digitalWrite(PIN_MOC,valorMOC);
          break;
    }
  }

  
}
