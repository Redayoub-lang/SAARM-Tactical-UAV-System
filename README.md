# SAARM: Autonomous Aerial Reconnaissance & Multimodal Fusion Architecture

![C++17](https://img.shields.io/badge/Standard-C%2B%2B17-blue)
![Python 3.10](https://img.shields.io/badge/AI-Python%203.10-yellow)
![Qt 5.15](https://img.shields.io/badge/C2-Qt%2FQuick-green)
![License](https://img.shields.io/badge/License-MIT-lightgrey)

**SAARM (Système Aérostatique Autonome de Reconnaissance Multimodale)** is a production-grade C++/Python R&D framework engineered for Unmanned Aerial Vehicles (UAVs) operating in GPS-denied environments and highly contested Electronic Warfare (EW) spectrums.

## ⚙️ Core Subsystems

1. **Flight Controller Core (C++17/Eigen)**: Quaternion-based Extended Kalman Filter (EKF) ensuring singularity-free state estimation, integrated with a Zero-Trust Architecture (ZTA) CAN Bus Intrusion Detection System (IDS).
2. **Edge AI Engine (Python/PyCUDA)**: Asynchronous parallel sensor fusion combining Synthetic Aperture Radar (SAR) and Electro-Optical/Infrared (EO/IR) point streams via TensorRT streams.
3. **Cognitive ECCM (PyTorch)**: Reinforcement Learning agent executing adaptive Frequency Hopping Spread Spectrum (FHSS) powered by a Deep Q-Network (DQN) to mitigate broadband jamming.
4. **Tactical C2 Command Station (C++/Qt/QML)**: Low-latency telemetry dashboard rendering real-time kinematics, EW spectrum threat levels, and target lock state.

## 📐 Mathematical Formulation

The kinematic navigation filter tracks orientation via unit quaternions:

$$
\mathbf{x} = \begin{bmatrix} p_x & p_y & p_z & v_x & v_y & v_z & q_w & q_x & q_y & q_z \end{bmatrix}^T
$$

The Cognitive EW module minimizes the Temporal Difference error:

$$
L(\theta) = \mathbb{E} \left[ \left( r_t + \gamma \max_{a'} Q(s_{t+1}, a'; \theta^-) - Q(s_t, a_t; \theta) \right)^2 \right]
$$

## 🚀 Execution & Build Instructions

```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
./ground_c2_station/TacticalC2Station
