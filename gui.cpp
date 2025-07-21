// #include <wx/wx.h>
// #include <wx/textctrl.h>
// #include <wx/filedlg.h>
// #include <wx/msgdlg.h>

// class MyApp : public wxApp
// {
// public:
//     virtual bool OnInit();
// };

// class MyFrame : public wxFrame
// {
// public:
//     MyFrame(const wxString &title);

// private:
//     void OnOpen(wxCommandEvent &event);
//     void OnSave(wxCommandEvent &event);

//     wxTextCtrl *textCtrl;

//     wxDECLARE_EVENT_TABLE();
// };

// enum
// {
//     ID_Open = 1,
//     ID_Save
// };

// wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
//     EVT_MENU(ID_Open, MyFrame::OnOpen)
//         EVT_MENU(ID_Save, MyFrame::OnSave)
//             wxEND_EVENT_TABLE()

//                 IMPLEMENT_APP(MyApp)

//                     bool MyApp::OnInit()
// {
//     MyFrame *frame = new MyFrame("Simple Text Editor");
//     frame->Show(true);
//     return true;
// }

// MyFrame::MyFrame(const wxString &title) : wxFrame(NULL, wxID_ANY, title)
// {
//     // Create menu bar
//     wxMenuBar *menuBar = new wxMenuBar();

//     // Create file menu
//     wxMenu *fileMenu = new wxMenu();
//     fileMenu->Append(ID_Open, "&Open\tCtrl-O", "Open a file");
//     fileMenu->Append(ID_Save, "&Save\tCtrl-S", "Save the file");

//     menuBar->Append(fileMenu, "&File");
//     SetMenuBar(menuBar);

//     // Create text control
//     textCtrl = new wxTextCtrl(this, wxID_ANY, "",
//                               wxDefaultPosition,
//                               wxDefaultSize,
//                               wxTE_MULTILINE | wxTE_PROCESS_ENTER);
// }

// void MyFrame::OnOpen(wxCommandEvent &event)
// {
//     wxFileDialog openFileDialog(this, "Open file", "", "",
//                                 "Text files (*.txt)|*.txt|All files (*.*)|*.*",
//                                 wxFD_OPEN | wxFD_FILE_MUST_EXIST);

//     if (openFileDialog.ShowModal() == wxID_OK)
//     {
//         wxString path = openFileDialog.GetPath();
//         wxTextFile file(path);
//         if (file.Open())
//         {
//             textCtrl->SetValue(file.GetFirstLine());
//             while (!file.Eof())
//             {
//                 textCtrl->AppendText("\n" + file.GetNextLine());
//             }
//             file.Close();
//         }
//         else
//         {
//             wxMessageBox("Could not open file!", "Error", wxOK | wxICON_ERROR);
//         }
//     }
// }

// void MyFrame::OnSave(wxCommandEvent &event)
// {
//     wxFileDialog saveFileDialog(this, "Save file", "", "",
//                                 "Text files (*.txt)|*.txt|All files (*.*)|*.*",
//                                 wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

//     if (saveFileDialog.ShowModal() == wxID_OK)
//     {
//         wxString path = saveFileDialog.GetPath();
//         if (textCtrl->SaveFile(path))
//         {
//             // File saved successfully
//         }
//         else
//         {
//             wxMessageBox("Could not save file!", "Error", wxOK | wxICON_ERROR);
//         }
//     }
// }