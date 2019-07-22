int rcButtonA = 0;
int rcButtonB = 0;
int rcButtonC = 0;
int rcButtonD = 0;
int slideSwitch = 0;
int var = 0;

void setup() {
  // put your setup code here, to run once:

  //RF control button inputs

  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  

  //relay control pin

  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);

  //slide switch

  pinMode(11, INPUT);

  //start serial
 
  Serial.begin(9600);
  Serial.println("Hello");
  

}

void loop() {
  // put your main code here, to run repeatedly:

  //read current status
  rcButtonA = digitalRead(3);
  rcButtonB = digitalRead(4);
  rcButtonC = digitalRead(5);
  rcButtonD = digitalRead(6);
  slideSwitch = digitalRead(11);

  //status report string
  String statusReport = String(rcButtonA) + " " + String(rcButtonB) + " " + String(rcButtonC) + " " + String(rcButtonD);

  //status check
  if (slideSwitch == HIGH)
  {
    Serial.println(statusReport);
  }
  
  
  if (rcButtonA == HIGH) //timed switch-on
  { 
    var = 0;
    while (var<1000)
    {
      digitalWrite(8, LOW);
      if (digitalRead(4) == HIGH) //button B force switch-off during timed phase
       {
        digitalWrite(8, HIGH);
        break;
      }
      var = var + 1;
      delay(100);
      Serial.println(var);
    }
    digitalWrite(8,HIGH);
    }

  if (rcButtonB == HIGH) //any-state switch off
  {
    digitalWrite(8,HIGH);
  }

  if (rcButtonC == HIGH) //permanent switch on
  {
    digitalWrite(8,LOW);
  }


  //Serial.println(buttonState);

