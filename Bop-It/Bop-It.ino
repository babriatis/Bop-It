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
  
  int count = 0;
}

void loop() {
  //game turns on
  while(count == 0)
  {
    if (digitalRead(button) == LOW)
    { count++;}
  }
  long noise;
  int score;
  bool isCorrect;
  int delayCount;
  isCorrect = false;
  score = 0;
  delayCount = 0;
  
  //start game
  while(score != 99 || isCorrect == false)
  {
    noise = random(1,4);
    
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
    
    while(delayCount<100 && isCorrect == false)
    {
      toggleVal = digitalRead(toggle);
      
      //call function to determine correct input
      isCorrect = readInput(noise, toggleVal)
      delay(10); //10 milliseconds
      delayCount++;
    }
  
      
}

bool readInput(int noise, int toggleVale){
  bool isCorrect;
  int buttonVal;
  int toggleVal2;
  double slideVal;
  
  buttonVal = digitalRead(button);
  toggleVal2 = digitalRead(toggle);
  
  if(noise == 1 && buttonVal == LOW)
  {
    isCorrect = true;
  }
  else if(noise == 2 && toggleVal2 != toggleVal)
  {
    isCorrect = true;
  }
  else if(noise == 3 && )
  {
    isCorrect = true;
  }
  else
  {
    isCorrect = false
  }
  
  return isCorrect;
}
