//data storage variables
byte newData = 0;
byte prevData = 0;
unsigned int time = 0;//keeps time and sends vales to store in timer[] occasionally
int timer[10];//storage for timing of events
int slope[10];//storage for slope of events
unsigned int totalTimer;//used to calculate period
unsigned int period;//storage for period of wave
byte index = 0;//current storage index
float frequency;//storage for frequency calculations
int maxSlope = 0;//used to calculate max slope as trigger point
int newSlope;//storage for incoming slope data

//variables for decided whether you have a match
byte noMatch = 0;//counts how many non-matches you've received to reset variables if it's been too long
byte slopeTol = 255;//slope tolerance- adjust this if you need
int timerTol = 10;//timer tolerance- adjust this if you need

//variables for amp detection
int ampTimer = 0;
byte maxAmp = 0;
byte checkMaxAmp;
byte ampThreshold = 50;//raise if you have a very noisy signal

void setup() {

  Serial.begin(9600);

  \\setting up the interrupt timer

  cli(); //disable interrupts = Clears the Global Interrupt flag

  //set up continuous sampling of analog pin 0 at 38.5kHz

  //clear ADCSRA and ADCSRB registers
  ADCSRA = 0; // setting analog to digital converter status register A to 0;
  ADCSRB = 0; // setting analog to digital converter status register B to 0;

  ADMUX |= (1 << REFS0); //set reference voltage - http://www.robotplatform.com/knowledge/ADC/adc_tutorial_3.html

  ADMUX |= (1 << ADLAR); //left align the ADC value- so we can read highest 8 bits from ADCH register only - ADC Left Adjust Result (ADLAR): Once the conversion is complete, result is stored in two ADC data registers ADCH and ADCL. This result can be either left justified or right justified. If ADLAR bit is set, then it is left adjusted, and clearing it will right justify the result. By default, bit is cleared and right justified.

  A multiway switch, also called a multiplexer or “mux, ” is used to configure the ADC and to switch the unit between multiple input pins. The next two lines set the ADC Multiplexer Selection Register (ADMUX): bits 7 and 6 of the register (REFS0 and REFS1) are used to set the reference voltage, and setting bit 5 (ADLAR) left - adjusts the results of the ADC conversion. In this example, values are adjusted so the highest eight bits can be read from the ADCH register.

      //BitMath left shifting values

      //http://www.avrbeginners.net/architecture/adc/adc.html#adcsr

      ADCSRA |= (1 << ADPS2) | (1 << ADPS0); //set ADC clock with 32 prescaler- 16mHz/32=500kHz
    ADCSRA |= (1 << ADATE); //enabble auto trigger (Analog to Digital Auto Trigger Enable)
    ADCSRA |= (1 << ADIE); //enable interrupts when measurement complete (Analog to Digital Interrupt Enable)
    ADCSRA |= (1 << ADEN); //enable ADC (ADC Enable)
    ADCSRA |= (1 << ADSC); //start ADC measurements (ADC Start Conversion)

    Prescalars
    The term prescalar refers to a divider that is used to reduce the rate that timers
    count pulses from a timebase. 5 The prescalar value is determined by a chart found
    in the ATmega datasheet (see Table 10.2). Setting ADPS2 and ADPS0 to 1 results
    in a prescalar of 32, so the timer frequency is 16mHz / 32 = 500kHz. Each conver -
        sion takes 13 clock cycles, 6 so the actual sample rate is 500kHz / 13 = 38.5 kHz.
            Listing 10.2 shows one approach to initializing the ADC with a prescalar.
            Note how the byte named data is declared as volatile because the value can be al -
            tered at any time within the timer function. The loop function is admittedly trivial,
            but it does demonstrate another approach to polling the input of the analog pin to
            see if a signal has exceeded a threshold. More advanced applications might include
            keeping a running total of samples to determine root mean square or to per -
            form Fourier analysis. (More information will be provided later in the chapter.)

              sei();//enable interrupts = Sets the Global Interrupt flag as above
  }

  ISR(ADC_vect) {//when new ADC value ready - ADC Conversion Complete Interrupt Service Routine (ISR)

  prevData = newData;//store previous value
  newData = ADCH;//get value from A0
  if (prevData < 127 && newData >= 127) { //if increasing and crossing midpoint
    newSlope = newData - prevData;//calculate slope
    if (abs(newSlope - maxSlope) < slopeTol) { //if slopes are ==
      //record new data and reset time
      slope[index] = newSlope;
      timer[index] = time;
      time = 0;
      if (index == 0) { //new max slope just reset
        noMatch = 0;
        index++;//increment index
      }
      else if (abs(timer[0] - timer[index]) < timerTol && abs(slope[0] - newSlope) < slopeTol) { //if timer duration and slopes match
        //sum timer values
        totalTimer = 0;
        for (byte i = 0; i < index; i++) {
          totalTimer += timer[i];
        }
        period = totalTimer;//set period
        //reset new zero index values to compare with
        timer[0] = timer[index];
        slope[0] = slope[index];
        index = 1;//set index to 1
        noMatch = 0;
      }
      else { //crossing midpoint but not match
        index++;//increment index
        if (index > 9) {
          reset();
        }
      }
    }
    else if (newSlope > maxSlope) { //if new slope is much larger than max slope
      maxSlope = newSlope;
      time = 0;//reset clock
      noMatch = 0;
      index = 0;//reset index
    }
    else { //slope 1 not steep enough
      noMatch++;//increment no match counter
      if (noMatch > 9) {
        reset();
      }
    }
  }

  time++;//increment timer at rate of 38.5kHz

  ampTimer++;//increment amplitude timer
  if (abs(127 - ADCH) > maxAmp) {
    maxAmp = abs(127 - ADCH);
  }
  if (ampTimer == 1000) {
    ampTimer = 0;
    checkMaxAmp = maxAmp;
    maxAmp = 0;
  }

}

void reset() { //clean out some variables
  index = 0;//reset index
  noMatch = 0;//reset match couner
  maxSlope = 0;//reset slope
}


void loop() {

  if (checkMaxAmp > ampThreshold) {
    frequency = 38462 / float(period); //calculate frequency timer rate/period

    //print results
    Serial.print(frequency);
    Serial.println(" hz");

  }

  delay(100);

}
