/*
 *
 *  plante connectée lcd + capteur   
 *  By : Alexandre Wagner
 * 
 *  Linkedin : https://fr.linkedin.com/in/alexandre-wagner-5280a4138
 *
 */
 
//=======Condition d'utilisation tweeter===
#include <SPI.h>  //Serial Peripheral Interface (SPI)
#include <Ethernet.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//========Arduino port de connection via composant externe ========
#define CAPTEUR A0



//------VALEURS HYDROMETRIE  ------------------
#define MAXDRYNESS 300
#define MAXWATER 60

//=====Debut du code==========
  /*Setup*/
void setup()
{  
    Serial.begin(9600);
    pinMode(CAPTEUR, INPUT);
    lcd.begin(16, 2);
}
/* Fonction pour faire passer le texte  et affiche le taux d'humidité */

void ecran(char *stats)
{
  int SensorValue = analogRead(CAPTEUR);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print(stats);  
  lcd.setCursor(5,1);
  lcd.print("Taux d humidite = ");
  lcd.print(SensorValue);
  delay(1000);
  for(int x=0; x<16; x++) 
  {
    lcd.scrollDisplayLeft(); 
    delay(250);
  } 
}
//  pour le status de la plante sur écran lcd et les consol logs et affichage LCD
void loop()
{
  int SensorValue = analogRead(CAPTEUR);
    Serial.print(SensorValue); 
    Serial.print(" Capucine la plante ");

  if(SensorValue >= MAXDRYNESS)
  {
    delay(1000);
    char *stats;
    stats = "J'ai soif !";
    ecran(stats);
    Serial.println(stats);
  }
  else if (SensorValue <= MAXWATER)
  {
    char *stats;
    stats = "Je me noie !!";
    ecran(stats);
    Serial.println(stats);
  }
  else
  { 
    char *stats;
    stats = "Nickel je me porte bien";
    ecran(stats);
    Serial.println(stats); 
      
  }
  lcd.scrollDisplayLeft();
  delay(2000);
}
