// doesn't work!!! 

#define LED1 4
#define SW1 5
#define SW2 6


volatile int SetTemp = 16;

void toggle(byte pinNum) {
  byte pinState = !digitalRead(pinNum);
  digitalWrite(pinNum, pinState);
}

void setup()  {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Welcome ");
  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW); // LED off
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  attachInterrupt(digitalPinToInterrupt(SW1), ISR0, RISING);
  attachInterrupt(digitalPinToInterrupt(SW2), ISR1, RISING);
  // interrupts();
}

void loop() {
  Serial.println(SetTemp);
} // end loop


void ISR0()
{
  SetTemp--;
  Serial.println("ISR0");
  toggle(LED1);
}

void ISR1() {
  SetTemp++;
  Serial.println("ISR1");
  toggle(LED1);
}

