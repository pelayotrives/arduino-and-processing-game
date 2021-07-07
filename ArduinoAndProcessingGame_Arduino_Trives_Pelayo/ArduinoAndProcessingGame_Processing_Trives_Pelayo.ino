  // Código creado por Pelayo Trives para la PEC3 de la asignatura Diseño de interacción del Grado en Multimedia de la UOC.
  
  #define LED_VERDE 8 // Definiendo así el pin en el que está el LED ahorraremos tiempo.
  #define LED_ROJO  9 // Definiendo así el pin en el que está el LED ahorraremos tiempo.
  #define LED_AZUL 10 // Definiendo así el pin en el que está el LED ahorraremos tiempo.

  char lectura; // Guarda las lecturas de puerto serie recibidas.
  char instruccion; // Guarda las lecturas de puerto serie recibidas.
  char instruccion2; // Guarda las lecturas de puerto serie recibidas.
  char instruccionAnalog; // Guarda las lecturas del pin analógico recibidas.
  
  int state = 0; // Estado por defecto es 0.
  int puntuacion = 0; // Puntuación por defecto es 0.
  int errores = 0; // Errores por defecto es 0.
  int digiPin = 4; // Pin usado para el botón de las instrucciones.
  int digiPin2 = 2; // Pin usado para el otro botón.
  int potenciometro = 0; // Valor inicial del potenciometro.

  void setup() { // Solo una vez.
    
    Serial.begin(9600);   // inicializa el puerto serie

    pinMode(LED_VERDE, OUTPUT); // Pin 8 para el LED verde.     
    pinMode(LED_ROJO, OUTPUT); // Pin 9 para el LED rojo.     
    pinMode(LED_AZUL, OUTPUT); // Pin 10 para el LED azul.     
    digitalWrite(LED_VERDE, LOW); // Estado inicial de este LED.
    digitalWrite(LED_ROJO, LOW); // Estado inicial de este LED.
    digitalWrite(LED_AZUL, LOW); // Estado inicial de este LED.
    
  }
  
  void loop() { // Sucesión constante.

    potenciometro = analogRead(A0); // Estableceremos una variable llamada valorAnalogico, la cual será el pin A0 de nuestro Arduino, que usaremos para almacenar el valor de dicha clavija.
    
    float valorDigital = digitalRead(digiPin); // Estableceremos una variable llamada valorDigital, la cual será la lectura del pin digital 4 de nuestro Arduino, que usaremos para almacenar el valor de dicha clavija.
    float valorDigital2 = digitalRead(digiPin2); // Estableceremos una variable llamada valorDigital, la cual será la lectura del pin digital 2 de nuestro Arduino, que usaremos para almacenar el valor de dicha clavija.
  
    if (valorDigital == 0) { // Si el botón está apretado, es 0. Si no, es 1. Por lo que si está apretado...
      instruccion = 'X'; // Convertimos esta variable char en este caracter.
      delay(100); // Delay para evitar latencias.
      Serial.println(instruccion); // Pasamos el caracter al monitor serial.
    }
  
    if (valorDigital2 == 0) { // Si el botón está apretado, es 0. Si no, es 1. Por lo que si está apretado...
      instruccion2 = 'Q'; // Convertimos esta variable char en este caracter.
      delay(100); // Delay para evitar latencias.
      Serial.println(instruccion2); // Pasamos el caracter al monitor serial.
    }
  
    if (potenciometro >= 20 && potenciometro <= 100) { // Si los valores del potenciómetro están entre estos números...
      instruccionAnalog = 'V'; // Convertimos esta variable char en este caracter.
      delay(20); // Delay para evitar latencias.
      Serial.println(instruccionAnalog); // Pasamos el caracter al monitor serial.
    } else if (potenciometro >= 101 && potenciometro <= 350) { // Si los valores del potenciómetro están entre estos números...
      instruccionAnalog = 'B'; // Convertimos esta variable char en este caracter.
      delay(20); // Delay para evitar latencias.
      Serial.println(instruccionAnalog); // Pasamos el caracter al monitor serial.
    } else if (potenciometro >= 351 && potenciometro <= 700) { // Si los valores del potenciómetro están entre estos números...
      instruccionAnalog = 'N'; // Convertimos esta variable char en este caracter.
      delay(20); // Delay para evitar latencias.
      Serial.println(instruccionAnalog); // Pasamos el caracter al monitor serial.
    } else if (potenciometro >= 701 && potenciometro <= 1023) { // Si los valores del potenciómetro están entre estos números...
      instruccionAnalog = 'M'; // Convertimos esta variable char en este caracter.
      delay(20); // Delay para evitar latencias.
      Serial.println(instruccionAnalog); // Pasamos el caracter al monitor serial.
    }

    switch (state) { // Hacemos un switch (más eficaz que el if para este caso tan largo).
      
      case 0: // Caso inicial o por defecto.
        digitalWrite(LED_AZUL, LOW); // Estado inicial de este LED.
        digitalWrite(LED_ROJO, LOW); // Estado inicial de este LED.
        digitalWrite(LED_VERDE, LOW); // Estado inicial de este LED.
        if (Serial.available()) { // Si hay datos disponibles en el puerto serial...
          lectura = Serial.read(); // Almacenaremos en la variable "lectura" los caracteres que nos entren por el puerto serial, con lo que podríamos pasar a los siguientes casos...
          if (lectura == 'A') state = 1; // Si la lectura contiene este caracter, pasaremos a este caso.
          else if (lectura == 'F') state = 2; // Si la lectura contiene este caracter, pasaremos a este caso.
          else if (lectura == 'E') state = 3; // Si la lectura contiene este caracter, pasaremos a este caso.
          else if (lectura == 'W') state = 4; // Si la lectura contiene este caracter, pasaremos a este caso.
          else if (lectura == 'L') state = 5; // Si la lectura contiene este caracter, pasaremos a este caso.
          else state = 0; // Si no, se pasa al estado o caso 0.
        }
        
        break; // Salimos del caso.
  
      case 1: // Si la lectura es "A"...
      
        digitalWrite(LED_VERDE, HIGH); // El LED verde se enciende.
        delay(100); // Esperamos 100 ms.
        digitalWrite(LED_VERDE, LOW); // El LED verde se apaga.
        puntuacion++;
        state = 0; // Volvemos al estado o caso 0.
        
        break; // Salimos del caso.
  
      case 2: // Si la lectura es "F"...
      
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(100); // Esperamos 100 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        errores++;
        state = 0; // Volvemos al estado o caso 0.
        
        break; // Salimos del caso.

      case 3: // Si la lectura es "E"...
      
        digitalWrite(LED_AZUL, HIGH); // El LED azul se enciende.
        delay(100); // Esperamos 100 ms.
        digitalWrite(LED_AZUL, LOW); // El LED azul se apaga.
        state = 0; // Volvemos al estado o caso 0.
        
        break; // Salimos del caso.

      case 4: // Si la lectura es "W"...

        digitalWrite(LED_AZUL, HIGH); // El LED azul se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_AZUL, LOW); // El LED azul se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_VERDE, HIGH); // El LED verde se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_VERDE, LOW); // El LED verde se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_AZUL, HIGH); // El LED azul se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_AZUL, LOW); // El LED azul se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_VERDE, HIGH); // El LED verde se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_VERDE, LOW); // El LED verde se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_AZUL, HIGH); // El LED azul se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_AZUL, LOW); // El LED azul se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_VERDE, HIGH); // El LED verde se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_VERDE, LOW); // El LED verde se apaga.
        state = 0; // Volvemos al estado o caso 0.
        
        break; // Salimos del caso.

      case 5: // Si la lectura es "L"...
      
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, HIGH); // El LED rojo se enciende.
        delay(150); // Esperamos 150 ms.
        digitalWrite(LED_ROJO, LOW); // El LED rojo se apaga.
        state = 0; // Volvemos al estado o caso 0.
        
        break; // Salimos del caso.
    }
    
  }
