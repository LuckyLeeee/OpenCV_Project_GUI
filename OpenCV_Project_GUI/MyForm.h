#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <zbar.h>
#include <alpr.h>
#include <string>
#include <baseapi.h>
#include <allheaders.h>

cv::VideoCapture cap;
cv::Mat src;
char* filePath;

namespace OpenCVProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::PictureBox^  pictureBoxImage;
	private: System::Windows::Forms::PictureBox^  pictureBoxCamera;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::PictureBox^  pictureBoxResult;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBoxImage = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBoxCamera = (gcnew System::Windows::Forms::PictureBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->pictureBoxResult = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxImage))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCamera))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResult))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 44);
			this->button1->TabIndex = 0;
			this->button1->Tag = L"btnimage";
			this->button1->Text = L"Select Image";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Location = System::Drawing::Point(127, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 44);
			this->button2->TabIndex = 1;
			this->button2->Tag = L"btncamera";
			this->button2->Text = L"Start Camera";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Controls->Add(this->button2);
			this->flowLayoutPanel1->Controls->Add(this->button3);
			this->flowLayoutPanel1->Controls->Add(this->button4);
			this->flowLayoutPanel1->Controls->Add(this->button5);
			this->flowLayoutPanel1->Location = System::Drawing::Point(826, 28);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(250, 191);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(3, 53);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(234, 42);
			this->button3->TabIndex = 2;
			this->button3->Tag = L"btnocr";
			this->button3->Text = L"Text Recognition";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(3, 101);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(234, 42);
			this->button4->TabIndex = 3;
			this->button4->Tag = L"btnalpr";
			this->button4->Text = L"LICENSE PLATE";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(3, 149);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(234, 42);
			this->button5->TabIndex = 4;
			this->button5->Tag = L"btnzbar";
			this->button5->Text = L"QR Code";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(826, 225);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(264, 259);
			this->textBox1->TabIndex = 4;
			this->textBox1->Tag = L"textBox";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(797, 481);
			this->tabControl1->TabIndex = 5;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::White;
			this->tabPage1->Controls->Add(this->pictureBoxImage);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(789, 452);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Image";
			// 
			// pictureBoxImage
			// 
			this->pictureBoxImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxImage.Image")));
			this->pictureBoxImage->Location = System::Drawing::Point(6, 6);
			this->pictureBoxImage->Name = L"pictureBoxImage";
			this->pictureBoxImage->Size = System::Drawing::Size(777, 440);
			this->pictureBoxImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxImage->TabIndex = 0;
			this->pictureBoxImage->TabStop = false;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::White;
			this->tabPage2->Controls->Add(this->pictureBoxCamera);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(789, 452);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Camera";
			// 
			// pictureBoxCamera
			// 
			this->pictureBoxCamera->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxCamera.Image")));
			this->pictureBoxCamera->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxCamera.InitialImage")));
			this->pictureBoxCamera->Location = System::Drawing::Point(6, 6);
			this->pictureBoxCamera->Name = L"pictureBoxCamera";
			this->pictureBoxCamera->Size = System::Drawing::Size(777, 440);
			this->pictureBoxCamera->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxCamera->TabIndex = 0;
			this->pictureBoxCamera->TabStop = false;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::White;
			this->tabPage3->Controls->Add(this->pictureBoxResult);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(789, 452);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Result";
			// 
			// pictureBoxResult
			// 
			this->pictureBoxResult->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxResult.Image")));
			this->pictureBoxResult->Location = System::Drawing::Point(3, 3);
			this->pictureBoxResult->Name = L"pictureBoxResult";
			this->pictureBoxResult->Size = System::Drawing::Size(783, 446);
			this->pictureBoxResult->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBoxResult->TabIndex = 0;
			this->pictureBoxResult->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1102, 512);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxImage))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCamera))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxResult))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void panel1_Paint_1(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->Filter = "Image Files(*.BMP;*.JPG;*.PNG;*.TIF)|*.BMP;*.JPG;*.PNG;*.TIF";
		tabControl1->SelectedTab = tabPage1;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ filename = openFileDialog1->FileName;
			filePath = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(filename);
			src = cv::imread(filePath, cv::IMREAD_COLOR);
			if (!src.data) textBox1->Text = "Can't open Image";
			//Bitmap^ bmImage = gcnew Bitmap(src.cols, src.rows, 3 * src.cols, Imaging::PixelFormat::Format24bppRgb, IntPtr(src.data));
			//Image^ image = static_cast<Bitmap^>(bmImage);
			pictureBoxImage->Image = Image::FromFile(filename);
			pictureBoxImage->Refresh();
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		cap.open(0);
		tabControl1->SelectedTab = tabPage2;
		if (pictureBoxCamera->Image != pictureBoxCamera->InitialImage)
			pictureBoxCamera->Image = pictureBoxCamera->InitialImage;
		if (button2->Text == "Stop Camera")
		{
			button2->Text = "Start Camera";
			if (cap.isOpened()) cap.release();
		}
		else if (button2->Text == "Start Camera")
		{
			button2->Text = "Stop Camera";
			if (!cap.isOpened()) cap.open(0);
		}
		while (button2->Text == "Stop Camera")
		{
			cap >> src;
			Bitmap^ bmImage = gcnew Bitmap(src.cols, src.rows, 3 * src.cols, Imaging::PixelFormat::Format24bppRgb, IntPtr(src.data));
			Image^ image = static_cast<Bitmap^>(bmImage);
			pictureBoxCamera->Image = bmImage;
			pictureBoxCamera->Refresh();
			cv::waitKey(1);
		}
	}
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	MessageBoxButtons buttons = MessageBoxButtons::YesNoCancel;
	MessageBoxIcon icon = MessageBoxIcon::Warning;
	if (cap.isOpened())
	{
		System::Windows::Forms::DialogResult result = MessageBox::Show("Webcam van dang bat, ban co muon tat Webcam", "Close GUI", buttons, icon);
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			cap.release();
			exit(1);
		}		
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text = "";

	// Create Tesseract object
	tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

	// Initialize tesseract to use English (eng) and the LSTM OCR engine. 
	ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

	// Set Page segmentation mode to PSM_AUTO (3)
	ocr->SetPageSegMode(tesseract::PSM_AUTO);

	// Open input image using OpenCV
	cv::Mat im = src.clone();

	// Set image data
	ocr->SetImage(im.data, im.cols, im.rows, 3, im.step);

	// Run Tesseract OCR on image
	System::String^ outText = gcnew System::String(ocr->GetUTF8Text());

	textBox1->Text = outText;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text = "";
	alpr::Alpr openalpr("us", "D:\\OPENALPR\\openalpr_64\\openalpr.conf");
	openalpr.setTopN(10);
	openalpr.setDefaultRegion("md");
	if (openalpr.isLoaded() == false)
	{
		textBox1->Text = "Error Loading OpenALPR";
		return;
	}
	//char* fileName = (char*)(void*)System::Runtime::InteropServices::Marshall::StringToHGlobalAnsi(strFileName);
	alpr::AlprResults results = openalpr.recognize(std::string(filePath));
	for (int i = 0; i < results.plates.size(); i++)
	{
		alpr::AlprPlateResult plate = results.plates[i];
		textBox1->Text = "plate " + i.ToString() + " - " + plate.topNPlates.size().ToString() + " result: \n";
		int x1 = plate.plate_points[0].x;
		int y1 = plate.plate_points[0].y;
		int x2 = plate.plate_points[2].x;
		int y2 = plate.plate_points[2].y;
		cv::Mat dst = src.clone();
		cv::rectangle(dst, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0, 0, 255), 3, 8, 0);
		for (int k = 0; k < plate.topNPlates.size(); k++)
		{
			alpr::AlprPlate candidate = plate.topNPlates[k];
			System::String^ str = "\n  - \n";
			str += gcnew System::String(candidate.characters.c_str()) + "\n";
			str += "\n confidence: " + candidate.overall_confidence.ToString() + "\n";
			str += "\n pattern_match: " + candidate.matches_template.ToString() + "\n";
			textBox1->Text += str;
		}
	}
}
		 private: System::Drawing::Bitmap^ MatToBitmap(cv::Mat img, bool use_log_scale)
		 {
			 cv::Mat disp_img = img.clone();
			 if (disp_img.channels() == 1)
			 {
				 //disp_img.convertTo(disp_img, CV_32F);
				 cv::normalize(disp_img, disp_img, 0, 255.0, cv::NORM_MINMAX);
				 if (use_log_scale)
				 {
					 cv::log(1 + disp_img, disp_img);
					 cv::normalize(disp_img, disp_img, 0, 255.0, cv::NORM_MINMAX);
				 }
				 disp_img.convertTo(disp_img, CV_8U);
				 cvtColor(disp_img, disp_img, cv::COLOR_GRAY2BGR);

				 /*for (int row = 0; row < disp_img.rows; row++)
				 {
					 for (int col = 0; col < disp_img.cols; col++)
					 {
						 int intensity = disp_img.at<uchar>(row, col);
						 bmp->SetPixel(col, row, System::Drawing::Color::FromArgb(intensity, intensity, intensity));
					 }
				 }*/
			 }
			 else if (disp_img.channels() == 3)
			 {
				 disp_img.convertTo(disp_img, CV_8U);

				 /*for (int row = 0; row < disp_img.rows; row++)
				 {
					 for (int col = 0; col < disp_img.cols; col++)
					 {
						 cv::Vec3b color = disp_img.at<cv::Vec3b>(row, col);
						 bmp->SetPixel(col, row, System::Drawing::Color::FromArgb(color.val[2], color.val[1], color.val[0]));
					 }
				 }*/
			 }

			 //create the bitmap and get the pointer to the data
			 Imaging::PixelFormat fmt(Imaging::PixelFormat::Format24bppRgb);
			 Bitmap ^bmpimg = gcnew Bitmap(disp_img.cols, disp_img.rows, fmt);

			 Imaging::BitmapData ^data = bmpimg->LockBits(Rectangle(0, 0, disp_img.cols, disp_img.rows), Imaging::ImageLockMode::WriteOnly, fmt);

			 System::Byte *dstData = reinterpret_cast<System::Byte*>(data->Scan0.ToPointer());

			 unsigned char *srcData = disp_img.data;

			 for (int row = 0; row < data->Height; ++row)
			 {
				 memcpy(reinterpret_cast<void*>(&dstData[row*data->Stride]), reinterpret_cast<void*>(&srcData[row*disp_img.step]), disp_img.cols*disp_img.channels());
			 }

			 bmpimg->UnlockBits(data);
			 return bmpimg;
		 }

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text = "";
	zbar::ImageScanner scanner;
	scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);
	cv::Mat gray;
	cv::Mat src_clone = src.clone();
	cvtColor(src_clone, gray, cv::COLOR_BGR2GRAY);
	int width = src_clone.cols;
	int height = src_clone.rows;
	uchar *raw = (uchar *)gray.data;
	// wrap image data   
	zbar::Image image(width, height, "Y800", raw, width * height);
	// scan the image for barcodes   
	int n = scanner.scan(image);
	// extract results   
	for (zbar::Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) 
	{
		std::vector<cv::Point> vp;
		String^ typeName = gcnew String(symbol->get_type_name().c_str());
		String^ data = gcnew String(symbol->get_data().c_str());
		// do something useful with results   
		textBox1->Text = "Loai code: " + typeName + "\n Thong tin: " + data + "\n";
		int n = symbol->get_location_size();
		for (int i = 0; i < n; i++)
		{
			vp.push_back(cv::Point(symbol->get_location_x(i), symbol->get_location_y(i)));
		}
		cv::RotatedRect r = cv::minAreaRect(vp);
		cv::Point2f pts[4];
		r.points(pts);
		for (int i = 0; i < 4; i++)
		{
			cv::line(src_clone, pts[i], pts[(i + 1) % 4], cv::Scalar(255, 0, 0), 3);
		}
	}
	//cv::imshow("result", src_clone);
	Bitmap^ bmImage = MatToBitmap(src_clone, false);// gcnew Bitmap(src_clone.cols, src_clone.rows, 3 * src_clone.cols, Imaging::PixelFormat::Format24bppRgb, IntPtr(src_clone.data));
	tabControl1->SelectedTab = tabPage3;
		pictureBoxResult->Image = bmImage;
		pictureBoxResult->Refresh();
}
};
}

