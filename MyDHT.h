/*
 * MyDHT.h
 *
 *  Created on: Dec 24, 2015
 *      Author: root
 */

#ifndef MYDHT_H_
#define MYDHT_H_

#include <DHT.h>
#include "Time.h"

class MyDHT {
private:
	struct info {
		float val;
		time_t t;
		boolean valid;
	};
	info temperature;
	info humidity;
	DHT dht;
protected:
	void update(time_t current);
public:
	MyDHT(int p, int t) :
			dht(p, t) {
	}
	virtual ~MyDHT() {
	}
	virtual void update() {
		update(now());
	}
	boolean isTemperatureValid() const {
		return temperature.valid;
	}
	boolean isHumidityValid() const {
		return humidity.valid;
	}
	time_t getTemperatureTime() const {
		return temperature.t;
	}
	time_t getHumidityTime() const {
		return humidity.t;
	}
	float getTemperature() const {
		return temperature.val;
	}
	float getHumidity() const {
		return humidity.val;
	}
	void begin() {
		dht.begin();
	}

};

#endif /* MYDHT_H_ */
