#pragma once
#include <Arduino.h>

bool parsePacketData(const String &packet, int &counter, float &t, float &h, float &p, int &m);
