#include <hFramework.h>
#include <stdio.h>

#include "Mindsensors_LineLeader.h"

using namespace hFramework;
using namespace hSensors;

void hMain(void)
{
	sys.setLogDev(&Serial);

	Mindsensors_LineLeader sensor(hSens1);
	sensor.setKp(25,32);
	sensor.setKi(1,255);
	sensor.setKd(8,33);
	sensor.setPoint(45);

	for (;;)
	{
		uint8_t kp, kpf, ki, kif, kd, kdf, setp, av, result;
		uint8_t whitethreshold[8];
		uint8_t blackthreshold[8];
		uint8_t raw[8];
		int8_t uncalibrated[8];
		int8_t steering;
		LED1.toggle();
		sensor.readKp(kp);
		sensor.readKpFactor(kpf);
		sensor.readKi(ki);
		sensor.readKiFactor(kif);
		sensor.readKd(kd);
		sensor.readKdFactor(kdf);
		sensor.readsetPoint(setp);
		sensor.readWhiteThresh(whitethreshold);
		sensor.readBlackThresh(blackthreshold);
		sensor.readAverage(av);
		sensor.readResult(result);
		sensor.readSensorRaw(raw);
		sensor.readSensorUncalibrated(uncalibrated);
		printf("PID values: Kp = %d, Kp_factor = %d , Ki = %d, Ki_factor = %d, Kd = %d, Kd_factor = %d \r\n", kp, kpf, ki, kif, kd, kdf);
		printf("Set point values: %d, average: %d, ubyte value with each bit equal to a sensor: %d \r\n", setp, av, result);
		printf("Raw values from all sensors: ");
		for(int i = 0; i < 9; i++)
		{
			printf("%d, ", raw[i]);
		}
		printf("\r\n Uncalibrated values from all sensors: ");
		for(int i = 0; i < 9; i++)
		{
			printf("%d, ", uncalibrated[i]);
		}
		printf("\r\n White Threshold values from all sensors: ");
		for(int i = 0; i < 9; i++)
		{
			printf("%d, ", whitethreshold[i]);
		}
		printf("\r\n Black Threshold values from all sensors: ");
		for(int i = 0; i < 9; i++)
		{
			printf("%d, ", whitethreshold[i]);
		}
		printf("Steering value: %d", steering);
		sys.delay_ms(10);
	}
}
