#include <Servo.h>



//declaration servos
Servo basculeH;
Servo baseH;
Servo basculeV;
Servo baseV;


int ReceptionOctet=0; // variable de stockage des octets reçus par port série
int ReceptionNombre=0; // variable de calcul du nombre reçu par port série
int e = 1;

//1er moteur
const int vitessePinceH=3; 
const int sensPinceH=12; 

//2eme moteur
const int vitessePinceV=11; 
const int sensPinceV=13; 

void setup ()
{
  OSCAL = 0x9F;
  Serial.begin(115200);
  
  baseH.attach(10,500,2500);
  basculeH.attach(9,500,2500);
  
  baseV.attach(5,500,2500);
  basculeV.attach(6,500,2500);

  
  pinMode (vitessePinceH,OUTPUT); // Broche vitessePinceH configurée en sortie
  pinMode (sensPinceH,OUTPUT); // Broche sensPinceH configurée en sortie
  pinMode (vitessePinceV,OUTPUT); 
  pinMode (sensPinceV,OUTPUT);
  
  digitalWrite(vitessePinceH,LOW); // a l'arret
  digitalWrite(sensPinceH,LOW); 
  digitalWrite(vitessePinceV,LOW); // a l'arret
  digitalWrite(sensPinceV,LOW); 
}


void InitialisationModules()
{
  //initialisation des modules
  
  basculeV.writeMicroseconds(1300);
  delay(500);
  
  //ouverture pince
  digitalWrite(sensPinceV,LOW); // sens 1
  digitalWrite(vitessePinceV, HIGH); // vitesse maximale
  delay(1000);
  digitalWrite(vitessePinceV, LOW); // vitesse maximale
  delay(600);
  
  basculeH.writeMicroseconds(1300);
  delay(600);
  
  //ouverture pince
  digitalWrite(sensPinceH,LOW); // sens 1
  digitalWrite(vitessePinceH, HIGH); // vitesse maximale
  delay(1000);
  digitalWrite(vitessePinceH, LOW); // vitesse maximale
  delay(600);
  
  baseV.writeMicroseconds(555);
  delay(1000);
  baseV.writeMicroseconds(1480);
  delay(1000);
  
  baseH.writeMicroseconds(515);
  delay(1000);
  baseH.writeMicroseconds(1400);  
  delay(1000);
  
  basculeV.writeMicroseconds(1460);
  delay(500);
  basculeH.writeMicroseconds(1515);
  delay(2000);

}
void SaisieCube()
{
  //on prend le cube
      //fermeture de la pince
      digitalWrite(sensPinceV,HIGH); // sens 2
      digitalWrite(vitessePinceV, HIGH); // vitesse maximale
      delay(500);
      digitalWrite(vitessePinceV, LOW); // vitesse maximale
      delay(500);
      
      //fermeture de la pince
      digitalWrite(sensPinceH,HIGH); // sens 2
      digitalWrite(vitessePinceH, HIGH); // vitesse maximale
      delay(500);
      digitalWrite(vitessePinceH, LOW); // vitesse maximale
      delay(500);
      basculeH.writeMicroseconds(1450);
      delay(500);
}

void LacherCube()
{
  //ouverture pince
  digitalWrite(sensPinceH,LOW); // sens 1
  digitalWrite(vitessePinceH, HIGH); // vitesse maximale
  delay(600);
  digitalWrite(vitessePinceH, LOW); // vitesse maximale
  delay(600);
  
  basculeH.writeMicroseconds(600);
  delay(500);
  
  baseV.writeMicroseconds(555);
  delay(500);
  
  basculeV.writeMicroseconds(600);
  delay(500);
  
  //ouverture pince
  digitalWrite(sensPinceV,LOW); // sens 1
  digitalWrite(vitessePinceV, HIGH); // vitesse maximale
  delay(500);
  digitalWrite(vitessePinceV, LOW); // vitesse maximale
  delay(1000);
  basculeV.writeMicroseconds(1460);
  delay(400);
  baseV.writeMicroseconds(1500);
  delay(100);
}

void Pinces()
{
  //ouverture pince
  digitalWrite(sensPinceV,LOW); // sens 1
  digitalWrite(vitessePinceV, HIGH); // vitesse maximale
  digitalWrite(sensPinceH,LOW); // sens 1
  digitalWrite(vitessePinceH, HIGH); // vitesse maximale
  delay(300);
  digitalWrite(vitessePinceV, LOW); // vitesse maximale
  digitalWrite(vitessePinceH, LOW); // vitesse maximale


  
  //fermeture de la pince
  /*digitalWrite(sensPinceV,HIGH); // sens 2
  digitalWrite(vitessePinceV, HIGH); // vitesse maximale
  delay(600);
  digitalWrite(vitessePinceV, LOW); // vitesse maximale
  delay(500);*/
  
  //ouverture de la pince
  /*digitalWrite(sensPinceH,LOW); // sens 1
  digitalWrite(vitessePinceH, HIGH); // vitesse maximale
  delay(300);
  digitalWrite(vitessePinceH, LOW); // vitesse maximale
*/
  
  //fermeture de la pince
  /*digitalWrite(sensPinceH,HIGH); // sens 2
  digitalWrite(vitessePinceH, HIGH); // vitesse maximale
  delay(500);
  digitalWrite(vitessePinceH, LOW); // vitesse maximale
  delay(500);*/
}

//fonctions de mouvement du cube
void BV_Up()
{
  //on ouvre la pince
  digitalWrite(sensPinceV,LOW); // sens 1
  digitalWrite(vitessePinceV, HIGH); // vitesse maximale
  delay(800);
  digitalWrite(vitessePinceV, LOW);
  
  //on bascule la pince
  basculeV.writeMicroseconds(1300);
  delay(700);
  
}

void BV_Down()
{
  //on bascule la pince
  basculeV.writeMicroseconds(1460);
  delay(200);

  //on ferme la pince
  digitalWrite(sensPinceV,HIGH); // sens 2
  digitalWrite(vitessePinceV, HIGH); // vitesse maximale
  delay(600);
  digitalWrite(vitessePinceV, LOW); // vitesse maximale
  delay(700);
}

void BH_Up()
{
  //on desserre la pince
  digitalWrite(sensPinceH,LOW); // sens 1
  digitalWrite(vitessePinceH, HIGH); // vitesse maximale
  delay(700);
  digitalWrite(vitessePinceH, LOW); // vitesse maximale 

  
  //on releve la pince
  basculeH.writeMicroseconds(1300);
  delay(700);
  
}

void BH_Down (int e)
{
  //on rabat la pince
  basculeH.writeMicroseconds(1520);
  delay(200);
  
  //on referme la pince
  digitalWrite(sensPinceH,HIGH); // sens 2
  digitalWrite(vitessePinceH, HIGH); // vitesse maximale
  delay(700);
  digitalWrite(vitessePinceH, LOW); // vitesse maximale
  delay(200);
  
  //on compense le poid du cube
  if (e == 1)
  {
   basculeH.writeMicroseconds(1450);
  }
  
  delay(200);
}


void BV_CW(int e)
{
  if(e ==1)
  {
    BV_Up();
  }
  //rotation de la base 
  baseV.writeMicroseconds(550);
  delay(700);
  
  BV_Down();
}

void BV_CCW (int e)
{
  if (e == 1)
  {
    BV_Up();
  }
  //rotation de la base 
  baseV.writeMicroseconds(2500);
  delay(700);
  
  BV_Down();
}

void BV_Mid (int e)
{
   BV_Up();
   if(e == 1)
   {
     baseV.writeMicroseconds(1500);
   }
   if(e == 2)
   {
     baseV.writeMicroseconds(1480);
   }
   delay(700);
   BV_Down();
}

void BH_Mid()
{
  BH_Up();
  baseH.writeMicroseconds(1415);
  delay(700);
  BH_Down(1);
}
 
void BH_CCW (int e)
{
  if(e == 1)
  {
    BH_Up();
  }
  //rotation de la base 
  baseH.writeMicroseconds(2370);
  delay(700);
  
  BH_Down(1);
}
  
void BH_CW (int e)
{
  if(e == 1)
  {
    BH_Up ();
  }
  //rotation de la base 
  baseH.writeMicroseconds(515);
  delay(700);
  
  BH_Down(2);
}




void Front ()
{
  //aller
  BV_CCW(1);//on deplace la pinceV de la gauche vers la droite
  BH_Up(); //on souleve la pinceV
  baseV.writeMicroseconds(1500); //on ramene le cube face a la pinceH
  delay(700);
  
  //rotation
  BH_CW(2);//on deplace la pince de la droite vers la gauche 
  baseH.writeMicroseconds(1400); //on ramene la pinceH en faisant tourner la face
  delay(700);
  
  //retour
  BH_Up();// on releve la pinceH
  baseV.writeMicroseconds(555);//on ramene le cube a sa place originelle
  delay(700);
  BH_Down(1); //on rabat la pinceH
  BV_Mid(1);
}

void Front_I ()
{
  //aller
  BV_CCW(1);//on deplace la pinceV de la gauche vers la droite
  BH_Up(); //on souleve la pinceV
  baseV.writeMicroseconds(1500); //on ramene le cube face a la pinceH
  delay(700);
  
  //rotation
  BH_CCW(2);//on deplace la pince de la gauche vers la droite 
  baseH.writeMicroseconds(1400); //on ramene la pinceH en faisant tourner la face
  delay(700);
  
  //retour
  BH_Up();// on releve la pinceH
  baseV.writeMicroseconds(555);//on ramene le cube a sa place originelle
  delay(700);
  BH_Down(1); //on rabat la pinceH
  BV_Mid(1);
}
  
void Back ()
{
  //aller
  BV_CW(1);//on deplace la pinceV de la gauche vers la droite
  BH_Up(); //on souleve la pinceV
  baseV.writeMicroseconds(1480); //on ramene le cube face a la pinceH
  delay(700);
  
  //rotation
  BH_CCW(2);//on deplace la pince de la gauche vers la droite 
  baseH.writeMicroseconds(1400); //on ramene la pinceH en faisant tourner la face
  delay(700);
  
  //retour
  BH_Up();// on releve la pinceH
  baseV.writeMicroseconds(2500);//on ramene le cube a sa place originelle
  delay(700);
  BH_Down(1); //on rabat la pinceH
  BV_Mid(2);
}

void Back_I ()
{
  //aller
  BV_CW(1);
  BH_Up(); 
  baseV.writeMicroseconds(1480);
  delay(700);
  
  //rotation
  BH_CW(2);
  baseH.writeMicroseconds(1400);
  delay(700);
  
  //retour
  BH_Up();// on releve la pinceH
  baseV.writeMicroseconds(2500);//on ramene le cube a sa place originelle
  delay(700);
  BH_Down(1); //on rabat la pinceH
  BV_Mid(2);
}

void Right ()
{
  //aller
  BV_FaceOppose();
  
  //rotation de la face
  BH_CCW(2);
  baseH.writeMicroseconds(1415); 
  delay(700);
  
  //retour a la position de départ
  BV_FaceOppose();
}  

void Right_I ()
{
  //aller
  BV_FaceOppose();
  
  //rotation de la face
  BH_CW(2);
  baseH.writeMicroseconds(1415); 
  delay(700);
  
  //retour a la position de départ
  BV_FaceOppose();
}  

void Left ()
{
  BH_CCW(1);
  baseH.writeMicroseconds(1415);
  delay(700);
}

void Left_I()
{
  BH_CW(1);
  baseH.writeMicroseconds(1415);
  delay(700);
}

void Up ()
{
  //aller
  BH_FaceOppose();
  
  //rotation
  BV_CCW(1);
  baseV.writeMicroseconds(1500);
  delay(700);
  
  //retour
  BH_FaceOppose();
}


void Up_I ()
{
  //aller
  BH_FaceOppose();
  
  //rotation
  BV_CW(1);
  baseV.writeMicroseconds(1500);
  delay(700);
  
  //retour
  BH_FaceOppose();
}

void Down ()
{
  BV_CCW(1);
  baseV.writeMicroseconds(1500);
  delay(700);
}

void Down_I ()
{
  BV_CW(1);
  baseV.writeMicroseconds(1500);
  delay(700);
}

void BV_FaceOppose()
{
  BV_CW(1);
  BH_Up();
  baseV.writeMicroseconds(2500);
  delay(1200);
  BH_Down(1);
  BV_Mid(1);
}

void BH_FaceOppose()
{
  BH_CW(1);
  BV_Up();
  baseH.writeMicroseconds(2370);
  delay(1200);
  BV_Down();
  BH_Mid();
}

void BV_NextFace(int e)
{
  if (e == 1)
  {
    BV_CCW(1);
    BH_Up();
    baseV.writeMicroseconds(1500);
    delay(700);
    BH_Down(1);
    BV_Mid(1);
  }
  
  if (e==2)
  {
    BV_CW(1);
    BH_Up();
    baseV.writeMicroseconds(1500);
    delay(700);
    BH_Down(1);
    BV_Mid(2);
  }
}

void BH_NextFace(int e)
{
  if (e == 1)
  {
    BH_CCW(1);
    BV_Up();
    baseH.writeMicroseconds(1415);
    delay(700);
    BV_Down();
    BH_Mid();
  }
  
  if (e==2)
  {
    BH_CW(1);
    BV_Up();
    baseH.writeMicroseconds(1415);
    delay(700);
    BV_Down();
    BH_Mid();
  }
}



void Demo ()
{
  Left();
  Left();
  delay(500);
  BV_FaceOppose();
  delay(500);
  Left();
  Left();
  Down();
  Down();
  delay(500);
  BH_FaceOppose();
  delay(500);
  Down();
  Down();
  delay(500);
  BV_NextFace(1);
  delay(500);
  Left();
  Left();
  delay(500);
  BV_FaceOppose();
  delay(500);
  Left();
  Left();
}
  
  


void loop(){
  ReceptionNombre = 0;
  
  if (Serial.available()>0)
  {
    while (Serial.available()>0) {
    ReceptionOctet= Serial.read(); // renvoie le 1er octet présent dans la file attente série (-1 si aucun) 
    ReceptionOctet=ReceptionOctet-48; // transfo valeur ASCII en valeur décimale

    if ((ReceptionOctet>=0)&&(ReceptionOctet<=9))     ReceptionNombre = (ReceptionNombre*10)+ReceptionOctet; 
    delay(1); 
    }
    Serial.println(ReceptionNombre);
    
    switch( ReceptionNombre)
    {
      case 504 :
      Pinces();
      break;
      
      case 111 :
      InitialisationModules();
      break;
      
      case 0 :
      SaisieCube();
      break;
      
      case 404 :
      LacherCube();
      break;
      
      case 1 :
      Front ();
      break;
      
      case 2 :
      Front_I ();
      break;
      
      case 3 :
      Back ();
      break;
     
      
      case 4 :
      Back_I ();
      break;
      
      case 5 : 
      Right ();
      break;
      
      case 6 :
      Right_I ();
      break;
      
      
      case 7 :
      Left ();
      break;
      
      case 8 :
      Left_I ();
      break;
      
      case 9 :
      Up ();
      break;
      
      case 10 :
      Up_I ();
      break;
      
      case 11 : 
      Down ();
      break;
      
      case 12 :
      Down_I ();
      break;
      
      case 13 :
      BH_FaceOppose();
      break;
      
      case 14 :
      BV_FaceOppose();
      break;
      
      case 15 :
      BV_NextFace(1);
      break;
      
      case 16 :
      BH_NextFace(1);
      break;
      
      case 17 :
      Left();
      Left();
      break;
      
      case 18 :
      Down ();
      Down ();
      break;
      
      case 42 :
      Demo();
      break;
    }
  }
}
