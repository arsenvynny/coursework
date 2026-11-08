#pragma once

#include "CurrencyRepository.h"
#include "CurrencySorter.h"
#include "CurrencyReportBuilder.h"
#include "CurrencyFileService.h"
#include "ValueParser.h"
#include "StringBridge.h"
#include "InvalidFormatException.h"
#include "InvalidValueException.h"
#include "NumberOverflowException.h"
#include "ItemNotFoundException.h"
#include "DuplicateItemException.h"
#include "NotEnoughBanknotesException.h"
#include "IndexRangeException.h"
#include "MemoryAllocationException.h"
#include "FileAccessException.h"

namespace coursework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CurrencyApp;

	/// <summary>
	/// Головне вікно програми «Облік валют» (Windows Forms, українською).
	/// Форма в C++/CLI має бути керованим класом (ref) — цього вимагає Windows Forms;
	/// уся модель даних (валюти, банкноти, файли, сортування) — звичайні класи C++ без STL.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			repository = new CurrencyRepository();
			shown = new DynamicArray<int>();
			ShowAll();
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
			this->!MyForm();
		}

		/// <summary>Звільнення власних (нативних) об'єктів.</summary>
		!MyForm()
		{
			delete shown;
			shown = nullptr;
			delete repository;
			repository = nullptr;
		}

	private:
		// ---------- Дані (власні класи, без STL) ----------
		CurrencyRepository* repository;   // усі валюти
		DynamicArray<int>* shown;         // індекси валют, показаних у таблиці (усі / пошук / фільтр)

		// ---------- Елементи керування (створюються в InitializeComponent) ----------
		System::Windows::Forms::TabControl^ tabs;
		System::Windows::Forms::TabPage^ tabCurrencies;
		System::Windows::Forms::TabPage^ tabReports;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colName;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCountry;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colRate;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDollar;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colNotes;
		System::Windows::Forms::DataGridView^ grid;
		System::Windows::Forms::GroupBox^ grpNotes;
		System::Windows::Forms::Label^ lblDenomination;
		System::Windows::Forms::TextBox^ txtDenomination;
		System::Windows::Forms::Label^ lblQuantity;
		System::Windows::Forms::TextBox^ txtQuantity;
		System::Windows::Forms::Button^ btnAddNotes;
		System::Windows::Forms::Button^ btnRemoveNotes;
		System::Windows::Forms::CheckBox^ chkDescending;
		System::Windows::Forms::Button^ btnSort;
		System::Windows::Forms::GroupBox^ grpSearch;
		System::Windows::Forms::Label^ lblSearch;
		System::Windows::Forms::TextBox^ txtSearch;
		System::Windows::Forms::Button^ btnSearch;
		System::Windows::Forms::Label^ lblFrom;
		System::Windows::Forms::TextBox^ txtFrom;
		System::Windows::Forms::Label^ lblTo;
		System::Windows::Forms::TextBox^ txtTo;
		System::Windows::Forms::Button^ btnFilter;
		System::Windows::Forms::Button^ btnShowAll;
		System::Windows::Forms::GroupBox^ grpInput;
		System::Windows::Forms::Label^ lblName;
		System::Windows::Forms::TextBox^ txtName;
		System::Windows::Forms::Label^ lblCountry;
		System::Windows::Forms::TextBox^ txtCountry;
		System::Windows::Forms::Label^ lblRate;
		System::Windows::Forms::TextBox^ txtRate;
		System::Windows::Forms::Label^ lblDollar;
		System::Windows::Forms::TextBox^ txtDollar;
		System::Windows::Forms::Label^ lblNotes;
		System::Windows::Forms::TextBox^ txtNotes;
		System::Windows::Forms::Button^ btnAddCurrency;
		System::Windows::Forms::TextBox^ txtReport;
		System::Windows::Forms::Panel^ panelReports;
		System::Windows::Forms::Button^ btnReportCountries;
		System::Windows::Forms::Button^ btnReportDollars;
		System::Windows::Forms::StatusStrip^ statusStrip;
		System::Windows::Forms::ToolStripStatusLabel^ statusLabel;
		System::Windows::Forms::ToolStrip^ toolStrip;
		System::Windows::Forms::ToolStripButton^ tbOpen;
		System::Windows::Forms::ToolStripButton^ tbSave;
		System::Windows::Forms::ToolStripSeparator^ tsSep1;
		System::Windows::Forms::ToolStripButton^ tbAddCurrency;
		System::Windows::Forms::ToolStripButton^ tbRemoveCurrency;
		System::Windows::Forms::ToolStripSeparator^ tsSep2;
		System::Windows::Forms::ToolStripButton^ tbSearch;
		System::Windows::Forms::ToolStripButton^ tbFilter;
		System::Windows::Forms::ToolStripButton^ tbShowAll;
		System::Windows::Forms::ToolStripSeparator^ tsSep3;
		System::Windows::Forms::ToolStripButton^ tbAddNotes;
		System::Windows::Forms::ToolStripButton^ tbRemoveNotes;
		System::Windows::Forms::ToolStripSeparator^ tsSep4;
		System::Windows::Forms::ToolStripButton^ tbSort;
		System::Windows::Forms::ToolStripButton^ tbReportCountries;
		System::Windows::Forms::ToolStripButton^ tbReportDollars;
		System::Windows::Forms::MenuStrip^ menuStrip;
		System::Windows::Forms::ToolStripMenuItem^ miFile;
		System::Windows::Forms::ToolStripMenuItem^ miNew;
		System::Windows::Forms::ToolStripMenuItem^ miOpen;
		System::Windows::Forms::ToolStripMenuItem^ miSave;
		System::Windows::Forms::ToolStripSeparator^ sepFile;
		System::Windows::Forms::ToolStripMenuItem^ miExit;
		System::Windows::Forms::ToolStripMenuItem^ miCurrencies;
		System::Windows::Forms::ToolStripMenuItem^ miAddCurrency;
		System::Windows::Forms::ToolStripMenuItem^ miRemoveCurrency;
		System::Windows::Forms::ToolStripSeparator^ sepCurrencies;
		System::Windows::Forms::ToolStripMenuItem^ miSearch;
		System::Windows::Forms::ToolStripMenuItem^ miFilter;
		System::Windows::Forms::ToolStripMenuItem^ miShowAll;
		System::Windows::Forms::ToolStripMenuItem^ miNotes;
		System::Windows::Forms::ToolStripMenuItem^ miAddNotes;
		System::Windows::Forms::ToolStripMenuItem^ miRemoveNotes;
		System::Windows::Forms::ToolStripMenuItem^ miReports;
		System::Windows::Forms::ToolStripMenuItem^ miSort;
		System::Windows::Forms::ToolStripMenuItem^ miReportCountries;
		System::Windows::Forms::ToolStripMenuItem^ miReportDollars;
		System::Windows::Forms::ToolStripMenuItem^ miHelp;
		System::Windows::Forms::ToolStripMenuItem^ miFileFormat;
		System::Windows::Forms::ToolStripMenuItem^ miAbout;
		System::Windows::Forms::ContextMenuStrip^ gridMenu;
		System::Windows::Forms::ToolStripMenuItem^ cmAddNotes;
		System::Windows::Forms::ToolStripMenuItem^ cmRemoveNotes;
		System::Windows::Forms::ToolStripSeparator^ cmSep;
		System::Windows::Forms::ToolStripMenuItem^ cmRemoveCurrency;
		System::Windows::Forms::ToolStripMenuItem^ cmShowAll;
		System::Windows::Forms::ToolTip^ toolTip;

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tabs = (gcnew System::Windows::Forms::TabControl());
			this->tabCurrencies = (gcnew System::Windows::Forms::TabPage());
			this->tabReports = (gcnew System::Windows::Forms::TabPage());
			this->colName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCountry = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colRate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDollar = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNotes = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grid = (gcnew System::Windows::Forms::DataGridView());
			this->grpNotes = (gcnew System::Windows::Forms::GroupBox());
			this->lblDenomination = (gcnew System::Windows::Forms::Label());
			this->txtDenomination = (gcnew System::Windows::Forms::TextBox());
			this->lblQuantity = (gcnew System::Windows::Forms::Label());
			this->txtQuantity = (gcnew System::Windows::Forms::TextBox());
			this->btnAddNotes = (gcnew System::Windows::Forms::Button());
			this->btnRemoveNotes = (gcnew System::Windows::Forms::Button());
			this->chkDescending = (gcnew System::Windows::Forms::CheckBox());
			this->btnSort = (gcnew System::Windows::Forms::Button());
			this->grpSearch = (gcnew System::Windows::Forms::GroupBox());
			this->lblSearch = (gcnew System::Windows::Forms::Label());
			this->txtSearch = (gcnew System::Windows::Forms::TextBox());
			this->btnSearch = (gcnew System::Windows::Forms::Button());
			this->lblFrom = (gcnew System::Windows::Forms::Label());
			this->txtFrom = (gcnew System::Windows::Forms::TextBox());
			this->lblTo = (gcnew System::Windows::Forms::Label());
			this->txtTo = (gcnew System::Windows::Forms::TextBox());
			this->btnFilter = (gcnew System::Windows::Forms::Button());
			this->btnShowAll = (gcnew System::Windows::Forms::Button());
			this->grpInput = (gcnew System::Windows::Forms::GroupBox());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblCountry = (gcnew System::Windows::Forms::Label());
			this->txtCountry = (gcnew System::Windows::Forms::TextBox());
			this->lblRate = (gcnew System::Windows::Forms::Label());
			this->txtRate = (gcnew System::Windows::Forms::TextBox());
			this->lblDollar = (gcnew System::Windows::Forms::Label());
			this->txtDollar = (gcnew System::Windows::Forms::TextBox());
			this->lblNotes = (gcnew System::Windows::Forms::Label());
			this->txtNotes = (gcnew System::Windows::Forms::TextBox());
			this->btnAddCurrency = (gcnew System::Windows::Forms::Button());
			this->txtReport = (gcnew System::Windows::Forms::TextBox());
			this->panelReports = (gcnew System::Windows::Forms::Panel());
			this->btnReportCountries = (gcnew System::Windows::Forms::Button());
			this->btnReportDollars = (gcnew System::Windows::Forms::Button());
			this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->statusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->tbOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsSep1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbAddCurrency = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbRemoveCurrency = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsSep2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbSearch = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbFilter = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbShowAll = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsSep3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbAddNotes = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbRemoveNotes = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsSep4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tbSort = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbReportCountries = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbReportDollars = (gcnew System::Windows::Forms::ToolStripButton());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->miFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miNew = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepFile = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->miExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miCurrencies = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAddCurrency = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miRemoveCurrency = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sepCurrencies = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->miSearch = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miFilter = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miShowAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAddNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miRemoveNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miReports = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miSort = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miReportCountries = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miReportDollars = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miFileFormat = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gridMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->cmAddNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cmRemoveNotes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cmSep = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->cmRemoveCurrency = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cmShowAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTip = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->BeginInit();
			this->menuStrip->SuspendLayout();
			this->toolStrip->SuspendLayout();
			this->statusStrip->SuspendLayout();
			this->gridMenu->SuspendLayout();
			this->tabs->SuspendLayout();
			this->tabCurrencies->SuspendLayout();
			this->tabReports->SuspendLayout();
			this->grpInput->SuspendLayout();
			this->grpSearch->SuspendLayout();
			this->grpNotes->SuspendLayout();
			this->panelReports->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabs
			// 
			this->tabs->Controls->Add(this->tabCurrencies);
			this->tabs->Controls->Add(this->tabReports);
			this->tabs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabs->Location = System::Drawing::Point(0, 52);
			this->tabs->Name = L"tabs";
			this->tabs->SelectedIndex = 0;
			this->tabs->Size = System::Drawing::Size(1100, 600);
			this->tabs->TabIndex = 0;
			// 
			// tabCurrencies
			// 
			this->tabCurrencies->Controls->Add(this->grid);
			this->tabCurrencies->Controls->Add(this->grpNotes);
			this->tabCurrencies->Controls->Add(this->grpSearch);
			this->tabCurrencies->Controls->Add(this->grpInput);
			this->tabCurrencies->Location = System::Drawing::Point(4, 25);
			this->tabCurrencies->Name = L"tabCurrencies";
			this->tabCurrencies->Padding = System::Windows::Forms::Padding(3);
			this->tabCurrencies->Size = System::Drawing::Size(1092, 571);
			this->tabCurrencies->Text = L"Валюти";
			this->tabCurrencies->UseVisualStyleBackColor = true;
			// 
			// tabReports
			// 
			this->tabReports->Controls->Add(this->txtReport);
			this->tabReports->Controls->Add(this->panelReports);
			this->tabReports->Location = System::Drawing::Point(4, 25);
			this->tabReports->Name = L"tabReports";
			this->tabReports->Padding = System::Windows::Forms::Padding(3);
			this->tabReports->Size = System::Drawing::Size(1092, 571);
			this->tabReports->Text = L"Звіти";
			this->tabReports->UseVisualStyleBackColor = true;
			// 
			// colName
			// 
			this->colName->HeaderText = L"Назва";
			this->colName->Name = L"colName";
			// 
			// colCountry
			// 
			this->colCountry->HeaderText = L"Країна";
			this->colCountry->Name = L"colCountry";
			// 
			// colRate
			// 
			this->colRate->HeaderText = L"Курс";
			this->colRate->Name = L"colRate";
			// 
			// colDollar
			// 
			this->colDollar->HeaderText = L"Відношення до долара";
			this->colDollar->Name = L"colDollar";
			// 
			// colNotes
			// 
			this->colNotes->HeaderText = L"Наявні банкноти";
			this->colNotes->Name = L"colNotes";
			this->colNotes->FillWeight = 220;
			// 
			// grid
			// 
			this->grid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) { this->colName, this->colCountry, this->colRate, this->colDollar, this->colNotes });
			this->grid->AllowUserToAddRows = false;
			this->grid->AllowUserToDeleteRows = false;
			this->grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->grid->ContextMenuStrip = this->gridMenu;
			this->grid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grid->Location = System::Drawing::Point(3, 3);
			this->grid->MultiSelect = false;
			this->grid->Name = L"grid";
			this->grid->ReadOnly = true;
			this->grid->RowHeadersVisible = false;
			this->grid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->grid->Size = System::Drawing::Size(1086, 565);
			this->grid->TabIndex = 0;
			this->toolTip->SetToolTip(this->grid, L"Таблиця валют. Права кнопка миші — контекстне меню.");
			this->grid->CellMouseDown += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MyForm::OnGridCellMouseDown);
			// 
			// grpNotes
			// 
			this->grpNotes->Controls->Add(this->lblDenomination);
			this->grpNotes->Controls->Add(this->txtDenomination);
			this->grpNotes->Controls->Add(this->lblQuantity);
			this->grpNotes->Controls->Add(this->txtQuantity);
			this->grpNotes->Controls->Add(this->btnAddNotes);
			this->grpNotes->Controls->Add(this->btnRemoveNotes);
			this->grpNotes->Controls->Add(this->chkDescending);
			this->grpNotes->Controls->Add(this->btnSort);
			this->grpNotes->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->grpNotes->Location = System::Drawing::Point(3, 493);
			this->grpNotes->Name = L"grpNotes";
			this->grpNotes->Size = System::Drawing::Size(1086, 75);
			this->grpNotes->TabStop = false;
			this->grpNotes->Text = L"Банкноти вибраної валюти та сортування";
			this->grpNotes->TabIndex = 1;
			// 
			// lblDenomination
			// 
			this->lblDenomination->AutoSize = true;
			this->lblDenomination->Location = System::Drawing::Point(10, 33);
			this->lblDenomination->Name = L"lblDenomination";
			this->lblDenomination->Size = System::Drawing::Size(60, 16);
			this->lblDenomination->Text = L"Номінал:";
			this->lblDenomination->TabIndex = 0;
			// 
			// txtDenomination
			// 
			this->txtDenomination->Location = System::Drawing::Point(75, 30);
			this->txtDenomination->Name = L"txtDenomination";
			this->txtDenomination->Size = System::Drawing::Size(80, 22);
			this->txtDenomination->TabIndex = 1;
			this->toolTip->SetToolTip(this->txtDenomination, L"Номінал банкноти (ціле число > 0)");
			// 
			// lblQuantity
			// 
			this->lblQuantity->AutoSize = true;
			this->lblQuantity->Location = System::Drawing::Point(170, 33);
			this->lblQuantity->Name = L"lblQuantity";
			this->lblQuantity->Size = System::Drawing::Size(60, 16);
			this->lblQuantity->Text = L"Кількість:";
			this->lblQuantity->TabIndex = 2;
			// 
			// txtQuantity
			// 
			this->txtQuantity->Location = System::Drawing::Point(240, 30);
			this->txtQuantity->Name = L"txtQuantity";
			this->txtQuantity->Size = System::Drawing::Size(80, 22);
			this->txtQuantity->TabIndex = 3;
			this->toolTip->SetToolTip(this->txtQuantity, L"Кількість банкнот (ціле число > 0)");
			// 
			// btnAddNotes
			// 
			this->btnAddNotes->Location = System::Drawing::Point(335, 28);
			this->btnAddNotes->Name = L"btnAddNotes";
			this->btnAddNotes->Size = System::Drawing::Size(150, 28);
			this->btnAddNotes->Text = L"Додати банкноти";
			this->btnAddNotes->UseVisualStyleBackColor = true;
			this->btnAddNotes->TabIndex = 4;
			this->toolTip->SetToolTip(this->btnAddNotes, L"Додати банкноти вибраній валюті");
			this->btnAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddNotes);
			// 
			// btnRemoveNotes
			// 
			this->btnRemoveNotes->Location = System::Drawing::Point(495, 28);
			this->btnRemoveNotes->Name = L"btnRemoveNotes";
			this->btnRemoveNotes->Size = System::Drawing::Size(165, 28);
			this->btnRemoveNotes->Text = L"Вилучити банкноти";
			this->btnRemoveNotes->UseVisualStyleBackColor = true;
			this->btnRemoveNotes->TabIndex = 5;
			this->toolTip->SetToolTip(this->btnRemoveNotes, L"Вилучити банкноти у вибраної валюти");
			this->btnRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveNotes);
			// 
			// chkDescending
			// 
			this->chkDescending->AutoSize = true;
			this->chkDescending->Location = System::Drawing::Point(675, 33);
			this->chkDescending->Name = L"chkDescending";
			this->chkDescending->Size = System::Drawing::Size(111, 20);
			this->chkDescending->Text = L"За спаданням";
			this->chkDescending->UseVisualStyleBackColor = true;
			this->chkDescending->TabIndex = 6;
			this->toolTip->SetToolTip(this->chkDescending, L"Сортувати від більшого відношення до долара до меншого");
			// 
			// btnSort
			// 
			this->btnSort->Location = System::Drawing::Point(790, 28);
			this->btnSort->Name = L"btnSort";
			this->btnSort->Size = System::Drawing::Size(260, 28);
			this->btnSort->Text = L"Сортувати за відношенням до $";
			this->btnSort->UseVisualStyleBackColor = true;
			this->btnSort->TabIndex = 7;
			this->toolTip->SetToolTip(this->btnSort, L"Сортування підрахунком за відношенням до долара");
			this->btnSort->Click += gcnew System::EventHandler(this, &MyForm::OnSortByDollar);
			// 
			// grpSearch
			// 
			this->grpSearch->Controls->Add(this->lblSearch);
			this->grpSearch->Controls->Add(this->txtSearch);
			this->grpSearch->Controls->Add(this->btnSearch);
			this->grpSearch->Controls->Add(this->lblFrom);
			this->grpSearch->Controls->Add(this->txtFrom);
			this->grpSearch->Controls->Add(this->lblTo);
			this->grpSearch->Controls->Add(this->txtTo);
			this->grpSearch->Controls->Add(this->btnFilter);
			this->grpSearch->Controls->Add(this->btnShowAll);
			this->grpSearch->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpSearch->Location = System::Drawing::Point(3, 108);
			this->grpSearch->Name = L"grpSearch";
			this->grpSearch->Size = System::Drawing::Size(1086, 70);
			this->grpSearch->TabStop = false;
			this->grpSearch->Text = L"Пошук за назвою та фільтр за курсом";
			this->grpSearch->TabIndex = 2;
			// 
			// lblSearch
			// 
			this->lblSearch->AutoSize = true;
			this->lblSearch->Location = System::Drawing::Point(10, 31);
			this->lblSearch->Name = L"lblSearch";
			this->lblSearch->Size = System::Drawing::Size(60, 16);
			this->lblSearch->Text = L"Назва:";
			this->lblSearch->TabIndex = 0;
			// 
			// txtSearch
			// 
			this->txtSearch->Location = System::Drawing::Point(60, 28);
			this->txtSearch->Name = L"txtSearch";
			this->txtSearch->Size = System::Drawing::Size(150, 22);
			this->txtSearch->TabIndex = 1;
			this->toolTip->SetToolTip(this->txtSearch, L"Назва або її частина (регістр не враховується)");
			// 
			// btnSearch
			// 
			this->btnSearch->Location = System::Drawing::Point(220, 26);
			this->btnSearch->Name = L"btnSearch";
			this->btnSearch->Size = System::Drawing::Size(80, 28);
			this->btnSearch->Text = L"Знайти";
			this->btnSearch->UseVisualStyleBackColor = true;
			this->btnSearch->TabIndex = 2;
			this->toolTip->SetToolTip(this->btnSearch, L"Знайти валюти за назвою");
			this->btnSearch->Click += gcnew System::EventHandler(this, &MyForm::OnSearch);
			// 
			// lblFrom
			// 
			this->lblFrom->AutoSize = true;
			this->lblFrom->Location = System::Drawing::Point(330, 31);
			this->lblFrom->Name = L"lblFrom";
			this->lblFrom->Size = System::Drawing::Size(60, 16);
			this->lblFrom->Text = L"Курс від:";
			this->lblFrom->TabIndex = 3;
			// 
			// txtFrom
			// 
			this->txtFrom->Location = System::Drawing::Point(395, 28);
			this->txtFrom->Name = L"txtFrom";
			this->txtFrom->Size = System::Drawing::Size(70, 22);
			this->txtFrom->TabIndex = 4;
			this->toolTip->SetToolTip(this->txtFrom, L"Нижня межа курсу (x)");
			// 
			// lblTo
			// 
			this->lblTo->AutoSize = true;
			this->lblTo->Location = System::Drawing::Point(475, 31);
			this->lblTo->Name = L"lblTo";
			this->lblTo->Size = System::Drawing::Size(60, 16);
			this->lblTo->Text = L"до:";
			this->lblTo->TabIndex = 5;
			// 
			// txtTo
			// 
			this->txtTo->Location = System::Drawing::Point(505, 28);
			this->txtTo->Name = L"txtTo";
			this->txtTo->Size = System::Drawing::Size(70, 22);
			this->txtTo->TabIndex = 6;
			this->toolTip->SetToolTip(this->txtTo, L"Верхня межа курсу (y)");
			// 
			// btnFilter
			// 
			this->btnFilter->Location = System::Drawing::Point(585, 26);
			this->btnFilter->Name = L"btnFilter";
			this->btnFilter->Size = System::Drawing::Size(80, 28);
			this->btnFilter->Text = L"Фільтр";
			this->btnFilter->UseVisualStyleBackColor = true;
			this->btnFilter->TabIndex = 7;
			this->toolTip->SetToolTip(this->btnFilter, L"Показати валюти з курсом від x до y");
			this->btnFilter->Click += gcnew System::EventHandler(this, &MyForm::OnFilterByRate);
			// 
			// btnShowAll
			// 
			this->btnShowAll->Location = System::Drawing::Point(675, 26);
			this->btnShowAll->Name = L"btnShowAll";
			this->btnShowAll->Size = System::Drawing::Size(120, 28);
			this->btnShowAll->Text = L"Показати всі";
			this->btnShowAll->UseVisualStyleBackColor = true;
			this->btnShowAll->TabIndex = 8;
			this->toolTip->SetToolTip(this->btnShowAll, L"Скасувати пошук або фільтр");
			this->btnShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// grpInput
			// 
			this->grpInput->Controls->Add(this->lblName);
			this->grpInput->Controls->Add(this->txtName);
			this->grpInput->Controls->Add(this->lblCountry);
			this->grpInput->Controls->Add(this->txtCountry);
			this->grpInput->Controls->Add(this->lblRate);
			this->grpInput->Controls->Add(this->txtRate);
			this->grpInput->Controls->Add(this->lblDollar);
			this->grpInput->Controls->Add(this->txtDollar);
			this->grpInput->Controls->Add(this->lblNotes);
			this->grpInput->Controls->Add(this->txtNotes);
			this->grpInput->Controls->Add(this->btnAddCurrency);
			this->grpInput->Dock = System::Windows::Forms::DockStyle::Top;
			this->grpInput->Location = System::Drawing::Point(3, 3);
			this->grpInput->Name = L"grpInput";
			this->grpInput->Size = System::Drawing::Size(1086, 105);
			this->grpInput->TabStop = false;
			this->grpInput->Text = L"Нова валюта (введення з клавіатури)";
			this->grpInput->TabIndex = 3;
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(10, 31);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(60, 16);
			this->lblName->Text = L"Назва:";
			this->lblName->TabIndex = 0;
			// 
			// txtName
			// 
			this->txtName->Location = System::Drawing::Point(60, 28);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(150, 22);
			this->txtName->TabIndex = 1;
			this->toolTip->SetToolTip(this->txtName, L"Назва валюти, наприклад: Євро");
			// 
			// lblCountry
			// 
			this->lblCountry->AutoSize = true;
			this->lblCountry->Location = System::Drawing::Point(225, 31);
			this->lblCountry->Name = L"lblCountry";
			this->lblCountry->Size = System::Drawing::Size(60, 16);
			this->lblCountry->Text = L"Країна:";
			this->lblCountry->TabIndex = 2;
			// 
			// txtCountry
			// 
			this->txtCountry->Location = System::Drawing::Point(280, 28);
			this->txtCountry->Name = L"txtCountry";
			this->txtCountry->Size = System::Drawing::Size(150, 22);
			this->txtCountry->TabIndex = 3;
			this->toolTip->SetToolTip(this->txtCountry, L"Країна, наприклад: Польща");
			// 
			// lblRate
			// 
			this->lblRate->AutoSize = true;
			this->lblRate->Location = System::Drawing::Point(445, 31);
			this->lblRate->Name = L"lblRate";
			this->lblRate->Size = System::Drawing::Size(60, 16);
			this->lblRate->Text = L"Курс:";
			this->lblRate->TabIndex = 4;
			// 
			// txtRate
			// 
			this->txtRate->Location = System::Drawing::Point(490, 28);
			this->txtRate->Name = L"txtRate";
			this->txtRate->Size = System::Drawing::Size(80, 22);
			this->txtRate->TabIndex = 5;
			this->toolTip->SetToolTip(this->txtRate, L"Вартість 1 одиниці в національній валюті країни");
			// 
			// lblDollar
			// 
			this->lblDollar->AutoSize = true;
			this->lblDollar->Location = System::Drawing::Point(585, 31);
			this->lblDollar->Name = L"lblDollar";
			this->lblDollar->Size = System::Drawing::Size(60, 16);
			this->lblDollar->Text = L"Відношення до $:";
			this->lblDollar->TabIndex = 6;
			// 
			// txtDollar
			// 
			this->txtDollar->Location = System::Drawing::Point(700, 28);
			this->txtDollar->Name = L"txtDollar";
			this->txtDollar->Size = System::Drawing::Size(80, 22);
			this->txtDollar->TabIndex = 7;
			this->toolTip->SetToolTip(this->txtDollar, L"Скільки доларів США за 1 одиницю цієї валюти");
			// 
			// lblNotes
			// 
			this->lblNotes->AutoSize = true;
			this->lblNotes->Location = System::Drawing::Point(10, 66);
			this->lblNotes->Name = L"lblNotes";
			this->lblNotes->Size = System::Drawing::Size(60, 16);
			this->lblNotes->Text = L"Банкноти (номінал:кількість;…):";
			this->lblNotes->TabIndex = 8;
			// 
			// txtNotes
			// 
			this->txtNotes->Location = System::Drawing::Point(215, 63);
			this->txtNotes->Name = L"txtNotes";
			this->txtNotes->Size = System::Drawing::Size(365, 22);
			this->txtNotes->TabIndex = 9;
			this->toolTip->SetToolTip(this->txtNotes, L"Необов'язково. Приклад: 5:10;20:3;100:7");
			// 
			// btnAddCurrency
			// 
			this->btnAddCurrency->Location = System::Drawing::Point(600, 60);
			this->btnAddCurrency->Name = L"btnAddCurrency";
			this->btnAddCurrency->Size = System::Drawing::Size(140, 28);
			this->btnAddCurrency->Text = L"Додати валюту";
			this->btnAddCurrency->UseVisualStyleBackColor = true;
			this->btnAddCurrency->TabIndex = 10;
			this->toolTip->SetToolTip(this->btnAddCurrency, L"Додати валюту з полів введення");
			this->btnAddCurrency->Click += gcnew System::EventHandler(this, &MyForm::OnAddCurrency);
			// 
			// txtReport
			// 
			this->txtReport->BackColor = System::Drawing::SystemColors::Window;
			this->txtReport->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtReport->Font = (gcnew System::Drawing::Font(L"Consolas", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->txtReport->Location = System::Drawing::Point(3, 48);
			this->txtReport->Multiline = true;
			this->txtReport->Name = L"txtReport";
			this->txtReport->ReadOnly = true;
			this->txtReport->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->txtReport->Size = System::Drawing::Size(1086, 520);
			this->txtReport->WordWrap = false;
			this->txtReport->TabIndex = 0;
			// 
			// panelReports
			// 
			this->panelReports->Controls->Add(this->btnReportCountries);
			this->panelReports->Controls->Add(this->btnReportDollars);
			this->panelReports->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelReports->Location = System::Drawing::Point(3, 3);
			this->panelReports->Name = L"panelReports";
			this->panelReports->Size = System::Drawing::Size(1086, 45);
			this->panelReports->TabIndex = 1;
			// 
			// btnReportCountries
			// 
			this->btnReportCountries->Location = System::Drawing::Point(10, 8);
			this->btnReportCountries->Name = L"btnReportCountries";
			this->btnReportCountries->Size = System::Drawing::Size(230, 28);
			this->btnReportCountries->Text = L"Валюти за країнами (А–Я)";
			this->btnReportCountries->UseVisualStyleBackColor = true;
			this->btnReportCountries->TabIndex = 0;
			this->toolTip->SetToolTip(this->btnReportCountries, L"Країни за алфавітом; для кожної — валюти та наявні банкноти");
			this->btnReportCountries->Click += gcnew System::EventHandler(this, &MyForm::OnReportCountries);
			// 
			// btnReportDollars
			// 
			this->btnReportDollars->Location = System::Drawing::Point(250, 8);
			this->btnReportDollars->Name = L"btnReportDollars";
			this->btnReportDollars->Size = System::Drawing::Size(300, 28);
			this->btnReportDollars->Text = L"Суми банкнот у доларах за країнами";
			this->btnReportDollars->UseVisualStyleBackColor = true;
			this->btnReportDollars->TabIndex = 1;
			this->toolTip->SetToolTip(this->btnReportDollars, L"Переведення банкнот у долари та загальна сума для кожної країни");
			this->btnReportDollars->Click += gcnew System::EventHandler(this, &MyForm::OnReportDollars);
			// 
			// statusStrip
			// 
			this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusLabel });
			this->statusStrip->Location = System::Drawing::Point(0, 678);
			this->statusStrip->Name = L"statusStrip";
			this->statusStrip->Size = System::Drawing::Size(1100, 22);
			this->statusStrip->TabIndex = 1;
			this->statusStrip->Text = L"statusStrip";
			// 
			// statusLabel
			// 
			this->statusLabel->Name = L"statusLabel";
			this->statusLabel->Text = L"Готово";
			// 
			// toolStrip
			// 
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(16) { this->tbOpen, this->tbSave, this->tsSep1, this->tbAddCurrency, this->tbRemoveCurrency, this->tsSep2, this->tbSearch, this->tbFilter, this->tbShowAll, this->tsSep3, this->tbAddNotes, this->tbRemoveNotes, this->tsSep4, this->tbSort, this->tbReportCountries, this->tbReportDollars });
			this->toolStrip->Location = System::Drawing::Point(0, 24);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->ShowItemToolTips = true;
			this->toolStrip->Size = System::Drawing::Size(1100, 25);
			this->toolStrip->TabIndex = 2;
			this->toolStrip->Text = L"toolStrip";
			// 
			// tbOpen
			// 
			this->tbOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbOpen->Name = L"tbOpen";
			this->tbOpen->Text = L"Відкрити";
			this->tbOpen->ToolTipText = L"Завантажити валюти з файлу (Ctrl+O)";
			this->tbOpen->Click += gcnew System::EventHandler(this, &MyForm::OnOpenFile);
			// 
			// tbSave
			// 
			this->tbSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbSave->Name = L"tbSave";
			this->tbSave->Text = L"Зберегти";
			this->tbSave->ToolTipText = L"Зберегти валюти у файл (Ctrl+S)";
			this->tbSave->Click += gcnew System::EventHandler(this, &MyForm::OnSaveFile);
			// 
			// tsSep1
			// 
			this->tsSep1->Name = L"tsSep1";
			// 
			// tbAddCurrency
			// 
			this->tbAddCurrency->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbAddCurrency->Name = L"tbAddCurrency";
			this->tbAddCurrency->Text = L"Додати валюту";
			this->tbAddCurrency->ToolTipText = L"Додати валюту з полів введення (Ctrl+D)";
			this->tbAddCurrency->Click += gcnew System::EventHandler(this, &MyForm::OnAddCurrency);
			// 
			// tbRemoveCurrency
			// 
			this->tbRemoveCurrency->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbRemoveCurrency->Name = L"tbRemoveCurrency";
			this->tbRemoveCurrency->Text = L"Видалити";
			this->tbRemoveCurrency->ToolTipText = L"Видалити вибрану валюту (Ctrl+Del)";
			this->tbRemoveCurrency->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveCurrency);
			// 
			// tsSep2
			// 
			this->tsSep2->Name = L"tsSep2";
			// 
			// tbSearch
			// 
			this->tbSearch->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbSearch->Name = L"tbSearch";
			this->tbSearch->Text = L"Знайти";
			this->tbSearch->ToolTipText = L"Пошук за назвою (Ctrl+F)";
			this->tbSearch->Click += gcnew System::EventHandler(this, &MyForm::OnSearch);
			// 
			// tbFilter
			// 
			this->tbFilter->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbFilter->Name = L"tbFilter";
			this->tbFilter->Text = L"Фільтр за курсом";
			this->tbFilter->ToolTipText = L"Валюти з курсом від x до y (Ctrl+R)";
			this->tbFilter->Click += gcnew System::EventHandler(this, &MyForm::OnFilterByRate);
			// 
			// tbShowAll
			// 
			this->tbShowAll->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbShowAll->Name = L"tbShowAll";
			this->tbShowAll->Text = L"Усі";
			this->tbShowAll->ToolTipText = L"Показати всі валюти (F5)";
			this->tbShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// tsSep3
			// 
			this->tsSep3->Name = L"tsSep3";
			// 
			// tbAddNotes
			// 
			this->tbAddNotes->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbAddNotes->Name = L"tbAddNotes";
			this->tbAddNotes->Text = L"+ Банкноти";
			this->tbAddNotes->ToolTipText = L"Додати банкноти (Ctrl+B)";
			this->tbAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddNotes);
			// 
			// tbRemoveNotes
			// 
			this->tbRemoveNotes->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbRemoveNotes->Name = L"tbRemoveNotes";
			this->tbRemoveNotes->Text = L"– Банкноти";
			this->tbRemoveNotes->ToolTipText = L"Вилучити банкноти (Ctrl+Shift+B)";
			this->tbRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveNotes);
			// 
			// tsSep4
			// 
			this->tsSep4->Name = L"tsSep4";
			// 
			// tbSort
			// 
			this->tbSort->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbSort->Name = L"tbSort";
			this->tbSort->Text = L"Сортувати";
			this->tbSort->ToolTipText = L"Сортування підрахунком за відношенням до долара (F6)";
			this->tbSort->Click += gcnew System::EventHandler(this, &MyForm::OnSortByDollar);
			// 
			// tbReportCountries
			// 
			this->tbReportCountries->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbReportCountries->Name = L"tbReportCountries";
			this->tbReportCountries->Text = L"За країнами";
			this->tbReportCountries->ToolTipText = L"Валюти та банкноти за країнами (F7)";
			this->tbReportCountries->Click += gcnew System::EventHandler(this, &MyForm::OnReportCountries);
			// 
			// tbReportDollars
			// 
			this->tbReportDollars->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->tbReportDollars->Name = L"tbReportDollars";
			this->tbReportDollars->Text = L"Суми в $";
			this->tbReportDollars->ToolTipText = L"Суми банкнот у доларах за країнами (F8)";
			this->tbReportDollars->Click += gcnew System::EventHandler(this, &MyForm::OnReportDollars);
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) { this->miFile, this->miCurrencies, this->miNotes, this->miReports, this->miHelp });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->ShowItemToolTips = true;
			this->menuStrip->Size = System::Drawing::Size(1100, 24);
			this->menuStrip->TabIndex = 3;
			this->menuStrip->Text = L"menuStrip";
			// 
			// miFile
			// 
			this->miFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) { this->miNew, this->miOpen, this->miSave, this->sepFile, this->miExit });
			this->miFile->Name = L"miFile";
			this->miFile->Text = L"&Файл";
			// 
			// miNew
			// 
			this->miNew->Name = L"miNew";
			this->miNew->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->miNew->Text = L"&Новий (очистити дані)";
			this->miNew->ToolTipText = L"Видалити всі валюти з пам'яті програми";
			this->miNew->Click += gcnew System::EventHandler(this, &MyForm::OnNewData);
			// 
			// miOpen
			// 
			this->miOpen->Name = L"miOpen";
			this->miOpen->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->miOpen->Text = L"&Відкрити з файлу...";
			this->miOpen->ToolTipText = L"Режим введення №2: завантажити валюти з текстового файлу";
			this->miOpen->Click += gcnew System::EventHandler(this, &MyForm::OnOpenFile);
			// 
			// miSave
			// 
			this->miSave->Name = L"miSave";
			this->miSave->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->miSave->Text = L"&Зберегти у файл...";
			this->miSave->ToolTipText = L"Записати всі валюти у текстовий файл";
			this->miSave->Click += gcnew System::EventHandler(this, &MyForm::OnSaveFile);
			// 
			// sepFile
			// 
			this->sepFile->Name = L"sepFile";
			// 
			// miExit
			// 
			this->miExit->Name = L"miExit";
			this->miExit->Text = L"В&ихід";
			this->miExit->ToolTipText = L"Закрити програму";
			this->miExit->Click += gcnew System::EventHandler(this, &MyForm::OnExit);
			// 
			// miCurrencies
			// 
			this->miCurrencies->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) { this->miAddCurrency, this->miRemoveCurrency, this->sepCurrencies, this->miSearch, this->miFilter, this->miShowAll });
			this->miCurrencies->Name = L"miCurrencies";
			this->miCurrencies->Text = L"&Валюти";
			// 
			// miAddCurrency
			// 
			this->miAddCurrency->Name = L"miAddCurrency";
			this->miAddCurrency->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D));
			this->miAddCurrency->Text = L"&Додати з полів введення";
			this->miAddCurrency->ToolTipText = L"Режим введення №1: додати валюту з клавіатури";
			this->miAddCurrency->Click += gcnew System::EventHandler(this, &MyForm::OnAddCurrency);
			// 
			// miRemoveCurrency
			// 
			this->miRemoveCurrency->Name = L"miRemoveCurrency";
			this->miRemoveCurrency->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Delete));
			this->miRemoveCurrency->Text = L"Ви&далити вибрану";
			this->miRemoveCurrency->ToolTipText = L"Видалити вибрану в таблиці валюту";
			this->miRemoveCurrency->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveCurrency);
			// 
			// sepCurrencies
			// 
			this->sepCurrencies->Name = L"sepCurrencies";
			// 
			// miSearch
			// 
			this->miSearch->Name = L"miSearch";
			this->miSearch->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->miSearch->Text = L"&Знайти за назвою";
			this->miSearch->ToolTipText = L"Пошук валюти за назвою (повною або частковою)";
			this->miSearch->Click += gcnew System::EventHandler(this, &MyForm::OnSearch);
			// 
			// miFilter
			// 
			this->miFilter->Name = L"miFilter";
			this->miFilter->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->miFilter->Text = L"Фільтр за &курсом";
			this->miFilter->ToolTipText = L"Показати валюти з курсом від x до y";
			this->miFilter->Click += gcnew System::EventHandler(this, &MyForm::OnFilterByRate);
			// 
			// miShowAll
			// 
			this->miShowAll->Name = L"miShowAll";
			this->miShowAll->ShortcutKeys = System::Windows::Forms::Keys::F5;
			this->miShowAll->Text = L"Показати &всі";
			this->miShowAll->ToolTipText = L"Скасувати пошук або фільтр";
			this->miShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// miNotes
			// 
			this->miNotes->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->miAddNotes, this->miRemoveNotes });
			this->miNotes->Name = L"miNotes";
			this->miNotes->Text = L"&Банкноти";
			// 
			// miAddNotes
			// 
			this->miAddNotes->Name = L"miAddNotes";
			this->miAddNotes->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
			this->miAddNotes->Text = L"&Додати банкноти";
			this->miAddNotes->ToolTipText = L"Додати банкноти вибраній валюті";
			this->miAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddNotes);
			// 
			// miRemoveNotes
			// 
			this->miRemoveNotes->Name = L"miRemoveNotes";
			this->miRemoveNotes->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift | System::Windows::Forms::Keys::B));
			this->miRemoveNotes->Text = L"&Вилучити банкноти";
			this->miRemoveNotes->ToolTipText = L"Вилучити банкноти у вибраної валюти";
			this->miRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveNotes);
			// 
			// miReports
			// 
			this->miReports->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) { this->miSort, this->miReportCountries, this->miReportDollars });
			this->miReports->Name = L"miReports";
			this->miReports->Text = L"&Звіти";
			// 
			// miSort
			// 
			this->miSort->Name = L"miSort";
			this->miSort->ShortcutKeys = System::Windows::Forms::Keys::F6;
			this->miSort->Text = L"&Сортування за відношенням до $";
			this->miSort->ToolTipText = L"Сортування підрахунком за відношенням до долара";
			this->miSort->Click += gcnew System::EventHandler(this, &MyForm::OnSortByDollar);
			// 
			// miReportCountries
			// 
			this->miReportCountries->Name = L"miReportCountries";
			this->miReportCountries->ShortcutKeys = System::Windows::Forms::Keys::F7;
			this->miReportCountries->Text = L"Валюти за &країнами";
			this->miReportCountries->ToolTipText = L"Країни за алфавітом; для кожної — валюти та банкноти";
			this->miReportCountries->Click += gcnew System::EventHandler(this, &MyForm::OnReportCountries);
			// 
			// miReportDollars
			// 
			this->miReportDollars->Name = L"miReportDollars";
			this->miReportDollars->ShortcutKeys = System::Windows::Forms::Keys::F8;
			this->miReportDollars->Text = L"Суми в &доларах за країнами";
			this->miReportDollars->ToolTipText = L"Переведення банкнот у долари та загальна сума по країні";
			this->miReportDollars->Click += gcnew System::EventHandler(this, &MyForm::OnReportDollars);
			// 
			// miHelp
			// 
			this->miHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->miFileFormat, this->miAbout });
			this->miHelp->Name = L"miHelp";
			this->miHelp->Text = L"&Довідка";
			// 
			// miFileFormat
			// 
			this->miFileFormat->Name = L"miFileFormat";
			this->miFileFormat->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->miFileFormat->Text = L"&Формат файлу даних";
			this->miFileFormat->ToolTipText = L"Опис структури вхідного файлу";
			this->miFileFormat->Click += gcnew System::EventHandler(this, &MyForm::OnFileFormatHelp);
			// 
			// miAbout
			// 
			this->miAbout->Name = L"miAbout";
			this->miAbout->Text = L"&Про програму";
			this->miAbout->ToolTipText = L"Відомості про програму";
			this->miAbout->Click += gcnew System::EventHandler(this, &MyForm::OnAbout);
			// 
			// gridMenu
			// 
			this->gridMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) { this->cmAddNotes, this->cmRemoveNotes, this->cmSep, this->cmRemoveCurrency, this->cmShowAll });
			this->gridMenu->Name = L"gridMenu";
			this->gridMenu->Size = System::Drawing::Size(200, 98);
			// 
			// cmAddNotes
			// 
			this->cmAddNotes->Name = L"cmAddNotes";
			this->cmAddNotes->Text = L"Додати банкноти";
			this->cmAddNotes->ToolTipText = L"Додати банкноти вибраній валюті";
			this->cmAddNotes->Click += gcnew System::EventHandler(this, &MyForm::OnAddNotes);
			// 
			// cmRemoveNotes
			// 
			this->cmRemoveNotes->Name = L"cmRemoveNotes";
			this->cmRemoveNotes->Text = L"Вилучити банкноти";
			this->cmRemoveNotes->ToolTipText = L"Вилучити банкноти у вибраної валюти";
			this->cmRemoveNotes->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveNotes);
			// 
			// cmSep
			// 
			this->cmSep->Name = L"cmSep";
			// 
			// cmRemoveCurrency
			// 
			this->cmRemoveCurrency->Name = L"cmRemoveCurrency";
			this->cmRemoveCurrency->Text = L"Видалити валюту";
			this->cmRemoveCurrency->ToolTipText = L"Видалити вибрану валюту";
			this->cmRemoveCurrency->Click += gcnew System::EventHandler(this, &MyForm::OnRemoveCurrency);
			// 
			// cmShowAll
			// 
			this->cmShowAll->Name = L"cmShowAll";
			this->cmShowAll->Text = L"Показати всі валюти";
			this->cmShowAll->ToolTipText = L"Скасувати пошук або фільтр";
			this->cmShowAll->Click += gcnew System::EventHandler(this, &MyForm::OnShowAll);
			// 
			// toolTip
			// 
			this->toolTip->AutoPopDelay = 9000;
			this->toolTip->InitialDelay = 400;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->ClientSize = System::Drawing::Size(1100, 700);
			this->Controls->Add(this->tabs);
			this->Controls->Add(this->statusStrip);
			this->Controls->Add(this->toolStrip);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->MinimumSize = System::Drawing::Size(1000, 600);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Облік валют";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->statusStrip->ResumeLayout(false);
			this->statusStrip->PerformLayout();
			this->gridMenu->ResumeLayout(false);
			this->gridMenu->PerformLayout();
			this->tabs->ResumeLayout(false);
			this->tabs->PerformLayout();
			this->tabCurrencies->ResumeLayout(false);
			this->tabCurrencies->PerformLayout();
			this->tabReports->ResumeLayout(false);
			this->tabReports->PerformLayout();
			this->grpInput->ResumeLayout(false);
			this->grpInput->PerformLayout();
			this->grpSearch->ResumeLayout(false);
			this->grpSearch->PerformLayout();
			this->grpNotes->ResumeLayout(false);
			this->grpNotes->PerformLayout();
			this->panelReports->ResumeLayout(false);
			this->panelReports->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private:
		// =====================================================================
		//  Допоміжні методи відображення
		// =====================================================================
		System::Void SetStatus(System::String^ message) {
			statusLabel->Text = System::String::Format(L"{0}  |  Усього валют: {1}  |  У таблиці: {2}",
				message, repository->Count(), shown->Count());
		}

		System::Void ShowWarning(System::String^ message) {
			MessageBox::Show(message, L"Попередження", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		System::Void ShowError(System::String^ message) {
			MessageBox::Show(message, L"Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		System::Void ShowNativeError(CurrencyException& ex) {
			ShowWarning(StringBridge::ToManaged(ex.Reason()));
		}

		/// Заповнює таблицю валютами, індекси яких лежать у shown.
		System::Void RefillGrid(System::String^ status) {
			grid->Rows->Clear();
			for (int i = 0; i < shown->Count(); i++) {
				const Currency& currency = repository->GetAt(shown->At(i));
				array<System::Object^>^ cells = gcnew array<System::Object^>{
					StringBridge::ToManaged(currency.GetName()),
						StringBridge::ToManaged(currency.GetCountry()),
						StringBridge::ToManaged(WideString::FromDoubleShort(currency.GetRate())),
						StringBridge::ToManaged(WideString::FromDoubleShort(currency.GetRateToDollar())),
						StringBridge::ToManaged(currency.GetBanknotes().ToDisplayString())
				};
				grid->Rows->Add(cells);
			}
			SetStatus(status);
		}

		/// Показує всі валюти сховища.
		System::Void ShowAll() {
			DynamicArray<int>* all = new DynamicArray<int>();
			for (int i = 0; i < repository->Count(); i++) {
				all->Add(i);
			}
			delete shown;
			shown = all;
			RefillGrid(L"Готово");
		}

		/// Показує лише валюти з переданими індексами (результат пошуку або фільтра).
		System::Void ShowIndices(DynamicArray<int>& indices, System::String^ status) {
			DynamicArray<int>* selected = new DynamicArray<int>(static_cast<DynamicArray<int>&&>(indices));
			delete shown;
			shown = selected;
			RefillGrid(status);
		}

		/// Номер вибраного рядка таблиці (інакше — ItemNotFoundException).
		int GetSelectedRow() {
			if (grid->CurrentRow == nullptr || grid->CurrentRow->Index < 0 || grid->CurrentRow->Index >= shown->Count()) {
				throw ItemNotFoundException(L"Спочатку виберіть валюту в таблиці.");
			}
			return grid->CurrentRow->Index;
		}

		System::Void RestoreSelection(int row) {
			if (grid->Rows->Count == 0) {
				return;
			}
			if (row >= grid->Rows->Count) {
				row = grid->Rows->Count - 1;
			}
			grid->CurrentCell = grid->Rows[row]->Cells[0];
			grid->Rows[row]->Selected = true;
		}

		System::Void ClearInputFields() {
			txtName->Text = System::String::Empty;
			txtCountry->Text = System::String::Empty;
			txtRate->Text = System::String::Empty;
			txtDollar->Text = System::String::Empty;
			txtNotes->Text = System::String::Empty;
			txtName->Focus();
		}

		// =====================================================================
		//  Обробники подій
		// =====================================================================
		System::Void OnGridCellMouseDown(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
			if (e->Button == System::Windows::Forms::MouseButtons::Right && e->RowIndex >= 0) {
				grid->ClearSelection();
				grid->Rows[e->RowIndex]->Selected = true;
				grid->CurrentCell = grid->Rows[e->RowIndex]->Cells[0];
			}
		}

		System::Void OnNewData(System::Object^ sender, System::EventArgs^ e) {
			try {
				if (MessageBox::Show(L"Видалити всі валюти з пам'яті?", L"Підтвердження",
					MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes) {
					return;
				}
				repository->Clear();
				ShowAll();
				txtReport->Clear();
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(ex->Message);
			}
		}

		System::Void OnOpenFile(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ dialog = gcnew OpenFileDialog();
			dialog->Title = L"Відкрити файл із валютами";
			dialog->Filter = L"Текстові файли (*.txt)|*.txt|Усі файли (*.*)|*.*";
			if (dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				return;
			}
			try {
				WideString warnings;
				int loaded = CurrencyFileService::LoadFromFile(StringBridge::ToWide(dialog->FileName), *repository, warnings);
				ShowAll();
				SetStatus(System::String::Format(L"Завантажено валют: {0}", loaded));
				if (!warnings.IsEmpty()) {
					MessageBox::Show(StringBridge::ToManaged(warnings), L"Деякі записи пропущено",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			catch (FileAccessException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnSaveFile(System::Object^ sender, System::EventArgs^ e) {
			SaveFileDialog^ dialog = gcnew SaveFileDialog();
			dialog->Title = L"Зберегти валюти у файл";
			dialog->Filter = L"Текстові файли (*.txt)|*.txt|Усі файли (*.*)|*.*";
			dialog->DefaultExt = L"txt";
			if (dialog->ShowDialog() != System::Windows::Forms::DialogResult::OK) {
				return;
			}
			try {
				CurrencyFileService::SaveToFile(StringBridge::ToWide(dialog->FileName), *repository);
				SetStatus(L"Дані збережено у файл");
			}
			catch (FileAccessException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnExit(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}

		System::Void OnAddCurrency(System::Object^ sender, System::EventArgs^ e) {
			try {
				Currency currency(
					StringBridge::ToWide(txtName->Text),
					StringBridge::ToWide(txtCountry->Text),
					ValueParser::ParseDouble(StringBridge::ToWide(txtRate->Text), L"Курс"),
					ValueParser::ParseDouble(StringBridge::ToWide(txtDollar->Text), L"Відношення до долара"),
					ValueParser::ParseBanknotes(StringBridge::ToWide(txtNotes->Text)));
				repository->Add(static_cast<Currency&&>(currency));
				ShowAll();
				ClearInputFields();
				SetStatus(L"Валюту додано");
			}
			catch (DuplicateItemException& ex) {
				ShowNativeError(ex);
			}
			catch (InvalidFormatException& ex) {
				ShowNativeError(ex);
			}
			catch (InvalidValueException& ex) {
				ShowNativeError(ex);
			}
			catch (NumberOverflowException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnRemoveCurrency(System::Object^ sender, System::EventArgs^ e) {
			try {
				int index = shown->At(GetSelectedRow());
				System::String^ title = StringBridge::ToManaged(repository->GetAt(index).ToString());
				if (MessageBox::Show(L"Видалити валюту «" + title + L"»?", L"Підтвердження",
					MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes) {
					return;
				}
				repository->RemoveAt(index);
				ShowAll();
				SetStatus(L"Валюту видалено");
			}
			catch (ItemNotFoundException& ex) {
				ShowNativeError(ex);
			}
			catch (IndexRangeException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnSearch(System::Object^ sender, System::EventArgs^ e) {
			try {
				DynamicArray<int> found;
				repository->SearchByName(StringBridge::ToWide(txtSearch->Text), found);
				int count = found.Count();
				ShowIndices(found, System::String::Format(L"Знайдено валют: {0}", count));
			}
			catch (InvalidValueException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnFilterByRate(System::Object^ sender, System::EventArgs^ e) {
			try {
				double minRate = ValueParser::ParseDouble(StringBridge::ToWide(txtFrom->Text), L"Курс від");
				double maxRate = ValueParser::ParseDouble(StringBridge::ToWide(txtTo->Text), L"Курс до");
				DynamicArray<int> found;
				repository->FilterByRate(minRate, maxRate, found);
				int count = found.Count();
				ShowIndices(found, System::String::Format(L"Валют з курсом у заданому діапазоні: {0}", count));
			}
			catch (InvalidFormatException& ex) {
				ShowNativeError(ex);
			}
			catch (InvalidValueException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnShowAll(System::Object^ sender, System::EventArgs^ e) {
			ShowAll();
		}

		System::Void OnAddNotes(System::Object^ sender, System::EventArgs^ e) {
			try {
				int row = GetSelectedRow();
				int index = shown->At(row);
				int denomination = ValueParser::ParseInteger(StringBridge::ToWide(txtDenomination->Text), L"Номінал");
				int quantity = ValueParser::ParseInteger(StringBridge::ToWide(txtQuantity->Text), L"Кількість");
				repository->GetAt(index).GetBanknotes().Add(denomination, quantity);
				RefillGrid(L"Банкноти додано");
				RestoreSelection(row);
			}
			catch (ItemNotFoundException& ex) {
				ShowNativeError(ex);
			}
			catch (InvalidFormatException& ex) {
				ShowNativeError(ex);
			}
			catch (NumberOverflowException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnRemoveNotes(System::Object^ sender, System::EventArgs^ e) {
			try {
				int row = GetSelectedRow();
				int index = shown->At(row);
				int denomination = ValueParser::ParseInteger(StringBridge::ToWide(txtDenomination->Text), L"Номінал");
				int quantity = ValueParser::ParseInteger(StringBridge::ToWide(txtQuantity->Text), L"Кількість");
				repository->GetAt(index).GetBanknotes().Remove(denomination, quantity);
				RefillGrid(L"Банкноти вилучено");
				RestoreSelection(row);
			}
			catch (NotEnoughBanknotesException& ex) {
				ShowNativeError(ex);
			}
			catch (ItemNotFoundException& ex) {
				ShowNativeError(ex);
			}
			catch (InvalidFormatException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnSortByDollar(System::Object^ sender, System::EventArgs^ e) {
			try {
				CurrencySorter::SortByDollarRateCounting(*repository, chkDescending->Checked);
				ShowAll();
				SetStatus(L"Відсортовано підрахунком за відношенням до долара");
			}
			catch (MemoryAllocationException& ex) {
				ShowNativeError(ex);
			}
			catch (NumberOverflowException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnReportCountries(System::Object^ sender, System::EventArgs^ e) {
			try {
				txtReport->Text = StringBridge::ToManaged(CurrencyReportBuilder::BuildBanknoteReportByCountry(*repository));
				tabs->SelectedTab = tabReports;
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnReportDollars(System::Object^ sender, System::EventArgs^ e) {
			try {
				txtReport->Text = StringBridge::ToManaged(CurrencyReportBuilder::BuildDollarTotalsByCountry(*repository));
				tabs->SelectedTab = tabReports;
			}
			catch (NumberOverflowException& ex) {
				ShowNativeError(ex);
			}
			catch (CurrencyException& ex) {
				ShowNativeError(ex);
			}
			catch (System::Exception^ ex) {
				ShowError(L"Непередбачена помилка: " + ex->Message);
			}
		}

		System::Void OnFileFormatHelp(System::Object^ sender, System::EventArgs^ e) {
			System::String^ text =
				L"Файл — текстовий, кодування UTF-8.\r\n"
				L"Один запис = один рядок. Поля розділені символом '|':\r\n\r\n"
				L"Назва|Країна|Курс|Відношення до долара|Номінал:Кількість;Номінал:Кількість\r\n\r\n"
				L"• Курс — вартість 1 одиниці в національній валюті країни.\r\n"
				L"• Відношення до долара — скільки доларів за 1 одиницю валюти.\r\n"
				L"• Дробові числа записуються через крапку (допускається й кома).\r\n"
				L"• Банкноти: пари «номінал:кількість» через ';' (можна залишити порожнім).\r\n"
				L"• Рядки, що починаються з '#', та порожні рядки ігноруються.\r\n\r\n"
				L"Приклад:\r\n"
				L"Євро|Польща|4.3|1.09|10:30;20:20;100:5";
			MessageBox::Show(text, L"Формат файлу даних", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		System::Void OnAbout(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show(
				L"Облік валют\r\nC++/CLI, Windows Forms (.NET Framework), модель без STL.",
				L"Про програму", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	};
}
