/*
 
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Proyecto Final 
   Dev: Hugo Alexander Reyes Veliz 
   Fecha: 5/24/2024
*/


#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>
#include <Wire.h> 

#define filas_teclado 4        // cantidad de filas que posee el teclado matricial.
#define columnas_teclado 4     // cantidad de columnas que posee el teclado matricial.
#define f1_teclado 5          
#define f2_teclado 6         
#define f3_teclado 13          
#define f4_teclado 0
#define c1_teclado 2
#define c2_teclado 3         
#define c3_teclado 4           
#define c4_teclado 1     
#define led1 A0
#define led2 A1
#define led3 A2
#define led4 A3
#define a_teclado 8
#define b_teclado 9
#define c_teclado 10
#define d_teclado 11
#define g_teclado 12


#define pin_servo 7
#define direccion_lcd 0x20    // Dirección I2C de la pantalla LCD (actualizada a 0x27 comúnmente usada)
#define filas 2                // Cantidad de filas que posee la pantalla LCD
#define columnas 16            // Cantidad de columnas que posee la pantalla LCD

char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
};

byte pines_filas[filas_teclado] = {f1_teclado, f2_teclado, f3_teclado, f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado, c2_teclado, c3_teclado, c4_teclado};
Keypad keypad = Keypad(makeKeymap(keys), pines_filas, pines_columnas, filas_teclado, columnas_teclado);

Servo miservo;
LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);  

int conteo = 0;
int posicion = 0;

  void displaySequence_1(){
  int pins[2] = {9,10};
  for (int i = 0; i < 2; i++) {
    digitalWrite(pins[i], HIGH);
  } 
  delay(1000);
  for (int i = 2; i >= 0; i--) {
    digitalWrite(pins[i], LOW);
  } 
  delay(1000);
}

void displaySequence_2() {
  int pins_1[5] = {8,9,10,11,12};
  for (int i = 0; i < 5; i++) {
    digitalWrite(pins_1[i], HIGH);
  } 
  delay(1000);
  for (int i = 5; i >= 0; i--) {
    digitalWrite(pins_1[i], LOW);
  } 
  delay(1000);
}

void displaySequence_3() {
  int pins_1[3] = {8,9,10};
  for (int i = 0; i < 3; i++) {
    digitalWrite(pins_1[i], HIGH);
  } 
  delay(1000);
  for (int i = 3; i >= 0; i--) {
    digitalWrite(pins_1[i], LOW);
  } 
  delay(1000);
}


void setup() {
  Serial.begin(9600);
 

  miservo.attach(pin_servo);
  miservo.write(0);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  
  lcd.init();
  lcd.backlight(); 
  lcd.setCursor(2,0);
  lcd.print("Hugo Reyes");
  lcd.setCursor(0,1);
  lcd.print("Proyecto Final");
  
 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
  
}


void loop() {
  char key = keypad.getKey();
  
  if (key == '1') {
    for (int i = 0; i < 100; i++) {
      conteo = i; 
      Serial.print(" ");
      Serial.println(conteo);
      delay(200);
    }
  }
  
  if (key == '2') {
    for (int i = 99; i >= 0; i--) {
      conteo = i;
      Serial.print(" ");
      Serial.println(conteo);
      delay(200);
    }
  }
  
  if (key == '3') {
    int pines[] = {A0, A1, A2, A3}; 
    int time = 500;
    
    for (int p = 0; p < 4; p++) {
      digitalWrite(pines[p], HIGH);
      delay(time);
      digitalWrite(pines[p], LOW);
      delay(time);
    }  
    
    for (int p = 3; p >= 0; p--) {
      digitalWrite(pines[p], HIGH);
      delay(time);
      digitalWrite(pines[p], LOW);
      delay(time);
    }
  }
  
   if (key == '4') {
    displaySequence_1();
    displaySequence_2();
    displaySequence_3();
   }
  
  if (key == '5') {
    for (posicion = 0; posicion <= 180; posicion++) {
      miservo.write(posicion);
      delay(20);
    }
    
    for (posicion = 180; posicion > 0; posicion--) {
      miservo.write(posicion);
      delay(20);
    }
  }
}
