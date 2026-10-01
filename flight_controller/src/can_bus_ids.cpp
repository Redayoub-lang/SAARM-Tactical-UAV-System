#include "can_bus_ids.h"
#include

void UAV_CyberDefense_IDS::clean_stale_entries(uint64_t current_time)
{
    for (auto it = last_message_time.begin(); it != last_message_time.end();)
    {
        if (current_time - it->second > 1000000)
        {
            it = last_message_time.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

bool UAV_CyberDefense_IDS::verify_frame_integrity(const CAN_Frame &frame)
{
    clean_stale_entries(frame.timestamp_us);

    auto it = last_message_time.find(frame.message_id);
    if (it != last_message_time.end())
    {
        if ((frame.timestamp_us - it->second) < MIN_INJECTION_INTERVAL_US)
        {
            std::cerr << "[CYBER_SECURITY_ALERT] Rapid Packet Injection Detected! Message ID: " << frame.message_id << "\n";
            return false;
        }
    }

    last_message_time[frame.message_id] = frame.timestamp_us;
    return true;
}