#define IR 3
//déclaration de variables
int8_t LVL; //La variable pour stocker la valeur du signal du récepteur.
bool chronoStatus; // Pour mémoriser si on est en On ou Off
int lance =0; // variable 

unsigned long millisON = millis(); //initialise fonction millis
unsigned long millisOff = 0; //initialise une variable positive 
 
void setup() {
  // Résistance interne contre VCC
  LVL = digitalRead(IR); //Initialisation du capteur infrarouge, stock la valeur du capteur dans une variable                                          
  Serial.begin(9600);
  chronoStatus = true;
}
 
void loop() {
 LVL = digitalRead(IR);
  delay(100); //pause
  if (LVL == 0){
    lance++;                                
  }
 
  if (lance == 1 && chronoStatus == false) //Si un objet passe devant le capteur, le chronomètre démarre
  {
    millisON = millis(); //on met la valeur actuelle du compteur dans la variable milliSON
    Serial.println("Chrono ON"); //Indique que le chrono démarre
    chronoStatus = true;
  }
 
  if (lance  == 2 && chronoStatus == true) //Si l'objet repasse devant le 
                                          //capteur, le chronomètre s'arréte
  {
    millisOff = millis() - millisON; //Calcul le temps écoulé en ms : on met la valeur actuelle du compteur - millisON dans la variable millisOff 
    Serial.println("Péride T du pendule est = " + String(millisOff) + "ms"); //afficher la période T du pendule
    chronoStatus = false;
    lance = 0; //Réintiallise la variables à 0
    millisON = 0; //Réintialise la variable de temps à 0
  }
}