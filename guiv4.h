#pragma once
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
	private: System::Windows::Forms::Button^ button6;
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->readOnlyTextBox3 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->readOnlyTextBox2 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->readOnlyTextBox1 = (gcnew System::Web::Management::ReadOnlyTextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
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
			this->panel1->Controls->Add(this->button6);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(877, 622);
			this->panel1->TabIndex = 7;
			this->panel1->Parent = this;
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
			this->panel2->Parent = this;
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
			this->panel3->Parent = this;
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
			this->readOnlyTextBox2->Location = System::Drawing::Point(133, 107);
			this->readOnlyTextBox2->Multiline = true;
			this->readOnlyTextBox2->Name = L"readOnlyTextBox2";
			this->readOnlyTextBox2->ReadOnly = true;
			this->readOnlyTextBox2->Size = System::Drawing::Size(621, 355);
			this->readOnlyTextBox2->TabIndex = 8;
			this->readOnlyTextBox2->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(422, 477);
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
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(377, 527);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(125, 40);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Correct";
			this->button6->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(877, 622);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"XML EDITOR";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		panel1->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		panel2->Show();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		panel3->Show();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		panel1->Hide();
	}	

	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button8_Click_1(System::Object^ sender, System::EventArgs^ e) {
		panel2->Hide();
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		panel3->Hide();
	}
};
	}
