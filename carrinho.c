#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 200 
#define MAX_SPEED 190
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo servoMotor;   

boolean IrEmFrente=false;
int distancia = 100;
int MudarVelocidade = 0;

void Setup() {

  servoMotor.attach(10);  
  servoMotor.write(115); 
  delay(2000);
  distancia = VerificarPing();
  delay(100);
  distancia = VerificarPing();
  delay(100);
  distancia = VerificarPing();
  delay(100);
  distancia = VerificarPing();
  delay(100);
}

void loop() {
 int distanciaR = 0;
 int distanciaL =  0;
 delay(40);
 
 if(distancia<=15)
 {
  moveStop();
  delay(100);
  MoverseParaTras();
  delay(300);
  moveStop();
  delay(200);
  distanciaR = OlharDireita();
  delay(200);
  distanciaL = OlharEsquerda();
  delay(200);

  if(distanciaR>=distanciaL)
  {
    VirarParaDireita();
    moveStop();
  }else
  {
    VirarParaSquerda();
    moveStop();
  }
 }else
 {
  MorverSeParaFrente();
 }
 distancia = VerificarPing();
}

int OlharDireita()
{
    servoMotor.write(50); 
    delay(500);
    int distancia = VerificarPing();
    delay(100);
    servoMotor.write(115); 
    return distancia;
}

int OlharEsquerda()
{
    servoMotor.write(170); 
    delay(500);
    int distancia = VerificarPing();
    delay(100);
    servoMotor.write(115); 
    return distancia;
    delay(100);
}

int VerificarPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  } 
  
void MorverSeParaFrente() {

 if(!IrEmFrente)
  {
    IrEmFrente=true;
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD); 
    motor4.run(FORWARD);     
   for (MudarVelocidade = 0; MudarVelocidade < MAX_SPEED; MudarVelocidade +=2) 
   {
    motor1.setSpeed(MudarVelocidade);
    motor2.setSpeed(MudarVelocidade);
    motor3.setSpeed(MudarVelocidade);
    motor4.setSpeed(MudarVelocidade);
    delay(5);
   }
  }
}

void MoverseParaTras() {
    IrEmFrente=false;
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (MudarVelocidade = 0; MudarVelocidade < MAX_SPEED; MudarVelocidade +=2) 
  {
    motor1.setSpeed(MudarVelocidade);
    motor2.setSpeed(MudarVelocidade);
    motor3.setSpeed(MudarVelocidade);
    motor4.setSpeed(MudarVelocidade);
    delay(5);
  }
}  

void VirarParaDireita() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
  motor1.run(FORWARD);      
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);      
} 
 
void VirarParaSquerda() {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500);
  motor1.run(FORWARD);     
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}  