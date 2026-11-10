#pragma once

namespace coursework {

	using namespace System;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;

	// Форма з діаграмою: кожен стовпчик - сума наявних банкнот однієї країни в доларах.
	public ref class ChartForm : public System::Windows::Forms::Form
	{
	private:
		cli::array<String^>^ names;   // назви країн
		cli::array<double>^ values;   // суми в доларах
		System::Drawing::Font^ textFont;
		System::Drawing::Font^ titleFont;

	public:
		// Конструктор з параметрами: назви країн та відповідні суми
		ChartForm(cli::array<String^>^ countryNames, cli::array<double>^ totals)
		{
			names = countryNames;
			values = totals;
			textFont = gcnew System::Drawing::Font(L"Segoe UI", 9.0f);
			titleFont = gcnew System::Drawing::Font(L"Segoe UI", 11.0f, FontStyle::Bold);

			this->Text = L"Діаграма: суми банкнот за країнами";
			this->ClientSize = System::Drawing::Size(760, 460);
			this->MinimumSize = System::Drawing::Size(420, 320);
			this->StartPosition = FormStartPosition::CenterParent;
			this->BackColor = Color::White;
			this->DoubleBuffered = true;
			this->ResizeRedraw = true;
		}

	protected:
		// Деструктор: звільняє шрифти
		~ChartForm()
		{
			delete textFont;
			delete titleFont;
		}

		// Малювання діаграми
		virtual void OnPaint(PaintEventArgs^ e) override
		{
			Form::OnPaint(e);
			int count = names->Length;
			if (count == 0)
				return;

			Graphics^ g = e->Graphics;
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			double maxValue = 0;
			for (int i = 0; i < count; i++)
				if (values[i] > maxValue)
					maxValue = values[i];
			if (maxValue <= 0)
				maxValue = 1;

			int left = 50, right = 20, top = 60, bottom = 60;
			int width = this->ClientSize.Width - left - right;
			int height = this->ClientSize.Height - top - bottom;
			if (width < 50 || height < 50)
				return;

			g->DrawString(L"Сума наявних банкнот у доларах (USD) за країнами", titleFont, Brushes::Black, 10.0f, 10.0f);
			g->DrawLine(Pens::Black, left, top, left, top + height);                  // вісь Y
			g->DrawLine(Pens::Black, left, top + height, left + width, top + height); // вісь X

			StringFormat^ center = gcnew StringFormat();
			center->Alignment = StringAlignment::Center;

			int slot = width / count;
			int barWidth = slot * 2 / 3;
			for (int i = 0; i < count; i++)
			{
				int barHeight = static_cast<int>(values[i] / maxValue * (height - 25));
				int x = left + i * slot + (slot - barWidth) / 2;
				int y = top + height - barHeight;

				g->FillRectangle(Brushes::SteelBlue, x, y, barWidth, barHeight);

				// значення над стовпчиком
				g->DrawString(String::Format(L"{0:F2}", values[i]), textFont, Brushes::Black,
					RectangleF(static_cast<float>(x - 15), static_cast<float>(y - 20), static_cast<float>(barWidth + 30), 18.0f), center);

				// назва країни під віссю
				g->DrawString(names[i], textFont, Brushes::Black,
					RectangleF(static_cast<float>(left + i * slot), static_cast<float>(top + height + 6), static_cast<float>(slot), 40.0f), center);
			}
		}
	};
}