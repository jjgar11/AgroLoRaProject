#include "utils.h"

bool parsePacketData(const String &packet, unsigned long &ts, float &t, float &h, float &p, int &m) {
  int parts[5];
  int idx = 0;
  int lastIndex = 0;

  for (int i = 0; i < packet.length(); i++) {
    if (packet[i] == ',' || i == packet.length() - 1) {
      String segment = packet.substring(lastIndex, (packet[i] == ',' ? i : i + 1));
      lastIndex = i + 1;
      switch (idx) {
        case 0: ts = segment.toInt(); break;
        case 1: t = segment.toFloat(); break;
        case 2: h = segment.toFloat(); break;
        case 3: p = segment.toFloat(); break;
        case 4: m = segment.toInt(); break;
        default: return false; // Más campos de los esperados
      }
      idx++;
    }
  }
  return idx == 5;
}
