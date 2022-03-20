 
#include  <LiquidCrystal.h> /*# work to LCD*/
#include <Ticker.h> /* work to serial all times sensors variables */

/* AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/* 0b000 = B Bytes para el logo del sistema ------------------------------------------------------------------- */
byte One[8]={B11111,B10000,B10000,B10111,B10100,B10100,B10100,B10100,};
byte Two[8]={B11111,B00000,B00000,B00000,B00000,B00011,B00110,B00100,};
byte Three[8]={B11111,B00000,B00000,B00000,B00000,B00011,B00110,B00100,};
byte Four[8]={B11111,B00001,B00001,B11101,B00101,B00101,B00101,B00101,};
byte Five[8]={B10100,B10100,B10100,B10100,B10111,B10000,B10000,B11111,};
byte Six[8]={B00100,B01100,B11000,B00000,B00000,B00000,B00000,B11111,};
byte Seven[8]={B00100,B01100,B11000,B00000,B00000,B00000,B00000,B11111,};
byte Eight[8]={B00101,B00101,B00101,B00101,B11101,B00001,B00001,B11111,};
/* --------------------------------------------------------------------------------------------------------- */

const int pin_on = 6 ;
const int pin_led = 13 ;

int estado_on = HIGH;

// Funcion de lectura , impresion y transmision de Temperatura ------------------------------------------------
void function_temp(){
  unsigned int val1 = analogRead(A15);
  float temp1 = (val1 * 5.0) / 1024.0;     

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor( 10,1);
          lcd.print(" ");
          lcd.home();
          lcd.print("Temp1 ");
          lcd.setCursor ( 6 , 0);
          lcd.print(temp1);    
    }
  }

  if (estado_on == HIGH){
    delay(50);
    if(estado_on == HIGH){
      digitalWrite(pin_led,HIGH);
      lcd.clear();
      lcd.setCursor ( 2 , 1);
      lcd.print("Edit this MDF :v");
    }
  }
  Serial.println(temp1);
}
//-----------------------------------------------------
void function_temp2(){
  unsigned int val2 = analogRead(A14);
  float temp2 = (val2 * 5.0) / 1024.0;

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW) {
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 0 , 1);
          lcd.print("Temp2 ");
          lcd.setCursor ( 6 , 1);
          lcd.print(temp2);
    }
  }
   Serial.println(temp2); 
}
//-----------------------------------------------------
void function_temp3 (){
  unsigned int val3 = analogRead(A13);
  float temp3 = (val3 * 5.0) / 1024.0;
  
  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
        digitalWrite(pin_led,LOW);
        lcd.setCursor ( 0 , 2);
        lcd.print("Temp3 ");
        lcd.setCursor ( 6 , 2);
        lcd.print(temp3);
    }
  }
  Serial.println(temp3);
}
//-----------------------------------------------------
void function_temp4 (){
  unsigned int val4 = analogRead(A12);
  float temp4 = (val4 * 5.0) / 1024.0;
  
  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 0 , 3);
          lcd.print("Temp4 ");
          lcd.setCursor ( 6 , 3);
          lcd.print(temp4);
    }
  }
  Serial.println(temp4);
}
//-----------------------------------------------------
void function_temp5 (){
   unsigned int val5 = analogRead(A11);
  float temp5 = (val5 * 5.0) / 1024.0;
  
  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 0);
          lcd.print("Temp5 ");
          lcd.setCursor ( 17 , 0);
          lcd.print(temp5,1);
    }
  }
  Serial.println(temp5);
}
//-----------------------------------------------------
void function_temp6 (){
  unsigned int val6 = analogRead(A10);
  float temp6 = (val6 * 5.0) / 1024.0;

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 1);
          lcd.print("Temp6 ");
          lcd.setCursor ( 17 , 1);
          lcd.print(temp6,1);
    }
  }
  Serial.println(temp6);
}
//-----------------------------------------------------
void function_temp7 (){
  unsigned int val7 = analogRead(A9);
  float temp7 = (val7 * 5.0) / 1024.0;

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 2);
          lcd.print("Temp7 ");
          lcd.setCursor ( 17 , 2);
          lcd.print(temp7,1);
    }
  }
  Serial.println(temp7);
}
//-----------------------------------------------------
void function_temp8 (){
  unsigned int val8 = analogRead(A8);
  float temp8 = (val8 * 5.0) / 1024.0;

  if ( estado_on == LOW){
    delay(50);
    if(estado_on == LOW){
          digitalWrite(pin_led,LOW);
          lcd.setCursor ( 11 , 3);
          lcd.print("Temp8 ");
          lcd.setCursor ( 17 , 3);
          lcd.print(temp8,1); 
    }
  }
  Serial.println(temp8);
}
//-----------------------------------------------------
Ticker ticTemp1 ( function_temp ,  25);
Ticker ticTemp2 ( function_temp2 , 50);
Ticker ticTemp3 ( function_temp3 , 75);
Ticker ticTemp4 ( function_temp4 , 100);
Ticker ticTemp5 ( function_temp5 , 125);
Ticker ticTemp6 ( function_temp6 , 150);
Ticker ticTemp7 ( function_temp7 , 175);
Ticker ticTemp8 ( function_temp8 , 200);
//----------------------------------------------------------------------------------------------------------------
void setup()
{
  pinMode(pin_on , INPUT);
  pinMode(pin_led , OUTPUT);
  ticTemp1.start();
  ticTemp2.start();
  ticTemp3.start();
  ticTemp4.start();
  ticTemp5.start();
  ticTemp6.start();
  ticTemp7.start();
  ticTemp8.start();
  
  Serial.begin(9600);/* velocidad del puerto serie de 9600 baudios */
  delay(50); /* este patra evitar errores por instantaneadad en los datos del puerto  serie */
  
  lcd.begin(20, 4); /* INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 20X4 */
  lcd.home(); /* MOVER EL CURSOR A LA PRIMERA POSICION DE LA PANTALLA (0, 0) */
 
  lcd.createChar (1, One);
  lcd.createChar (2, Two);
  lcd.createChar (3, Three);
  lcd.createChar (4, Four);
  lcd.createChar (5, Five);
  lcd.createChar (6, Six);
  lcd.createChar (7, Seven);
  lcd.createChar (8, Eight);
   
  lcd.clear(); /*Inicializacion en blanco forzado, realmente limpia la pantalla */ 

  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.setCursor(0,1);
  lcd.write(byte(5));
  lcd.write(byte(6));
  lcd.write(byte(7));
  lcd.write(byte(8));

  lcd.setCursor ( 5, 1 );
  lcd.print("OnRuiso Art");
  lcd.setCursor ( 5, 2 );
  lcd.print("Unidad de");
  lcd.setCursor ( 3, 3 );
  lcd.print("Almacenamiento");

  int contador = 1;
  for (int i=0 ; i<5 ; i++){
    lcd.setCursor (19,4);
    lcd.print(contador);
    contador ++;
    delay(1000);
  }
  lcd.clear();
}

void loop()
{
  estado_on = digitalRead(pin_on);
  
  ticTemp1.update();
  ticTemp2.update();
  ticTemp3.update();
  ticTemp4.update();
  ticTemp5.update();
  ticTemp6.update();
  ticTemp7.update();
  ticTemp8.update();
}
