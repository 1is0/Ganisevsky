// ---------------------------------------------------------------------------
#include <tchar.h>

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

// class Line A(600, 600, 10);
class Rocket B(500, 506, 10);

void __fastcall TForm1::Timer1Timer(TObject *Sender) {
	B.hide(Image1->Canvas);
	B.move(Image1->Canvas);
	B.show(Image1->Canvas);
}
// ---------------------------------------------------------------------------
