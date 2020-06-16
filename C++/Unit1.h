// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>

// ---------------------------------------------------------------------------

int x, y, r;

class Line {
public:
	Line(int a, int b, int c) {
		x = a;
		y = b;
		r = c;
	}

	void show(TCanvas *Canvas) {
		Canvas->Pen->Color = clBlack;
		Canvas->Brush->Color = clBlack;
		Canvas->Rectangle(x - 0, y + r, x + 5, y - 50);

		// Canvas->Rectangle(x - r, y + r, x + r, y - r);
	}

	void move(TCanvas *Canvas) {
		y = y - 10;
	}

	void hide(TCanvas *Canvas) {
		Canvas->Pen->Color = clWhite;
		Canvas->Brush->Color = clWhite;
		Canvas->Rectangle(x - r, y + r, x + 5, y - r);

		// Canvas->Rectangle(x - r, y + r, x + r, y - r);
	}
};

class Rocket : public Line {
public:

	Rocket(int a, int b, int c) : Line(500, 600, 10)
	{
		x = a;
		y = b;
		r = c;
	}

	void show(TCanvas *Canvas) {
		Canvas->Pen->Color = clBlue;
		Canvas->Brush->Color = clBlue;
		Canvas->Rectangle(x - 0, y + 75, x + 75, y - 175); // x + 75, y - 175

		// polygon 1 -----------------------------------------------------------

		TPoint points[7];
		points[0] = Point(500, y - 176);
		points[1] = Point(537, y - 290);
		points[2] = Point(574, y - 176);

		Canvas->Polygon(points, 2);

		// polygon 2 -----------------------------------------------------------

		Canvas->Pen->Color = clPurple;
		Canvas->Brush->Color = clPurple;

		points[0] = Point(575, y - 76); // y = 430
		points[1] = Point(615, y - 6); // y = 500
		points[2] = Point(615, y + 93); // y = 599
		points[3] = Point(575, y + 74); // y = 580

		Canvas->Polygon(points, 3);

		// polygon 3 -----------------------------------------------------------

		points[0] = Point(499, y - 76); // y = 430
		points[1] = Point(459, y - 6); // y = 500
		points[2] = Point(459, y + 93); // y = 599
		points[3] = Point(499, y + 74); // y = 580

		Canvas->Polygon(points, 3);

		// flame ---------------------------------------------------------------

		Canvas->Pen->Color = clRed;
		Canvas->Brush->Color = clRed;

		points[0] = Point(500, y + 75); // y = 581
		points[1] = Point(490, y + 104); // y = 610
		points[2] = Point(515, y + 94); // y = 600
		points[3] = Point(537, y + 124); // y = 630
		points[4] = Point(559, y + 94); // y = 600
		points[5] = Point(584, y + 104); // y = 610
		points[6] = Point(574, y + 75); // y = 581

		Canvas->Polygon(points, 6);
	}

	void hide(TCanvas *Canvas) {
		Canvas->Pen->Color = clWhite;
		Canvas->Brush->Color = clWhite;
		Canvas->Rectangle(x - r, y + 75, x + 75, y - r);

		// polygon 2 hide ------------------------------------------------------

		TPoint points[7];

		points[0] = Point(575, y - 76); // y = 430
		points[1] = Point(615, y - 6); // y = 500
		points[2] = Point(615, y + 93); // y = 599
		points[3] = Point(575, y + 74); // y = 580

		Canvas->Polygon(points, 3);

		// polygon 3 hide ------------------------------------------------------

		points[0] = Point(499, y - 76); // y = 430
		points[1] = Point(459, y - 6); // y = 500
		points[2] = Point(459, y + 93); // y = 599
		points[3] = Point(499, y + 74); // y = 580

		Canvas->Polygon(points, 3);

		// flame hide ----------------------------------------------------------

		Canvas->Pen->Color = clWhite;
		Canvas->Brush->Color = clWhite;

		points[0] = Point(500, y + 75); // y = 581
		points[1] = Point(490, y + 104); // y = 610
		points[2] = Point(515, y + 94); // y = 600
		points[3] = Point(537, y + 124); // y = 630
		points[4] = Point(559, y + 94); // y = 600
		points[5] = Point(584, y + 104); // y = 610
		points[6] = Point(574, y + 75); // y = 581

		Canvas->Polygon(points, 6);
	}
};

// ---------------------------------------------------------------------------
class TForm1 : public TForm {
__published: // IDE-managed Components
	TImage *Image1;
	TTimer *Timer1;

	void __fastcall Timer1Timer(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm1(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
