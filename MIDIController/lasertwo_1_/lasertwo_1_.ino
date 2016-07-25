/*--------------------------------------------Circuito MIDI:---------------------------------------------------*/

// * digital in 1 conectado ao MIDI jack pin 5 (DO MIDI JACK)
// * MIDI jack pin 2 conectado ao ground (DO ARDUINO)
// * MIDI jack pin 4 (DO MIDI JACK) conectado ao +5V (DO ARDUINO) por um resistor de 220-ohm

int buttonPresses = 0; // quantas vezes a nota foi tocada

int LaserState = LOW; // laser "off"
int sensor = 8 ; // valor do sensor calibrado
int delayligado = 5; //minimo 2 para aparecer direito o laser
int delaymexe = 3; //delay entre movimentos minimo 3
int delaydesligado = 0; // minimo 0
long previousMillis = 0; // guarda ultima vez que o laser foi atualizado
const int LaserPin =  7; // define pin do arduino para o laser
long timer = 100; // intervalo que o laser vai pisca em milisegundos

int val = 100;

// define os pins do motor no arduino
int motorPins[] = {8, 9, 10, 11};

int note9 = 0x61;
int note8 = 0x63;
int note7 = 0x64;
int note6 = 0x66;
int note5 = 0x68;
int note4 = 0x70;
int note3 = 0x71;
int note2 = 0x40;
int note1 = 0x47;

int count = 0;

// ------------------------------------------------- setup ------------------------------------------------------------
void setup()
{
  // do motor:
  for (count = 0; count < 4; count++) {
    pinMode(motorPins[count], OUTPUT);
  }
  
  // do laser:
  pinMode(LaserPin, OUTPUT);
  // do led:
  pinMode(13, OUTPUT);
  //  ativa frequencia MIDI (baud rate):
  Serial.begin(31250);
}

void moveForward(int stepPin) {
digitalWrite(motorPins[stepPin], HIGH);

  for (count = 0; count < 4 ; count++) {
    if(motorPins[stepPin] != motorPins[count])
      digitalWrite(motorPins[count],  LOW);
  }
  delay(delaymexe);
}

void noteOn(int cmd, int pitch, int velocity)
{
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

//--------------------------------------------------- inicio do loop ---------------------------------------------------------------------------
void loop()
{ 
val = analogRead(0);
 
  // movimento horario
  digitalWrite(LaserPin, HIGH);    // liga laser 1
  delay(delayligado);

  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado e ainda nao começou a tocar, entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note1, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note1, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }

  digitalWrite(LaserPin, LOW);    // desliga laser 1
  delay(delaydesligado);

  //-------------------------------------------------------------------

  moveForward(0);
  moveForward(1);
  
  digitalWrite(LaserPin, HIGH);    // liga laser 2
  delay(delayligado);

  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note2, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { // //  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note2, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }

  digitalWrite(LaserPin, LOW);    // desliga laser 2
  delay(delaydesligado);
  
  //-------------------------------------------------------------------

  moveForward(2);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 3
  delay(delayligado);

  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note3, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  } 
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note3, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
 
  digitalWrite(LaserPin, LOW);    // desliga laser 3
  delay(delaydesligado);

  //------------------------------------------------------------------
  
  moveForward(0);
  moveForward(1);

  digitalWrite(LaserPin, HIGH);    // liga laser 4
  delay(delayligado);

  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note4, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note4, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 4
  delay(delaydesligado);

  //-----------------------------------------------------------------
  
  moveForward(2);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 5
  delay(delayligado);

  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note5, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note5, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }

  digitalWrite(LaserPin, LOW);    // desliga laser 5
  delay(delaydesligado);

  //-------------------------------------------------------------------

  moveForward(0);
  moveForward(1);

  digitalWrite(LaserPin, HIGH);    // liga laser 6
  delay(delayligado);
 
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note6, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { // //  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note6, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }

  digitalWrite(LaserPin, LOW);    // desliga laser 6
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(2);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 7
  delay(delayligado);

  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note7, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note7, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }

  digitalWrite(LaserPin, LOW);    // desliga laser 7
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(0);
  moveForward(1);

  digitalWrite(LaserPin, HIGH);    // liga laser 8
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  {// faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note8, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note8, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 8
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(2);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 9
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  {// faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note9, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note9, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }

  digitalWrite(LaserPin, LOW);    // desliga laser 9
  delay(delaydesligado);

  //-----------------------------------------------------------------------------
  
  // movimento anti-horario -----------------------------------------------------

  //-----------------------------------------------------------------------------

  moveForward(2);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 8
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note8, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  {//  faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note8, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 8
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(0);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 7
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  {// faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note7, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note7, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 7
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(2);
  moveForward(1);

  digitalWrite(LaserPin, HIGH);    // liga laser 6
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  { // faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note6, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { // faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note6, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 6
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(0);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 5
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  {// faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note5, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { // faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note5, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 5
  delay(delaydesligado);

  //------------------------------------------------------------------
  
  moveForward(2);
  moveForward(1);
  
  digitalWrite(LaserPin, HIGH);    // liga laser 4
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  {// faça A 
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note4, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note4, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 4
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(0);
  moveForward(3);

  digitalWrite(LaserPin, HIGH);    // liga laser 3
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  {// faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note3, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { //faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note3, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
 
  digitalWrite(LaserPin, LOW);    // desliga laser 3
  delay(delaydesligado);

  //-------------------------------------------------------------------

  moveForward(2);
  moveForward(1);

  digitalWrite(LaserPin, HIGH);    // liga laser 2
  delay(delayligado);
  
  if ( (analogRead(0) > sensor ) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota
  {// faça A
    digitalWrite(13, HIGH);       // acende o led
    noteOn(0x90, note2, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
    buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
  }
  else if (analogRead(0) < sensor ) // e se o sensor esta desativado
  { // faça B = silencia a nota
    digitalWrite(13, LOW);        // desliga o led
    noteOn(0x90, note2, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
    buttonPresses = 0;            // zera o "buttonPresses"
  }
  
  digitalWrite(LaserPin, LOW);    // desliga laser 2
  delay(delaydesligado);

  //------------------------------------------------------------------

  moveForward(0);
  moveForward(3);
}
// final do loop para mexer o motor e ligar/desligar laser (volta para o começo do loop)-----
//-------------------------------------------------------------------------------------------
