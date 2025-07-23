int Outputs[4] = {10,11,12,13};

int Color[16];
int Choices[16];
int size = 0;

int button = 0;
bool buttonDown = false;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  
  randomSeed(analogRead(0));
}

void loop()
{
  if (size == 16) {
    while (true) {
      digitalWrite(13, HIGH);
      delay(200);
      digitalWrite(13, LOW);
      digitalWrite(12, HIGH);
      delay(200);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      delay(200);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      delay(200);
      digitalWrite(10, LOW);
    }
  }
  
  Color[size] = Outputs[random(4)];
  size++;
  
  for (int i = 0; i < size; i++) {
  	digitalWrite(Color[i], HIGH);
    delay(250);
    digitalWrite(Color[i], LOW);
    delay(250);
  }
  
  int choice = 0;
  while (true) {
    for (int i = 0; i < 4; i++) {
      if (digitalRead(i + 4) == HIGH) {
        button = i + 4;
        digitalWrite(i + 10, HIGH);
        
        if (buttonDown == false) {
          buttonDown = true;
          
              if (i + 10 != Color[choice]) {
                while (true) {
                  for (int i = 0; i < 4; i++) {
                    digitalWrite(i + 10, HIGH);
                  }
                  delay(500);
                  for (int i = 0; i < 4; i++) {
                    digitalWrite(i + 10, LOW);
                  }
                  delay(500);
                }
              }

          Choices[choice] = i + 10;
          choice++;
        }
      } else if (digitalRead(button) == LOW) {
        buttonDown = false;
        digitalWrite(i + 10, LOW);
      }
    }
    if (choice == size) {
      delay (250);
      digitalWrite(button + 6, LOW);
      break;
    }
  }
  
  delay(500);
  digitalWrite(10, HIGH);
  delay(250);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(250);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(250);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  delay(250);
  digitalWrite(13, LOW);
  delay(500);
}