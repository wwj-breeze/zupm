/*
 * Author: Jon Trulson <jtrulson@ics.com>
 * 		   Abhishek Malik <abhishek.malik@intel.com>
 * Copyright (c) 2016 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "grovemoisture.h"

struct _upm_grove_moisture {
	mraa_aio_context	aio;
	uint16_t 			analog_pin;
};

const char upm_grove_moisture_name[] = "Grove Moisture";
const char upm_grove_moisture_description[] = "Analog Grove Moisture Sensor";
const upm_protocol_t upm_grove_moisture_protocol[] = {UPM_ANALOG};
const upm_sensor_t upm_grove_moisture_category[] = {UPM_MOISTURE};


upm_sensor_descriptor_t upm_grove_moisture_get_descriptor (void* dev){
	upm_sensor_descriptor_t usd;
	usd.name = upm_grove_moisture_name;
	usd.description = upm_grove_moisture_description;
	usd.protocol_size = 1;
	usd.protocol = upm_grove_moisture_protocol;
	usd.category_size = 1;
	usd.category = upm_grove_moisture_category;
	return usd;
}

void* upm_grove_moisture_get_ft(upm_sensor_t sensor_type){
	if(sensor_type == UPM_MOISTURE){
		struct _upm_moisture_ft *mft = malloc(sizeof(*mft));
		if(mft == NULL){
			printf("Unable to assign memory to the Heart Rate Monitor structure");
			return NULL;
		}
		mft->upm_moisture_sensor_get_moisture = upm_grove_moisture_get_moisture;
		return mft;
	}
	if(sensor_type == UPM_SENSOR){
		struct _upm_sensor_ft *ft = malloc(sizeof(*ft));
		if(ft == NULL){
			printf("Unable to assign memory to the Heart Rate Monitor structure");
			return NULL;
		}
		ft->upm_sensor_init_name = upm_grove_moisture_init_name;
		ft->upm_sensor_close = upm_grove_moisture_close;
		ft->upm_sensor_read = upm_grove_moisture_read;
		ft->upm_sensor_write = upm_grove_moisture_write;
		return ft;
	}
	return NULL;
}

void* upm_grove_moisture_init_name(int num,...){
	upm_grove_moisture dev = (upm_grove_moisture) malloc(sizeof(struct _upm_grove_moisture));
	va_list pin_list;
	va_start(pin_list, num);
	if(dev == NULL){
		printf("Unable to assign memory to the Servo motor structure\n");
		return NULL;
	}

	dev->analog_pin = va_arg(pin_list, int);
	dev->aio = mraa_aio_init(dev->analog_pin);

	if(dev->aio == NULL){
		printf("Unable to open the AIO pin\n");
		return NULL;
	}

	return dev;
}

void* upm_grove_moisture_init(int pin){
	upm_grove_moisture dev = (upm_grove_moisture) malloc(sizeof(struct _upm_grove_moisture));
	if(dev == NULL){
		printf("Unable to assign memory to the Servo motor structure\n");
		return NULL;
	}

	dev->analog_pin = pin;
	dev->aio = mraa_aio_init(dev->analog_pin);

	if(dev->aio == NULL){
		printf("Unable to open the AIO pin\n");
		return NULL;
	}

	return dev;
}

void upm_grove_moisture_close(void* dev){
	upm_grove_moisture device = (upm_grove_moisture) dev;
	mraa_aio_close(device->aio);
	free(dev);
}

upm_result_t upm_grove_moisture_get_moisture(void* dev, int* moisture){
	upm_grove_moisture device = (upm_grove_moisture) dev;
	upm_grove_moisture_read(device, moisture, 0);
	return UPM_SUCCESS;
}

upm_result_t upm_grove_moisture_read(void* dev, void* data, int len){
	upm_grove_moisture device = (upm_grove_moisture) dev;
	int* int_data = data;
	*int_data = mraa_aio_read(device->aio);
	return UPM_SUCCESS;
}

upm_result_t upm_grove_moisture_write(void* dev, void* data, int len){
	return UPM_ERROR_NOT_IMPLEMENTED;
}