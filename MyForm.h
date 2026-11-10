#pragma once

#include "ChartForm.h"
#include "CurrencyCatalog.h"
#include "CurrencyException.h"

#include <msclr/marshal_cppstd.h>

namespace coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Drawing;
	using namespace System::Globalization;
	using namespace System::Windows::Forms;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			catalog = new CurrencyCatalog();
			RefreshGrid(catalog->GetAll());
			SetStatus(L"Готово. Додайте валюту або відкрийте файл (Ctrl+O).");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			this->!MyForm();
		}

		!MyForm()
		{
			delete catalog;
			catalog = nullptr;
		}

	private:
		CurrencyCatalog* catalog;

	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::Label^ lblCountry;
	private: System::Windows::Forms::TextBox^ txtCountry;
	private: System::Windows::Forms::Label^ lblRate;
	private: System::Windows::Forms::TextBox^ txtRate;
	private: System::Windows::Forms::Label^ lblRatio;
	private: System::Windows::Forms::TextBox^ txtRatio;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::GroupBox^ groupNew;
	private: System::Windows::Forms::Label^ lblSearch;
	private: System::Windows::Forms::TextBox^ txtSearch;
	private: System::Windows::Forms::Button^ btnSearch;
	private: System::Windows::Forms::Label^ lblFrom;
	private: System::Windows::Forms::TextBox^ txtFrom;
	private: System::Windows::Forms::Label^ lblTo;
	private: System::Windows::Forms::TextBox^ txtTo;
	private: System::Windows::Forms::Button^ btnFilter;
	private: System::Windows::Forms::Button^ btnShowAll;
	private: System::Windows::Forms::GroupBox^ groupSearch;
	private: System::Windows::Forms::Label^ lblDenomination;
	private: System::Windows::Forms::TextBox^ txtDenomination;
	private: System::Windows::Forms::Label^ lblQuantity;
	private: System::Windows::Forms::TextBox^ txtQuantity;
	private: System::Windows::Forms::Button^ btnAddNotes;
	private: System::Windows::Forms::Button^ btnRemoveNotes;
	private: System::Windows::Forms::GroupBox^ groupNotes;
	private: System::Windows::Forms::Button^ btnSort;
	private: System::Windows::Forms::Button^ btnCountries;
	private: System::Windows::Forms::Button^ btnDollars;
	private: System::Windows::Forms::Button^ btnChart;
	private: System::Windows::Forms::GroupBox^ groupCalc;
	private: System::Windows::Forms::Panel^ panelLeft;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCountry;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colRate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colRatio;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNotes;
	private: System::Windows::Forms::DataGridView^ grid;
	private: System::Windows::Forms::TextBox^ txtReport;
	private: System::Windows::Forms::ToolStripMenuItem^ cmAddNotes;
	private: System::Windows::Forms::ToolStripMenuItem^ cmRemoveNotes;
	private: System::Windows::Forms::ToolStripSeparator^ sepCm;
	private: System::Windows::Forms::ToolStripMenuItem^ cmRemove;
	private: System::Windows::Forms::ToolStripMenuItem^ cmShowAll;
	private: System::Windows::Forms::ContextMenuStrip^ gridMenu;
	private: System::Windows::Forms::ToolStripStatusLabel^ statusLabel;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripButton^ tbOpen;
	private: System::Windows::Forms::ToolStripButton^ tbSave;
	private: System::Windows::Forms::ToolStripSeparator^ sepT1;
	private: System::Windows::Forms::ToolStripButton^ tbAdd;
	private: System::Windows::Forms::ToolStripButton^ tbRemove;
	private: System::Windows::Forms::ToolStripSeparator^ sepT2;
	private: System::Windows::Forms::ToolStripButton^ tbSearch;
	private: System::Windows::Forms::ToolStripButton^ tbFilter;
	private: System::Windows::Forms::ToolStripButton^ tbShowAll;
	private: System::Windows::Forms::ToolStripSeparator^ sepT3;
	private: System::Windows::Forms::ToolStripButton^ tbAddNotes;
	private: System::Windows::Forms::ToolStripButton^ tbRemoveNotes;
	private: System::Windows::Forms::ToolStripSeparator^ sepT4;
	private: System::Windows::Forms::ToolStripButton^ tbSort;
	private: System::Windows::Forms::ToolStripButton^ tbCountries;
	private: System::Windows::Forms::ToolStripButton^ tbDollars;
	private: System::Windows::Forms::ToolStripButton^ tbChart;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ miOpen;
	private: System::Windows::Forms::ToolStripMenuItem^ miSave;
	private: System::Windows::Forms::ToolStripSeparator^ sepF1;
	private: System::Windows::Forms::ToolStripMenuItem^ miClear;
	private: System::Windows::Forms::ToolStripSeparator^ sepF2;
	private: System::Windows::Forms::ToolStripMenuItem^ miExit;
	private: System::Windows::Forms::ToolStripMenuItem^ miFile;
	private: System::Windows::Forms::ToolStripMenuItem^ miAdd;
	private: System::Windows::Forms::ToolStripMenuItem^ miRemove;
	private: System::Windows::Forms::ToolStripSeparator^ sepC1;
	private: System::Windows::Forms::ToolStripMenuItem^ miSearch;
	private: System::Windows::Forms::ToolStripMenuItem^ miFilter;
	private: System::Windows::Forms::ToolStripMenuItem^ miShowAll;
	private: System::Windows::Forms::ToolStripMenuItem^ miCurrency;
	private: System::Windows::Forms::ToolStripMenuItem^ miAddNotes;
	private: System::Windows::Forms::ToolStripMenuItem^ miRemoveNotes;
	private: System::Windows::Forms::ToolStripMenuItem^ miNotes;
	private: System::Windows::Forms::ToolStripMenuItem^ miSort;
	private: System::Windows::Forms::ToolStripMenuItem^ miCountries;
	private: System::Windows::Forms::ToolStripMenuItem^ miDollars;
	private: System::Windows::Forms::ToolStripMenuItem^ miChart;
	private: System::Windows::Forms::ToolStripMenuItem^ miCalc;
	private: System::Windows::Forms::ToolStripMenuItem^ miFormat;
	private: System::Windows::Forms::ToolStripMenuItem^ miAbout;
	private: System::Windows::Forms::ToolStripMenuItem^ miHelp;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolTip^ toolTip;
private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblCountry = (gcnew System::Windows::Forms::Label());
			this->txtCountry = (gcnew System::Windows::Forms::TextBox());
			this->lblRate = (gcnew System::Windows::Forms::Label());
			this->txtRate = (gcnew System::Windows::Forms::TextBox());
			this->lblRatio = (gcnew System::Windows::Forms::Label());
			this->txtRatio = (gcnew System::Windows::Forms::TextBox());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->groupNew = (gcnew System::Windows::Forms::GroupBox());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->lblFrom = (gcnew System::Windows::Forms::Label());
			this->txtFrom = (gcnew System::Windows::Forms::TextBox());
			this->lblTo = (gcnew System::Windows::Forms::Label());
			this->txtTo = (gcnew System::Windows::Forms::TextBox());
			this->btnFilter = (gcnew System::Windows::Forms::Button());
			this->btnShowAll = (gcnew System::Windows::Forms::Button());
			this->groupSearch = (gcnew System::Windows::Forms::GroupBox());
			this->lblDenomination = (gcnew System::Windows::Forms::Label());
			this->txtDenomination = (gcnew System::Windows::Forms::TextBox());
			this->lblQuantity = (gcnew System::Windows::Forms::Label());
			this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
			this->btnAddNotes = (gcnew System::Windows::Forms::Button());
			this->btnRemoveNotes = (gcnew System::Windows::Forms::Button());
			this->groupNotes = (gcnew System::Windows::Forms::GroupBox());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->btnCountries = (gcnew System::Windows::Forms::Button());
			this->btnDollars = (gcnew System::Windows::Forms::Button());
			this->btnChart = (gcnew System::Windows::Forms::Button());
			this->groupCalc = (gcnew System::Windows::Forms::GroupBox());
			this->panelLeft = (gcnew System::Windows::Forms::Panel());
			this->colName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCountry = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colRate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colRatio = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNotes = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->gridMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->cmAddNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cmRemoveNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepCm = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cmRemove = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cmShowAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->txtReport = (gcnew System::Windows::Forms::TextBox());
			this->statusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->tbOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->sepT1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbAdd = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbRemove = (gcnew System::Windows::Forms::ToolStripButton());
			this->sepT2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbSearch = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbFilter = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbShowAll = (gcnew System::Windows::Forms::ToolStripButton());
			this->sepT3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbAddNotes = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbRemoveNotes = (gcnew System::Windows::Forms::ToolStripButton());
			this->sepT4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbSort = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbCountries = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbDollars = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbChart = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->miOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepF1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->miClear = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepF2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->miExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAdd = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miRemove = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepC1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->miSearch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miFilter = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miShowAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miCurrency = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAddNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miRemoveNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miSort = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miCountries = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miDollars = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miChart = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miCalc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miFormat = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->groupNew->SuspendLayout();
			this->groupSearch->SuspendLayout();
			this->groupNotes->SuspendLayout();
			this->groupCalc->SuspendLayout();
			this->panelLeft->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->gridMenu->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(13, 38);
			this->lblName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(52, 16);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"Назва:";
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(220, 34);
			this->txtName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(185, 22);
			this->txtName->TabIndex = 1;
			this->toolTip->SetToolTip(this->txtName, L"Назва валюти, наприклад: Євро. Назви мають бути унікальними.");
			// 
			// lblCountry
			// 
			this->lblCountry->AutoSize = true;
			this->lblCountry->Location = System::Drawing::Point(13, 78);
			this->lblCountry->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblCountry->Name = L"lblCountry";
			this->lblCountry->Size = System::Drawing::Size(53, 16);
			this->lblCountry->TabIndex = 2;
			this->lblCountry->Text = L"Країна:";
			// 
			// txtCountry
			// 
			this->txtCountry->Location = System::Drawing::Point(220, 74);
			this->txtCountry->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtCountry->Name = L"txtCountry";
			this->txtCountry->Size = System::Drawing::Size(185, 22);
			this->txtCountry->TabIndex = 3;
			this->toolTip->SetToolTip(this->txtCountry, L"Країна, наприклад: Німеччина");
			// 
			// lblRate
			// 
			this->lblRate->AutoSize = true;
			this->lblRate->Location = System::Drawing::Point(13, 117);
			this->lblRate->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblRate->Name = L"lblRate";
			this->lblRate->Size = System::Drawing::Size(149, 16);
			this->lblRate->TabIndex = 4;
			this->lblRate->Text = L"Курс ($ за 1 одиницю):";
			// 
			// txtRate
			// 
			this->txtRate->Location = System::Drawing::Point(220, 113);
			this->txtRate->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtRate->Name = L"txtRate";
			this->txtRate->Size = System::Drawing::Size(185, 22);
			this->txtRate->TabIndex = 5;
			this->toolTip->SetToolTip(this->txtRate, L"Скільки доларів коштує 1 одиниця валюти. Дробові числа - через крапку, наприклад "
				L"1.08");
			// 
			// lblRatio
			// 
			this->lblRatio->AutoSize = true;
			this->lblRatio->Location = System::Drawing::Point(13, 156);
			this->lblRatio->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblRatio->Name = L"lblRatio";
			this->lblRatio->Size = System::Drawing::Size(144, 16);
			this->lblRatio->TabIndex = 6;
			this->lblRatio->Text = L"Одиниць за 1 $ (ціле):";
			// 
			// txtRatio
			// 
			this->txtRatio->Location = System::Drawing::Point(220, 153);
			this->txtRatio->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtRatio->Name = L"txtRatio";
			this->txtRatio->Size = System::Drawing::Size(185, 22);
			this->txtRatio->TabIndex = 7;
			this->toolTip->SetToolTip(this->txtRatio, L"Відношення до долара: ціле число від 1 до 1000000");
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(220, 194);
			this->btnAdd->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(187, 34);
			this->btnAdd->TabIndex = 8;
			this->btnAdd->Text = L"Додати валюту";
			this->toolTip->SetToolTip(this->btnAdd, L"Додати валюту до списку (Ctrl+D)");
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::OnAddCurrency);
			// 
			// groupNew
			// 
			this->groupNew->Controls->Add(this->lblName);
			this->groupNew->Controls->Add(this->txtName);
			this->groupNew->Controls->Add(this->lblCountry);
			this->groupNew->Controls->Add(this->txtCountry);
			this->groupNew->Controls->Add(this->lblRate);
			this->groupNew->Controls->Add(this->txtRate);
			this->groupNew->Controls->Add(this->lblRatio);
			this->groupNew->Controls->Add(this->txtRatio);
			this->groupNew->Controls->Add(this->btnAdd);
			this->groupNew->Location = System::Drawing::Point(11, 10);
			this->groupNew->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupNew->Name = L"groupNew";
			this->groupNew->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupNew->Size = System::Drawing::Size(427, 246);
			this->groupNew->TabIndex = 0;
			this->groupNew->TabStop = false;
			this->groupNew->Text = L"1. Нова валюта (введення з клавіатури)";
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Location = System::Drawing::Point(13, 38);
			this->lblSearch->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(52, 16);
			this->lblSearch->TabIndex = 0;
			this->lblSearch->Text = L"Назва:";
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(87, 34);
			this->txtSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(185, 22);
			this->txtSearch->TabIndex = 1;
			this->toolTip->SetToolTip(this->txtSearch, L"Назва валюти або її частина (регістр має значення)");
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(287, 32);
			this->btnSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(120, 34);
			this->btnSearch->TabIndex = 2;
			this->btnSearch->Text = L"Знайти";
			this->toolTip->SetToolTip(this->btnSearch, L"Знайти валюту за назвою (Ctrl+F)");
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->Click += gcnew System::EventHandler(this, &MyForm::OnSearch);
			// 
			// lblFrom
			// 
			this->lblFrom->AutoSize = true;
			this->lblFrom->Location = System::Drawing::Point(13, 82);
			this->lblFrom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblFrom->Name = L"lblFrom";
			this->lblFrom->Size = System::Drawing::Size(63, 16);
			this->lblFrom->TabIndex = 3;
			this->lblFrom->Text = L"Курс від:";
			// 
			// txtFrom
			// 
			this->txtFrom->Location = System::Drawing::Point(93, 79);
			this->txtFrom->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtFrom->Name = L"txtFrom";
			this->txtFrom->Size = System::Drawing::Size(79, 22);
			this->txtFrom->TabIndex = 4;
			this->toolTip->SetToolTip(this->txtFrom, L"Нижня межа курсу (x)");
			// 
			// lblTo
			// 
			this->lblTo->AutoSize = true;
			this->lblTo->Location = System::Drawing::Point(184, 82);
			this->lblTo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblTo->Name = L"lblTo";
			this->lblTo->Size = System::Drawing::Size(26, 16);
			this->lblTo->TabIndex = 5;
			this->lblTo->Text = L"до:";
			// 
			// txtTo
			// 
			this->txtTo->Location = System::Drawing::Point(216, 79);
			this->txtTo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtTo->Name = L"txtTo";
			this->txtTo->Size = System::Drawing::Size(79, 22);
			this->txtTo->TabIndex = 6;
			this->toolTip->SetToolTip(this->txtTo, L"Верхня межа курсу (y)");
			// 
			// btnFilter
			// 
			this->btnFilter->Location = System::Drawing::Point(307, 76);
			this->btnFilter->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnFilter->Name = L"btnFilter";
			this->btnFilter->Size = System::Drawing::Size(100, 34);
			this->btnFilter->TabIndex = 7;
			this->btnFilter->Text = L"Фільтр";
			this->toolTip->SetToolTip(this->btnFilter, L"Показати валюти з курсом від x до y (Ctrl+R)");
			this->btnFilter->UseVisualStyleBackColor = true;
			this->btnFilter->Click += gcnew System::EventHandler(this, &MyForm::OnFilterByRate);
			// 
			// btnShowAll
			// 
			this->btnShowAll->Location = System::Drawing::Point(13, 121);
			this->btnShowAll->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnShowAll->Name = L"btnShowAll";
			this->btnShowAll->Size = System::Drawing::Size(393, 34);
			this->btnShowAll->TabIndex = 8;
			this->btnShowAll->Text = L"Показати всі";
			this->toolTip->SetToolTip(this->btnShowAll, L"Скасувати пошук або фільтр (F5)");
			this->btnShowAll->UseVisualStyleBackColor = true;
			this->btnShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// groupSearch
			// 
			this->groupSearch->Controls->Add(this->lblSearch);
			this->groupSearch->Controls->Add(this->txtSearch);
			this->groupSearch->Controls->Add(this->btnSearch);
			this->groupSearch->Controls->Add(this->lblFrom);
			this->groupSearch->Controls->Add(this->txtFrom);
			this->groupSearch->Controls->Add(this->lblTo);
			this->groupSearch->Controls->Add(this->txtTo);
			this->groupSearch->Controls->Add(this->btnFilter);
			this->groupSearch->Controls->Add(this->btnShowAll);
			this->groupSearch->Location = System::Drawing::Point(11, 266);
			this->groupSearch->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupSearch->Name = L"groupSearch";
			this->groupSearch->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupSearch->Size = System::Drawing::Size(427, 172);
			this->groupSearch->TabIndex = 1;
			this->groupSearch->TabStop = false;
			this->groupSearch->Text = L"2. Пошук і фільтр";
			// 
			// lblDenomination
			// 
			this->lblDenomination->AutoSize = true;
			this->lblDenomination->Location = System::Drawing::Point(13, 41);
			this->lblDenomination->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblDenomination->Name = L"lblDenomination";
			this->lblDenomination->Size = System::Drawing::Size(64, 16);
			this->lblDenomination->TabIndex = 0;
			this->lblDenomination->Text = L"Номінал:";
			// 
			// txtDenomination
			// 
			this->txtDenomination->Location = System::Drawing::Point(113, 37);
			this->txtDenomination->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtDenomination->Name = L"txtDenomination";
			this->txtDenomination->Size = System::Drawing::Size(105, 22);
			this->txtDenomination->TabIndex = 1;
			this->toolTip->SetToolTip(this->txtDenomination, L"Номінал банкноти (ціле число більше 0)");
			// 
			// lblQuantity
			// 
			this->lblQuantity->AutoSize = true;
			this->lblQuantity->Location = System::Drawing::Point(13, 84);
			this->lblQuantity->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblQuantity->Name = L"lblQuantity";
			this->lblQuantity->Size = System::Drawing::Size(67, 16);
			this->lblQuantity->TabIndex = 2;
			this->lblQuantity->Text = L"Кількість:";
			// 
			// txtQuantity
			// 
			this->txtQuantity->Location = System::Drawing::Point(113, 80);
			this->txtQuantity->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtQuantity->Name = L"txtQuantity";
			this->txtQuantity->Size = System::Drawing::Size(105, 22);
			this->txtQuantity->TabIndex = 3;
			this->toolTip->SetToolTip(this->txtQuantity, L"Кількість банкнот (ціле число більше 0)");
			// 
			// btnAddNotes
			// 
			this->btnAddNotes->Location = System::Drawing::Point(247, 32);
			this->btnAddNotes->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnAddNotes->Name = L"btnAddNotes";
			this->btnAddNotes->Size = System::Drawing::Size(160, 34);
			this->btnAddNotes->TabIndex = 4;
			this->btnAddNotes->Text = L"Додати";
			this->toolTip->SetToolTip(this->btnAddNotes, L"Додати банкноти вибраній валюті (Ctrl+B)");
			this->btnAddNotes->UseVisualStyleBackColor = true;
			this->btnAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddBanknotes);
			// 
			// btnRemoveNotes
			// 
			this->btnRemoveNotes->Location = System::Drawing::Point(247, 76);
			this->btnRemoveNotes->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnRemoveNotes->Name = L"btnRemoveNotes";
			this->btnRemoveNotes->Size = System::Drawing::Size(160, 34);
			this->btnRemoveNotes->TabIndex = 5;
			this->btnRemoveNotes->Text = L"Вилучити";
			this->toolTip->SetToolTip(this->btnRemoveNotes, L"Вилучити банкноти у вибраної валюти (Ctrl+Shift+B)");
			this->btnRemoveNotes->UseVisualStyleBackColor = true;
			this->btnRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveBanknotes);
			// 
			// groupNotes
			// 
			this->groupNotes->Controls->Add(this->lblDenomination);
			this->groupNotes->Controls->Add(this->txtDenomination);
			this->groupNotes->Controls->Add(this->lblQuantity);
			this->groupNotes->Controls->Add(this->txtQuantity);
			this->groupNotes->Controls->Add(this->btnAddNotes);
			this->groupNotes->Controls->Add(this->btnRemoveNotes);
			this->groupNotes->Location = System::Drawing::Point(11, 448);
			this->groupNotes->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupNotes->Name = L"groupNotes";
			this->groupNotes->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupNotes->Size = System::Drawing::Size(427, 135);
			this->groupNotes->TabIndex = 2;
			this->groupNotes->TabStop = false;
			this->groupNotes->Text = L"3. Банкноти вибраної валюти";
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(13, 30);
			this->btnSort->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(393, 34);
			this->btnSort->TabIndex = 0;
			this->btnSort->Text = L"Сортувати за відношенням до $";
			this->toolTip->SetToolTip(this->btnSort, L"Сортування методом підрахунку за відношенням до долара (F6)");
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->Click += gcnew System::EventHandler(this, &MyForm::OnSort);
			// 
			// btnCountries
			// 
			this->btnCountries->Location = System::Drawing::Point(13, 71);
			this->btnCountries->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnCountries->Name = L"btnCountries";
			this->btnCountries->Size = System::Drawing::Size(393, 34);
			this->btnCountries->TabIndex = 1;
			this->btnCountries->Text = L"Валюти за країнами";
			this->toolTip->SetToolTip(this->btnCountries, L"Країни за алфавітом; для кожної - валюти та наявні банкноти (F7)");
			this->btnCountries->UseVisualStyleBackColor = true;
			this->btnCountries->Click += gcnew System::EventHandler(this, &MyForm::OnReportCountries);
			// 
			// btnDollars
			// 
			this->btnDollars->Location = System::Drawing::Point(13, 113);
			this->btnDollars->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnDollars->Name = L"btnDollars";
			this->btnDollars->Size = System::Drawing::Size(393, 34);
			this->btnDollars->TabIndex = 2;
			this->btnDollars->Text = L"Суми банкнот у доларах";
			this->toolTip->SetToolTip(this->btnDollars, L"Переведення банкнот у долари та загальна сума для кожної країни (F8)");
			this->btnDollars->UseVisualStyleBackColor = true;
			this->btnDollars->Click += gcnew System::EventHandler(this, &MyForm::OnReportDollars);
			// 
			// btnChart
			// 
			this->btnChart->Location = System::Drawing::Point(13, 155);
			this->btnChart->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnChart->Name = L"btnChart";
			this->btnChart->Size = System::Drawing::Size(393, 34);
			this->btnChart->TabIndex = 3;
			this->btnChart->Text = L"Діаграма сум за країнами";
			this->toolTip->SetToolTip(this->btnChart, L"Візуальна діаграма сум у доларах (F9)");
			this->btnChart->UseVisualStyleBackColor = true;
			this->btnChart->Click += gcnew System::EventHandler(this, &MyForm::OnShowChart);
			// 
			// groupCalc
			// 
			this->groupCalc->Controls->Add(this->btnSort);
			this->groupCalc->Controls->Add(this->btnCountries);
			this->groupCalc->Controls->Add(this->btnDollars);
			this->groupCalc->Controls->Add(this->btnChart);
			this->groupCalc->Location = System::Drawing::Point(11, 593);
			this->groupCalc->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupCalc->Name = L"groupCalc";
			this->groupCalc->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupCalc->Size = System::Drawing::Size(427, 209);
			this->groupCalc->TabIndex = 3;
			this->groupCalc->TabStop = false;
			this->groupCalc->Text = L"4. Обчислення та звіти";
			// 
			// panelLeft
			// 
			this->panelLeft->AutoScroll = true;
			this->panelLeft->Controls->Add(this->groupNew);
			this->panelLeft->Controls->Add(this->groupSearch);
			this->panelLeft->Controls->Add(this->groupNotes);
			this->panelLeft->Controls->Add(this->groupCalc);
			this->panelLeft->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelLeft->Location = System::Drawing::Point(0, 55);
			this->panelLeft->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panelLeft->Name = L"panelLeft";
			this->panelLeft->Size = System::Drawing::Size(453, 781);
			this->panelLeft->TabIndex = 2;
			// 
			// colName
			// 
			this->colName->HeaderText = L"Назва";
			this->colName->MinimumWidth = 6;
			this->colName->Name = L"colName";
			this->colName->ReadOnly = true;
			this->colName->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// colCountry
			// 
			this->colCountry->HeaderText = L"Країна";
			this->colCountry->MinimumWidth = 6;
			this->colCountry->Name = L"colCountry";
			this->colCountry->ReadOnly = true;
			this->colCountry->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// colRate
			// 
			this->colRate->HeaderText = L"Курс ($ за 1 одиницю)";
			this->colRate->MinimumWidth = 6;
			this->colRate->Name = L"colRate";
			this->colRate->ReadOnly = true;
			this->colRate->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// colRatio
			// 
			this->colRatio->HeaderText = L"Одиниць за 1 $";
			this->colRatio->MinimumWidth = 6;
			this->colRatio->Name = L"colRatio";
			this->colRatio->ReadOnly = true;
			this->colRatio->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// colNotes
			// 
			this->colNotes->FillWeight = 200;
			this->colNotes->HeaderText = L"Наявні банкноти (номінал x кількість)";
			this->colNotes->MinimumWidth = 6;
			this->colNotes->Name = L"colNotes";
			this->colNotes->ReadOnly = true;
			this->colNotes->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// grid
			// 
			this->grid->AllowUserToAddRows = false;
			this->grid->AllowUserToDeleteRows = false;
			this->grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colName, this->colCountry,
					this->colRate, this->colRatio, this->colNotes
			});
			this->grid->ContextMenuStrip = this->gridMenu;
			this->grid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grid->Location = System::Drawing::Point(453, 55);
			this->grid->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->grid->MultiSelect = false;
			this->grid->Name = L"grid";
			this->grid->ReadOnly = true;
			this->grid->RowHeadersVisible = false;
			this->grid->RowHeadersWidth = 51;
			this->grid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->grid->Size = System::Drawing::Size(1120, 548);
			this->grid->TabIndex = 0;
			this->toolTip->SetToolTip(this->grid, L"Таблиця валют. Права кнопка миші - контекстне меню.");
			this->grid->CellMouseDown += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::OnGridCellMouseDown);
			// 
			// gridMenu
			// 
			this->gridMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->gridMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->cmAddNotes, this->cmRemoveNotes,
					this->sepCm, this->cmRemove, this->cmShowAll
			});
			this->gridMenu->Name = L"gridMenu";
			this->gridMenu->Size = System::Drawing::Size(214, 106);
			// 
			// cmAddNotes
			// 
			this->cmAddNotes->Name = L"cmAddNotes";
			this->cmAddNotes->Size = System::Drawing::Size(213, 24);
			this->cmAddNotes->Text = L"Додати банкноти";
			this->cmAddNotes->ToolTipText = L"Додати банкноти вибраній валюті (номінал і кількість беруться з лівої панелі)";
			this->cmAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddBanknotes);
			// 
			// cmRemoveNotes
			// 
			this->cmRemoveNotes->Name = L"cmRemoveNotes";
			this->cmRemoveNotes->Size = System::Drawing::Size(213, 24);
			this->cmRemoveNotes->Text = L"Вилучити банкноти";
			this->cmRemoveNotes->ToolTipText = L"Вилучити банкноти у вибраної валюти";
			this->cmRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveBanknotes);
			// 
			// sepCm
			// 
			this->sepCm->Name = L"sepCm";
			this->sepCm->Size = System::Drawing::Size(210, 6);
			// 
			// cmRemove
			// 
			this->cmRemove->Name = L"cmRemove";
			this->cmRemove->Size = System::Drawing::Size(213, 24);
			this->cmRemove->Text = L"Видалити валюту";
			this->cmRemove->ToolTipText = L"Видалити вибрану валюту зі списку";
			this->cmRemove->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveCurrency);
			// 
			// cmShowAll
			// 
			this->cmShowAll->Name = L"cmShowAll";
			this->cmShowAll->Size = System::Drawing::Size(213, 24);
			this->cmShowAll->Text = L"Показати всі";
			this->cmShowAll->ToolTipText = L"Скасувати пошук або фільтр";
			this->cmShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// txtReport
			// 
			this->txtReport->BackColor = System::Drawing::SystemColors::Window;
			this->txtReport->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->txtReport->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtReport->Location = System::Drawing::Point(453, 603);
			this->txtReport->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtReport->Multiline = true;
			this->txtReport->Name = L"txtReport";
			this->txtReport->ReadOnly = true;
			this->txtReport->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtReport->Size = System::Drawing::Size(1120, 233);
			this->txtReport->TabIndex = 1;
			this->toolTip->SetToolTip(this->txtReport, L"Тут відображаються звіти по країнах");
			this->txtReport->WordWrap = false;
			// 
			// statusLabel
			// 
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Size = System::Drawing::Size(57, 20);
			this->statusLabel->Text = L"Готово";
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusLabel });
			this->statusStrip1->Location = System::Drawing::Point(0, 836);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Padding = System::Windows::Forms::Padding(1, 0, 19, 0);
			this->statusStrip1->Size = System::Drawing::Size(1573, 26);
			this->statusStrip1->TabIndex = 3;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// tbOpen
			// 
			this->tbOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbOpen->Name = L"tbOpen";
			this->tbOpen->Size = System::Drawing::Size(74, 24);
			this->tbOpen->Text = L"Відкрити";
			this->tbOpen->ToolTipText = L"Завантажити валюти з файлу (Ctrl+O)";
			this->tbOpen->Click += gcnew System::EventHandler(this, &MyForm::OnOpenFile);
			// 
			// tbSave
			// 
			this->tbSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbSave->Name = L"tbSave";
			this->tbSave->Size = System::Drawing::Size(76, 24);
			this->tbSave->Text = L"Зберегти";
			this->tbSave->ToolTipText = L"Зберегти валюти у файл (Ctrl+S)";
			this->tbSave->Click += gcnew System::EventHandler(this, &MyForm::OnSaveFile);
			// 
			// sepT1
			// 
			this->sepT1->Name = L"sepT1";
			this->sepT1->Size = System::Drawing::Size(6, 27);
			// 
			// tbAdd
			// 
			this->tbAdd->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbAdd->Name = L"tbAdd";
			this->tbAdd->Size = System::Drawing::Size(116, 24);
			this->tbAdd->Text = L"Додати валюту";
			this->tbAdd->ToolTipText = L"Додати валюту з полів лівої панелі (Ctrl+D)";
			this->tbAdd->Click += gcnew System::EventHandler(this, &MyForm::OnAddCurrency);
			// 
			// tbRemove
			// 
			this->tbRemove->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbRemove->Name = L"tbRemove";
			this->tbRemove->Size = System::Drawing::Size(79, 24);
			this->tbRemove->Text = L"Видалити";
			this->tbRemove->ToolTipText = L"Видалити вибрану валюту (Ctrl+Delete)";
			this->tbRemove->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveCurrency);
			// 
			// sepT2
			// 
			this->sepT2->Name = L"sepT2";
			this->sepT2->Size = System::Drawing::Size(6, 27);
			// 
			// tbSearch
			// 
			this->tbSearch->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Size = System::Drawing::Size(62, 24);
			this->tbSearch->Text = L"Знайти";
			this->tbSearch->ToolTipText = L"Пошук за назвою (Ctrl+F)";
			this->tbSearch->Click += gcnew System::EventHandler(this, &MyForm::OnSearch);
			// 
			// tbFilter
			// 
			this->tbFilter->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbFilter->Name = L"tbFilter";
			this->tbFilter->Size = System::Drawing::Size(132, 24);
			this->tbFilter->Text = L"Фільтр за курсом";
			this->tbFilter->ToolTipText = L"Валюти з курсом від x до y (Ctrl+R)";
			this->tbFilter->Click += gcnew System::EventHandler(this, &MyForm::OnFilterByRate);
			// 
			// tbShowAll
			// 
			this->tbShowAll->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbShowAll->Name = L"tbShowAll";
			this->tbShowAll->Size = System::Drawing::Size(33, 24);
			this->tbShowAll->Text = L"Усі";
			this->tbShowAll->ToolTipText = L"Показати всі валюти (F5)";
			this->tbShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// sepT3
			// 
			this->sepT3->Name = L"sepT3";
			this->sepT3->Size = System::Drawing::Size(6, 27);
			// 
			// tbAddNotes
			// 
			this->tbAddNotes->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbAddNotes->Name = L"tbAddNotes";
			this->tbAddNotes->Size = System::Drawing::Size(93, 24);
			this->tbAddNotes->Text = L"+ Банкноти";
			this->tbAddNotes->ToolTipText = L"Додати банкноти (Ctrl+B)";
			this->tbAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddBanknotes);
			// 
			// tbRemoveNotes
			// 
			this->tbRemoveNotes->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbRemoveNotes->Name = L"tbRemoveNotes";
			this->tbRemoveNotes->Size = System::Drawing::Size(91, 24);
			this->tbRemoveNotes->Text = L"– Банкноти";
			this->tbRemoveNotes->ToolTipText = L"Вилучити банкноти (Ctrl+Shift+B)";
			this->tbRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveBanknotes);
			// 
			// sepT4
			// 
			this->sepT4->Name = L"sepT4";
			this->sepT4->Size = System::Drawing::Size(6, 27);
			// 
			// tbSort
			// 
			this->tbSort->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbSort->Name = L"tbSort";
			this->tbSort->Size = System::Drawing::Size(84, 24);
			this->tbSort->Text = L"Сортувати";
			this->tbSort->ToolTipText = L"Сортування підрахунком за відношенням до $ (F6)";
			this->tbSort->Click += gcnew System::EventHandler(this, &MyForm::OnSort);
			// 
			// tbCountries
			// 
			this->tbCountries->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbCountries->Name = L"tbCountries";
			this->tbCountries->Size = System::Drawing::Size(98, 24);
			this->tbCountries->Text = L"За країнами";
			this->tbCountries->ToolTipText = L"Валюти за країнами з банкнотами (F7)";
			this->tbCountries->Click += gcnew System::EventHandler(this, &MyForm::OnReportCountries);
			// 
			// tbDollars
			// 
			this->tbDollars->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbDollars->Name = L"tbDollars";
			this->tbDollars->Size = System::Drawing::Size(73, 24);
			this->tbDollars->Text = L"Суми в $";
			this->tbDollars->ToolTipText = L"Суми банкнот у доларах за країнами (F8)";
			this->tbDollars->Click += gcnew System::EventHandler(this, &MyForm::OnReportDollars);
			// 
			// tbChart
			// 
			this->tbChart->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbChart->Name = L"tbChart";
			this->tbChart->Size = System::Drawing::Size(77, 24);
			this->tbChart->Text = L"Діаграма";
			this->tbChart->ToolTipText = L"Діаграма сум за країнами (F9)";
			this->tbChart->Click += gcnew System::EventHandler(this, &MyForm::OnShowChart);
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(17) {
				this->tbOpen, this->tbSave,
					this->sepT1, this->tbAdd, this->tbRemove, this->sepT2, this->tbSearch, this->tbFilter, this->tbShowAll, this->sepT3, this->tbAddNotes,
					this->tbRemoveNotes, this->sepT4, this->tbSort, this->tbCountries, this->tbDollars, this->tbChart
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 28);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1573, 27);
			this->toolStrip1->TabIndex = 4;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// miOpen
			// 
			this->miOpen->Name = L"miOpen";
			this->miOpen->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->miOpen->Size = System::Drawing::Size(272, 26);
			this->miOpen->Text = L"&Відкрити з файлу...";
			this->miOpen->ToolTipText = L"Режим введення №2: завантажити валюти з текстового файлу";
			this->miOpen->Click += gcnew System::EventHandler(this, &MyForm::OnOpenFile);
			// 
			// miSave
			// 
			this->miSave->Name = L"miSave";
			this->miSave->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->miSave->Size = System::Drawing::Size(272, 26);
			this->miSave->Text = L"&Зберегти у файл...";
			this->miSave->ToolTipText = L"Записати всі валюти у текстовий файл";
			this->miSave->Click += gcnew System::EventHandler(this, &MyForm::OnSaveFile);
			// 
			// sepF1
			// 
			this->sepF1->Name = L"sepF1";
			this->sepF1->Size = System::Drawing::Size(269, 6);
			// 
			// miClear
			// 
			this->miClear->Name = L"miClear";
			this->miClear->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->miClear->Size = System::Drawing::Size(272, 26);
			this->miClear->Text = L"&Очистити список";
			this->miClear->ToolTipText = L"Видалити всі валюти з пам\'яті програми";
			this->miClear->Click += gcnew System::EventHandler(this, &MyForm::OnClearAll);
			// 
			// sepF2
			// 
			this->sepF2->Name = L"sepF2";
			this->sepF2->Size = System::Drawing::Size(269, 6);
			// 
			// miExit
			// 
			this->miExit->Name = L"miExit";
			this->miExit->Size = System::Drawing::Size(272, 26);
			this->miExit->Text = L"Вихід";
			this->miExit->ToolTipText = L"Закрити програму";
			this->miExit->Click += gcnew System::EventHandler(this, &MyForm::OnExit);
			// 
			// miFile
			// 
			this->miFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->miOpen, this->miSave,
					this->sepF1, this->miClear, this->sepF2, this->miExit
			});
			this->miFile->Name = L"miFile";
			this->miFile->Size = System::Drawing::Size(59, 24);
			this->miFile->Text = L"&Файл";
			this->miFile->ToolTipText = L"Робота з файлами";
			// 
			// miAdd
			// 
			this->miAdd->Name = L"miAdd";
			this->miAdd->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D));
			this->miAdd->Size = System::Drawing::Size(286, 26);
			this->miAdd->Text = L"&Додати валюту";
			this->miAdd->ToolTipText = L"Режим введення №1: додати валюту з полів лівої панелі";
			this->miAdd->Click += gcnew System::EventHandler(this, &MyForm::OnAddCurrency);
			// 
			// miRemove
			// 
			this->miRemove->Name = L"miRemove";
			this->miRemove->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Delete));
			this->miRemove->Size = System::Drawing::Size(286, 26);
			this->miRemove->Text = L"Ви&далити вибрану";
			this->miRemove->ToolTipText = L"Видалити вибрану в таблиці валюту";
			this->miRemove->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveCurrency);
			// 
			// sepC1
			// 
			this->sepC1->Name = L"sepC1";
			this->sepC1->Size = System::Drawing::Size(283, 6);
			// 
			// miSearch
			// 
			this->miSearch->Name = L"miSearch";
			this->miSearch->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->miSearch->Size = System::Drawing::Size(286, 26);
			this->miSearch->Text = L"&Знайти за назвою";
			this->miSearch->ToolTipText = L"Пошук валюти за назвою";
			this->miSearch->Click += gcnew System::EventHandler(this, &MyForm::OnSearch);
			// 
			// miFilter
			// 
			this->miFilter->Name = L"miFilter";
			this->miFilter->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->miFilter->Size = System::Drawing::Size(286, 26);
			this->miFilter->Text = L"Фільтр за &курсом";
			this->miFilter->ToolTipText = L"Показати валюти з курсом від x до y";
			this->miFilter->Click += gcnew System::EventHandler(this, &MyForm::OnFilterByRate);
			// 
			// miShowAll
			// 
			this->miShowAll->Name = L"miShowAll";
			this->miShowAll->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->miShowAll->Size = System::Drawing::Size(286, 26);
			this->miShowAll->Text = L"Показати &всі";
			this->miShowAll->ToolTipText = L"Скасувати пошук або фільтр";
			this->miShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// miCurrency
			// 
			this->miCurrency->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->miAdd, this->miRemove,
					this->sepC1, this->miSearch, this->miFilter, this->miShowAll
			});
			this->miCurrency->Name = L"miCurrency";
			this->miCurrency->Size = System::Drawing::Size(74, 24);
			this->miCurrency->Text = L"&Валюта";
			this->miCurrency->ToolTipText = L"Операції з валютами";
			// 
			// miAddNotes
			// 
			this->miAddNotes->Name = L"miAddNotes";
			this->miAddNotes->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
			this->miAddNotes->Size = System::Drawing::Size(318, 26);
			this->miAddNotes->Text = L"&Додати банкноти";
			this->miAddNotes->ToolTipText = L"Додати банкноти вибраній валюті";
			this->miAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddBanknotes);
			// 
			// miRemoveNotes
			// 
			this->miRemoveNotes->Name = L"miRemoveNotes";
			this->miRemoveNotes->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::B));
			this->miRemoveNotes->Size = System::Drawing::Size(318, 26);
			this->miRemoveNotes->Text = L"&Вилучити банкноти";
			this->miRemoveNotes->ToolTipText = L"Вилучити банкноти у вибраної валюти";
			this->miRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveBanknotes);
			// 
			// miNotes
			// 
			this->miNotes->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->miAddNotes,
					this->miRemoveNotes
			});
			this->miNotes->Name = L"miNotes";
			this->miNotes->Size = System::Drawing::Size(89, 24);
			this->miNotes->Text = L"&Банкноти";
			this->miNotes->ToolTipText = L"Операції з банкнотами";
			// 
			// miSort
			// 
			this->miSort->Name = L"miSort";
			this->miSort->ShortcutKeys = System::Windows::Forms::Keys::F6;
			this->miSort->Size = System::Drawing::Size(338, 26);
			this->miSort->Text = L"&Сортувати за відношенням до $";
			this->miSort->ToolTipText = L"Сортування методом підрахунку";
			this->miSort->Click += gcnew System::EventHandler(this, &MyForm::OnSort);
			// 
			// miCountries
			// 
			this->miCountries->Name = L"miCountries";
			this->miCountries->ShortcutKeys = System::Windows::Forms::Keys::F7;
			this->miCountries->Size = System::Drawing::Size(338, 26);
			this->miCountries->Text = L"Валюти за &країнами";
			this->miCountries->ToolTipText = L"Країни за алфавітом; для кожної - валюти та банкноти";
			this->miCountries->Click += gcnew System::EventHandler(this, &MyForm::OnReportCountries);
			// 
			// miDollars
			// 
			this->miDollars->Name = L"miDollars";
			this->miDollars->ShortcutKeys = System::Windows::Forms::Keys::F8;
			this->miDollars->Size = System::Drawing::Size(338, 26);
			this->miDollars->Text = L"Суми банкнот у &доларах";
			this->miDollars->ToolTipText = L"Банкноти в доларах і загальна сума для кожної країни";
			this->miDollars->Click += gcnew System::EventHandler(this, &MyForm::OnReportDollars);
			// 
			// miChart
			// 
			this->miChart->Name = L"miChart";
			this->miChart->ShortcutKeys = System::Windows::Forms::Keys::F9;
			this->miChart->Size = System::Drawing::Size(338, 26);
			this->miChart->Text = L"&Діаграма сум";
			this->miChart->ToolTipText = L"Візуальна діаграма сум за країнами";
			this->miChart->Click += gcnew System::EventHandler(this, &MyForm::OnShowChart);
			// 
			// miCalc
			// 
			this->miCalc->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->miSort, this->miCountries,
					this->miDollars, this->miChart
			});
			this->miCalc->Name = L"miCalc";
			this->miCalc->Size = System::Drawing::Size(109, 24);
			this->miCalc->Text = L"&Обчислення";
			this->miCalc->ToolTipText = L"Сортування, звіти й діаграма";
			// 
			// miFormat
			// 
			this->miFormat->Name = L"miFormat";
			this->miFormat->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->miFormat->Size = System::Drawing::Size(261, 26);
			this->miFormat->Text = L"&Формат файлу даних";
			this->miFormat->ToolTipText = L"Як має виглядати вхідний текстовий файл";
			this->miFormat->Click += gcnew System::EventHandler(this, &MyForm::OnFileFormat);
			// 
			// miAbout
			// 
			this->miAbout->Name = L"miAbout";
			this->miAbout->Size = System::Drawing::Size(261, 26);
			this->miAbout->Text = L"&Про програму";
			this->miAbout->ToolTipText = L"Відомості про програму";
			this->miAbout->Click += gcnew System::EventHandler(this, &MyForm::OnAbout);
			// 
			// miHelp
			// 
			this->miHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->miFormat, this->miAbout });
			this->miHelp->Name = L"miHelp";
			this->miHelp->Size = System::Drawing::Size(77, 24);
			this->miHelp->Text = L"&Довідка";
			this->miHelp->ToolTipText = L"Довідкова інформація";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->miFile, this->miCurrency,
					this->miNotes, this->miCalc, this->miHelp
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->ShowItemToolTips = true;
			this->menuStrip1->Size = System::Drawing::Size(1573, 28);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolTip
			// 
			this->toolTip->AutoPopDelay = 5000;
			this->toolTip->InitialDelay = 300;
			this->toolTip->ReshowDelay = 100;
			this->toolTip->ShowAlways = true;
			this->toolTip->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyForm::toolTip_Popup);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1573, 862);
			this->Controls->Add(this->grid);
			this->Controls->Add(this->txtReport);
			this->Controls->Add(this->panelLeft);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MinimumSize = System::Drawing::Size(1327, 789);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Облік валют";
			this->groupNew->ResumeLayout(false);
			this->groupNew->PerformLayout();
			this->groupSearch->ResumeLayout(false);
			this->groupSearch->PerformLayout();
			this->groupNotes->ResumeLayout(false);
			this->groupNotes->PerformLayout();
			this->groupCalc->ResumeLayout(false);
			this->panelLeft->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->gridMenu->ResumeLayout(false);
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		static std::string ToStd(String^ text)
		{
			return msclr::interop::marshal_as<std::string>(text);
		}

		static String^ ToNet(const std::string& text)
		{
			return gcnew String(text.c_str());
		}

		void SetStatus(String^ text)
		{
			statusLabel->Text = text;
		}

		// Показує повідомлення про виняткову ситуацію
		void ShowError(CurrencyException& ex)
		{
			MessageBox::Show(ToNet(ex.GetText()), L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			SetStatus(String::Concat(L"Помилка: ", ToNet(ex.GetText())));
		}

		// Заповнює таблицю переданим списком валют
		void RefreshGrid(const std::vector<Currency>& list)
		{
			grid->Rows->Clear();
			for (size_t i = 0; i < list.size(); i++)
			{
				const Currency& c = list[i];
				cli::array<Object^>^ row = gcnew cli::array<Object^>(5);
				row[0] = ToNet(c.GetName());
				row[1] = ToNet(c.GetCountry());
				row[2] = Convert::ToString(c.GetRate(), CultureInfo::InvariantCulture);
				row[3] = Convert::ToString(c.GetDollarRatio());
				row[4] = ToNet(c.BanknotesToString());
				grid->Rows->Add(row);
			}
		}

		// Виділяє в таблиці рядок з вказаною назвою
		void SelectByName(const std::string& name)
		{
			String^ target = ToNet(name);
			for (int i = 0; i < grid->Rows->Count; i++)
			{
				if (grid->Rows[i]->Cells[0]->Value->ToString() == target)
				{
					grid->CurrentCell = grid->Rows[i]->Cells[0];
					return;
				}
			}
		}

		// Назва валюти, вибраної в таблиці
		std::string SelectedName()
		{
			if (grid->CurrentRow == nullptr)
				throw CurrencyException("Спочатку виберіть валюту в таблиці");
			return ToStd(grid->CurrentRow->Cells[0]->Value->ToString());
		}

		// Текстове поле не має бути порожнім
		void RequireText(TextBox^ box, const std::string& message)
		{
			if (box->Text->Trim()->Length == 0)
				throw CurrencyException(message);
		}

		// Зчитування дійсного числа з поля (крапка або кома)
		double ReadDouble(TextBox^ box, const std::string& fieldName)
		{
			double value;
			String^ text = box->Text->Trim()->Replace(L',', L'.');
			if (!Double::TryParse(text, NumberStyles::Float, CultureInfo::InvariantCulture, value)
				|| Double::IsNaN(value) || Double::IsInfinity(value))
				throw CurrencyException(fieldName + " має бути числом");
			return value;
		}

		// Зчитування цілого числа з поля
		int ReadInt(TextBox^ box, const std::string& fieldName)
		{
			int value;
			if (!Int32::TryParse(box->Text->Trim(), NumberStyles::Integer, CultureInfo::InvariantCulture, value))
				throw CurrencyException(fieldName + " має бути цілим числом");
			return value;
		}

		//Обробники подій

		// Права кнопка миші виділяє рядок під курсором (для контекстного меню)
		void OnGridCellMouseDown(Object^ sender, DataGridViewCellMouseEventArgs^ e)
		{
			if (e->Button == System::Windows::Forms::MouseButtons::Right && e->RowIndex >= 0)
				grid->CurrentCell = grid->Rows[e->RowIndex]->Cells[0];
		}

		void OnAddCurrency(Object^ sender, EventArgs^ e)
		{
			try
			{
				RequireText(txtName, "Назва валюти не може бути порожньою");
				RequireText(txtCountry, "Країна не може бути порожньою");
				double rate = ReadDouble(txtRate, "Курс");
				int ratio = ReadInt(txtRatio, "Відношення до долара");

				Currency currency(ToStd(txtName->Text->Trim()), ToStd(txtCountry->Text->Trim()), rate, ratio);
				catalog->AddCurrency(currency);
				RefreshGrid(catalog->GetAll());
				SelectByName(currency.GetName());
				SetStatus(String::Concat(L"Валюту додано: ", ToNet(currency.GetName())));

				txtName->Clear();
				txtCountry->Clear();
				txtRate->Clear();
				txtRatio->Clear();
				txtName->Focus();
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnRemoveCurrency(Object^ sender, EventArgs^ e)
		{
			try
			{
				std::string name = SelectedName();
				if (MessageBox::Show(String::Concat(L"Видалити валюту «", ToNet(name), L"»?"), L"Підтвердження",
					MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes)
					return;
				catalog->RemoveCurrency(name);
				RefreshGrid(catalog->GetAll());
				SetStatus(L"Валюту видалено");
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnSearch(Object^ sender, EventArgs^ e)
		{
			try
			{
				std::vector<Currency> found = catalog->SearchByName(ToStd(txtSearch->Text->Trim()));
				RefreshGrid(found);
				SetStatus(String::Format(L"Знайдено валют: {0}", static_cast<int>(found.size())));
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnFilterByRate(Object^ sender, EventArgs^ e)
		{
			try
			{
				double from = ReadDouble(txtFrom, "Нижня межа курсу");
				double to = ReadDouble(txtTo, "Верхня межа курсу");
				std::vector<Currency> found = catalog->FilterByRate(from, to);
				RefreshGrid(found);
				SetStatus(String::Format(L"Валют з курсом у цьому діапазоні: {0}", static_cast<int>(found.size())));
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnShowAll(Object^ sender, EventArgs^ e)
		{
			RefreshGrid(catalog->GetAll());
			SetStatus(String::Format(L"Усього валют: {0}", catalog->Count()));
		}

		void OnAddBanknotes(Object^ sender, EventArgs^ e)
		{
			try
			{
				std::string name = SelectedName();
				int denomination = ReadInt(txtDenomination, "Номінал");
				int quantity = ReadInt(txtQuantity, "Кількість");
				catalog->AddBanknotes(name, denomination, quantity);
				RefreshGrid(catalog->GetAll());
				SelectByName(name);
				SetStatus(L"Банкноти додано");
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnRemoveBanknotes(Object^ sender, EventArgs^ e)
		{
			try
			{
				std::string name = SelectedName();
				int denomination = ReadInt(txtDenomination, "Номінал");
				int quantity = ReadInt(txtQuantity, "Кількість");
				catalog->RemoveBanknotes(name, denomination, quantity);
				RefreshGrid(catalog->GetAll());
				SelectByName(name);
				SetStatus(L"Банкноти вилучено");
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnSort(Object^ sender, EventArgs^ e)
		{
			try
			{
				catalog->SortByDollarRatio();
				RefreshGrid(catalog->GetAll());
				SetStatus(L"Відсортовано за відношенням до долара (метод підрахунку)");
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnReportCountries(Object^ sender, EventArgs^ e)
		{
			try
			{
				txtReport->Text = ToNet(catalog->BuildCountryReport());
				SetStatus(L"Сформовано список валют за країнами");
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnReportDollars(Object^ sender, EventArgs^ e)
		{
			try
			{
				txtReport->Text = ToNet(catalog->BuildDollarReport());
				SetStatus(L"Банкноти переведено в долари");
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnShowChart(Object^ sender, EventArgs^ e)
		{
			try
			{
				std::map<std::string, double> totals = catalog->TotalsInDollarsByCountry();
				cli::array<String^>^ names = gcnew cli::array<String^>(static_cast<int>(totals.size()));
				cli::array<double>^ values = gcnew cli::array<double>(static_cast<int>(totals.size()));
				int i = 0;
				for (const auto& item : totals)
				{
					names[i] = ToNet(item.first);
					values[i] = item.second;
					i++;
				}
				ChartForm^ chart = gcnew ChartForm(names, values);
				chart->ShowDialog(this);
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnOpenFile(Object^ sender, EventArgs^ e)
		{
			try
			{
				OpenFileDialog^ dialog = gcnew OpenFileDialog();
				dialog->Title = L"Відкрити файл з валютами";
				dialog->Filter = L"Текстові файли (*.txt)|*.txt|Усі файли (*.*)|*.*";
				if (dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK)
					return;
				catalog->LoadFromFile(ToStd(dialog->FileName));
				RefreshGrid(catalog->GetAll());
				txtReport->Clear();
				SetStatus(String::Format(L"Завантажено валют: {0}", catalog->Count()));
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnSaveFile(Object^ sender, EventArgs^ e)
		{
			try
			{
				if (catalog->Count() == 0)
					throw CurrencyException("Список валют порожній - нічого зберігати");
				SaveFileDialog^ dialog = gcnew SaveFileDialog();
				dialog->Title = L"Зберегти валюти у файл";
				dialog->Filter = L"Текстові файли (*.txt)|*.txt";
				dialog->DefaultExt = L"txt";
				if (dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK)
					return;
				catalog->SaveToFile(ToStd(dialog->FileName));
				SetStatus(String::Format(L"Збережено валют: {0}", catalog->Count()));
			}
			catch (CurrencyException& ex)
			{
				ShowError(ex);
			}
		}

		void OnClearAll(Object^ sender, EventArgs^ e)
		{
			if (MessageBox::Show(L"Видалити всі валюти зі списку?", L"Підтвердження",
				MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes)
				return;
			catalog->Clear();
			RefreshGrid(catalog->GetAll());
			txtReport->Clear();
			SetStatus(L"Список очищено");
		}

		void OnExit(Object^ sender, EventArgs^ e)
		{
			this->Close();
		}

		void OnFileFormat(Object^ sender, EventArgs^ e)
		{
			MessageBox::Show(
				L"Текстовий файл у кодуванні ANSI (Windows-1251). Один рядок - одна валюта:\n\n"
				L"назва;країна;курс;відношення;номінал:кількість номінал:кількість\n\n"
				L"Приклад:\nЄвро;Німеччина;1.08;1;5:10 20:5 100:3\n\n"
				L"- курс: скільки доларів коштує 1 одиниця валюти (крапка як роздільник);\n"
				L"- відношення: скільки одиниць валюти за 1 долар (ціле число);\n"
				L"- банкноти: пари номінал:кількість через пробіл (можуть бути відсутні).",
				L"Формат файлу даних", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		void OnAbout(Object^ sender, EventArgs^ e)
		{
			MessageBox::Show(
				L"Облік валют\nКурсова робота з дисципліни «Об'єктно-орієнтоване програмування»\n"
				L"C++/CLI, Windows Forms",
				L"Про програму", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	private: System::Void toolTip_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
	}
};
}