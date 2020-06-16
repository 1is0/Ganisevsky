// ---------------------------------------------------------------------------
#include <cmath>
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit4.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

using namespace std;
TForm3 *Form3;
int lastX = -1, lastY = -1;
SaveXY *XY = new SaveXY[50];
int Figure = -1;
int Item = -1;
int ChangeX = -1, ChangeY = -1;
bool isThisMove = false;

// ---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner) : TForm(Owner) {
	KeyPreview = true;   //����� �������� ���������� ������
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Image1MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {   // ������� ����

	if (Button == mbRight) {
		Item = -1;
		isThisMove = false;
	}
	else {
		if (lastX > 0 && lastY > 0) {
			DrawFigure(Sender, X, Y);
		}
		else {
			Figure++;
			SaveColor(Figure);
			X += 9;
			Y += 8;
			Canvas->MoveTo(X, Y);
			XY[Figure].FirstX = X;
			XY[Figure].FirstY = Y;
			lastX = X;
			lastY = Y;
			XY[Figure].XYPoligon[0][XY[Figure].iX] = X;
			XY[Figure].XYPoligon[1][XY[Figure].iY] = Y;
			XY[Figure].iX++;
			XY[Figure].iY++;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Image1MouseMove(TObject *Sender, TShiftState Shift,
	int X, int Y) {  //�������� ����
	if (Object->ItemIndex == 0 && Shift.Contains(ssLeft)) {
		DrawFigure(Sender, X, Y);
	}

	if (Item != -1 && isThisMove) {
		if (!XY[Item].Elipse) {
			Hide(Sender, Item);
			ComponentColor(Sender, Item);
			move(X - 10 , Y - 10 );
			BuildLabel(XY[Item].FirstX, XY[Item].FirstY, Item);

			CenterLabel(XY[Item].CenterX, XY[Item].CenterY, Item);
		}
		else {
			DeleteLabel(Item);
			Canvas->Brush->Color = clBtnHighlight;
			Canvas->Pen->Color = clBtnHighlight;
			Canvas->Ellipse(XY[Item].XYPoligon[0][0], XY[Item].XYPoligon[1][0],
				XY[Item].XYPoligon[0][1], XY[Item].XYPoligon[1][1]);
			ColorClick(Sender);
			BrushColorClick(Sender);
			ComponentColor(Sender, Item);
			move(X - 10, Y - 10);
			infoElipce(Item);
			BuildLabel(XY[Item].FirstX, XY[Item].FirstY, Item);
			CenterLabel(XY[Item].CenterX, XY[Item].CenterY, Item);
			ColorClick(Sender);
			BrushColorClick(Sender);
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::Image1MouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y) {  //��� ��������, ���� ���������� �� ������
	if (Object->ItemIndex == 0) {
		lastX = -1;
		lastY = -1;
	}
}

void __fastcall TForm3::DrawFigure(TObject *Sender, int X, int Y) {
	X += 9;
	Y += 8;
	switch (Object->ItemIndex) {
	case 0:
	case 1:
		Canvas->LineTo(X, Y);
		XY[Figure].XYPoligon[0][XY[Figure].iX] = X;
		XY[Figure].XYPoligon[1][XY[Figure].iY] = Y;
		XY[Figure].iX++;
		XY[Figure].iY++;
		break;
	case 2:
		Canvas->Ellipse(lastX, lastY, X, Y);
		XY[Figure].Elipse = true;
		XY[Figure].XYPoligon[0][0] = lastX;
		XY[Figure].XYPoligon[1][0] = lastY;
		XY[Figure].XYPoligon[0][1] = X;
		XY[Figure].XYPoligon[1][1] = Y;
		XY[Figure].iX = 2;
		XY[Figure].iY = 2;
		XY[Figure].FirstX = lastX;
		XY[Figure].FirstY = lastY;
		lastX = -1;
		lastY = -1;
		FindCenter(Figure);
		infoElipce(Figure);
		BuildLabel(XY[Figure].FirstX, XY[Figure].FirstY, Figure);
		CenterLabel(XY[Figure].CenterX, XY[Figure].CenterY, Figure);
		break;
	case 3:
		Canvas->Rectangle(lastX, lastY, X, Y);
		XY[Figure].XYPoligon[0][0] = lastX;
		XY[Figure].XYPoligon[1][0] = lastY;
		XY[Figure].XYPoligon[0][1] = X;
		XY[Figure].XYPoligon[1][1] = lastY;
		XY[Figure].XYPoligon[0][2] = X;
		XY[Figure].XYPoligon[1][2] = Y;
		XY[Figure].XYPoligon[0][3] = lastX;
		XY[Figure].XYPoligon[1][3] = Y;
		XY[Figure].iX = 4;
		XY[Figure].iY = 4;
		lastX = -1;
		lastY = -1;
		info(Figure);
		break;
	case 4:
		for (int i = 0; i < Figure; i++) {
			if (fabs(sqrt(powl(XY[i].CenterX, 2) + powl(XY[i].CenterY, 2)) -
				sqrt(powl(X, 2) + powl(Y, 2))) < 30) {
				Item = i;
			}
		}
		if (fabs(sqrt(powl(XY[Item].CenterX, 2) + powl(XY[Item].CenterY, 2)) -
			sqrt(powl(X, 2) + powl(Y, 2))) > 30) {
			ChangeX = X;
			ChangeY = Y;
		}
		break;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender) {  //�������� �����
	Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
	Image1->Canvas->Brush->Color = clBtnHighlight;
	Image1->Canvas->FillRect(Rect(0, 0, Image1->Width, Image1->Height));
	Canvas->Brush->Color = clBtnHighlight;
	// Canvas->Brush->Color = clGray;

}

// ---------------------------------------------------------------------------
void __fastcall TForm3::ObjectClick(TObject *Sender) {
	lastX = -1;
	lastY = -1;
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::ColorClick(TObject *Sender) {    //����� �����
	TColor style;
	switch (Color->ItemIndex) {
	case 0:
		style = clBlack;
		break;
	case 1:
		style = clBlue;
		break;
	case 2:
		style = clRed;
		break;
	case 3:
		style = clGreen;
		break;
	case 4:
		style = clPurple;
		break;
	case 5:
		style = clWhite;
		break;
	}
	Canvas->Pen->Color = style;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::ClearPoligon(int DeleteItem) {   //��� �������� ��������
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 100; j++)
			XY[DeleteItem].XYPoligon[i][j] = 0;
	}
	XY[DeleteItem].FirstX = -1;
	XY[DeleteItem].FirstY = -1;
}

void __fastcall TForm3::PoligonFigure() {    //��� ��������� ��������
	TPoint *pnt = new TPoint[XY[Figure].iX];
	for (int i = 0; i < XY[Figure].iX; i++) {
		pnt[i] = Point(XY[Figure].XYPoligon[0][i], XY[Figure].XYPoligon[1][i]);
	}
	Canvas->Polygon(pnt, XY[Figure].iX - 1);
	info(Figure);

}

void __fastcall TForm3::FormKeyDown(TObject *Sender, WORD &Key,
	TShiftState Shift) { //��� ���������� ��������� �� ��������������
	if (Key == VK_ESCAPE && XY[Figure].iX != 0) {
		lastX = -1;
		lastY = -1;
		PoligonFigure();
	}
}

void __fastcall TForm3::CenterLabel(int CenterX, int CenterY, int FigureItem) {
	TLabel *Label = new TLabel(this);  //������ ������
	Label->Parent = this;
	Label->Name = "Label" + IntToStr(FigureItem) + IntToStr(FigureItem) +
		IntToStr(FigureItem) + IntToStr(FigureItem);
	Label->Left = CenterX;
	Label->Top = CenterY;
	Label->Caption = "Center";
}

void __fastcall TForm3::BuildLabel(int FirstX, int FirstY, int FigureItem) {
	TLabel *Label = new TLabel(this); //���������� �������
	Label->Parent = this;
	Label->Name = "Label" + IntToStr(FigureItem);
	Label->Left = FirstX;
	Label->Top = FirstY;
	Label->Caption = "Sq = " + IntToStr(XY[FigureItem].sq) + "\nPer = " +
		IntToStr(XY[FigureItem].per);
}

void __fastcall TForm3::info(int FigureItem) { //������ ���������� � ������
	if (XY[FigureItem].FirstX > 0) {
		XY[FigureItem].per = 0;
		XY[FigureItem].sq = 0;
		for (int i = 1; i < XY[FigureItem].iX; i++) {
			XY[FigureItem].per +=
				sqrt(pow(XY[FigureItem].XYPoligon[0][i] -
				XY[FigureItem].XYPoligon[0][i - 1], 2) +
				pow(XY[FigureItem].XYPoligon[1][i] -
				XY[FigureItem].XYPoligon[1][i - 1], 2));
			XY[FigureItem].sq +=
				(XY[FigureItem].XYPoligon[0][i - 1] * XY[FigureItem].XYPoligon
				[1][i] - XY[FigureItem].XYPoligon[0][i] * XY[FigureItem]
				.XYPoligon[1][i - 1]);
		}
		XY[FigureItem].per +=
			sqrt(pow(XY[FigureItem].XYPoligon[0][0] -
			XY[FigureItem].XYPoligon[0][XY[FigureItem].iX - 1], 2) +
			pow(XY[FigureItem].XYPoligon[1][0] -
			XY[FigureItem].XYPoligon[1][XY[FigureItem].iY - 1], 2));
		XY[FigureItem].sq +=
			(XY[FigureItem].XYPoligon[0][XY[FigureItem].iX - 1] * XY[FigureItem]
			.XYPoligon[1][0] - XY[FigureItem].XYPoligon[0][0] * XY[FigureItem]
			.XYPoligon[1][XY[FigureItem].iX - 1]);

		XY[FigureItem].sq = abs(XY[FigureItem].sq) / 2;

		BuildLabel(XY[FigureItem].FirstX, XY[FigureItem].FirstY, FigureItem);
		FindCenter(FigureItem);
		CenterLabel(XY[FigureItem].CenterX, XY[FigureItem].CenterY, FigureItem);
	}
}

void __fastcall TForm3::FindCenter(int FigureItem) {    //����� ������ ������
	int temp = 0;

	XY[FigureItem].CenterX = 0;
	XY[FigureItem].CenterY = 0;

	for (int i = 0; i < XY[FigureItem].iX; i++) {
		temp++;
		XY[FigureItem].CenterX += XY[FigureItem].XYPoligon[0][i];
		XY[FigureItem].CenterY += XY[FigureItem].XYPoligon[1][i];
	}
	XY[FigureItem].CenterX /= temp;
	XY[FigureItem].CenterY /= temp;
}

// ---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender) {
	if (Item != -1) {       //��������

		if (!XY[Item].Elipse) {
			Hide(Sender, Item);  //�����
			ClearPoligon(Item);
		}
		else {
			DeleteLabel(Item);              //��� ������ ������
			Canvas->Brush->Color = clBtnHighlight;
			Canvas->Pen->Color = clBtnHighlight;
			Canvas->Ellipse(XY[Item].XYPoligon[0][0], XY[Item].XYPoligon[1][0],
				XY[Item].XYPoligon[0][1], XY[Item].XYPoligon[1][1]);
			ColorClick(Sender);
			BrushColorClick(Sender);
		}
	}
	Item = -1;
}

// ---------------------------------------------------------------------------
void __fastcall TForm3::move(int MoveX, int MoveY) {    //��������
	if (!XY[Item].Elipse) {  //������
		TPoint *tpn = new TPoint[XY[Item].iX];
		int tempX = XY[Item].CenterX - MoveX;
		int tempY = XY[Item].CenterY - MoveY;
		for (int i = 0; i < XY[Item].iX; i++) {
			XY[Item].XYPoligon[0][i] -= tempX;
			XY[Item].XYPoligon[1][i] -= tempY;
			tpn[i] = Point(XY[Item].XYPoligon[0][i], XY[Item].XYPoligon[1][i]);

		}
		Canvas->Polygon(tpn, XY[Item].iX - 1);

		XY[Item].CenterX = MoveX;
		XY[Item].CenterY = MoveY;
		XY[Item].FirstX = XY[Item].XYPoligon[0][0];
		XY[Item].FirstY = XY[Item].XYPoligon[1][0];
	}
	else {                                                //��� ���������
		int tempX = XY[Item].CenterX - MoveX;
		int tempY = XY[Item].CenterY - MoveY;
		for (int i = 0; i < XY[Item].iX; i++) {
			XY[Item].XYPoligon[0][i] -= tempX;
			XY[Item].XYPoligon[1][i] -= tempY;
		}
		XY[Item].CenterX = MoveX;
		XY[Item].CenterY = MoveY;
		XY[Item].FirstX = XY[Item].XYPoligon[0][0];
		XY[Item].FirstY = XY[Item].XYPoligon[1][0];
		Canvas->Ellipse(XY[Item].XYPoligon[0][0], XY[Item].XYPoligon[1][0],
			XY[Item].XYPoligon[0][1], XY[Item].XYPoligon[1][1]);
	}
}

void __fastcall TForm3::ClearHelp(TPoint *pnt, int FigureItem) {  //������ ��������� �����
	for (int i = 0; i < XY[FigureItem].iX; i++) {
		pnt[i] = Point(XY[FigureItem].XYPoligon[0][i],
			XY[FigureItem].XYPoligon[1][i]);
	}
	Canvas->Polygon(pnt, XY[FigureItem].iX - 1);
}

void __fastcall TForm3::Hide(TObject *Sender, int FigureItem) {   //��������� ����� ������ ����
	TPoint *pnt = new TPoint[XY[FigureItem].iX];
	Canvas->Brush->Color = clBtnHighlight;
	Canvas->Pen->Color = clBtnHighlight;
	ClearHelp(pnt, FigureItem);
	DeleteLabel(FigureItem);

	// Canvas->Brush->Color = clGray;
	TForm3::ColorClick(Sender);
	TForm3::BrushColorClick(Sender);

}

void __fastcall TForm3::DeleteLabel(int FigureItem) {   //�������� �������
	TComponent *Label = Form3->FindComponent("Label" + IntToStr(FigureItem));
	delete Label;
	Label = Form3->FindComponent("Label" + IntToStr(FigureItem) +
		IntToStr(FigureItem) + IntToStr(FigureItem) + IntToStr(FigureItem));
	delete Label;
}

void __fastcall TForm3::Button3Click(TObject *Sender) {   //��������� ��������
	if (StrToFloat(Edit1->Text) > 0 && Item != -1) {
		if (!XY[Item].Elipse) {  //������
			Hide(Sender, Item);
		}
		else {
			DeleteLabel(Item);
			Canvas->Brush->Color = clBtnHighlight;
			Canvas->Pen->Color = clBtnHighlight;
			Canvas->Ellipse(XY[Item].XYPoligon[0][0], XY[Item].XYPoligon[1][0],
				XY[Item].XYPoligon[0][1], XY[Item].XYPoligon[1][1]);
			ColorClick(Sender);
			BrushColorClick(Sender);
		}
		TPoint *tpn = new TPoint[XY[Item].iX];
		for (int i = 0; i < XY[Item].iX; i++) { //��� ���������
			XY[Item].XYPoligon[0][i] =
				sqrt(StrToFloat(Edit1->Text)) *
				(XY[Item].XYPoligon[0][i] - XY[Item].CenterX) +
				XY[Item].CenterX;
			XY[Item].XYPoligon[1][i] =
				sqrt(StrToFloat(Edit1->Text)) *
				(XY[Item].XYPoligon[1][i] - XY[Item].CenterY) +
				XY[Item].CenterY;

			if (!XY[Item].Elipse) {
				tpn[i] = Point(XY[Item].XYPoligon[0][i],
					XY[Item].XYPoligon[1][i]);
			}
		}
		if (!XY[Item].Elipse) {
			ComponentColor(Sender, Item);
			Canvas->Polygon(tpn, XY[Item].iX - 1);
			info(Item);
		}
		else {
			ComponentColor(Sender, Item);
			Canvas->Ellipse(XY[Item].XYPoligon[0][0], XY[Item].XYPoligon[1][0],
				XY[Item].XYPoligon[0][1], XY[Item].XYPoligon[1][1]);
			infoElipce(Item);
			BuildLabel(XY[Item].FirstX, XY[Item].FirstY, Item);
			CenterLabel(XY[Item].CenterX, XY[Item].CenterY, Item);
		}
		ColorClick(Sender);
		BrushColorClick(Sender);
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::BrushColorClick(TObject *Sender) {  // ����� �������
	TColor style;
	switch (BrushColor->ItemIndex) {
	case 0:
		style = clBtnHighlight;
		break;
	case 1:
		style = clBlue;
		break;
	case 2:
		style = clRed;
		break;
	case 3:
		style = clGreen;
		break;
	case 4:
		style = clPurple;
		break;
	case 5:
		style = clBlack;
		break;
	}
	Canvas->Brush->Color = style;
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender) {     //�������
	int tempAngle = 0;
	if (Item != -1 && StrToInt(angle1->Text)) {
		int tempAng = StrToInt(angle1->Text);
		while (tempAngle != tempAng) {
			if (!XY[Item].Elipse) {
				Hide(Sender, Item);
			}
			else {
				DeleteLabel(Item);
				Canvas->Brush->Color = clBtnHighlight;
				Canvas->Pen->Color = clBtnHighlight;
				Canvas->Ellipse(XY[Item].XYPoligon[0][0],
					XY[Item].XYPoligon[1][0], XY[Item].XYPoligon[0][1],
					XY[Item].XYPoligon[1][1]);
				ColorClick(Sender);
				BrushColorClick(Sender);
			}
			TPoint *tpn = new TPoint[XY[Item].iX];
			float tempX, tempY;
			for (int i = 0; i < XY[Item].iX; i++) {
				XY[Item].XYPoligon[0][i] -= ChangeX;
				XY[Item].XYPoligon[1][i] -= ChangeY;
				tempX = XY[Item].XYPoligon[0][i] * cos(M_PI / 180) -
					XY[Item].XYPoligon[1][i] * sin(M_PI / 180);
				tempY = XY[Item].XYPoligon[0][i] * sin(M_PI / 180) +
					XY[Item].XYPoligon[1][i] * cos(M_PI / 180);
				XY[Item].XYPoligon[0][i] = tempX;
				XY[Item].XYPoligon[1][i] = tempY;
				XY[Item].XYPoligon[0][i] += ChangeX;
				XY[Item].XYPoligon[1][i] += ChangeY;
				if (!XY[Item].Elipse) {
					ComponentColor(Sender, Item);
					tpn[i] = Point(XY[Item].XYPoligon[0][i],
						XY[Item].XYPoligon[1][i]);
				}
			}
			XY[Item].FirstX = XY[Item].XYPoligon[0][0];
			XY[Item].FirstY = XY[Item].XYPoligon[1][0];
			if (!XY[Item].Elipse) {
				Canvas->Polygon(tpn, XY[Item].iX - 1);
				info(Item);
			}
			else {
				ComponentColor(Sender, Item);
				XY[Item].FirstX = XY[Item].XYPoligon[0][0];
				XY[Item].FirstY = XY[Item].XYPoligon[1][0];
				FindCenter(Item);
				infoElipce(Item);
				BuildLabel(XY[Item].FirstX, XY[Item].FirstY, Item);
				CenterLabel(XY[Item].CenterX, XY[Item].CenterY, Item);
				Canvas->Ellipse(XY[Item].XYPoligon[0][0],
					XY[Item].XYPoligon[1][0], XY[Item].XYPoligon[0][1],
					XY[Item].XYPoligon[1][1]);
			}
			tempAngle++;
		}
	}
	ColorClick(Sender);
	BrushColorClick(Sender);
}

void __fastcall TForm3::infoElipce(int FigureItem) {  //���� ��� ������
	unsigned int TempX =
		abs(XY[FigureItem].XYPoligon[0][1] -
		XY[FigureItem].XYPoligon[0][0]) / 2;
	unsigned int TempY =
		abs(XY[FigureItem].XYPoligon[1][1] -
		XY[FigureItem].XYPoligon[1][0]) / 2;
	XY[FigureItem].sq = M_PI * TempX * TempY;
	XY[FigureItem].per = 2 * M_PI * sqrt(powl(TempX, 2) + powl(TempY, 2) / 2);
}
// ---------------------------------------------------------------------------

void __fastcall TForm3::Timer1Timer(TObject *Sender) {
	for (int i = 0; i < Figure; i++) {
		ComponentColor(Sender, i);
		if (!XY[i].Elipse) {
			Hide(Sender, i);
		}
		else {
			DeleteLabel(i);
			Canvas->Brush->Color = clBtnHighlight;
			Canvas->Pen->Color = clBtnHighlight;
			Canvas->Ellipse(XY[i].XYPoligon[0][0], XY[i].XYPoligon[1][0],
				XY[i].XYPoligon[0][1], XY[i].XYPoligon[1][1]);
			ColorClick(Sender);
			BrushColorClick(Sender);
		}
		TPoint *tpn = new TPoint[XY[i].iX];
		ComponentColor(Sender, i);
		if (!XY[i].Elipse) {
			for (int j = 0; j < XY[i].iX; j++) {
				tpn[j] = Point(XY[i].XYPoligon[0][j], XY[i].XYPoligon[1][j]);
			}
			Canvas->Polygon(tpn, XY[i].iX - 1);
			info(i);
		}
		else {
			Canvas->Ellipse(XY[i].XYPoligon[0][0], XY[i].XYPoligon[1][0],
				XY[i].XYPoligon[0][1], XY[i].XYPoligon[1][1]);
			infoElipce(i);
			BuildLabel(XY[i].FirstX, XY[i].FirstY, i);
			CenterLabel(XY[i].CenterX, XY[i].CenterY, i);
		}
		delete[]tpn;
	}
	ColorClick(Sender);
	BrushColorClick(Sender);
}

void __fastcall TForm3::ComponentColor(TObject *Sender, int FigureItem) {
	TColor style;
	switch (XY[FigureItem].BrushColor) {  //����� �������
	case 0:
		style = clBtnHighlight;
		break;
	case 1:
		style = clBlue;
		break;
	case 2:
		style = clRed;
		break;
	case 3:
		style = clGreen;
		break;
	case 4:
		style = clPurple;
		break;
	case 5:
		style = clBlack;
		break;
	}
	Canvas->Brush->Color = style;

	switch (XY[FigureItem].PenColor) {    //����� ����� ����
	case 0:
		style = clBlack;
		break;
	case 1:
		style = clBlue;
		break;
	case 2:
		style = clRed;
		break;
	case 3:
		style = clGreen;
		break;
	case 4:
		style = clPurple;
		break;
	case 5:
		style = clWhite;
		break;
	}
	Canvas->Pen->Color = style;

}

void __fastcall TForm3::SaveColor(int FigureItem) {  //���������� ���������� �����
	XY[FigureItem].PenColor = Color->ItemIndex;
	XY[FigureItem].BrushColor = BrushColor->ItemIndex;
//	XY[FigureItem].PenStyle = Line->ItemIndex;
}

// ---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender) { //���� ������ ������ ��������
	isThisMove = true;
}
// ---------------------------------------------------------------------------



