/**
 ******************************************************************************
 * \file    lego.h
 * \author  Husarion team
 * \version V0.9
 * \date    2-June-2014
 * \brief   Provides interface for Lego Touch sensor.
 ******************************************************************************
 * \details This file is part of robocore-sensors library.
 *
 * \copyright Copyright (C) 2014 Husarion Sp. z o.o. <husarion.com> - All Rights Reserved.
 * Unauthorized copying of this file and the robocore-sensors library,
 * via any medium is strictly prohibited. Proprietary and confidential.
 *
 * \attention
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */

#ifndef __LEGO_H__
#define __LEGO_H__

#include <hFramework.h>

class tLegoSensor
{
public:
	ISensor &sens;
	bool initialized;
	int mode, state;
	
	tLegoSensor(ISensor& sens) : sens(sens), initialized(false) { }
	~tLegoSensor()
	{
		deinit();
	}
	void deinit()
	{
		sens.selectGPIO();
		sens.getPinIntAdc().disableADC();
		sens.getPin1().setIn();
		sens.getPin2().setIn();
		initialized = false;
	}
};

class tLegoSensor_i2c
{
public:
	ISensor_i2c &sens;
	bool initialized;
	int mode, state;

	tLegoSensor_i2c(ISensor_i2c& sens) : sens(sens), initialized(false) { }
	~tLegoSensor_i2c()
	{
		deinit();
	}
	void deinit()
	{
		sens.selectGPIO();
		sens.getPinIntAdc().disableADC();
		sens.getPin1().setIn();
		sens.getPin2().setIn();
		initialized = false;
	}
};

#endif