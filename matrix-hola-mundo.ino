
#define Linea_1 2
#define Linea_2 3
#define Linea_3 4
#define Linea_4 5
#define Linea_5 6
#define Linea_6 7
#define Linea_7 8
#define Linea_8 9

#define Columna_1 10
#define Columna_2 11
#define Columna_3 12
#define Columna_4 13
#define Columna_5 A0
#define Columna_6 A1
#define Columna_7 A2
#define Columna_8 A3

const byte  lineas[] = {
  Linea_1, Linea_2, Linea_3, Linea_4, Linea_5, Linea_6, Linea_7, Linea_8
};

const byte columnas[] = {
  Columna_1, Columna_2, Columna_3, Columna_4, Columna_5, Columna_6, Columna_7, Columna_8
};

byte ALL[] = {B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111, B11111111};
byte A[] = {B00000000, B00111100, B01100110, B01100110, B01111110, B01100110, B01100110, B01100110};

void setup() {
  // put your setup code here, to run once:

  for ( byte i = 2; i <= 13; i++ ) {
    pinMode(i, OUTPUT);
  }

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

}

void loop() {

  matrixLeds(A);

}

void matrixLeds(byte accion[]) {

  for ( byte i = 0; i < 8; i++ ) {

    digitalWrite(lineas[i], HIGH);

    for (byte a = 0; a < 8; a++ ) {
      digitalWrite(columnas[a], (~accion[i] >> a ) & 0x01 );

      delayMicroseconds(10);

      digitalWrite(columnas[a], 1);
    }

    digitalWrite(lineas[i], LOW);

  }


}
