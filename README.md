# Toll Tax System using RFID Module 
This Arduino code is designed to automate a toll collection system using an RFID module, servo motors, and an LCD display. The system verifies RFID cards, deducts balance, and controls gate access using servo motors, with visual and audio feedback.
## Hardware Setup:
- RFID Module: MFRC522 connected via SPI (SS - pin 10, RST - pin 9).
* Servo Motors: Two servos (barrier control) connected to pins 2 and 5.
+ LCD Display: I2C LCD (16x2) at address 0x27.
+ Indicators: Green LED (pin 7), Red LED (pin 6), Buzzer (pin 3) for status indication.

Functions:
## Functions:
### 1.  setup():

   - Initializes RFID, servos, LCD, and I/O pins.
   * Displays a welcome message and sets initial gate positions.
   + Sets up initial balance and toll amount.
### 2. loop():

   - Continuously checks for new RFID card scans.
   * Validates the card against a predefined UID.
   * If valid and balance is sufficient, toll is deducted and gate opens.
   * If invalid or low balance, access is denied with appropriate message and indicators.
### 3. isValidCard():

   - Compares scanned UID with the stored valid UID.
### 4. openGate():

   - Displays success message and balance on LCD.
   - Opens the gate by rotating servos in opposite directions.
   - Turns on green LED and keeps gate open for 3 seconds before closing.
### 5. denyAccess():

   - Displays access denied message.
   * Activates red LED and buzzer.
### 6. showInsufficientBalance ():

   -Displays low balance warning and prompts to add funds.
   *Red LED flashes as indicator.
## Control Logic:
   - Gate opens only when a valid card is scanned and sufficient balance is available.
   - Toll amount is deducted from stored balance on each successful scan.
   - Invalid or low-balance cards trigger warning indicators and gate remains closed.

## Serial Output:
   - Prints scanned RFID card UID for debugging and verification.
