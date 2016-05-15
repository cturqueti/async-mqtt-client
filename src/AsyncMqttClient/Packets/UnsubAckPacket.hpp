#pragma once

#include "Arduino.h"
#include "Packet.hpp"
#include "../ParsingInformation.hpp"
#include "../Callbacks.hpp"

namespace AsyncMqttClientInternals {
class UnsubAckPacket : public Packet {
 public:
  explicit UnsubAckPacket(ParsingInformation* parsingInformation, OnUnsubAckCallback callback);
  ~UnsubAckPacket();

  void parseVariableHeader(const char* data, size_t* currentBytePosition);
  void parsePayload(const char* data, size_t* currentBytePosition);

 private:
  ParsingInformation* _parsingInformation;
  OnUnsubAckCallback _callback;

  uint8_t _bytePosition;
  char _packetIdMsb;
  uint16_t _packetId;
};
}  // namespace AsyncMqttClientInternals