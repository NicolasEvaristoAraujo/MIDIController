  // Circuito MIDI:
 // * digital in 1 conectado ao MIDI jack pin 5 (DO MIDI JACK)
 // * MIDI jack pin 2 conectado ao ground (DO ARDUINO)
 // * MIDI jack pin 4 (DO MIDI JACK) conectado ao +5V (DO ARDUINO) por um resistor de 220-ohm 

int buttonPresses = 0; // quantas vezes a nota foi tocada

int SENSOR_CONST = 6;
int LIGHT_SENSOR = 0;
int AMBIENT_OFFSET = 0;
int lightSensorThreshold = 4;

int LaserState = LOW; // laser "off"
int delayligado = 5; //minimo 2 para aparecer direito o laser
int delaymexe = 3; //delay entre movimentos minimo 3
int delaydesligado = 0; // minimo 0
long previousMillis = 0; // guarda ultima vez que o laser foi atualizado
const int LaserPin =  7; // define pin do arduino para o laser
long timer = 100; // intervalo que o laser vai pisca em milisegundos

int val = 100;

// define os pins do motor no arduino
int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;


//(/*)
int note9 = 0x61;
int note8 = 0x63;
int note7 = 0x64;
int note6 = 0x66;
int note5 = 0x68;
int note4 = 0x70;
int note3 = 0x71;
int note2 = 0x40;
int note1 = 0x47;
//(*/)
/*
int note9 = 0x33;   
int note8 = 0x32;    
int note7 = 0x30;  
int note6 = 0x2E;  
int note5 = 0x2C;  
int note4 = 0x2B;  
int note3 = 0x29;  
int note2 = 0x24;  
int note1 = 0x25; 
*/

// setup ------------------------------------------------------------
void setup() 
{
  
  
  // do motor:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  // do laser:
  pinMode(LaserPin, OUTPUT);  

      for (int i = 0; i < 30; i++) {
    AMBIENT_OFFSET += analogRead(LIGHT_SENSOR);
    digitalWrite(13, HIGH);
  }

  AMBIENT_OFFSET = AMBIENT_OFFSET / 30;

  // do led:
  pinMode(13, OUTPUT);

  //  ativa frequencia MIDI (baud rate):
  Serial.begin(31250);
}

void noteOn(int cmd, int pitch, int velocity)
  {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
  }
  
//-------------------------------------------------------------------------------------------
// inicio do loop ---------------------------------------------------------------------------
void loop()
{

// movimento horario ----------------------------------------------------------  

digitalWrite(LaserPin, HIGH);    // liga laser 1
 delay(delayligado); 
//**********************************************************************************************************************************  
if ( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note1, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note1, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************

 digitalWrite(LaserPin, LOW);    // desliga laser 1
 delay(delaydesligado); 

//-------------------------------------------------------------------  
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 2
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);  
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 3
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);  
  delay(delaymexe); // espera o motor
  
  digitalWrite(LaserPin, HIGH);    // liga laser 2
   delay(delayligado);
  
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note2, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note2, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 2
 delay(delaydesligado); 

//-------------------------------------------------------------------
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 4
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 5
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 3
   delay(delayligado);
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST)  && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note3, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note3, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 3
 delay(delaydesligado); 

//------------------------------------------------------------------ 
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 6
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 7
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor

  digitalWrite(LaserPin, HIGH);    // liga laser 4
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note4, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) < AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note4, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 4
 delay(delaydesligado); 

//-----------------------------------------------------------------
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 8
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 9
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 5
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note5, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) < AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note5, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 5
 delay(delaydesligado); 

//-------------------------------------------------------------------
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 10
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 11
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 6
   delay(delayligado); 
 //**********************************************************************************************************************************  
if( (analogRead(0) > AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note6, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note6, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 6
 delay(delaydesligado); 

//------------------------------------------------------------------  
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 12
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 13
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 7
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note7, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note7, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 7
 delay(delaydesligado); 

//------------------------------------------------------------------
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 14
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 15
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 8
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note8, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note8, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 8
 delay(delaydesligado); 

//------------------------------------------------------------------
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 16
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 17
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 9
   delay(delayligado); 
//**********************************************************************************************************************************  **  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note9, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note9, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************


  digitalWrite(LaserPin, LOW);    // desliga laser 9 
 delay(delaydesligado); 

//----------------------------------------------------------------------------- 
// movimento anti-horario -----------------------------------------------------  

//------------------------------------------------------------------ 
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 16
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 15
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 8
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note8, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note8, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 8
 delay(delaydesligado); 

//------------------------------------------------------------------ 
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 14
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 13
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 7
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note7, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note7, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 7
 delay(delaydesligado); 

//------------------------------------------------------------------ 
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 13
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 12
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 6
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note6, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note6, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 6
 delay(delaydesligado); 

//------------------------------------------------------------------
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 11
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 10
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 5
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note5, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note5, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 5
 delay(delaydesligado); 

//------------------------------------------------------------------  
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 9
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 8
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 4
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note4, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note4, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 4
 delay(delaydesligado); 

//------------------------------------------------------------------ 
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 7
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 6
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 3
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) >  AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note3, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note3, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 3
 delay(delaydesligado); 

//------------------------------------------------------------------- 
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 5
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 4
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
    
  digitalWrite(LaserPin, HIGH);    // liga laser 2
   delay(delayligado); 
//**********************************************************************************************************************************  
if( (analogRead(0) > AMBIENT_OFFSET + SENSOR_CONST) && (buttonPresses == 0) ) //se o sensor esta ativado E  ainda nao começou a tocar entao toca a nota++++++++++++
          
             { 
             // faça A -----------------------------------------------------------------------------------------------------------
             digitalWrite(13, HIGH);       // acende o led  
             noteOn(0x90, note2, 0x7F);    // toca a nota no: channel 1 = (0x90), nota = (note), volume = (0x7F)
             buttonPresses++;              // aumenta o valor do buttonPresses (para avisar que a nota ja comecou a tocar)
             } 
           
// --------------------------------------------------------------------------------------------------------------------   
else if(analogRead(0) <  AMBIENT_OFFSET + SENSOR_CONST) // e se o sensor esta desativado +++++++++++++++++++++++++++++++++++++++++++++++++++++++
          
                  { // //  faça B = silencia a nota
                  digitalWrite(13, LOW);        // desliga o led   
                  noteOn(0x90, note2, 0x00);     // silencia a nota no: channel 1 (0x90), nota = (note), volume de silencio = (0x00)
                  buttonPresses = 0;            // zera o "buttonPresses"
                  }        
//**********************************************************************************************************************************
  digitalWrite(LaserPin, LOW);    // desliga laser 2
 delay(delaydesligado); 

//------------------------------------------------------------------ 
  digitalWrite(motorPin1, HIGH); // comanda o motor para mexer para 3
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delaymexe); // espera o motor
  digitalWrite(motorPin1, LOW); // comanda o motor para mexer para 2
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delaymexe); // espera o motor
  

     
}
// final do loop para mexer o motor e ligar/desligar laser (volta para o começo do loop)-----
//-------------------------------------------------------------------------------------------
