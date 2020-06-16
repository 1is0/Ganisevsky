object Form1: TForm1
  Left = 549
  Top = 247
  Caption = 'Rocket'
  ClientHeight = 505
  ClientWidth = 801
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 801
    Height = 505
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 768
    Top = 472
  end
end
