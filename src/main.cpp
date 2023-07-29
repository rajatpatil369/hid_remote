#include <Arduino.h>
#include <IrNec.h>
#include <DigiKeyboard.h>

void setup(void) {
  nsIrNec::begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(void) {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(KEY_NOKEY);
  nsIrNec::loop();
  if (nsIrNec::dataOut != 0) {
    digitalWrite(LED_BUILTIN, HIGH);
    if (nsIrNec::dataOut == 0x00F700FF) {
        DigiKeyboard.sendKeyStroke(KEY_RIGHT);
        // DigiKeyboard.sendKeyStroke(KEY_R);
    } else if (nsIrNec::dataOut == 0x00F7807F) {
        DigiKeyboard.sendKeyStroke(KEY_LEFT);
        // DigiKeyboard.sendKeyStroke(KEY_L);
    }
    nsIrNec::dataOut = 0;
    digitalWrite(LED_BUILTIN, LOW);
  }  
}
