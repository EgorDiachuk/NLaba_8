#pragma once
#include<cstdlib>
#include<ctime>
using namespace std;

namespace NLaba8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			srand(time(0));
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
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::TextBox^ textBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(177, 42);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Додати елемент до стеку";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(177, 71);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(169, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Видалити елементи";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(177, 100);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(169, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Обчислити";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(22, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введіть розмір стеку";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(25, 99);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(110, 134);
			this->listBox1->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(25, 44);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(110, 20);
			this->textBox1->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(554, 484);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		System::Collections::Generic::Stack<int>myStack1;
		int count = 0;
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int size = Convert::ToInt32(textBox1->Text); // Отримуємо розмір стеку
	if (count < size) {
		int randomValue = rand() % 20; // Генеруємо випадкове число від 0 до 20
		myStack1.Push(randomValue); // Додаємо до стеку

		listBox1->Items->Insert(0, randomValue.ToString()); // Відображаємо у ListBox

		count++;
	}
	else {
		MessageBox::Show("Досягнуто ліміт чисел");
	}
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (myStack1.Count > 0) {
		myStack1.Pop(); // Видаляємо верхній елемент стеку
		listBox1->Items->Clear();

		for each (int value in myStack1) {
			listBox1->Items->Add(value.ToString()); // Оновлюємо ListBox після видалення
		}
	}
	else {
		listBox1->Items->Add("Стек Порожній");
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int sum = 0;

	for each (int value in myStack1) { // Проходимо по всіх елементах стеку
		if (value < 5) { // Перевіряємо умову "менше 5"
			sum += value; // Додаємо до суми
		}
	}

	MessageBox::Show("Сума елементів, менших за 5: " + sum.ToString());
}

};
}
