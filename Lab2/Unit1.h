//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TCheckBox *CheckBoxAddStudent;
    TEdit *EditName;
    TEdit *EditSpecialty;
    TEdit *EditGroup;
    TRadioGroup *RadioGroupTypeOfTraining;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TEdit *EditMath;
    TEdit *EditProga;
    TEdit *EditPhilosophy;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *Label7;
    TButton *ButtonAddStudent;
    TButton *ButtonRemoveStudent;
    TButton *ButtonOpenFile;
    TButton *ButtonSaveDialog;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TListBox *ListBox1;
    TLabel *Label8;
    TPanel *Panel1;
    TLabel *Label9;
    TRadioGroup *RadioGroupTypeOfTraining2;
    TComboBox *ComboBoxSort;
    TEdit *EditSortParameter;
    TButton *btnClearSortList;
    TLabel *Label10;
    TLabel *labelff23;
    TTimer *Timer1;
    TLabel *LabelAverageMark;
    TButton *btnSortList;
    TRadioGroup *RadioGroupAverageMark;
    TButton *Button1;
    void __fastcall CheckBoxAddStudentClick(TObject *Sender);
    void __fastcall ListBox1Click(TObject *Sender);
    void __fastcall ButtonRemoveStudentClick(TObject *Sender);
    void __fastcall ButtonOpenFileClick(TObject *Sender);
    void __fastcall ButtonSaveDialogClick(TObject *Sender);
    void __fastcall ButtonAddStudentClick(TObject *Sender);
    void __fastcall btnSortListClick(TObject *Sender);
    void __fastcall btnClearSortListClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
