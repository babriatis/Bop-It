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
    if digitalRead(button) == LOW
      
}
