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
//���������κ���
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
	//src:��������
	//x,y �������
	//width,height:���ο��
	rectangle(src,Rect(x, y, width, height),Scalar(255,0,0));

}


//mciSendString("ָ��",0,0,0); open close play
void ShowImage()
{
	Mat img = imread("./mm.png");
	namedWindow("��ŮͼƬ");
	imshow("��ŮͼƬ", img);
	waitKey(6000);
}
void ShowVideo()
{
	VideoCapture cap = VideoCapture("1.mp4"); //����Ƶ
	if (!cap.isOpened())
	{
		cout << " Open Failed!" << endl;
		return ;
	}
	//��ȡ��Ƶ��С
	int width = cap.get(CAP_PROP_FRAME_WIDTH); // 3
	int height = cap.get(4);
	cout << "Open Sucess!" << endl;
	//2��ÿһ֡��������
	//C++��: IO��
	Mat video;
	Mat old;
	int flag = 1;
	vector<Rect> face;
	string face_file = "./haarcascade_frontalface_default.xml";//�����ļ���PATH
	//�������������
	CascadeClassifier object;
	//��������ز����ļ�
	object.load(face_file);
	//face.push_back(Rect(100, 100, 300, 300));
	while (cap.read(old)) // ÿ��ѭ����һ֡
	{
		
		face.clear();
		//��Сͼ����ٹ�����
		resize(old,video,Size(width/10,height/10));//ʮ��֮һ
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
//�������ͷ,��һ������ʶ��
void Show_Image()
{
	VideoCapture cap = VideoCapture(0);
	if (!cap.isOpened())
	{
		cout << "��ȡ����ͷʧ��!" << endl;
		return;
	}
	cout << "�򿪳ɹ�!" << endl;
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
	Show_Image();//����ͷ
	//ShowVideo();
	return 0;
}