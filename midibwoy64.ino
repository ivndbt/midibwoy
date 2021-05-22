/* Buttons to USB MIDI Example

   You must select MIDI from the "Tools > USB Type" menu

   To view the raw MIDI data on Linux: aseqdump -p "Teensy MIDI"

   This example code is in the public domain.
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 2;
int m = 0;
const int debounce = 7;
const int vel = 99;

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, debounce);
Bounce button1 = Bounce(1, debounce);  // 5 = 5 ms debounce time
Bounce button2 = Bounce(2, debounce);  // which is appropriate for good
Bounce button3 = Bounce(3, debounce);  // quality mechanical pushbuttons
Bounce button4 = Bounce(4, debounce);
Bounce button5 = Bounce(5, debounce);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, debounce);  // to rapid touch, you can
Bounce button7 = Bounce(7, debounce);  // increase this time.
Bounce button8 = Bounce(8, debounce);
Bounce button9 = Bounce(9, debounce);
Bounce button10 = Bounce(10, debounce);
Bounce button11 = Bounce(11, debounce);
Bounce button12 = Bounce(12, debounce);
Bounce button13 = Bounce(14, debounce);  //NO 13
Bounce button14 = Bounce(15, debounce);
Bounce button15 = Bounce(16, debounce);
    //4 BANKS
Bounce bank0 = Bounce(17, debounce);
Bounce bank1 = Bounce(18, debounce);
Bounce bank2 = Bounce(19, debounce);
Bounce bank3 = Bounce(20, debounce);

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP); 
  pinMode(12, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);  //NO 13
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();
  button12.update();
  button13.update();
  button14.update();
  button15.update();
  bank0.update();
  bank1.update();
  bank2.update();
  bank3.update();

  // Check each button for "falling" edge.
  // Send a MIDI Note On message when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.fallingEdge()) {
    usbMIDI.sendNoteOn(m+48, vel, channel);  //48= C2
  }
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOn(m+49, vel, channel);  // C#2
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(m+50, vel, channel);  // D2
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOn(m+51, vel, channel);  // D#2
  }
  if (button4.fallingEdge()) {
    usbMIDI.sendNoteOn(m+52, vel, channel);  // E2
  }
  if (button5.fallingEdge()) {
    usbMIDI.sendNoteOn(m+53, vel, channel);  // F2
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendNoteOn(m+54, vel, channel);  // F#2
  }
  if (button7.fallingEdge()) {
    usbMIDI.sendNoteOn(m+55, vel, channel);  // G2
  }
  if (button8.fallingEdge()) {
    usbMIDI.sendNoteOn(m+56, vel, channel);  // G#2
  }
  if (button9.fallingEdge()) {
    usbMIDI.sendNoteOn(m+57, vel, channel);  // A2
  }
  if (button10.fallingEdge()) {
    usbMIDI.sendNoteOn(m+58, vel, channel);  // A#2
  }
  if (button11.fallingEdge()) {
    usbMIDI.sendNoteOn(m+59, vel, channel);  // B2
  }
  if (button12.fallingEdge()) {
    usbMIDI.sendNoteOn(m+60, vel, channel);  // C3,E4,G#5,C7
  }
  if (button13.fallingEdge()) {
    usbMIDI.sendNoteOn(m+61, vel, channel);  // C#3
  }
  if (button14.fallingEdge()) {
    usbMIDI.sendNoteOn(m+62, vel, channel);  // D3
  }
  if (button15.fallingEdge()) {
    usbMIDI.sendNoteOn(m+63, vel, channel);  // D#3
  }
  
          //SWITCH BANK
//  if (bank0.fallingEdge()) {
//    m = 0;                         //mode0
//  }
//  if (bank1.fallingEdge()) {
//    m = 16;                        //mode1
//  }
//  if (bank2.fallingEdge()) {
//    m = 32;                        //mode2
//  }
//  if (bank3.fallingEdge()) {
//    m = 48;                        //mode3
//  }


  // Check each button for "rising" edge
  // Send a MIDI Note Off message when each button releases
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.risingEdge()) {
    usbMIDI.sendNoteOff(m+48, 0, channel);
  }
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOff(m+49, 0, channel);
  }
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(m+50, 0, channel);
  }
  if (button3.risingEdge()) {
    usbMIDI.sendNoteOff(m+51, 0, channel);
  }
  if (button4.risingEdge()) {
    usbMIDI.sendNoteOff(m+52, 0, channel);
  }
  if (button5.risingEdge()) {
    usbMIDI.sendNoteOff(m+53, 0, channel);
  }
  if (button6.risingEdge()) {
    usbMIDI.sendNoteOff(m+54, 0, channel);
  }
  if (button7.risingEdge()) {
    usbMIDI.sendNoteOff(m+55, 0, channel);
  }
  if (button8.risingEdge()) {
    usbMIDI.sendNoteOff(m+56, 0, channel);
  }
  if (button9.risingEdge()) {
    usbMIDI.sendNoteOff(m+57, 0, channel);
  }
  if (button10.risingEdge()) {
    usbMIDI.sendNoteOff(m+58, 0, channel);
  }
  if (button11.risingEdge()) {
    usbMIDI.sendNoteOff(m+59, 0, channel);
  }
  if (button12.fallingEdge()) {
    usbMIDI.sendNoteOff(m+60, 0, channel);
  }
  if (button13.fallingEdge()) {
    usbMIDI.sendNoteOff(m+61, 0, channel);
  }
  if (button14.fallingEdge()) {
    usbMIDI.sendNoteOff(m+62, 0, channel);
  }
  if (button15.fallingEdge()) {
    usbMIDI.sendNoteOff(m+63, 0, channel);
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}
