#pragma once

#include "opencv2/objdetect.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/videoio.hpp>
#include "opencv2/imgproc.hpp"
#include "header.h"

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;
using namespace defCamera;

	

	namespace CLRTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	Camera camera;
	Mat frame;
	VideoCapture cam;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// 컨트롤 접근을 위한 선언
	private: System::Windows::Forms::PictureBox^ picCam;
	private: System::Windows::Forms::Button^ btnPlay;
	private: System::Windows::Forms::Button^ Stop;

	



	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->picCam = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->Stop = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->BeginInit();
			this->SuspendLayout();
			// 
			// picCam
			// 
			this->picCam->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->picCam->Location = System::Drawing::Point(14, 15);
			this->picCam->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->picCam->Name = L"picCam";
			this->picCam->Size = System::Drawing::Size(802, 480);
			this->picCam->TabIndex = 2;
			this->picCam->TabStop = false;
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(848, 15);
			this->btnPlay->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(286, 109);
			this->btnPlay->TabIndex = 3;
			this->btnPlay->Text = L"Play";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &MyForm::btnPlay_Click);
			// 
			// Stop
			// 
			this->Stop->Location = System::Drawing::Point(848, 145);
			this->Stop->Name = L"Stop";
			this->Stop->Size = System::Drawing::Size(286, 107);
			this->Stop->TabIndex = 4;
			this->Stop->Text = L"Stop";
			this->Stop->UseVisualStyleBackColor = true;
			this->Stop->Click += gcnew System::EventHandler(this, &MyForm::Stop_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(1623, 931);
			this->Controls->Add(this->Stop);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->picCam);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picCam))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		int LiveCam()
		{
			//VideoCapture cap;
			int deviceID = 0;             // 0 = open default camera
			int apiID = cv::CAP_ANY;      // 0 = autodetect default API
			cam.open(deviceID + apiID);
			if (!cam.isOpened()) {
				cerr << "ERROR! Unable to open camera\n";
				return -1;
			}
			cout << "Start grabbing" << endl
				<< "Press any key to terminate" << endl;
			for (;;)
			{
				cam.read(frame);
				if (frame.empty()) {
					cerr << "ERROR! blank frame grabbed\n";
					break;
				}
				//imshow("Live", frame);
				picCam->Image = camera.Show(frame);
				if (waitKey(5) >= 0)
					break;   
			}
			return 0;
		}

	private: System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
		LiveCam();
	}
	private: System::Void Stop_Click(System::Object^ sender, System::EventArgs^ e) {
		exit(0);
	}

};
}
