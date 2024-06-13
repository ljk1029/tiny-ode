#include <iostream>

class PIDController {
private:
    double Kp;  // 比例增益
    double Ki;  // 积分增益
    double Kd;  // 微分增益
    double setpoint;  // 设定值
    double previous_error;  // 上一次误差
    double integral;  // 积分项

public:
    // 构造函数
    PIDController(double Kp, double Ki, double Kd, double setpoint) {
        this->Kp = Kp;
        this->Ki = Ki;
        this->Kd = Kd;
        this->setpoint = setpoint;
        this->previous_error = 0;
        this->integral = 0;
    }

    // 更新PID控制器状态并计算输出
    double update(double measurement, double dt) {
        double error = setpoint - measurement;
        integral += error * dt;
        double derivative = (error - previous_error) / dt;
        double output = Kp * error + Ki * integral + Kd * derivative;
        previous_error = error;
        return output;
    }
};

double get_measurement() {
    return 9.0;
}

double get_dt() {
    return 1.0;
}

int main() {
    // 创建PID控制器实例
    PIDController pid(0.5, 0.1, 0.2, 10.0);

    // 模拟控制循环
    for (int i = 0; i < 100; ++i) {
        // 获取测量值和时间间隔（这里只是用示意值代替）
        double measurement = get_measurement();
        double dt = get_dt();

        // 更新PID控制器并获取控制输出
        double control_output = pid.update(measurement, dt);

        // 应用控制输出（这里只是输出到控制台）
        std::cout << "Control Output: " << control_output << std::endl;
    }

    return 0;
}
