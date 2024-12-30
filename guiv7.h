#pragma once
#include "BeautifyXML.h"
#include "compress.h"
#include "XMLValidator.h"
#include "Minify.h"

using namespace System;
using namespace System::IO;
namespace GUIproject {

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
			panel1->Hide();
			panel2->Hide();
			panel3->Hide();
			panel4->Hide();
			panel6->Hide();
			panel7->Hide();
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label2;
	private: System::Web::Management::ReadOnlyTextBox^ readOnlyTextBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button8;
	private: System::Web::Management::ReadOnlyTextBox^ readOnlyTextBox2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Web::Management::ReadOnlyTextBox^ readOnlyTextBox3;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button12;
	private: System::Web::Management::ReadOnlyTextBox^ readOnlyTextBox4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Web::Management::ReadOnlyTextBox^ readOnlyTextBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button16;
	private: System::Windows::Forms::Label^ label7;
	private: String^ selectedFilePath = "";
	private: String^ outputFilePath = "C:\\Users\\YAHIA\\Desktop\\output.xml";
	private: String^ savedFilePath = "";
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Label^ label8;
	private: System::Web::Management::ReadOnlyTextBox^ readOnlyTextBox6;
	private: String^ compressedFilePath = "C:\\Users\\YAHIA\\Desktop\\output.comp";
	private: String^ GetCurrentContent(TextBox^ textBox) {
			   // Retrieve the text from the specified read-only text box
			   return textBox->Text;
		   }
	private: bool visited = false;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->readOnlyTextBox1 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->readOnlyTextBox2 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->readOnlyTextBox4 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->readOnlyTextBox3 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->readOnlyTextBox5 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->readOnlyTextBox6 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(687, 527);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Check the file";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(531, 527);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 40);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Compress file";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(366, 527);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 40);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Decompress file";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(202, 527);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(125, 40);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Convert to JSON";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(35, 527);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(125, 40);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Prettify";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 97);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(570, 365);
			this->textBox1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(261, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(321, 30);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Please enter your .XML file";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->readOnlyTextBox1);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(877, 622);
			this->panel1->TabIndex = 7;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(100, 477);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// readOnlyTextBox1
			// 
			this->readOnlyTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->readOnlyTextBox1->Location = System::Drawing::Point(107, 81);
			this->readOnlyTextBox1->Multiline = true;
			this->readOnlyTextBox1->Name = L"readOnlyTextBox1";
			this->readOnlyTextBox1->ReadOnly = true;
			this->readOnlyTextBox1->Size = System::Drawing::Size(657, 366);
			this->readOnlyTextBox1->TabIndex = 2;
			this->readOnlyTextBox1->TabStop = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(35, 29);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(30, 30);
			this->button7->TabIndex = 1;
			this->button7->Text = L"←";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button9);
			this->panel2->Controls->Add(this->button8);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->readOnlyTextBox2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(877, 622);
			this->panel2->TabIndex = 11;
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button9->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(366, 493);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(125, 40);
			this->button9->TabIndex = 11;
			this->button9->Text = L"Save as";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button8->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(35, 29);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 30);
			this->button8->TabIndex = 9;
			this->button8->Text = L"←";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::GrayText;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(337, 48);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(204, 30);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Compressed File";
			// 
			// readOnlyTextBox2
			// 
			this->readOnlyTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->readOnlyTextBox2->Location = System::Drawing::Point(128, 107);
			this->readOnlyTextBox2->Multiline = true;
			this->readOnlyTextBox2->Name = L"readOnlyTextBox2";
			this->readOnlyTextBox2->ReadOnly = true;
			this->readOnlyTextBox2->Size = System::Drawing::Size(621, 355);
			this->readOnlyTextBox2->TabIndex = 8;
			this->readOnlyTextBox2->TabStop = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->label5);
			this->panel4->Controls->Add(this->button13);
			this->panel4->Controls->Add(this->button12);
			this->panel4->Controls->Add(this->readOnlyTextBox4);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(877, 622);
			this->panel4->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::GrayText;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(337, 48);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(127, 30);
			this->label5->TabIndex = 13;
			this->label5->Text = L"JSON File";
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button13->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(366, 481);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(125, 40);
			this->button13->TabIndex = 12;
			this->button13->Text = L"Save as";
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click_1);
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button12->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(35, 29);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(30, 30);
			this->button12->TabIndex = 10;
			this->button12->Text = L"←";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click_1);
			// 
			// readOnlyTextBox4
			// 
			this->readOnlyTextBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->readOnlyTextBox4->Location = System::Drawing::Point(107, 107);
			this->readOnlyTextBox4->Multiline = true;
			this->readOnlyTextBox4->Name = L"readOnlyTextBox4";
			this->readOnlyTextBox4->ReadOnly = true;
			this->readOnlyTextBox4->Size = System::Drawing::Size(657, 350);
			this->readOnlyTextBox4->TabIndex = 9;
			this->readOnlyTextBox4->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->button11);
			this->panel3->Controls->Add(this->readOnlyTextBox3);
			this->panel3->Controls->Add(this->button10);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(877, 622);
			this->panel3->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(309, 48);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(232, 30);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Decompressed File";
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button11->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(377, 509);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(125, 40);
			this->button11->TabIndex = 12;
			this->button11->Text = L"Save as";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// readOnlyTextBox3
			// 
			this->readOnlyTextBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->readOnlyTextBox3->Location = System::Drawing::Point(107, 100);
			this->readOnlyTextBox3->Multiline = true;
			this->readOnlyTextBox3->Name = L"readOnlyTextBox3";
			this->readOnlyTextBox3->ReadOnly = true;
			this->readOnlyTextBox3->Size = System::Drawing::Size(657, 366);
			this->readOnlyTextBox3->TabIndex = 9;
			this->readOnlyTextBox3->TabStop = false;
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button10->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(35, 29);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(30, 30);
			this->button10->TabIndex = 8;
			this->button10->Text = L"←";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->readOnlyTextBox5);
			this->panel6->Controls->Add(this->label6);
			this->panel6->Controls->Add(this->button14);
			this->panel6->Controls->Add(this->button15);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(877, 622);
			this->panel6->TabIndex = 0;
			// 
			// readOnlyTextBox5
			// 
			this->readOnlyTextBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->readOnlyTextBox5->Location = System::Drawing::Point(107, 107);
			this->readOnlyTextBox5->Multiline = true;
			this->readOnlyTextBox5->Name = L"readOnlyTextBox5";
			this->readOnlyTextBox5->ReadOnly = true;
			this->readOnlyTextBox5->Size = System::Drawing::Size(657, 367);
			this->readOnlyTextBox5->TabIndex = 16;
			this->readOnlyTextBox5->TabStop = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::GrayText;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(349, 48);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(153, 30);
			this->label6->TabIndex = 15;
			this->label6->Text = L"New Format";
			// 
			// button14
			// 
			this->button14->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button14->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(35, 29);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(30, 30);
			this->button14->TabIndex = 14;
			this->button14->Text = L"←";
			this->button14->UseVisualStyleBackColor = false;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button15->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(366, 527);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(125, 40);
			this->button15->TabIndex = 13;
			this->button15->Text = L"Save as";
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(718, 29);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(125, 40);
			this->button6->TabIndex = 17;
			this->button6->Text = L"Minify";
			this->button6->UseVisualStyleBackColor = false;
			//this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(325, 24);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 16);
			this->label7->TabIndex = 17;
			// 
			// button16
			// 
			this->button16->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button16->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(20, 15);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(125, 40);
			this->button16->TabIndex = 18;
			this->button16->Text = L"Browse";
			this->button16->UseVisualStyleBackColor = false;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->button18);
			this->panel7->Controls->Add(this->button17);
			this->panel7->Controls->Add(this->label8);
			this->panel7->Controls->Add(this->readOnlyTextBox6);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel7->Location = System::Drawing::Point(0, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(877, 622);
			this->panel7->TabIndex = 17;
			// 
			// button18
			// 
			this->button18->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button18->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(377, 509);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(125, 40);
			this->button18->TabIndex = 20;
			this->button18->Text = L"Save as";
			this->button18->UseVisualStyleBackColor = false;
			//this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button17
			// 
			this->button17->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button17->Font = (gcnew System::Drawing::Font(L"Arial Black", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(35, 39);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(30, 30);
			this->button17->TabIndex = 19;
			this->button17->Text = L"←";
			this->button17->UseVisualStyleBackColor = false;
			//this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::GrayText;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(349, 48);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(153, 30);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Minified File";
			// 
			// readOnlyTextBox6
			// 
			this->readOnlyTextBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->readOnlyTextBox6->Location = System::Drawing::Point(116, 108);
			this->readOnlyTextBox6->Multiline = true;
			this->readOnlyTextBox6->Name = L"readOnlyTextBox6";
			this->readOnlyTextBox6->ReadOnly = true;
			this->readOnlyTextBox6->Size = System::Drawing::Size(657, 367);
			this->readOnlyTextBox6->TabIndex = 17;
			this->readOnlyTextBox6->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(877, 622);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"XML EDITOR";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void DisplayOutputInTextBox(String^ outputFilePath, TextBox^ outputTextBox)
		{
			try
			{
				// Create a StreamReader to read the content of the output file
				StreamReader^ reader = gcnew StreamReader(outputFilePath);

				// Read the entire content of the file
				String^ fileContent = reader->ReadToEnd();

				// Close the StreamReader
				reader->Close();

				// Set the content of the TextBox to the file content
				outputTextBox->Text = fileContent;
			}
			catch (Exception^ ex)
			{
				// Handle any exceptions (e.g., file not found)
				MessageBox::Show("Error reading the file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {//check
		panel1->Show();
		bool result = false;
		String^ outt = "";
		result = XMLValidator::IsXMLValid(selectedFilePath,"",false,outt);
		DisplayOutputInTextBox(selectedFilePath, readOnlyTextBox1);
		if (result) {
			label2->Text = "The XML file is valid";
			label2->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label2->ForeColor = System::Drawing::Color::Blue;
		}
		else {
			label2->Text = "The XML file is NOT valid"+" "+outt;
			label2->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			label2->ForeColor = System::Drawing::Color::Red;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {//compress
		panel2->Show();
		XMLCompressor::Compress(selectedFilePath, outputFilePath);
		DisplayOutputInTextBox(outputFilePath, readOnlyTextBox2);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {//decompress
		panel3->Show();
		XMLCompressor::Decompress(selectedFilePath, outputFilePath);
		DisplayOutputInTextBox(outputFilePath, readOnlyTextBox3);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {//toJSON
		panel4->Show();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {//pretiffy  
		panel6->Show();
		BeautifyXMLCLI::Beautify(selectedFilePath, outputFilePath);
		DisplayOutputInTextBox(outputFilePath, readOnlyTextBox5);
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		panel1->Hide();
	}	

	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {//save as panel3
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "XML Files (*.xml)|*.xml|Compressed Files (*.comp)|*.comp";
		saveFileDialog->DefaultExt = "xml"; // Default extension
		saveFileDialog->AddExtension = true;

		// Show the dialog and check if the user selected a file
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ selectedFilePath = saveFileDialog->FileName;

			try {
				// Assume we have a method to get the current content as a string.
				String^ content = GetCurrentContent(readOnlyTextBox2); // Replace with your actual method to get content.

				// Write content to the selected file
				File::WriteAllText(selectedFilePath, content);

				MessageBox::Show("File saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error saving file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	private: System::Void button8_Click_1(System::Object^ sender, System::EventArgs^ e) {
		panel2->Hide();
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		panel3->Hide();
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {//SAVE AS BUTTON panel2
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "XML Files (*.xml)|*.xml|Compressed Files (*.comp)|*.comp";
		saveFileDialog->DefaultExt = "xml"; // Default extension
		saveFileDialog->AddExtension = true;

		// Show the dialog and check if the user selected a file
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ selectedFilePath = saveFileDialog->FileName;

			try {
				// Assume we have a method to get the current content as a string.
				String^ content = GetCurrentContent(readOnlyTextBox3); // Replace with your actual method to get content.

				// Write content to the selected file
				File::WriteAllText(selectedFilePath, content);

				MessageBox::Show("File saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error saving file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void button12_Click_1(System::Object^ sender, System::EventArgs^ e) {
		panel4->Hide();
	}
	private: System::Void button13_Click_1(System::Object^ sender, System::EventArgs^ e) {//save as button panel4
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "XML Files (*.xml)|*.xml|Compressed Files (*.comp)|*.comp";
		saveFileDialog->DefaultExt = "xml"; // Default extension
		saveFileDialog->AddExtension = true;

		// Show the dialog and check if the user selected a file
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ selectedFilePath = saveFileDialog->FileName;

			try {
				// Assume we have a method to get the current content as a string.
				String^ content = GetCurrentContent(readOnlyTextBox4); // Replace with your actual method to get content.

				// Write content to the selected file
				File::WriteAllText(selectedFilePath, content);

				MessageBox::Show("File saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error saving file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		panel6->Hide();
	}
	private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {//browse button
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Title = "Select an XML or a Compressed File";
		openFileDialog->Filter = "XML and Compressed Files (*.xml;*.comp)|*.xml;*.comp";
		
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			
			selectedFilePath = openFileDialog->FileName;

			MessageBox::Show("Selected File: " + selectedFilePath, "File Selected", MessageBoxButtons::OK, MessageBoxIcon::Information);

			label7->Text = selectedFilePath;

			
		}

		if (selectedFilePath != "" && savedFilePath == "") {
			DisplayOutputInTextBox(selectedFilePath, textBox1);
		}
		else {
			DisplayOutputInTextBox(savedFilePath, textBox1);
		}
	
	}
	
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {//save as button on panel6
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "XML Files (*.xml)|*.xml|Compressed Files (*.comp)|*.comp";
		saveFileDialog->DefaultExt = "xml"; // Default extension
		saveFileDialog->AddExtension = true;

		// Show the dialog and check if the user selected a file
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ selectedFilePath = saveFileDialog->FileName;

			try {
				// Assume we have a method to get the current content as a string.
				String^ content = GetCurrentContent(readOnlyTextBox5); // Replace with your actual method to get content.

				// Write content to the selected file
				File::WriteAllText(selectedFilePath, content);

				MessageBox::Show("File saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error saving file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	//private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {//minify button	
	//	panel7->Show();
	//	MinifyUtility::Minifier::Minify(selectedFilePath,outputFilePath);
	//}
	//private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {//go back button for minifying
	//	panel7->Hide();
	//}

	//private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {//save as button of minifying
	//	SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
	//	saveFileDialog->Filter = "XML Files (*.xml)|*.xml|Compressed Files (*.comp)|*.comp";
	//	saveFileDialog->DefaultExt = "xml"; // Default extension
	//	saveFileDialog->AddExtension = true;

	//	// Show the dialog and check if the user selected a file
	//	if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
	//		String^ selectedFilePath = saveFileDialog->FileName;

	//		try {
	//			// Assume we have a method to get the current content as a string.
	//			String^ content = GetCurrentContent(); // Replace with your actual method to get content.

	//			// Write content to the selected file
	//			File::WriteAllText(selectedFilePath, content);

	//			MessageBox::Show("File saved successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	//		}
	//		catch (Exception^ ex) {
	//			MessageBox::Show("Error saving file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	//		}
	//	}
	//}
};
	}
