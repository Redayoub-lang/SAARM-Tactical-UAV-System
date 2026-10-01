#pragma once
#include
#include
#include

struct CAN_Frame
{
    uint32_t message_id;
    uint8_t payload[8];
    uint64_t timestamp_us;
    std::string cryptographic_signature;
};

class UAV_CyberDefense_IDS
{
private:
    std::unordered_map last_message_time;
    const uint64_t MIN_INJECTION_INTERVAL_US = 5000; // 5ms الحد الأدنى لمنع هجمات Dos
    void clean_stale_entries(uint64_t current_time);

public:
    bool verify_frame_integrity(const CAN_Frame &frame);
};