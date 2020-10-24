
float N[2][2] = {
  {-0.14736599, -7.83405221},
  { -1.15400831,  9.72328823}};

float B [2][1]={{3.89827002}, 
                 {-4.41150649}}; //bias de la neurona N1


float S[1][2]=
{{-6.60705046 , 6.00857268}};
 
float B2=0.20379602; //bias de la neurona de salida  
float X[2][1]={{0.3}, 
               {0.7}};

float N0,N1,S0,S1,flag0,flag1;

               
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  delay(500);
  Serial.println("###########################");
  Serial.println("COMUNICACION SERIE HABILITADA.");
  Serial.println("###########################");  
// initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
Serial.print("INGRESE SEPARADOS POR COMA LOS VALORES DE X0 Y X1: ");
 while(1)
 {
  if (Serial.available()){
X[0][0]= Serial.parseFloat();
X[1][0]=Serial.parseFloat();
  }
  // put your main code here, to run repeatedly:
N0=N[0][0]*X[0][0]+N[0][1]*X[1][0]+B[0][0];
N1=N[1][0]*X[0][0]+N[1][1]*X[1][0]+B[1][0];
S0=N0*S[0][0]+N1*S[0][1];
S1=1+pow(2.718281,-S0);
S1=1/S1;
if((X[0][0]!=flag0)&&(X[1][0]!=flag1)){
  if((X[0][0]!=0)&&(X[1][0]!=0)){
  flag0=X[0][0];
  flag1=X[1][0];
  
Serial.print("\n");
Serial.print(" X0 : ");
Serial.print(X[0][0]);
Serial.print(" X1 : ");
Serial.print(X[1][0]);   
Serial.print("SALIDA: ");
Serial.print(S1);
Serial.println("    ");}}
 }
}
