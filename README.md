# Background

**crc8.ino**, if loaded onto an Arduino board, will generate the appropriate CRC8 checksum for a given string input and choice of CRC8 input polynomial, and prints it to the serial port.

**crc8.js**, loaded into **index.html**, logs the CRC8 checkum for a given string input and choice of CRC8 polynomial, and logs it to console.log.

Using same string inputs and polynomials, this might be useful for seeing whether a string generated on the Arduino has been communicated successfully to browser.

The idea would be to generate the checksum for any given text to be sent from the Arduino, and append it to the message.  Then the browser can parse the input message, generate the checksum for it, and compare it to the checksum sent by the Arduino.
