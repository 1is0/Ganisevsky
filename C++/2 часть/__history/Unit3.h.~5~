//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TRadioGroup *Color;
	TRadioGroup *Object;
	TButton *Button1;
	TButton *Button3;
	TButton *Button4;
	TEdit *Edit1;
	TRadioGroup *BrushColor;
	TLabel *ID;
	TLabel *angle;
	TEdit *angle1;
	TTimer *Timer1;
	TButton *Button2;
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ObjectClick(TObject *Sender);
	void __fastcall ColorClick(TObject *Sender);
	void __fastcall DrawFigure(TObject *Sender, int X, int Y);
	void __fastcall ClearPoligon(int DeleteItem);
	void __fastcall PoligonFigure();
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall info(int FigureItem);
	void __fastcall CenterLabel(int CenterX,int CenterY, int FigureItem);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Hide(TObject *Sender, int FigureItem);
	void __fastcall BuildLabel(int FirstX,int FirstY, int FigureItem);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall ClearHelp(TPoint *pnt, int FigureItem);
	void __fastcall move(int MoveX, int MoveY);
	void __fastcall BrushColorClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall DeleteLabel(int FigureItem);
	void __fastcall FindCenter(int FigureItem);
	void __fastcall infoElipce (int FigureItem);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall ComponentColor(TObject *Sender, int FigureItem);
	void __fastcall SaveColor(int FigureItem);
	void __fastcall Button2Click(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
