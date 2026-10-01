#include "ekf_quaternion.h"

EKF_Quaternion::EKF_Quaternion()
{
    x = Eigen::VectorXd::Zero(10);
    x(6) = 1.0; // Quaternion qw = 1 (حالة التعامد الأولية)

    P = Eigen::MatrixXd::Identity(10, 10) * 0.1;
    Q = Eigen::MatrixXd::Identity(10, 10) * 0.01;
    R = Eigen::MatrixXd::Identity(6, 6) * 0.05;
}

void EKF_Quaternion::predict(const Eigen::Vector3d &accel, const Eigen::Vector3d &gyro, double dt)
{
    double qw = x(6), qx = x(7), qy = x(8), qz = x(9);

    Eigen::Matrix4d Omega;
    Omega << 0, -gyro(0), -gyro(1), -gyro(2),
        gyro(0), 0, gyro(2), -gyro(1),
        gyro(1), -gyro(2), 0, gyro(0),
        gyro(2), gyro(1), -gyro(0), 0;

    Eigen::Vector4d q;
    q << qw, qx, qy, qz;
    q = q + 0.5 * dt * (Omega * q);
    q.normalize(); // الحفاظ على شرط التعامد الخطي (Unit Quaternion)

    x.segment(0, 3) += x.segment(3, 3) * dt + 0.5 * accel * dt * dt;
    x.segment(3, 3) += accel * dt;
    x.segment(6, 4) = q;

    Eigen::MatrixXd F = Eigen::MatrixXd::Identity(10, 10);
    F.block<3, 3>(0, 3) = Eigen::Matrix3d::Identity() * dt;
    P = F * P * F.transpose() + Q;
}

void EKF_Quaternion::update(const Eigen::VectorXd &z)
{
    Eigen::MatrixXd H = Eigen::MatrixXd::Zero(6, 10);
    H.block<6, 6>(0, 0) = Eigen::MatrixXd::Identity(6, 6);

    Eigen::MatrixXd S = H * P * H.transpose() + R;
    Eigen::MatrixXd K = P * H.transpose() * S.inverse();

    Eigen::VectorXd y = z - H * x;
    x = x + K * y;
    P = (Eigen::MatrixXd::Identity(10, 10) - K * H) * P;

    x.segment(6, 4).normalize();
}

Eigen::VectorXd EKF_Quaternion::getState() const
{
    return x;
}