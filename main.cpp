#include "opencv2/opencv.hpp"
#include <iostream>
#include <conio.h>
#include <boost/thread.hpp>
# include <iostream>
# include <Windows.h>
# include <MMSystem.h>

using namespace std;
using namespace cv;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120

boost::mutex mutex;



void playvideo(int* a)
{
	
	
	VideoCapture cap;
	int frame_counter;
	Mat frame;

	bool ret1;
	bool ret2;
	bool ret3;
	bool ret4;
	

	ret1 = true;
	

	boost::mutex::scoped_try_lock lock(mutex);


	while (1) {

		//cout << "X is now: " << *a << endl;
			
		if (*a == 1) {

			if (ret1 == true)
			{
				cap.release();
				cap.open("MAIN.mov");
				frame_counter = 0;
				ret4 = true;
				ret3 = true;
				ret2 = true;
				ret1 = false;	
			}

			if (frame_counter == cap.get(CV_CAP_PROP_FRAME_COUNT)) {
				cout << "Video Ended" << endl;
				frame_counter = 0;
				cap.set(CV_CAP_PROP_POS_FRAMES, 120);
			}

			cap >> frame;
			frame_counter += 1;

			if (!frame.empty()) {
				// Display the resulting frame			
				cvNamedWindow("Frame", CV_WINDOW_NORMAL);
				cvSetWindowProperty("Frame", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
				imshow("Frame", frame);
			}

			// Press  ESC on keyboard to exit
			char c = (char)waitKey(25);
			if (c == 27)
				break;

		}

		if (*a == 2) {

			if (ret2 == true)
			{
				cap.release();
				cap.open("PRODUCT.mov");
				frame_counter = 0;
				ret4 = true;
				ret3 = true;
				ret2 = false;
				ret1 = true;
			}

			if (frame_counter == cap.get(CV_CAP_PROP_FRAME_COUNT)) {
				cout << "Video Ended" << endl;
				frame_counter = 0;
				cap.set(CV_CAP_PROP_POS_FRAMES, 102);
			}

			cap >> frame;
			frame_counter += 1;

			if (!frame.empty()) {
				// Display the resulting frame
				cvNamedWindow("Frame", CV_WINDOW_NORMAL);
				cvSetWindowProperty("Frame", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
				imshow("Frame", frame);
			}

			// Press  ESC on keyboard to exit
			char c = (char)waitKey(25);
			if (c == 27)
				break;

		}

		if (*a == 3) {

			if (ret3 == true)
			{
				cap.release();
				cap.open("SERVICE.mov");
				frame_counter = 0;
				ret4 = true;
				ret3 = false;
				ret2 = true;
				ret1 = true;
			}

			if (frame_counter == cap.get(CV_CAP_PROP_FRAME_COUNT)) {
				cout << "Video Ended" << endl;
				frame_counter = 0;
				cap.set(CV_CAP_PROP_POS_FRAMES, 102);
			}

			cap >> frame;
			frame_counter += 1;

			if (!frame.empty()) {
				// Display the resulting frame
				cvNamedWindow("Frame", CV_WINDOW_NORMAL);
				cvSetWindowProperty("Frame", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
				imshow("Frame", frame);
			}

			// Press  ESC on keyboard to exit
			char c = (char)waitKey(25);
			if (c == 27)
				break;

		}

		if (*a == 4) {

			if (ret4 == true)
			{
				cap.release();
				cap.open("PEOPLE.mov");
				frame_counter = 0;
				ret4 = false;
				ret3 = true;
				ret2 = true;
				ret1 = true;
			}

			if (frame_counter == cap.get(CV_CAP_PROP_FRAME_COUNT)) {
				cout << "Video Ended" << endl;
				frame_counter = 0;
				cap.set(CV_CAP_PROP_POS_FRAMES, 102);
			}

			cap >> frame;
			frame_counter += 1;

			if (!frame.empty()) {
				// Display the resulting frame
				cvNamedWindow("Frame", CV_WINDOW_NORMAL);
				cvSetWindowProperty("Frame", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
				imshow("Frame", frame);
			}

			// Press  ESC on keyboard to exit
			char c = (char)waitKey(25);
			if (c == 27)
				break;

		}
	

	}
}


void playsound(int*b)
{

	bool play1;
	bool play2;
	bool play3;
	bool play4;

	play1 = true;
	play2 = true;
	play3 = true;
	play4 = true;

	boost::mutex::scoped_try_lock lock(mutex);

	while (1) {
		
		if (*b == 1) {
			if (play1 == true) {
				//cout << "play1" << endl;
				PlaySound(TEXT("MAIN.wav"), NULL, SND_ASYNC);
				play1 = false;
				play2 = true;
				play3 = true;
				play4 = true;
			}
		}

		if (*b == 2) {
			if (play2 == true) {
				//cout << "play2" << endl;
				PlaySound(TEXT("PRODUCT.wav"), NULL, SND_ASYNC);
				play1 = true;
				play2 = false;
				play3 = true;
				play4 = true;
			}
		}

		if (*b == 3) {
			if (play3 == true) {
				//cout << "play3" << endl;
				PlaySound(TEXT("SERVICE.wav"), NULL, SND_ASYNC);
				play1 = true;
				play2 = true;
				play3 = false;
				play4 = true;
			}
		}

		if (*b == 4) {
			if (play4 == true) {
				//cout << "play4" << endl;
				PlaySound(TEXT("PEOPLE.wav"), NULL, SND_ASYNC);
				play1 = true;
				play2 = true;
				play3 = true;
				play4 = false;
			}
		}


	}

}

int main() {
	
	
	int x;

	x = 0;
	
	
	boost::thread getvideo (playvideo,&x);

	boost::thread soundplay(playsound, &x);

	char key = getch();
	int value = key;

	while (value != KEY_X) {

		switch (getch()) {

		case KEY_UP:
			x = 1;
			cout << "X is now: " << x << endl;
			break;
		case KEY_DOWN:
			x = 2;
			cout << "X is now: " << x << endl;
			break;
		case KEY_LEFT:
			x = 3;
			cout << "X is now: " << x << endl;
			break;
		case KEY_RIGHT:
			x = 4;
			cout << "X is now: " << x << endl;
			break;
		}

		key = getch();
		value = key;

	}

	system("pause");
	
	soundplay.join();
	getvideo.join();
	
	

	return 0;
}