#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define addressI2C 0x27 //Endereço obtido a partir do código anterior
#define BL 3
#define EN 2
#define RW 1
#define RS 0
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define col 16
#define lin 2

LiquidCrystal_I2C lcd(0x27, EN, RW, RS, D4, D5, D6, D7);

int Cursor = 16;
int inicioFrase, fimFrase = 0;
int tamanhoFrase = 0;
String frase = "Portal do Arduino: www.portaldoarduino.com.br";

void setup(){
  lcd.begin(col, lin);
  lcd.setBacklightPin(BL, POSITIVE);
  lcd.setBacklight(HIGH); //Luz de fundo ON
}

void loop(){
  lcd.setCursor(5,0);
  lcd.print("Lucas");
  lcd.setCursor(0,1);  
  lcd.print(frase.substring(inicioFrase,fimFrase));
  delay(200); //Velocidade do scroll. Menor = mais rápido.  
  rolagem();
  tamanhoFrase = frase.length();
  if(inicioFrase == tamanhoFrase){
    inicioFrase = 0;
    fimFrase = 0;
  }
}

void rolagem(){
  lcd.clear();
  if(inicioFrase == 0 && Cursor > 0){
    Cursor--;
    fimFrase++;
  } else if (inicioFrase == fimFrase){
    inicioFrase = 0;
    fimFrase = 0;
    Cursor = 16;
  } else if(fimFrase == frase.length() && Cursor == 0){
    inicioFrase++;
  } else {
    inicioFrase++;
    fimFrase++;
  }
}
