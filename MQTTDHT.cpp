/*
 * MQTTDHT.cpp
 *
 *  Created on: Jan 18, 2016
 *      Author: root
 */

#include <MQTTDHT.h>

MQTTDHT::MQTTDHT(int p, int t, String c, MQTT2*pMQTT) :
		MyDHT(p, t), tempChannel(
				"esp/" + c + "/temperature"), humChannel(
				"esp/" + c + "/humidity") {
mqttChannel = pMQTT;
}

MQTTDHT::~MQTTDHT() {
}
void MQTTDHT::update() {
	MyDHT::update();
	if (isTemperatureValid()) {
		String temp = String(getTemperature());
		mqttChannel->publish(tempChannel, temp);
	}

	if (isHumidityValid())
		mqttChannel->publish(humChannel, String(getHumidity()));

}
