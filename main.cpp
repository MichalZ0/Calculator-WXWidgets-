// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <math.h>
#include <string>
#include <sstream>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

void CheckForZero();
void GetRidOfZeros();
void CommaWithoutNumber();
void Add(); 
int NumberAmount(); 

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
	void Delete(wxCommandEvent& event);
	void Negate(wxCommandEvent& event);
	void OnSize(wxSizeEvent& event); 
	void OnClick(wxKeyEvent& event); 
	void OnRelease(wxKeyEvent& event); 
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
	ID_Subtraction = 18,
	ID_Delete = 19

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
EVT_BUTTON(ID_ButtonNegate, MyApp::Negate)
EVT_BUTTON(ID_ButtonComma, MyApp::Comma)
EVT_BUTTON(ID_Delete, MyApp::Delete)
EVT_KEY_DOWN(MyApp::OnClick)
EVT_SIZE(MyApp::OnSize)
EVT_KEY_UP(MyApp::OnRelease)
//EVT_MAXIMIZE(MyApp::OnFullscreen)


wxEND_EVENT_TABLE()



wxIMPLEMENT_APP(MyApp);

std::string NumberArray = "0", NumberArray2;
char Operator = 0;
float number1 = 0, number2 = 0;
int NumbersAfterComma = 0;
int CommaPosition = 0;
wxStaticText* text;
std::ostringstream ss;
wxWindow* window;
int fontSize = 20; 
bool ShiftPressed = false;
wxSize currentSize = wxSize(384, 466); 
bool Update = false; 
wxSizer* windowSizer; 

bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame("Hello World", ID_Frame, wxPoint(0, 0), wxDefaultSize);
	
	window = new wxWindow(frame, ID_Window, wxPoint(0, 0), wxDefaultSize);
	window->SetClientSize(wxSize(384, 466));
	window->SetEvtHandlerEnabled(true); 
	
	wxFont font = wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
	
	text = new wxStaticText(window, ID_Text, NumberArray, wxDefaultPosition, wxDefaultSize);
	text->SetFont(font); 
	window->SetFont(font);

	wxGridSizer* buttonSizer = new wxGridSizer(4, 4, 1);
	wxBoxSizer* textSizer = new wxBoxSizer(wxHORIZONTAL); 
	windowSizer = new wxBoxSizer(wxVERTICAL); 

	wxButton* button_7 = new wxButton(window, ID_Button7, "7", wxDefaultPosition, wxDefaultSize); 
	wxButton* button_8 = new wxButton(window, ID_Button8, "8", wxDefaultPosition, wxDefaultSize); 
	wxButton* button_9 = new wxButton(window, ID_Button9, "9", wxDefaultPosition, wxDefaultSize); 

	wxButton* button_4 = new wxButton(window, ID_Button4, "4", wxDefaultPosition, wxDefaultSize);
	wxButton* button_5 = new wxButton(window, ID_Button5, "5", wxDefaultPosition, wxDefaultSize);
	wxButton* button_6 = new wxButton(window, ID_Button6, "6", wxDefaultPosition, wxDefaultSize);

	wxButton* button_1 = new wxButton(window, ID_Button1, "1", wxDefaultPosition, wxDefaultSize); 
	wxButton* button_2 = new wxButton(window, ID_Button2, "2",  wxDefaultPosition, wxDefaultSize);
	wxButton* button_3 = new wxButton(window, ID_Button3, "3", wxDefaultPosition, wxDefaultSize);

	wxButton* button_negate = new wxButton(window, ID_ButtonNegate, "+/-", wxDefaultPosition, wxDefaultSize);
	wxButton* button_0 = new wxButton(window, ID_Button0, "0", wxDefaultPosition, wxDefaultSize);
	wxButton* button_comma = new wxButton(window, ID_ButtonComma, ",", wxDefaultPosition, wxDefaultSize);

	wxButton* button_result = new wxButton(window, ID_ButtonResult, '=', wxDefaultPosition, wxDefaultSize);
	wxButton* button_add = new wxButton(window, ID_ButtonAdd, "+", wxDefaultPosition, wxDefaultSize);
	wxButton* button_subtr = new wxButton(window, ID_Subtraction, "-", wxDefaultPosition, wxDefaultSize);

	wxButton* del = new wxButton(window, ID_Delete, "<-", wxDefaultPosition, wxDefaultSize);


	
	textSizer->Add(text, 1, wxALIGN_CENTER, 1);
	
	buttonSizer->Add(button_7, 1, wxEXPAND, 1);
	buttonSizer->Add(button_8, 1, wxEXPAND, 1);
	buttonSizer->Add(button_9, 1, wxEXPAND, 1);
	buttonSizer->Add(del, 1, wxEXPAND, 1);
	
	buttonSizer->Add(button_4, 1, wxEXPAND, 1);
	buttonSizer->Add(button_5, 1, wxEXPAND, 1);
	buttonSizer->Add(button_6, 1, wxEXPAND, 1);
	buttonSizer->Add(button_subtr, 1, wxEXPAND, 1);
	
	buttonSizer->Add(button_1, 1, wxEXPAND, 1); 
	buttonSizer->Add(button_2, 1, wxEXPAND, 1);
	buttonSizer->Add(button_3, 1, wxEXPAND, 1);
	buttonSizer->Add(button_add, 1, wxEXPAND, 1);
	
	buttonSizer->Add(button_negate, 1, wxEXPAND, 1);
	buttonSizer->Add(button_0, 1, wxEXPAND, 1);
	buttonSizer->Add(button_comma, 1, wxEXPAND, 1);
	buttonSizer->Add(button_result, 1, wxEXPAND, 1);

	
	windowSizer->Add(textSizer, 1, wxEXPAND, 1);
	windowSizer->Add(buttonSizer, 6, wxEXPAND, 1);  
	window->SetSizerAndFit(windowSizer); 

	frame->SetMinSize(wxSize(320, 505)); 
	window->SetMinSize(wxSize(320, 505)); 

	frame->Show(true);
	return true;
}
MyFrame::MyFrame(const wxString& title, wxWindowID id, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, id, title, pos, size)
{
	
};

void MyApp::OnButtonPressed0(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("0");
		/*NumberArray[PointToNumber] = '0';*/

		text->wxStaticText::SetLabel(NumberArray);
	}
}

void MyApp::OnButtonPressed1(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("1");

		text->wxStaticText::SetLabel(NumberArray);

	}
}

void MyApp::OnButtonPressed2(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("2");


		text->wxStaticText::SetLabel(NumberArray);

	}
}

void MyApp::OnButtonPressed3(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("3");

		text->wxStaticText::SetLabel(NumberArray);

	}
}

void MyApp::OnButtonPressed4(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("4");

		text->wxStaticText::SetLabel(NumberArray);

	}
}

void MyApp::OnButtonPressed5(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("5");

		text->wxStaticText::SetLabel(NumberArray);

	}
}

void MyApp::OnButtonPressed6(wxCommandEvent& event)
{

	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("6");

		text->wxStaticText::SetLabel(NumberArray);
	}
}

void MyApp::OnButtonPressed7(wxCommandEvent& event)
{

	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("7");

		text->wxStaticText::SetLabel(NumberArray);

	}
}

void MyApp::OnButtonPressed8(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("8");

		text->wxStaticText::SetLabel(NumberArray);

	}
}

void MyApp::OnButtonPressed9(wxCommandEvent& event)
{
	if (NumberAmount())
	{
		CheckForZero();

		NumberArray.append("9");

		text->wxStaticText::SetLabel(NumberArray);

	}
}

void Add()
{
	if (NumberArray.find(Operator, 1) != std::string::npos)
	{
		NumberArray.pop_back(); 
	}

		Operator = '+';

		number1 = std::stof(NumberArray);

		CommaPosition = NumberArray.find(".");

		if (NumberArray.length() - CommaPosition - 1 > NumbersAfterComma)
			NumbersAfterComma = NumberArray.length() - CommaPosition - 1;

		NumberArray.append("+");

		text->wxStaticText::SetLabel(NumberArray);

	
	
}

void MyApp::Addition(wxCommandEvent& event)
{
	Add(); 
}

void Res()
{
	int OperatorPos = NumberArray.find(Operator, 1);
	
	if (number1 != std::stof(NumberArray))
	{
		return; 
	}

	if (Operator == 0 || (NumberArray.length() - 1 == NumberArray.find(Operator, 1)))
	{ 
		return; 
	}
	
	if (OperatorPos != std::string::npos)
	{
		NumberArray2 = NumberArray.substr(OperatorPos + 1);
		number2 = std::stof(NumberArray2);
	}

	if (Operator == '+')
		number1 += number2;

	if (Operator == '-')
		number1 -= number2;

	NumberArray.erase();

	ss << number1;
	NumberArray = ss.str();

	ss.str("");
	ss.clear();

	text->wxStaticText::SetLabel(NumberArray);

}

void MyApp::Result(wxCommandEvent& event)
{
	Res(); 
}

void Sub()
{
					if (NumberArray.find(Operator, 1) != std::string::npos)
					{
						NumberArray.pop_back(); 
					}
		
					Operator = '-';

					number1 = std::stof(NumberArray);

					CommaPosition = NumberArray.find(".");

					if (NumberArray.length() - CommaPosition - 1 > NumbersAfterComma)
						NumbersAfterComma = NumberArray.length() - CommaPosition - 1;

					
					NumberArray.append("-");

					text->wxStaticText::SetLabel(NumberArray);

	
}

void MyApp::Subtraction(wxCommandEvent& event)
{
	Sub(); 
}

void com()
{
	if (NumberArray.find(Operator) != std::string::npos && Operator != 0)
	{
		if (NumberArray.find(".", NumberArray.find(Operator)) != std::string::npos)
		{
			return;
		}
	}

	else
	{
		if (NumberArray.find(".") != std::string::npos)
		{
			return;
		}
	}

	if (Operator != 0 && NumberArray.find(Operator) == std::string::npos && NumberArray.find(".") != std::string::npos)
	{
		wxSafeShowMessage("Test", "Test"); 
		return; 
	}


	CommaWithoutNumber();

	NumberArray.append(".");

	text->wxStaticText::SetLabel(NumberArray);
}

void MyApp::Comma(wxCommandEvent& event)
{
	com(); 
}

void MyApp::Delete(wxCommandEvent& event)
{
	if (NumberArray.length() == 1)
	{
		NumberArray.pop_back();
		NumberArray.append("0");
		text->wxStaticText::SetLabel(NumberArray);
	}

	if (NumberArray.length() > 1)
	{
		NumberArray.pop_back();
		text->wxStaticText::SetLabel(NumberArray);
	}
}

void MyApp::Negate(wxCommandEvent& event)
{
	float ConvertedNum = std::stof(NumberArray);
	if (ConvertedNum != 0)
	{
		if (NumberArray[0] != '-' && NumberArray.find(Operator, 1) == std::string::npos)
		{
			NumberArray.insert(0, "-");  
		}
		else if (NumberArray[0] == '-' && NumberArray.find(Operator, 1) == std::string::npos && Operator != 0)
		{
			NumberArray.erase(0, 1); 
		}

		else if (NumberArray.find(Operator, 1) != std::string::npos && NumberArray.find(Operator, 1) != 0 && Operator != 0)
		{
			if (Operator == '-')
			{
				NumberArray[NumberArray.find(Operator, 1)] = '+';
				Operator = '+'; 
			}
			else
			{
				NumberArray[NumberArray.find(Operator, 1)] = '-';
				Operator = '-';
			}
		}
	}
	text->wxStaticText::SetLabel(NumberArray); 


}

void MyApp::OnSize(wxSizeEvent& event)
{
	 
	if (event.GetEventObject() == window && text != nullptr)
	{
		if ((event.GetSize()).GetWidth() >= 320-16)
		{
			int interval = (event.GetSize()).GetWidth() / 384;
			fontSize = 20 + (interval * 5);
			/*wxSafeShowMessage("font size", std::to_string(fontSize));*/

			wxFont f = text->GetFont();
			f.SetPointSize(fontSize);
			text->SetFont(f);

			windowSizer->Layout(); 


		}
		else
		{
			return;
		}


	}
}

void CheckForZero()
{
	// Forbid multiple zeros on the beginning
	if (NumberArray[0] == '0' && NumberArray[1] != '.' && NumberArray.find(Operator) != 1)
	{
		NumberArray.pop_back(); 
	}
	else if (NumberArray.find(Operator) != std::string::npos && NumberArray.length() >= NumberArray.find(Operator) + 2)
	{
		if (NumberArray[NumberArray.find(Operator) + 1] == '0' && NumberArray[NumberArray.find(Operator) + 2] != '.')
		{
			NumberArray.pop_back(); 
		}
	}
}

void CommaWithoutNumber()
{
	int pos = NumberArray.find(Operator);
	int len = NumberArray.length();
	if (pos != std::string::npos)
	{
		if (len - pos == 1)
		{
			NumberArray.append("0");

		}
	}
}

void Test()
{
	wxSafeShowMessage("Test", "Hallo"); 
}

void MyApp::OnClick(wxKeyEvent& event)
{
	int keyPressed = event.GetKeyCode() - 48;

	if (event.GetKeyCode() == WXK_SHIFT && ShiftPressed == false)
	{
		ShiftPressed = true; 
		return; 
	}
	if (ShiftPressed == true)
	{
		if (event.GetKeyCode() == 61)
		{
			Add(); 
		}   
	}
	else
	{
		if (event.GetKeyCode() == 61)
		{
			Res(); 
		}

	}

	if (event.GetKeyCode() == WXK_RETURN)
	{
		Res(); 
	}

	if (event.GetKeyCode() == 45)
	{
		Sub(); 
	}
	
	if (event.GetKeyCode() == 44)
	{
		com(); 
	}
	
	if (keyPressed + 48>= 48 && keyPressed + 48 <= 57)
	{
		if (NumberAmount())
		{
			CheckForZero();
			std::string key = std::to_string(keyPressed); 
			NumberArray.append(key);
			text->wxStaticText::SetLabel(NumberArray);
		}
	}

	if (event.GetKeyCode() == WXK_BACK)
	{
		if (NumberArray.length() == 1)
		{
			NumberArray.pop_back();
			NumberArray.append("0");
			text->wxStaticText::SetLabel(NumberArray);
		}

		if (NumberArray.length() > 1)
		{
			NumberArray.pop_back();
			text->wxStaticText::SetLabel(NumberArray);
		}
	}	
}

void MyApp::OnRelease(wxKeyEvent& event)
{
	if (event.GetKeyCode() == WXK_SHIFT)
	{
		ShiftPressed = false; 
	}
}


int NumberAmount()
{
	if (NumberArray.find(Operator, 1) == std::string::npos)
	{
		if (NumberArray[0] == '-' && NumberArray.length() < 6)
		{
			return 1; 
		}
		else if (NumberArray.length() > 4)
		{
			return 0;
		}
	}

	else if (NumberArray.find(Operator, 1) != std::string::npos && NumberArray.length() - NumberArray.find(Operator, 1) - 1 > 4)
	{
		return 0; 
	}

	else
	{
		return 1; 
	}
}



