# SAARM: Autonomous Aerial Reconnaissance & Multimodal Fusion

![C++17](https://img.shields.io/badge/Standard-C%2B%2B17-blue)
![AI](https://img.shields.io/badge/AI-Python%203.10-yellow)

An advanced R&D architecture for UAVs operating in GPS-denied and Electronic Warfare environments.

## Subsystems
1. **Flight Controller (C++)**: EKF (Quaternion) + ZTA CAN Bus IDS.
2. **Edge AI (Python)**: TensorRT Multimodal Fusion (Radar + Thermal).
3. **Cognitive ECCM**: Deep Q-Network for Anti-Jamming.
4. **Tactical C2**: Low-latency Qt/QML Dashboard.
