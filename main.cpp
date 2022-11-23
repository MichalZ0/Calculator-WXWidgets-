// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <math.h>
#include <string>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

void CheckForZero(); 
void GetRidOfZeros();

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
private:
	void OnButtonPressed0(wxCommandEvent& event);
	void OnButtonPressed1(wxCommandEvent& event);
	void OnButtonPressed2(wxCommandEvent& event);
	void OnButtonPressed3(wxCommandEvent& event);
	void OnButtonPressed4(wxCommandEvent& event);
	void OnButtonPressed5(wxCommandEvent& event);
	void OnButtonPressed6(wxCommandEvent& event);
	void OnButtonPressed7(wxCommandEvent& event);
	void OnButtonPressed8(wxCommandEvent& event);
	void OnButtonPressed9(wxCommandEvent& event);
	void Comma(wxCommandEvent& event);
	void Addition(wxCommandEvent& event);
	void Subtraction(wxCommandEvent& event);
	void Result(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();

};

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, wxWindowID id, const wxPoint& pos, const wxSize& size);
};


enum
{
	ID_Frame = 1,
	ID_Window = 2,
	ID_Button0 = 3,
	ID_Button1 = 4,
	ID_Button2 = 5,
	ID_Button3 = 6,
	ID_Button4 = 7,
	ID_Button5 = 8,
	ID_Button6 = 9,
	ID_Button7 = 10,
	ID_Button8 = 11,
	ID_Button9 = 12,
	ID_ButtonAdd = 13,
	ID_ButtonResult = 14,
	ID_ButtonNegate = 15,
	ID_ButtonComma = 16,
	ID_Text = 17,
	ID_Subtraction = 18

};


wxBEGIN_EVENT_TABLE(MyApp, wxApp)
EVT_BUTTON(ID_Button0, MyApp::OnButtonPressed0)
EVT_BUTTON(ID_Button1, MyApp::OnButtonPressed1)
EVT_BUTTON(ID_Button2, MyApp::OnButtonPressed2)
EVT_BUTTON(ID_Button3, MyApp::OnButtonPressed3)
EVT_BUTTON(ID_Button4, MyApp::OnButtonPressed4)
EVT_BUTTON(ID_Button5, MyApp::OnButtonPressed5)
EVT_BUTTON(ID_Button6, MyApp::OnButtonPressed6)
EVT_BUTTON(ID_Button7, MyApp::OnButtonPressed7)
EVT_BUTTON(ID_Button8, MyApp::OnButtonPressed8)
EVT_BUTTON(ID_Button9, MyApp::OnButtonPressed9)
EVT_BUTTON(ID_ButtonResult, MyApp::Result)
EVT_BUTTON(ID_ButtonAdd, MyApp::Addition)
EVT_BUTTON(ID_Subtraction, MyApp::Subtraction)
EVT_BUTTON(ID_ButtonNegate, MyApp::OnButtonPressed0)
EVT_BUTTON(ID_ButtonComma, MyApp::Comma)
wxEND_EVENT_TABLE()



wxIMPLEMENT_APP(MyApp);

std::string NumberArray = "0", NumberArray2;
char Operator;
float number1 = 0, number2 = 0, numberResult=0; 
int Number, LoopToPoint;
int PointToNumber = 0;
int FirstCommaPosition = 0, SecondCommaPosition = 0;
int GoToSecondNumber = 0; 
wxStaticText* text;
std::string* CurrentArray = &NumberArray; 

float ConvertToNumber(int StartingPoint, int EndingPoint, int CommaPos = 0)
{
	float result = 0;
	int power = 0;
	if (CommaPos > 0)
	{
		power = CommaPos - 1 - StartingPoint;
	}
	else
	{
		power = EndingPoint - StartingPoint;
	}

	for (StartingPoint; StartingPoint <= EndingPoint; StartingPoint++)
	{
		if (CommaPos != StartingPoint || StartingPoint == 0)
		{
			result += (NumberArray[StartingPoint] - 48) * pow(10, power);
			power--;

		}
	}

	return result;
}

bool MyApp::OnInit()
{

	MyFrame* frame = new MyFrame("Hello World", ID_Frame, wxPoint(0, 0), wxSize(600, 885));
	wxWindow* window = new wxWindow(frame, ID_Window, wxPoint(0, 0), wxSize(450, 340));
	wxFont font = wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	window->SetFont(font);

	wxButton* button_7 = new wxButton(window, ID_Button7, "7", wxPoint(0, 250), wxSize(150, 150));
	wxButton* button_8 = new wxButton(window, ID_Button8, "8", wxPoint(150, 250), wxSize(150, 150));
	wxButton* button_9 = new wxButton(window, ID_Button9, "9", wxPoint(300, 250), wxSize(150, 150));

	wxButton* button_4 = new wxButton(window, ID_Button4, "4", wxPoint(0, 400), wxSize(150, 150));
	wxButton* button_5 = new wxButton(window, ID_Button5, "5", wxPoint(150, 400), wxSize(150, 150));
	wxButton* button_6 = new wxButton(window, ID_Button6, "6", wxPoint(300, 400), wxSize(150, 150));

	wxButton* button_1 = new wxButton(window, ID_Button1, "1", wxPoint(0, 550), wxSize(150, 150));
	wxButton* button_2 = new wxButton(window, ID_Button2, "2", wxPoint(150, 550), wxSize(150, 150));
	wxButton* button_3 = new wxButton(window, ID_Button3, "3", wxPoint(300, 550), wxSize(150, 150));

	wxButton* button_negate = new wxButton(window, ID_ButtonNegate, "+/-", wxPoint(0, 700), wxSize(150, 150));
	wxButton* button_0 = new wxButton(window, ID_Button0, "0", wxPoint(150, 700), wxSize(150, 150));
	wxButton* button_comma = new wxButton(window, ID_ButtonComma, ",", wxPoint(300, 700), wxSize(150, 150));

	wxButton* button_result = new wxButton(window, ID_ButtonResult, '=', wxPoint(450, 700), wxSize(150, 150));
	wxButton* button_add = new wxButton(window, ID_ButtonAdd, "+", wxPoint(450, 550), wxSize(150, 150));
	wxButton* button_subtr = new wxButton(window, ID_Subtraction, "-", wxPoint(450, 400), wxSize(150, 150));

	text = new wxStaticText(window, ID_Text, NumberArray, wxPoint(0, 0), wxSize(617, 60));



	frame->Show(true);
	return true;
}
MyFrame::MyFrame(const wxString& title, wxWindowID id, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, id, title, pos, size)
{
};

void MyApp::OnButtonPressed0(wxCommandEvent& event)
{
	if (NumberArray[0] == 48)
		NumberArray.pop_back();

	NumberArray.append("0"); 
	/*NumberArray[PointToNumber] = '0';*/
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed1(wxCommandEvent& event)
{
	CheckForZero();

	NumberArray.append("1"); 

	PointToNumber++;
	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed2(wxCommandEvent& event)
{
	CheckForZero();
	
	NumberArray.append("2");

	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed3(wxCommandEvent& event)
{
	CheckForZero();

	NumberArray.append("3");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed4(wxCommandEvent& event)
{
	CheckForZero();
	
	NumberArray.append("4");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed5(wxCommandEvent& event)
{
	CheckForZero();
	
	NumberArray.append("5");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed6(wxCommandEvent& event)
{
	
	CheckForZero();
	
	NumberArray.append("6");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed7(wxCommandEvent& event)
{
	
	CheckForZero();
	
	NumberArray.append("7");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed8(wxCommandEvent& event)
{
	CheckForZero();
	
	NumberArray.append("8");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::OnButtonPressed9(wxCommandEvent& event)
{
	CheckForZero();
	
	NumberArray.append("9");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);
}



void MyApp::Addition(wxCommandEvent& event)
{
	CheckForZero(); 
	
	Operator = '+';
	
	number1 = std::stof(NumberArray);


	NumberArray.append("+");
	PointToNumber++;

	text->wxStaticText::SetLabel(NumberArray);

	CurrentArray = &NumberArray2;
}

void MyApp::Result(wxCommandEvent& event)
{
	int OperatorPos = NumberArray.find(Operator);
	NumberArray2 = NumberArray.substr(OperatorPos+1); 
	
	number2 = std::stof(NumberArray2); 
	
	if (Operator == '+')
		numberResult = number1 + number2;

	if (Operator == '-')
		numberResult = number1 - number2; 

	NumberArray.erase();
	NumberArray = std::to_string(numberResult); 

	GetRidOfZeros(); 

	text->wxStaticText::SetLabel(NumberArray); 




}

void MyApp::Subtraction(wxCommandEvent& event)
{
	CheckForZero();
	
	Operator = '-';

	number1 = std::stof(NumberArray);

	NumberArray.append("-");

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::Comma(wxCommandEvent& event)
{
		if (GoToSecondNumber == 1)
		{
			SecondCommaPosition = PointToNumber;
			GoToSecondNumber++; 
		}

	    if (GoToSecondNumber == 0)
	    {
	        FirstCommaPosition = PointToNumber; 
	        GoToSecondNumber++;
	    }


	NumberArray.append(".");
	PointToNumber++;
	text->wxStaticText::SetLabel(NumberArray);

}

void CheckForZero()
{
	if (NumberArray[0] == 48)
	{
		NumberArray.pop_back(); 
	}

}

void GetRidOfZeros()
{
	for (int i = NumberArray.length() - 1; i > 0; i--)
	{
		if (NumberArray[i] == '0')
			NumberArray.pop_back();
		else if (NumberArray[i] == '.')
			NumberArray.pop_back();

		else
			return; 
	}
}

