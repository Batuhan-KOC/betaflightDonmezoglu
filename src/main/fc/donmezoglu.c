#include "donmezoglu.h"

#include "../io/serial.h"

static serialPort_t* dSerialPort = NULL;

static bool dInitializationCompleted = false;

static timeUs_t dTimePoint = 0;

void taskDonmezoglu(timeUs_t currentTimeUs){
    UNUSED(currentTimeUs);

    // Complete initialization if it is not completed yet
    if(!dInitializationCompleted){

        serialPortUsage_t* usage = findSerialPortUsageByIdentifier(SERIAL_PORT_UART5);

        if(usage != NULL){
            dSerialPort = usage->serialPort;
        }
        else{
            dSerialPort = openSerialPortSafe(
            SERIAL_PORT_UART5,
            FUNCTION_NONE,
            NULL,
            NULL,
            BAUD_9600,
            MODE_RXTX,
            SERIAL_NOT_INVERTED | SERIAL_BIDIR
            );
        }

        dInitializationCompleted = true;
    }

    if(currentTimeUs - dTimePoint > 1000000){
        if(dSerialPort != NULL){
            serialWrite(dSerialPort, 'R');
        }

        dTimePoint = currentTimeUs;
    }
}