typedef uint8_t crc;
#define POLYNOMIAL 0x07  /* CRC8_CCITT -- this polynomial needs to match choice on javascript end */
#define WIDTH  (8 * sizeof(crc))
#define TOPBIT (1 << (WIDTH - 1))

crc  crcTable[256];


void crcInit(void)
{
    crc  remainder;

    for (int dividend = 0; dividend < 256; ++dividend)
    {
        remainder = dividend << (WIDTH - 8);

        
        for (uint8_t bit = 8; bit > 0; --bit)
        {  
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }

        crcTable[dividend] = remainder;
    }

}


crc crcFast(uint8_t const message[], int nBytes)
{
    uint8_t data;
    crc remainder = 0;


    for (int byte = 0; byte < nBytes; ++byte)
    {
        data = message[byte] ^ (remainder >> (WIDTH - 8));
        remainder = crcTable[data] ^ (remainder << 8);
    }

   
    return (remainder);

}  


void setup() {
  
  Serial.begin(9600);
  crcInit();
}

void loop() {


unsigned char  test[] = "hello";
Serial.println(crcFast(test, strlen(test)));
//Serial.println("hello");

delay(1000);


}


