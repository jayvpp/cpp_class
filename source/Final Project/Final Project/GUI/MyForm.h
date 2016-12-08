#pragma once
#include "..\opencv\build\include\opencv2\opencv.hpp"

#include "..\Final Project\FileImageHandler.h"
#include "..\Final Project\ImageCatalog.h"
#include "..\Final Project\ImageHandlerBase.h"
#include "..\Final Project\ImageMozaicProcessor.h"
#include "..\Final Project\ImageProcessor.h"
#include "..\Final Project\ImageSaver.h"
#include "..\Final Project\InMemoryImageHandler.h"
#include "..\Final Project\PixelPacket.h"
#include <stdlib.h>
#include <string>
#include <msclr\marshal_cppstd.h>


 

using namespace cv;

namespace GUI {



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;
	using namespace System::IO;


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
	private: System::Windows::Forms::Button^  btn_SourceImage;
	private: System::Windows::Forms::Button^  btn_Save;
	private: System::Windows::Forms::Button^  btn_SmallGallery;

	private: System::Windows::Forms::Button^  btn_Quit;
	protected:
    
 
	public:

		 ref class ImageProcessingModel
		{
		public:
			System::String^ bigImagePath;
			System::String^ smallImageCollectionPath;
			System::String^ finalImagePath;
		};

		ImageProcessingModel data;
	private: System::Windows::Forms::Button^  button1;
	public:
	private:



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
			this->btn_SourceImage = (gcnew System::Windows::Forms::Button());
			this->btn_Save = (gcnew System::Windows::Forms::Button());
			this->btn_SmallGallery = (gcnew System::Windows::Forms::Button());
			this->btn_Quit = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_SourceImage
			// 
			this->btn_SourceImage->Location = System::Drawing::Point(26, 57);
			this->btn_SourceImage->Margin = System::Windows::Forms::Padding(2);
			this->btn_SourceImage->Name = L"btn_SourceImage";
			this->btn_SourceImage->Size = System::Drawing::Size(86, 28);
			this->btn_SourceImage->TabIndex = 0;
			this->btn_SourceImage->Text = L"Source Image";
			this->btn_SourceImage->UseVisualStyleBackColor = true;
			this->btn_SourceImage->Click += gcnew System::EventHandler(this, &MyForm::btn_SourceImage_Click);
			// 
			// btn_Save
			// 
			this->btn_Save->Location = System::Drawing::Point(26, 170);
			this->btn_Save->Margin = System::Windows::Forms::Padding(2);
			this->btn_Save->Name = L"btn_Save";
			this->btn_Save->Size = System::Drawing::Size(86, 28);
			this->btn_Save->TabIndex = 1;
			this->btn_Save->Text = L"Save";
			this->btn_Save->UseVisualStyleBackColor = true;
			this->btn_Save->Click += gcnew System::EventHandler(this, &MyForm::btn_Save_Click);
			// 
			// btn_SmallGallery
			// 
			this->btn_SmallGallery->Location = System::Drawing::Point(26, 114);
			this->btn_SmallGallery->Margin = System::Windows::Forms::Padding(2);
			this->btn_SmallGallery->Name = L"btn_SmallGallery";
			this->btn_SmallGallery->Size = System::Drawing::Size(86, 28);
			this->btn_SmallGallery->TabIndex = 2;
			this->btn_SmallGallery->Text = L"Small Gallery";
			this->btn_SmallGallery->UseVisualStyleBackColor = true;
			this->btn_SmallGallery->Click += gcnew System::EventHandler(this, &MyForm::btn_SmallGallery_Click);
			// 
			// btn_Quit
			// 
			this->btn_Quit->Location = System::Drawing::Point(26, 226);
			this->btn_Quit->Margin = System::Windows::Forms::Padding(2);
			this->btn_Quit->Name = L"btn_Quit";
			this->btn_Quit->Size = System::Drawing::Size(86, 28);
			this->btn_Quit->TabIndex = 3;
			this->btn_Quit->Text = L"Quit";
			this->btn_Quit->UseVisualStyleBackColor = true;
			this->btn_Quit->Click += gcnew System::EventHandler(this, &MyForm::btn_Quit_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(145, 57);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 28);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Run Algorithm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 334);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btn_Quit);
			this->Controls->Add(this->btn_SmallGallery);
			this->Controls->Add(this->btn_Save);
			this->Controls->Add(this->btn_SourceImage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"PicCollage";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		// Event Handlers 

	ref class ImageProcessingModel;
	private: System::Void btn_SourceImage_Click(System::Object^  sender, System::EventArgs^  e) {

		System::String^ bigImagePath;

		bigImagePath = ""; // ensure we do not save an old path
		OpenFileDialog ^ openFileDialog1 = gcnew OpenFileDialog(); // instantiate OpenFileDialog

		if (openFileDialog1->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) // ShowDialog
		{
			bigImagePath = Convert::ToString(openFileDialog1->InitialDirectory + openFileDialog1->FileName); // store fileName
		}
		//check that bigImagePath is good. 
		 
		data.bigImagePath = bigImagePath;
 
	}

	private: System::Void btn_SmallGallery_Click(System::Object^  sender, System::EventArgs^  e) {
		FolderBrowserDialog ^ openFileDialog1 = gcnew FolderBrowserDialog(); // instantiate OpenFileDialog
 
		System::String^ smallGalletyPath;
		if (openFileDialog1->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) // ShowDialog
		{
			smallGalletyPath = Convert::ToString(openFileDialog1->SelectedPath); // store fileName
		}
		data.smallImageCollectionPath = smallGalletyPath;

	}

	private: System::Void btn_Quit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close(); // quit program
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void btn_Save_Click(System::Object^  sender, System::EventArgs^  e) {
	
		FolderBrowserDialog ^ openFileDialog1 = gcnew FolderBrowserDialog(); // instantiate OpenFileDialog
 
		System::String^ outputPicturePath;
		if (openFileDialog1->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) // ShowDialog
		{
			outputPicturePath = Convert::ToString(openFileDialog1->SelectedPath); // store fileName
		}
		data.finalImagePath = outputPicturePath + "\\Result";

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


		const char* bigPicturePath = (const char*)(Marshal::StringToHGlobalAnsi(data.bigImagePath)).ToPointer();
		const char* smallPicturePath = (const char*)(Marshal::StringToHGlobalAnsi(data.smallImageCollectionPath)).ToPointer();
		const char* outputPicturePath = (const char*)(Marshal::StringToHGlobalAnsi(data.finalImagePath)).ToPointer();

		std::string bigPicPath(bigPicturePath);
		std::string smallPicPath(smallPicturePath);
		std::string outPicPath(outputPicturePath);

		array<System::String^>^ file =  Directory::GetFiles(data.smallImageCollectionPath);
		std::vector<char*> listOfFile;

		char* currentFile = nullptr;
		for (int i = 0; i < file->Length; i++)
		{
			currentFile = (char*)(Marshal::StringToHGlobalAnsi(file[i])).ToPointer();
			listOfFile.push_back(currentFile);
		}

		MessageBox::Show("The Image Processing will take some time to complete, Check Save Directory to see process every 100 frames, During this time, UI will be blocked");
		ImageMozaicProcessor p(listOfFile, bigPicPath);
		p.ProcessImage(outPicPath);
		MessageBox::Show("Process Completed :)");

	}
};



}
