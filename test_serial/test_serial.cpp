// test_serial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tchar.h>
#include <windows.h>
#include "Serial.h"

int main()
{
    char buf[10];
    int ret;
    CSerial serial;
    ret = serial.Open(10, 9600);
    if (!ret) {
        printf("Open Serial port %d error.\n", 10);
        return -1;
    }
    for (int i = 0; i < 10; i++) {
        buf[i] = 0x55;
    }
    while (1) {
        serial.SendData(buf, 10);
        Sleep(100);
    }
    return ret;
}

