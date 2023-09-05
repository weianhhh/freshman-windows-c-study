#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <windows.h>
#include <mmsystem.h>
#define PR(fmt,val) printf(#val"=%"#fmt"\t",(val))
#pragma comment(lib,"winmm.lib")
using namespace std;
using namespace cv;
//画人脸矩形函数
bool DrawFace(Mat& src, vector<Rect>& face,int scaleX=10,int scaleY=10)
{
	if (face.empty())
	{
		return false;
	}
	int x = face[0].tl().x*scaleX;
	int y = face[0].tl().y*scaleY;
	int width = face[0].width;
	int height = face[0].height;
	//src:画在哪里
	//x,y 矩形起点
	//width,height:矩形宽高
	rectangle(src,Rect(x, y, width, height),Scalar(255,0,0));

}


//mciSendString("指令",0,0,0); open close play
void ShowImage()
{
	Mat img = imread("./mm.png");
	namedWindow("美女图片");
	imshow("美女图片", img);
	waitKey(6000);
}
void ShowVideo()
{
	VideoCapture cap = VideoCapture("1.mp4"); //打开视频
	if (!cap.isOpened())
	{
		cout << " Open Failed!" << endl;
		return ;
	}
	//获取视频大小
	int width = cap.get(CAP_PROP_FRAME_WIDTH); // 3
	int height = cap.get(4);
	cout << "Open Sucess!" << endl;
	//2。每一帧给导出来
	//C++流: IO流
	Mat video;
	Mat old;
	int flag = 1;
	vector<Rect> face;
	string face_file = "./haarcascade_frontalface_default.xml";//采样文件的PATH
	//创建人脸检测器
	CascadeClassifier object;
	//检测器加载采样文件
	object.load(face_file);
	//face.push_back(Rect(100, 100, 300, 300));
	while (cap.read(old)) // 每次循环读一帧
	{
		
		face.clear();
		//缩小图像减少工作量
		resize(old,video,Size(width/10,height/10));//十分之一
		object.detectMultiScale(video, face);
		if (DrawFace(old, face))
		{
			if (flag == 1)
			{
				mciSendString(L"open 1.mp3", 0, 0, 0);
				mciSendString(L"play 1.mp3", 0, 0, 0);
				flag++;
			}
			imshow("video", video);
			waitKey(30);
		}
		DrawFace(video, face);
		imshow("video", video);
		waitKey(15);
	}
	video.release();
	return;
}
//结合摄像头,做一个人脸识别
void Show_Image()
{
	VideoCapture cap = VideoCapture(0);
	if (!cap.isOpened())
	{
		cout << "获取摄像头失败!" << endl;
		return;
	}
	cout << "打开成功!" << endl;
	Mat img;
	while (cap.read(img)) {
		imshow("image",img);
		waitKey(30);
	}
	cap.release();
}
int main()
{
	PR(d,5);
	//ShowImage();
	Show_Image();//摄像头
	//ShowVideo();
	return 0;
}