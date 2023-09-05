#include <opencv2/opencv.hpp>

int main() {
    // 读取图像
    cv::Mat background = cv::imread("ascii.jpg");
    cv::Mat mainObject = cv::imread("Tank.jpg");

    // 确保图像尺寸相同
    cv::resize(mainObject, mainObject, background.size());

    // 合并图像
    double alpha = 0.5;  // 设置透明度
    cv::Mat blendedImage;
    cv::addWeighted(background, 1 - alpha, mainObject, alpha, 0.0, blendedImage);

    // 显示结果
    cv::imshow("Blended Image", blendedImage);
    cv::waitKey(0);
    return 0;
}
