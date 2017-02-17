#ifndef BANANAPI_MFRC522_MFRC522_H
#define BANANAPI_MFRC522_MFRC522_H

#include <cstdio>
#include <cstring>

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#include <wiringPi.h>

class MFRC522 {

    int spi;

    const char *dev;
    unsigned int speed;

    void reset();
    void SpiWrite(char data);
    void SpiClose();


public:

    MFRC522(const char *dev = "/dev/spidev0.0", unsigned int speed = 1000000);
    ~MFRC522();
};


#endif //BANANAPI_MFRC522_MFRC522_H
