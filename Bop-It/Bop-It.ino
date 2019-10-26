int speaker = 24;
int slide = 23
int button = 4;
int toggle = 5;
int red = 6;
int green = 11;
int yellow1 = 13;
int yellow2 = 14;
int yellow3 = 15;
int yellow4 = 16;
int yellow5 = 17;
int yellow6 = 18;
int yellow7 = 19;

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);     // Speaker Output
  pinMode(slide, INPUT);      // Slide Switch Input
  
  pinMode(button, INPUT_PULLUP);       // Button Input
  pinMode(toggle, INPUT);       // Toggle Input
  pinMode(red, OUTPUT);      // Red LED
  pinMode(green, OUTPUT);     // Green LED
  pinMode(yellow1, OUTPUT);     // Yellow LED 1
  pinMode(yellow2, OUTPUT);     // Yellow LED 2
  pinMode(yellow3, OUTPUT);     // Yellow LED 3
  pinMode(yellow4, OUTPUT);    // Yellow LED 4
  pinMode(yellow5, OUTPUT);    // Yellow LED 5
  pinMode(yellow6, OUTPUT);    // Yellow LED 6
  pinMode(yellow7, OUTPUT);    // Yellow LED 7
  

}

void loop() {
    int count = 0;
  //game turns on
  while(count == 0)
  {
    if (digitalRead(button) == LOW)
    { count++;}
  } //when button hit count != 0 and game begins
  
  long noise;
  int score;
  bool isCorrect;
  int delayCount;
  int toggleVal;
  double slideVal;
  isCorrect = true;
  score = 0;
  delayCount = 0;
  
  //start game
  while(score != 99 && isCorrect == true) //loop while score is not maxed out and while last answer was correct
  {
    isCorrect = false; //reset value of isCorrect on each try
    noise = random(1,4); //generate noise to indicate action
    
    if (noise == 1) //button
    {
      tone(speaker, 2500, 1000); //tone(pin, frequency, duration in ms)
    }
    else if (noise == 2) //toggle
    {
      tone(speaker, 3500,1000);
    }
    else  //noise == 3, slide
    {
      tone(speaker,4500,1000);
    }
    
    //user has set amount of time to complete action, time decreases with each turn
      //first try you get ~(1000-0)*10ms = 10,000 ms = 10sec
      //second try you get ~(1000-16)*10ms = 9,840 ms = 9.8 sec
      //98th try you get ~(1000-8*98)*10ms = 2,169 ms = 2 sec
    while(delayCount<(1000-8*score) && isCorrect == false)
    {
      toggleVal = digitalRead(toggle); //read toggle value to compare later
      slideVal = analogRead(slide); //read slide switch value to compare later
      
      //call function to determine correct input
      isCorrect = readInput(noise, toggleVal, slideVal) //function to determine if correct action complete
      delay(10); //10 milliseconds
      delayCount++;
    } //when correct action done isCorrect == true and go back to make new noise
    
    if (isCorrect == true)
    {
      digitalWrite(green, HIGH); //shine green light for 1 sec
      delay(1000);
      digitalWrite(green, LOW);
      score++ //last turn will be 98, score increments to 99 after correct answer and exit loop
    }
    else
    {
      digitalWrite(red, HIGH); //shine red light for 1 sec
      delay(1000);
      digitalWrite(red, LOW);
    }
  }
  
  //display score after reach 99 or after wrong answer
  //assume LEDs go from left to right so yellow7 is LSB
  int rem1, rem2, rem3, rem4, rem5, rem6, rem7;
  int countDiv;
  countDiv = 7;
  rem1 = 0;
  rem2 = 0;
  rem3 = 0;
  rem4 = 0;
  rem5 = 0;
  rem6 = 0;
  rem7 = 0;
  
  rem7 = score%2; //LSB
  score = score/2; //should leave only whole number part after division bc score is an int
  
  rem6 = score%2;
  score = score/2;
  
  rem5 = score%2;
  score = score/2;
  
  rem4 = score%2;
  score = score/2;
  
  rem3 = score%2;
  score = score/2;
  
  rem2 = score%2;
  score = score/2;
  
  rem1 = score%2; //MSB
  score = score/2;
  
  if(rem7 == 1)
  { digitalWrite(yellow7, HIGH);}
  
  if(rem6 == 1)
  { digitalWrite(yellow6, HIGH);}
  
  if(rem5 == 1)
  { digitalWrite(yellow5, HIGH);}
  
  if(rem4 == 1)
  { digitalWrite(yellow4, HIGH);}
  
  if(rem3 == 1)
  { digitalWrite(yellow3, HIGH);}
  
  if(rem2 == 1)
  { digitalWrite(yellow2, HIGH);}
  
  if(rem1 == 1)
  { digitalWrite(yellow1, HIGH);}
  
  delay(5000); //score stays on for 5 sec
  
  digitalWrite(yellow7, LOW);
  digitalWrite(yellow6, LOW);
  digitalWrite(yellow5, LOW);
  digitalWrite(yellow4, LOW);
  digitalWrite(yellow3, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(yellow1, LOW);
  
  //after score displayed go back and wait for button press to start new game
}

bool readInput(int noise, int toggleVale, double slideVal){
  bool isCorrect;
  int buttonVal;
  int toggleVal2;
  double slideVal2;
  
  buttonVal = digitalRead(button);
  toggleVal2 = digitalRead(toggle);
  slideVal2 = analogRead(slide);
  
  if(noise == 1 && buttonVal == LOW)
  {
    isCorrect = true;
  }
  else if(noise == 2 && toggleVal2 != toggleVal)
  {
    isCorrect = true;
  }
  else if(noise == 3 && ) //need to decide what this condition is
  {
    isCorrect = true;
  }
  else
  {
    isCorrect = false
  }
  
  return isCorrect;
}
