typedef uint8_t crc;
//#define POLYNOMIAL 0xD8  /* 11011 followed by 0's */

#define POLYNOMIAL 0x07  /* CRC8_CCITT */


#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:


unsigned char  test[] = "hello";
Serial.println(crcSlow(test, strlen(test)));
//Serial.println("hello");

delay(1000);


}


crc crcSlow(uint8_t const message[], int nBytes)
{
    crc  remainder = 0;  


    /*
     * Perform modulo-2 division, a byte at a time.
     */
    for (int byte = 0; byte < nBytes; ++byte)
    {
        /*
         * Bring the next byte into the remainder.
         */
        remainder ^= (message[byte] << (WIDTH - 8));

        /*
         * Perform modulo-2 division, a bit at a time.
         */
        for (uint8_t bit = 8; bit > 0; --bit)
        {
            /*
             * Try to divide the current data bit.
             */
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
    }

    /*
     * The final remainder is the CRC result.
     */
    return (remainder);

}   /* crcSlow() */
