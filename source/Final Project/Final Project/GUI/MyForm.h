#pragma once
#include "..\Final Project\FileImageHandler.h"
//#include "..\Final Project\FileImageHandler.h"
//#include "..\Final Project\ImageCatalog.h"
//#include "..\Final Project\ImageHandlerBase.h"
//#include "..\Final Project\ImageMozaicProcessor.h"
//#include "..\Final Project\ImageProcessor.h"
//#include "..\Final Project\ImageSaver.h"
//#include "..\Final Project\InMemoryImageHandler.h"
#include "..\Final Project\PixelPacket.h"
#include <string>

namespace GUI {

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
	private: System::Windows::Forms::Button^  btn_SourceImage;
	private: System::Windows::Forms::Button^  btn_Save;
	private: System::Windows::Forms::Button^  btn_SmallGallery;

	private: System::Windows::Forms::Button^  btn_Quit;
	protected:

	private:
		std::string* smallImagePath;
		std::string* bigImagePath;
		std::string* outputPath;

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
			this->SuspendLayout();
			// 
			// btn_SourceImage
			// 
			this->btn_SourceImage->Location = System::Drawing::Point(53, 109);
			this->btn_SourceImage->Name = L"btn_SourceImage";
			this->btn_SourceImage->Size = System::Drawing::Size(173, 53);
			this->btn_SourceImage->TabIndex = 0;
			this->btn_SourceImage->Text = L"Source Image";
			this->btn_SourceImage->UseVisualStyleBackColor = true;
			this->btn_SourceImage->Click += gcnew System::EventHandler(this, &MyForm::btn_SourceImage_Click);
			// 
			// btn_Save
			// 
			this->btn_Save->Location = System::Drawing::Point(53, 327);
			this->btn_Save->Name = L"btn_Save";
			this->btn_Save->Size = System::Drawing::Size(173, 53);
			this->btn_Save->TabIndex = 1;
			this->btn_Save->Text = L"Save";
			this->btn_Save->UseVisualStyleBackColor = true;
			// 
			// btn_SmallGallery
			// 
			this->btn_SmallGallery->Location = System::Drawing::Point(53, 219);
			this->btn_SmallGallery->Name = L"btn_SmallGallery";
			this->btn_SmallGallery->Size = System::Drawing::Size(173, 53);
			this->btn_SmallGallery->TabIndex = 2;
			this->btn_SmallGallery->Text = L"Small Gallery";
			this->btn_SmallGallery->UseVisualStyleBackColor = true;
			this->btn_SmallGallery->Click += gcnew System::EventHandler(this, &MyForm::btn_SmallGallery_Click);
			// 
			// btn_Quit
			// 
			this->btn_Quit->Location = System::Drawing::Point(53, 435);
			this->btn_Quit->Name = L"btn_Quit";
			this->btn_Quit->Size = System::Drawing::Size(173, 53);
			this->btn_Quit->TabIndex = 3;
			this->btn_Quit->Text = L"Quit";
			this->btn_Quit->UseVisualStyleBackColor = true;
			this->btn_Quit->Click += gcnew System::EventHandler(this, &MyForm::btn_Quit_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1156, 643);
			this->Controls->Add(this->btn_Quit);
			this->Controls->Add(this->btn_SmallGallery);
			this->Controls->Add(this->btn_Save);
			this->Controls->Add(this->btn_SourceImage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"PicCollage";
			this->ResumeLayout(false);

		}
#pragma endregion
	// Event Handlers 
	private: System::Void btn_SourceImage_Click(System::Object^  sender, System::EventArgs^  e) {
		PixelPacked c(10, 20, 19);

		String ^ s = Convert::ToString(c.red);
		MessageBox::Show(s);
	}

	private: System::Void btn_SmallGallery_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void btn_Quit_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close(); // quit program
	}
};
}
