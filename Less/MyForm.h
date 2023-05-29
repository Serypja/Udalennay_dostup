#pragma once
#include"Screenshot.h"
#include<windows.h>
#include <vcclr.h>
#include <iostream>
#include <gdiplus.h>
#include <gdiplusbitmap.h>
#include <thread>



namespace Less {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 83);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Кнопка";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(245, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(579, 431);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(12, 136);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(167, 83);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Video play";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(23, 255);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 26);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gainsboro;
			this->ClientSize = System::Drawing::Size(836, 455);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	int frameCount = 0;
	System::Windows::Forms::Timer^ timer;
	System::Diagnostics::Stopwatch^ stopwatch;
	DateTime lastUpdateTime = DateTime::Now;
	const int targetFPS = 60;
	const int targetFrameTime = 1000 / targetFPS;
	/*private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		timer = gcnew System::Windows::Forms::Timer();
		timer->Interval = 30;
		timer->Tick += gcnew System::EventHandler(this, &MyForm::OnTimerTick);
		timer->Start();

		stopwatch = gcnew System::Diagnostics::Stopwatch();
		stopwatch->Start();

		System::Threading::Thread^ thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::CaptureThread));
		thread->IsBackground = true;
		thread->Start();
	}*/


	

	//private: System::Void CaptureThread() {
	//	while (true) {
	//		DateTime currentTime = DateTime::Now;

	//		// Проверяем, прошло ли достаточно времени с момента последнего обновления изображения
	//		if ((currentTime - lastUpdateTime).TotalMilliseconds >= targetFrameTime) {
	//			Bitmap^ bmp = gcnew Bitmap(Screen::PrimaryScreen->Bounds.Width, Screen::PrimaryScreen->Bounds.Height, PixelFormat::Format24bppRgb);
	//			Graphics^ graphics = Graphics::FromImage(bmp);
	//			graphics->CopyFromScreen(Point::Empty, Point::Empty, Screen::PrimaryScreen->Bounds.Size);

	//			// Обновляем изображение в основном потоке
	//			Invoke(gcnew Action<Bitmap^>(this, &MyForm::UpdateImage), bmp);

	//			frameCount++;

	//			lastUpdateTime = currentTime;
	//		}
	//	}
	//}

	//private: System::Void UpdateImage(Bitmap^ bmp) {
	//	pictureBox1->Image = bmp;
	//	pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;

	//	TimeSpan elapsed = stopwatch->Elapsed;
	//	stopwatch->Restart();

	//	double fps = 1000.0 / elapsed.TotalMilliseconds;
	//	label1->Text = "FPS: " + fps.ToString("0.00");
	//}


	//___________________________________

		   bool isCapturing = false;
		   System::Threading::ManualResetEvent^ stopEvent = gcnew System::Threading::ManualResetEvent(false);

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isCapturing) {
		isCapturing = true;
		button1->Text = "Stop";

		timer = gcnew System::Windows::Forms::Timer();
		timer->Interval = 30;
		timer->Tick += gcnew System::EventHandler(this, &MyForm::OnTimerTick);
		timer->Start();

		stopwatch = gcnew System::Diagnostics::Stopwatch();
		stopwatch->Start();

		System::Threading::Thread^ thread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyForm::CaptureThread));
		thread->IsBackground = true;
		thread->Start();
	}
	else {
		isCapturing = false;
		button1->Text = "Start";

		timer->Stop();
		stopEvent->Set();
	}
}

private: System::Void CaptureThread() {
	while (isCapturing) {
		DateTime currentTime = DateTime::Now;

		// Проверяем, прошло ли достаточно времени с момента последнего обновления изображения
		if ((currentTime - lastUpdateTime).TotalMilliseconds >= targetFrameTime) {
			Bitmap^ bmp = gcnew Bitmap(Screen::PrimaryScreen->Bounds.Width, Screen::PrimaryScreen->Bounds.Height, PixelFormat::Format24bppRgb);
			Graphics^ graphics = Graphics::FromImage(bmp);
			graphics->CopyFromScreen(Point::Empty, Point::Empty, Screen::PrimaryScreen->Bounds.Size);

			// Обновляем изображение в основном потоке
			Invoke(gcnew Action<Bitmap^>(this, &MyForm::UpdateImage), bmp);

			frameCount++;

			lastUpdateTime = currentTime;
		}

		// Остановить поток, когда isCapturing равно false
		if (stopEvent->WaitOne(0)) {
			break;
		}
	}
}

private: System::Void UpdateImage(Bitmap^ bmp) {
	if (isCapturing) {
		pictureBox1->Image = bmp;
		pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;

		TimeSpan elapsed = stopwatch->Elapsed;
		stopwatch->Restart();

		double fps = 1000.0 / elapsed.TotalMilliseconds;
		label1->Text = "FPS: " + fps.ToString("0.00");
	}
}



	




		   
	

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer = gcnew System::Windows::Forms::Timer();
		timer->Interval = 16;
		timer->Tick += gcnew System::EventHandler(this, &MyForm::OnTimerTick);
		timer->Start();

		stopwatch = gcnew System::Diagnostics::Stopwatch();
		stopwatch->Start();
	}

	private: System::Void OnTimerTick(System::Object^ sender, System::EventArgs^ e) {
		Bitmap^ bmp = gcnew Bitmap(Screen::PrimaryScreen->Bounds.Width, Screen::PrimaryScreen->Bounds.Height, PixelFormat::Format24bppRgb);
		Graphics^ graphics = Graphics::FromImage(bmp);
		graphics->CopyFromScreen(Point::Empty, Point::Empty, Screen::PrimaryScreen->Bounds.Size);

		pictureBox1->Image = bmp;
		pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;

		frameCount++;
		TimeSpan elapsed = stopwatch->Elapsed;
		stopwatch->Restart();

		double fps = 1000.0 / elapsed.TotalMilliseconds;
		label1->Text = "FPS: " + fps.ToString("0.00");
	}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

}
};
}
