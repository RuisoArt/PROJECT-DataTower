
#include  <LiquidCrystal.h>

/* AQUI SE CONFIGURAN LOS PINES PARA LA COMUNICACION CON LA PANTALLA */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/* 0b000 Bytes para el logo del sistema ------------------------------------------------------------------- */
byte Uno[8]={
  0b00011111,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010001,
  0b00010001,
};
byte Dos[8]={
  0b00011111,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00011100,
  0b00011100,
};
byte Tres[8]={
  0b00011111,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
};
byte Cuatro[8]={
  0b00011111,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000000,
  0b00000111,
  0b00000111,
};
byte Cinco[8]={
  0b00011111,
  0b00000001,
  0b00000001,
  0b00000001,
  0b00000001,
  0b00000001,
  0b00010001,
  0b00010001,
};
byte Seis[8]={
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
};
byte Siete[8]={
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010001,
  0b00010001,
  0b00010001,
};
byte Ocho[8]={
  0b00000000,
  0b00001100,
  0b00011100,
  0b00011000,
  0b00011000,
  0b00010001,
  0b00010001,
  0b00010001,
};
byte Nueve[8]={
  0b00000001,
  0b00001101,
  0b00011101,
  0b00011001,
  0b00011001,
  0b00010001,
  0b00010001,
  0b00010001,
};
byte Dies[8]={
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
  0b00010001,
};
byte Ichi[8]={
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
};
byte Ni[8]={
0b00010001,
0b00010001,
0b00010001,
0b00010011,
0b00010011,
0b00010111,
0b00010110,
0b00010000,
};
byte San[8]={
0b00010001,
0b00010001,
0b00010001,
0b00000011,
0b00000011,
0b00000111,
0b00000110,
0b00000000,
};
byte Shi[8]={
0b00010001,
0b00010001,
0b00010001,
0b00000001,
0b00000001,
0b00000001,
0b00000001,
0b00000001,
};
byte Go[8]={
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
0b00010001,
};
byte Roku[8]={
0b00010001,
0b00010001,
0b00010000,
0b00010000,
0b00010000,
0b00010000,
0b00010000,
0b00011111,
};
byte Nana[8]={
0b00011100,
0b00011100,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00011111,
};
byte Hachi[8]={
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00011111,
};
byte Kyu[8]={
0b00000111,
0b00000111,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00000000,
0b00011111,
};
byte Ju[8]={
0b00010001,
0b00010001,
0b00000001,
0b00000001,
0b00000001,
0b00000001,
0b00000001,
0b00011111,
};
/* --------------------------------------------------------------------------------------------------------- */
void setup()
{
  lcd.begin(20, 4); /* INDICAMOS QUE TENEMOS CONECTADA UNA PANTALLA DE 16X2 */
  lcd.home(); /* MOVER EL CURSOR A LA PRIMERA POSICION DE LA PANTALLA (0, 0) */
  lcd.print("Hola Mundo"); /* IMPRIMIR "Hola Mundo" EN LA PRIMERA LINEA */
  lcd.setCursor ( 0, 1 ); /*/ MOVER EL CURSOR A LA SEGUNDA LINEA (1) PRIMERA COLUMNA (0) */
  lcd.print("OnRuiso Art"); /*IMPRIMIR OTRA CADENA EN ESTA POSICION */
  delay(1000); /* ESPERAR UN SEGUNDO */

  lcd.clear();
  
  lcd.createChar (1, Uno);
  lcd.createChar (2, Dos);
  lcd.createChar (3, Tres);
  lcd.createChar (4, Cuatro);
  lcd.createChar (5, Cinco);
  lcd.createChar (6, Seis);
  lcd.createChar (7, Siete);
  lcd.createChar (8, Ocho);
  lcd.createChar (9, Nueve);
  lcd.createChar (10, Dies);
  lcd.createChar (11,Ichi);
  lcd.createChar (12,Ni);
  lcd.createChar (13,San);
  lcd.createChar (14,Shi);
  lcd.createChar (15,Go);
  lcd.createChar (16,Roku);
  lcd.createChar (17,Nana);
  lcd.createChar (18,Hachi);
  lcd.createChar (19,Kyu);
  lcd.createChar (20,Ju);
  
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
  lcd.setCursor(0,1);
  lcd.write(byte(6));
  lcd.write(byte(7));
  lcd.write(byte(8));
  lcd.write(byte(9));
  lcd.write(byte(10));
  lcd.setCursor(0,2);
  lcd.write(byte(11));
  lcd.write(byte(12));
  lcd.write(byte(13));
  lcd.write(byte(14));
  lcd.write(byte(15));
  lcd.setCursor(0,3); 
  lcd.write(byte(16));
  lcd.write(byte(17));
  lcd.write(byte(18));
  lcd.write(byte(19));
  lcd.write(byte(20));
  
}

void loop()
{

}
