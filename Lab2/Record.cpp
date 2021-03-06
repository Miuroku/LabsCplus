//---------------------------------------------------------------------------

#pragma hdrstop

//#include "Record.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

#include "Record.h"

using namespace std;

extern  char sepor;
extern char space;
extern AnsiString StudyTypePaid;
extern AnsiString StudyTypeFree;

Record getRecord(){
	Record tmp;

    //Trim() - delete unneccecuary probels.
	tmp.Name = Form1->EditName->Text.Trim();
	if(tmp.Name.Length() == 0){
		ShowMessage("������� ��� ��������");
		throw 0;
	}    
    
    
	if(Form1->RadioGroupTypeOfTraining->ItemIndex == 0){
        tmp.TypeOfTraining = StudyTypePaid;
    }
	else if(Form1->RadioGroupTypeOfTraining->ItemIndex == 1){
         tmp.TypeOfTraining = StudyTypeFree;
    }
    else if (Form1->RadioGroupTypeOfTraining->ItemIndex == -1) {
         ShowMessage("�������� ����� ��������");         
         throw 0;
    }           
	else {
		ShowMessage("�������� ����� ��������");
		throw 0;
	}

    tmp.Specialty = Form1->EditSpecialty->Text.Trim();
    if(tmp.Specialty.Length() == 0){
         ShowMessage("������� �������������");
         throw 0;
    }
    
	try {
		tmp.Group = StrToInt(Form1->EditGroup->Text);
		if(tmp.Group < 0) ShowMessage("����������� ������ ����� ������");
	} catch (...) {
		ShowMessage("������� ����� ������");
		throw 0;
	}

	try {
		tmp.Math= StrToFloat(Form1->EditMath->Text);
        if (tmp.Math<0 || tmp.Math>10) {
           ShowMessage("����������� ������ ����");
           throw 0;    
        }
	} catch (...) {
		ShowMessage("������� ������ �� ����������");
		throw 0;
	}

    try {
		tmp.Proga = StrToFloat(Form1->EditProga->Text);
        if (tmp.Proga<0 || tmp.Proga>10) {
           ShowMessage("����������� ������ ����");
           throw 0;    
        }
	} catch (...) {
		ShowMessage("������� ������ �� ����������������");
		throw 0;
	}

    try {
		tmp.Philosophy= StrToFloat(Form1->EditPhilosophy->Text);
        if (tmp.Philosophy<0 || tmp.Philosophy>10) {
           ShowMessage("����������� ������ ����");
        }
	} catch (...) {
		ShowMessage("������� ������ �� ���������");
		throw 0;
	}

    tmp.AverageMark = ((float)(tmp.Math + tmp.Philosophy + tmp.Proga))/3.0;
    Form1->LabelAverageMark->Caption = tmp.AverageMark;
    
	return tmp;
}

AnsiString FormatRecord(int ind){

    AnsiString tmpString;
    Record tmp;
    MyItems[ind] = tmp;

    tmpString = tmp.Name + space + sepor + space + tmp.TypeOfTraining + space + sepor +
                space + tmp.Specialty + space + sepor + space + tmp.Group + space + sepor +
                space + tmp.AverageMark + space + sepor;                     
    
	return tmpString;
}

AnsiString FormatRecord(Record tmp){
    AnsiString tmpString;

    tmpString = tmp.Name + space + sepor + space + tmp.TypeOfTraining + space + sepor +
                space + tmp.Specialty + space + sepor + space + tmp.Group + space + sepor +
                space + tmp.AverageMark + space + sepor;                    
    
	return tmpString;
}

Record FromStringToRecord(AnsiString ourStr){
       Record tmp;
       int i = 1;
       AnsiString tmpNameStr = "";
       AnsiString tmpTypeStr = "";
       AnsiString tmpSpecialtyStr = "";
       AnsiString tmpGroup = "";
       AnsiString tmpAverageMark = "";
       while (true){
           if (ourStr[i+1] != sepor ) {
                 tmpNameStr += ourStr[i];
           }
           else if (ourStr[i] == space && ourStr[i+1] == sepor) {
                i += 3;
                break;
           }
           i++;           
       }
       tmp.Name = tmpNameStr;

       while(true){
           if(ourStr[i+1] != sepor){
               tmpTypeStr += ourStr[i];
           }
           else if (ourStr[i] == space && ourStr[i+1] == sepor) {
                i += 3;
                break;
           }
           i++;
       }
       tmp.TypeOfTraining = tmpTypeStr;

       while(true){
           if(ourStr[i+1] != sepor){
               tmpSpecialtyStr += ourStr[i];
           }
           else if (ourStr[i] == space && ourStr[i+1] == sepor) {
                i += 3;
                break;
           }
           i++;
       }
       tmp.Specialty = tmpSpecialtyStr;

       while(true){
           if(ourStr[i+1] != sepor){
               tmpGroup += ourStr[i];
           }
           else if (ourStr[i] == space && ourStr[i+1] == sepor) {
                i += 3;
                break;
           }
           i++;
       }  
       tmp.Group = tmpGroup;

       while(true){
           if(ourStr[i+1] != sepor){
               tmpAverageMark += ourStr[i];
           }
           else if (ourStr[i] == space && ourStr[i+1] == sepor) {
                i += 3;
                break;
           }
           i++;
       }
       tmp.AverageMark = StrToInt(tmpAverageMark);
       

       
       return tmp;
}
