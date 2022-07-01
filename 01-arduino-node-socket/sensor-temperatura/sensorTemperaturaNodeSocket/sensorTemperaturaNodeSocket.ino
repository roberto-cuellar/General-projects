// Entradas 
int sensorLuz = 15;
int inicioFinPulsador = 2, emergenciaPulsador = 3;
// Actuadores
int actuador1 = 49, actuador2 = 51, actuador3 = 53;
// Variables de Estado 
bool estado = false; // Inicia el proceso por defecto en false (NO SENSANDO)
int valSensor; // Variable para almacenar el valor 

void setup() {
  // Definición de entradas 
  pinMode(sensorLuz,INPUT);
  pinMode(inicioFinPulsador,INPUT_PULLUP);
  pinMode(emergenciaPulsador,INPUT);

  // Entrada mediante Interrupciones (Eventos en Js)

  // Definición de Actuadores
  pinMode(actuador1, OUTPUT);
  pinMode(actuador2, OUTPUT);
  pinMode(actuador3, OUTPUT);

  // Inicialización de los actuadores y de la lectura del sensor principal
  digitalWrite(actuador1,HIGH);
  digitalWrite(actuador2,HIGH);
  digitalWrite(actuador3,HIGH);
  valSensor = analogRead(sensorLuz);

  // Inicialización del puerto serial 
  Serial.begin(9600); 

  // Interrupciones
  // attachInterrupt(digitalPinToInterrupt(pin), callback, mode)
  attachInterrupt(digitalPinToInterrupt(inicioFinPulsador), cambiarEstado, RISING);
  // Pines de interrupciones en Arduino Mega 2560 2,13,18,19,20,21
  // https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
}

void loop() {
  if(estado){
    valSensor = analogRead(sensorLuz);
      Serial.println(valSensor); 
      delay(500); 
  }

  if ( Serial.available() ) {
// read the character and do what you need 
    //Serial.print("Incoming Message: ");
    Serial.println(Serial.read());
    return; // just runs loop() again immediately
  }

  
}

void cambiarEstado(){
  estado = !estado;
  if(estado){
    digitalWrite(actuador1,LOW);
  }else{
    digitalWrite(actuador1,HIGH);
  }
}
