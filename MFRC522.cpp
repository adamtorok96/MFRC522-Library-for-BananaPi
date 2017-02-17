#include <exception>
#include "MFRC522.h"

MFRC522::MFRC522(const char *dev, unsigned int speed) {
    this->dev = dev;
    this->speed = speed;

    spi = open(dev, O_RDWR);

    if( spi < 0 )
        throw std::exception();

    wiringPiSetup();

    reset();
}

MFRC522::~MFRC522() {
    SpiClose();
}

void MFRC522::reset() {

}

void MFRC522::SpiWrite(char data) {
    struct spi_ioc_transfer message;

    memset(&message, 0, sizeof(message));

    message.tx_buf      = (unsigned long)data;
    message.rx_buf      = (unsigned long)data;
    message.len         = sizeof(data);
    message.delay_usecs     = 0;
    message.speed_hz        = speed;
    message.bits_per_word   = 8;
    message.cs_change       = 0;

    int ret = ioctl(spi, SPI_IOC_MESSAGE(1), message);

    if( ret < 0 )
        printf("error\n");
}

void MFRC522::SpiClose() {
    close(spi);
}
