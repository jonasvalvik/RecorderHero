
// h = hole, where h1 is the hole closest to the face when playing

const int h1 = 13;
const int h2 = 12;
const int h3 = 11;
const int h4 = 10;
const int h5 = 9;
const int h6 = 8;
const int h7 = 7;

// BPM to ms chart: https://guitargearfinder.com/guides/convert-ms-milliseconds-bpm-beats-per-minute-vice-versa/

int time1 = 200; //Vibration time /// LED on time
int time2 = 300; //Pause between each beat/quarter note -- 600 = full speed, 1200 = half speed (at 100 BPM)
int time3 = 2000;

//int chordCount = 0;

//Twinkle Twinkle array. Each element represents 1 beat, each line is 1 bar.

String melody[] = {
  "C", "C", "G", "G",
  "A", "A", "G", "PAUSE",
  "F", "F", "E", "E",
  "D", "D", "C", "PAUSE",
  "G", "G", "F", "F",
  "E", "E", "D", "PAUSE",
  "G", "G", "F", "F",
  "E", "E", "D", "PAUSE",
  "C", "C", "G", "G",
  "A", "A", "G", "PAUSE",
  "F", "F", "E", "E",
  "D", "D", "C", "PAUSE",
};

//String chosenSong[] = melody;

//boolean playSong = true;

void setup() {
  Serial.begin(9600);
  pinMode(h1, OUTPUT); //Left index
  pinMode(h2, OUTPUT); //Left middle
  pinMode(h3, OUTPUT); //Left ring
  pinMode(h4, OUTPUT); //Right index
  pinMode(h5, OUTPUT); //Right middle
  pinMode(h6, OUTPUT); //Right ring
  pinMode(h7, OUTPUT); //Right pinky
}

// Chart taken from this pic: https://i.pinimg.com/originals/75/6e/85/756e85ad78e1009c5106f1788345634e.jpg
void loop() {
  //Serial.print("chosenSong[]

  // while (playSong == true) {
  //Serial.println("-----------STARTING SONG--------------");
  for (int i = 0; i < 48 - 1; i++) {

    //Serial.println(melody[i]);

    if (melody[i] == "C") {
      Serial.println("C");
      digitalWrite(h1, HIGH);
      digitalWrite(h2, HIGH);
      digitalWrite(h3, HIGH);
      digitalWrite(h4, HIGH);
      digitalWrite(h5, HIGH);
      digitalWrite(h6, HIGH);
      digitalWrite(h7, HIGH);
      delay(time1) ;
      digitalWrite(h1, LOW);
      digitalWrite(h2, LOW);
      digitalWrite(h3, LOW);
      digitalWrite(h4, LOW);
      digitalWrite(h5, LOW);
      digitalWrite(h6, LOW);
      digitalWrite(h7, LOW);
      delay(time2);
    }
    else if (melody[i] == "D") {
      Serial.println("D");
      digitalWrite(h1, HIGH);
      digitalWrite(h2, HIGH);
      digitalWrite(h3, HIGH);
      digitalWrite(h4, HIGH);
      digitalWrite(h5, HIGH);
      digitalWrite(h6, HIGH);
      delay(time1) ;
      digitalWrite(h1, LOW);
      digitalWrite(h2, LOW);
      digitalWrite(h3, LOW);
      digitalWrite(h4, LOW);
      digitalWrite(h5, LOW);
      digitalWrite(h6, LOW);
      delay(time2);
    }
    else if (melody[i] == "E") {
      Serial.println("E");
      digitalWrite(h1, HIGH);
      digitalWrite(h2, HIGH);
      digitalWrite(h3, HIGH);
      digitalWrite(h4, HIGH);
      digitalWrite(h5, HIGH);
      delay(time1) ;
      digitalWrite(h1, LOW);
      digitalWrite(h2, LOW);
      digitalWrite(h3, LOW);
      digitalWrite(h4, LOW);
      digitalWrite(h5, LOW);
      delay(time2);
    }
    else if (melody[i] == "F") {
      Serial.println("F");
      digitalWrite(h1, HIGH);
      digitalWrite(h2, HIGH);
      digitalWrite(h3, HIGH);
      digitalWrite(h4, HIGH);
      digitalWrite(h6, HIGH);
      digitalWrite(h7, HIGH);
      delay(time1) ;
      digitalWrite(h1, LOW);
      digitalWrite(h2, LOW);
      digitalWrite(h3, LOW);
      digitalWrite(h4, LOW);
      digitalWrite(h6, LOW);
      digitalWrite(h7, LOW);
      delay(time2);
    }
    else if (melody[i] == "G") {
      Serial.println("G");
      digitalWrite(h1, HIGH);
      digitalWrite(h2, HIGH);
      digitalWrite(h3, HIGH);
      delay(time1) ;
      digitalWrite(h1, LOW);
      digitalWrite(h2, LOW);
      digitalWrite(h3, LOW);
      delay(time2);
    }
    else if (melody[i] == "A") {
      Serial.println("A");
      digitalWrite(h1, HIGH);
      digitalWrite(h2, HIGH);
      delay(time1) ;
      digitalWrite(h1, LOW);
      digitalWrite(h2, LOW);
      delay(time2);
    }
    else if (melody[i] == "B") {
      Serial.println("B");
      digitalWrite(h1, HIGH);
      delay(time1) ;
      digitalWrite(h1, LOW);
      delay(time2);
    }
    else if (melody[i] == "PAUSE") {
      Serial.println("PAUSE");
      delay(time1);
      delay(time2);
    }
    // "h1h4h6", "h3h5h7", "h1h2h3", "PAUSE",
    else if (melody[i] == "STOP") {
      Serial.println("STOPPING LOOP");
      exit(0);
    }
  }
}
