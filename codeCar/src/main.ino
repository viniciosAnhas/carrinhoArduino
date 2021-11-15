#include <Arduino.h>

byte inputs[] = {4, 5, 6, 7, 8, 9, 10, 11};
byte leds[] = {14, 15, 16, 17};

void setup() {
  
  for (int i = 0; i <= sizeof(inputs); i++){

      pinMode(inputs[i], OUTPUT);
      delay(15);

  }

  for (int i = 0; i <= sizeof(inputs); i++){

      digitalWrite(inputs[i], LOW);
      delay(15);

  }

  for (int i = 0; i <= sizeof(leds); i++){

      pinMode(leds[i], OUTPUT);
      delay(15);

  }

  for (int i = 0; i <= sizeof(leds); i++){

      digitalWrite(leds[i], LOW);
      delay(15);

  }

}

void loop() {

    // INICIO ACELERA

    for(int i = 0; i <= sizeof(inputs); i++){

        digitalWrite(inputs[i], LOW);
        delay(15);

    }

    for (int i = 0; i <= sizeof(leds); i++){

        digitalWrite(leds[i], LOW);
        delay(15);

    }

    digitalWrite(inputs[1], HIGH);
    digitalWrite(inputs[3], HIGH);

    digitalWrite(inputs[5], HIGH);
    digitalWrite(inputs[7], HIGH);

    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);

    delay(2000);

    // FIM ACELERA

    // INICIO ESQUERDA

    for(int i = 0; i <= sizeof(inputs); i++){

        digitalWrite(inputs[i], LOW);
        delay(15);

    }

    for (int i = 0; i <= sizeof(leds); i++){

        digitalWrite(leds[i], LOW);
        delay(15);

    }

    digitalWrite(inputs[1], HIGH);
    digitalWrite(inputs[3], HIGH);

    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);

    delay(2000);

    // FIM ESQUERDA

    // INICIO DIREITA

    for(int i = 0; i <= sizeof(inputs); i++){

        digitalWrite(inputs[i], LOW);
        delay(15);

    }

    for (int i = 0; i <= sizeof(leds); i++){

        digitalWrite(leds[i], LOW);
        delay(15);

    }

    digitalWrite(inputs[4], HIGH);
    digitalWrite(inputs[6], HIGH);

    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);

    delay(2000);

    // FIM DIREITA

    // INICIA RE
    
    for(int i = 0; i <= sizeof(inputs); i++){

        digitalWrite(inputs[i], LOW);
        delay(15);

    }

    for (int i = 0; i <= sizeof(leds); i++){

        digitalWrite(leds[i], LOW);
        delay(15);

    }

    digitalWrite(inputs[0], HIGH);
    digitalWrite(inputs[2], HIGH);

    digitalWrite(inputs[4], HIGH);
    digitalWrite(inputs[6], HIGH);

    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);

    delay(2000);

    // FIM RE

}