#include <Servo.h>

#define pin_garra 5
#define pin_base 2
#define pin_e1  11
#define pin_e2 4


Servo base;
Servo e1;
Servo e2;
Servo garra;

int temp = 500;
int corIdent;
int Qverde = 0;
int Qvermelho = 0;
int Qazul = 0;
int Choice=0;

void setup() {
  Serial.begin(9600);
  base.attach(pin_base);
  e1.attach(pin_e1);
  e2.attach(pin_e2);
  garra.attach(pin_garra);

  


  }

int estado = 0;

void loop() {
  // -------  Posição Inicial
  base.write(74);
  e1.write(79);
  e2.write(167);
  garra.write(7);
  delay(temp);
  

Serial.print(F("\nMenu (Choose option and press RETURN)\n"));
  Serial.print(F("\n 1 Vermelho = "));
  Serial.print(Qvermelho);
  Serial.print(F("\n 2 Azul = "));
  Serial.print(Qazul);
  Serial.print(F("\n 3 Verde = "));
  Serial.print(Qverde);
  Serial.print(F("\n 4 Ativar\n \n"));
  Choice = getChar();
  switch(Choice)
  {
    case '1': 
      Serial.println("Quantas peças do Vermelho");
      Qvermelho = getChar()-48;
      break;
    case '2':
    Serial.println("Quantas peças do azul");  
      Qazul = getChar()-48;
      break;
    case '3':  
    Serial.println("Quantas peças do Verde");
      Qverde = getChar()-48;
      
      break;
      case '4':  
     estado=1;
      break;
  }

  

  if (estado) {
    Serial.println("Ativado");
if(Qvermelho>0){
  for(int i=0;i<Qvermelho;i++){

    // ------- Abre garra
    garra.write(12);
    base.write(46);
    delay(temp);

    // -------- Sobe e Recua
    for (int pos = 150; pos >= 98; pos--) {
      
      e1.write(pos);
      e2.write(pos + 36);
      delay(50);
    }

    delay(200);

    //// -------- Avança e Abaixa
    //  e1.write(8);
    //  e2.write(15);
    //  delay(temp);
    //

    // ------- Fecha Garra
    garra.write(0);
    delay(temp);


    // -------- Sobe e Recua
    for (int pos = e1.read(); pos >= 51; pos--) {
      e1.write(pos);
      delay(15);
    }
    for (int pos = e2.read(); pos <= 179; pos++) {
      e2.write(pos);
      delay(15);
    }

    //// -------- Sobe
    //  e1.write(80);
    //  delay(temp);
    //
    //// -------- Recua
    //  e2.write(80);
    //  delay(temp);

    // -------- Avança e Abaixa
    for (int pos = e1.read(); pos >= 40; pos--) {
      e1.write(pos);
      delay(15);
    }

    for (int pos = e2.read(); pos <= 170; pos++) {
      e2.write(pos);
      delay(15);
    }

    // -------- Gira para a caixa
    // Red
      base.write(166);
      delay(2000);
     

    // ------- Abre garra
    garra.write(15);
    delay(temp);
}}
if(Qazul>0){
  for(int i=0;i<Qazul;i++){

    // ------- Abre garra
    garra.write(12);
    base.write(46);
    delay(temp);

    // -------- Sobe e Recua
    for (int pos = 150; pos >= 98; pos--) {
      
      e1.write(pos);
      e2.write(pos + 36);
      delay(50);
    }

    delay(200);

    //// -------- Avança e Abaixa
    //  e1.write(8);
    //  e2.write(15);
    //  delay(temp);
    //

    // ------- Fecha Garra
    garra.write(0);
    delay(temp);


    // -------- Sobe e Recua
    for (int pos = e1.read(); pos >= 51; pos--) {
      e1.write(pos);
      delay(15);
    }
    for (int pos = e2.read(); pos <= 179; pos++) {
      e2.write(pos);
      delay(15);
    }

    //// -------- Sobe
    //  e1.write(80);
    //  delay(temp);
    //
    //// -------- Recua
    //  e2.write(80);
    //  delay(temp);


    // -------- Avança e Abaixa
    for (int pos = e1.read(); pos >= 40; pos--) {
      e1.write(pos);
      delay(15);
    }

    for (int pos = e2.read(); pos <= 170; pos++) {
      e2.write(pos);
      delay(15);
    }

 
 
    // -------- Gira para a caixa
 

    // Blue
          base.write(136);
      delay(2000);
    

    // ------- Abre garra
    garra.write(15);
    delay(temp);
}}
if(Qverde>0){
  for(int i=0;i<Qverde;i++){

    // ------- Abre garra
    garra.write(12);
    base.write(46);
    delay(temp);

    // -------- Sobe e Recua
    for (int pos = 150; pos >= 98; pos--) {
      
      e1.write(pos);
      e2.write(pos + 36);
      delay(50);
    }

    delay(200);

    //// -------- Avança e Abaixa
    //  e1.write(8);
    //  e2.write(15);
    //  delay(temp);
    //

    // ------- Fecha Garra
    garra.write(0);
    delay(temp);


    // -------- Sobe e Recua
    for (int pos = e1.read(); pos >= 51; pos--) {
      e1.write(pos);
      delay(15);
    }
    for (int pos = e2.read(); pos <= 179; pos++) {
      e2.write(pos);
      delay(15);
    }

    //// -------- Sobe
    //  e1.write(80);
    //  delay(temp);
    //
    //// -------- Recua
    //  e2.write(80);
    //  delay(temp);

 


    // -------- Avança e Abaixa
    for (int pos = e1.read(); pos >= 40; pos--) {
      e1.write(pos);
      delay(15);
    }
for (int pos = e2.read(); pos <= 170; pos++) {
      e2.write(pos);
      delay(15);
    }

 

    // -------- Gira para a caixa

    // Green

      base.write(110);
      delay(2000);


    // ------- Abre garra
    garra.write(15);
    delay(temp);
}}
  estado = 0;
    Serial.println("Desativado");
  }

  delay(50);

}



char getChar()
// Wait for user to return a char over serial connection, returns uppercase version of any alpha char
{
  while (Serial.available() == 0)
    ;
  return(toupper(Serial.read()));
}
