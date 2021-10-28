# Projeto_Carro_arduino_SO

#Eliezer Nunes Rodrigues Junior  - 21627918
Relatório de desenvolvimento de projeto:
O projeto consiste em um veículo autônomo capaz de definir o melhor caminho a ser seguido livre de obstáculos, a partir de das leituras repassadas pelo sensor ultrassónico e um servo motor que permite a articulação do sensor em direções opostas a fim de verificar qual é o melhor rumo. 
Bibliotecas avulsas utilizadas para realização da atividade:

AFMotor.h disponível em https://learn.adafruit.com/adafruit-motor-shield/library-install
Servo.h disponível em https://github.com/arduino-libraries/Servo
NewPing.h disponível em <https://github.com/livetronic/Arduino-NewPing>
Lista de itens necessárias para concepção do projeto:
1 Arduino Uno R3;
L293D Motor Driver Shield for Arduino, (escolhido em vista de reduzir a complexidade do projeto, tendo em vista, que configurar a ponte H tornou se pouco produtivo e didático para este exercício);
4 (quatro) motores solenoides;
1 servo motor;
1 sensor ultrassônico HC-SR04;
1 bateria de 9V;
Diagrama do projeto:
 




Tempo compartilhado:
O trecho de código a seguir consegue representar o compartilhamento de recursos de processamento entre os ciclos de loops no código como um todo.
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

Preempção
if(distancia<=15) // Verifica a distância de um Obstaculo
 {
  moveStop(); // Para imediatamente;
  delay(100); // Aguarda 100 ms;
  MoverseParaTras(); Se move para trás afastando se do obstáculo.
  delay(300); // Aguarda 300 ms;
  moveStop(); // Para;
  delay(200); // 200 ms.
  distanciaR = OlharDireita(); verifica a Direita
  delay(200);	
  distanciaL = OlharEsquerda(); verifica a Esquerda
  delay(200);




Lista de prioridades, é adotada a partir da definição da execução no escopo do projeto, deve se observar, como prioritário, os seguintes itens nesta ordem:
Definição dos parâmetros padrões, ou seja, o valor “default” que serve apara manter os valores aceitáveis do sistema constando nas constantes:
TRIG_PIN A0 
ECHO_PIN A1 
MAX_DISTANCE 200 
MAX_SPEED 190
MAX_SPEED_OFFSET 20

E as funções Setup() e loop(), cuidando respectivamente de definir quais são os valores inicias captados pelo sensor do veículo. Função seguinte é responsável, por revalidar as leituras de ambiente, do registrador mantendo o sistema com informações precisas sobre obstáculos presentes à sua frente.
