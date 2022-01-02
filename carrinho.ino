#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3);

int readByte;

int flagL = 1;
int flagR = 1;
int flagF = 1;
int flagB = 1;

byte velocidadeMotoresDireita = 5;
byte velocidadeMotoresEsquerda = 6;

byte motoresDireitaFrente = 7;
byte motoresDireitaRe = 8;
byte motoresEsquerdaFrente = 12;
byte motoresEsquerdaRe = 13;

void setup() {

  bluetooth.begin(9600);

  pinMode(velocidadeMotoresDireita, OUTPUT);
  pinMode(velocidadeMotoresEsquerda, OUTPUT);
  pinMode(motoresDireitaFrente, OUTPUT);
  pinMode(motoresDireitaRe, OUTPUT);
  pinMode(motoresEsquerdaFrente, OUTPUT);
  pinMode(motoresEsquerdaRe, OUTPUT);

  analogWrite(velocidadeMotoresDireita, 0);
  analogWrite(velocidadeMotoresEsquerda, 0);
  digitalWrite(motoresDireitaFrente, LOW);
  digitalWrite(motoresDireitaRe, LOW);
  digitalWrite(motoresEsquerdaFrente, LOW);
  digitalWrite(motoresEsquerdaRe, LOW);

}

void loop() {

  if (bluetooth.available() > 0) {

    readByte = bluetooth.read();

    if (readByte == 'B' && (flagB) == 1) {
      
      re();

    }

    else if (readByte == 'B' && (flagB) == 0) {

      parar();

    } flagB = !flagB;

    if (readByte == 'F' && (flagF) == 1) {

      acelera();

    }

    else if (readByte == 'F' && (flagF) == 0) {

      parar();

    } flagF = !flagF;

    if (readByte == 'L' && flagL == 1) {

      esquerda();

    }

    else if (readByte == 'L' && flagL == 0) {

      parar();

    } flagL = !flagL;

    if (readByte == 'R' && flagR == 1) {

      direira();

    }

    else if (readByte == 'R' && flagR == 0) {

      parar();

    } flagR = !flagR;

  }

}

void acelera() {

  digitalWrite(motoresDireitaRe, LOW);
  digitalWrite(motoresEsquerdaRe, LOW);
  analogWrite(velocidadeMotoresDireita, 255);
  analogWrite(velocidadeMotoresEsquerda, 255);
  digitalWrite(motoresDireitaFrente, HIGH);
  digitalWrite(motoresEsquerdaFrente, HIGH);

}

void re() {

  digitalWrite(motoresDireitaFrente, LOW);
  digitalWrite(motoresEsquerdaFrente, LOW);
  analogWrite(velocidadeMotoresDireita, 255);
  analogWrite(velocidadeMotoresEsquerda, 2550);
  digitalWrite(motoresDireitaRe, HIGH);
  digitalWrite(motoresEsquerdaRe, HIGH);

}

void direira() {


  digitalWrite(motoresEsquerdaFrente, LOW);
  digitalWrite(motoresEsquerdaRe, LOW);
  digitalWrite(motoresDireitaRe, LOW);
  analogWrite(velocidadeMotoresEsquerda, LOW);
  analogWrite(velocidadeMotoresEsquerda, 255);
  digitalWrite(motoresEsquerdaFrente, HIGH);

}

void esquerda() {

  digitalWrite(motoresEsquerdaFrente, LOW);
  digitalWrite(motoresEsquerdaRe, LOW);
  digitalWrite(motoresDireitaRe, LOW);
  analogWrite(velocidadeMotoresEsquerda, LOW);
  analogWrite(velocidadeMotoresEsquerda, 255);
  digitalWrite(motoresEsquerdaRe, HIGH);

}

void parar() {

  digitalWrite(motoresDireitaRe, LOW);
  digitalWrite(motoresEsquerdaRe, LOW);
  analogWrite(velocidadeMotoresDireita, 0);
  analogWrite(velocidadeMotoresEsquerda, 0);
  digitalWrite(motoresDireitaFrente, LOW);
  digitalWrite(motoresEsquerdaFrente, LOW);

}