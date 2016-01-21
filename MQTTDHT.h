/*
 * MQTTDHT.h
 *
 *  Created on: Jan 18, 2016
 *      Author: root
 */

#ifndef MYDHT_MQTTDHT_H_
#define MYDHT_MQTTDHT_H_
#include "MyDHT.h"
#include "MQTT2.h"

class MQTTDHT: public MyDHT {
private:
	MQTT2 *mqttChannel;
	const String tempChannel;
	const String humChannel;
public:
	MQTTDHT(int p, int t, String c, MQTT2*pMQTT);
	virtual ~MQTTDHT();
	virtual void update();
};

#endif /* MYDHT_MQTTDHT_H_ */
