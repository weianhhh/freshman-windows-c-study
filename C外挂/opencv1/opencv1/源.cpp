#include <opencv2/opencv.hpp>

int main() {
    // ��ȡͼ��
    cv::Mat background = cv::imread("ascii.jpg");
    cv::Mat mainObject = cv::imread("Tank.jpg");

    // ȷ��ͼ��ߴ���ͬ
    cv::resize(mainObject, mainObject, background.size());

    // �ϲ�ͼ��
    double alpha = 0.5;  // ����͸����
    cv::Mat blendedImage;
    cv::addWeighted(background, 1 - alpha, mainObject, alpha, 0.0, blendedImage);

    // ��ʾ���
    cv::imshow("Blended Image", blendedImage);
    cv::waitKey(0);
    return 0;
}
