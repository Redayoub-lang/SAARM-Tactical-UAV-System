#pragma once
#include

class EKF_Quaternion
{
private:
    Eigen::VectorXd x; // حالة النظام (10 عناصر)
    Eigen::MatrixXd P; // مصفوفة التباين المشترك للخطأ
    Eigen::MatrixXd Q; // مصفوفة ضوضاء العملية
    Eigen::MatrixXd R; // مصفوفة ضوضاء القياس

public:
    EKF_Quaternion();
    void predict(const Eigen::Vector3d &accel, const Eigen::Vector3d &gyro, double dt);
    void update(const Eigen::VectorXd &z);
    Eigen::VectorXd getState() const;
};