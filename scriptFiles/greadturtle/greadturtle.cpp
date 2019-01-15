// Author: Marek K.

/*

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Dieses Programm ist Freie Software: Sie koennen es unter den Bedingungen
    der GNU General Public License, wie von der Free Software Foundation,
    Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
    veroeffentlichten Version, weiter verteilen und/oder modifizieren.

    Dieses Programm wird in der Hoffnung bereitgestellt, dass es nuetzlich sein wird, jedoch
    OHNE JEDE GEWAEHR,; sogar ohne die implizite
    Gewaehr der MARKTFAEHIGKEIT oder EIGNUNG FUER EINEN BESTIMMTEN ZWECK.
    Siehe die GNU General Public License fuer weitere Einzelheiten.

    Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
    Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
	
*/

#include <wx/wxprec.h>
#include <wx/string.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <wx/gdicmn.h>
#include <wx/filedlg.h>
#include <wx/listbox.h>
#include <wx/panel.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "greadturtle.hpp"
#include "turtlescript.hpp"

IMPLEMENT_APP(greadturtle)

MainFrame::MainFrame() : wxFrame((wxFrame *) nullptr, wxID_ANY, "greadturtle")
{
    SetInitialSize(wxSize(500, 500));
    
    wxMenu * menuFile = new wxMenu;
    menuFile->Append(ID_OPEN, "&Open\tCTRL-O", "Open a file");
    menuFile->Append(ID_CLOSE, "&Close", "Close a file");
    menuFile->AppendSeparator();
    menuFile->Append(ID_EXIT, "&Exit\tALT-F4", "Exit the program");
    
    wxMenu * menuHelp = new wxMenu;
    menuHelp->Append(ID_DATATYPES, "&Data types", "Show data types fo turtlescript");
    menuHelp->Append(ID_ABOUT, "&About", "About");
    
    wxMenuBar * menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    
    Bind(wxEVT_MENU, MainFrame::OnOpen, this, ID_OPEN);
    Bind(wxEVT_MENU, MainFrame::OnClose, this, ID_CLOSE);
    Bind(wxEVT_MENU, MainFrame::OnExit, this, ID_EXIT);
    Bind(wxEVT_MENU, MainFrame::OnDatatypes, this, ID_DATATYPES);
    Bind(wxEVT_MENU, MainFrame::OnAbout, this, ID_ABOUT);
    
    SetMenuBar(menuBar);
    
    wxPanel * mainPane = new wxPanel(this, -1);
    wxBoxSizer * sizer = new wxBoxSizer(wxHORIZONTAL);
    item_list = new wxListBox(mainPane, ID_LISTBOX, wxPoint(-1, -1), wxSize(-1, -1));
    sizer->Add(item_list, 3, wxEXPAND | wxALL, 20);
    
    Connect(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, 
      wxCommandEventHandler(MainFrame::OnDoubleClick));

    mainPane->SetSizer(sizer);
    
    CreateStatusBar();
    SetStatusText("No file");
}

void MainFrame::OnOpen(wxCommandEvent &)
{
    wxString filename, res;
    wxFileDialog fdia(this, "Open turtlescript file", "", "",
                        "turtlescript file (*.tur)|*.tur|All files (*.*)|*",
                        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    
    if(fdia.ShowModal() != wxID_OK)
    {
        wxMessageBox("Error", "Error", wxOK | wxICON_ERROR);
        return;
    }
    
    filename = fdia.GetPath();
    
    wxFileInputStream in(filename);
    wxTextInputStream txt(in);
    
    while(in.IsOk() && ! in.Eof())
    {
        res += txt.ReadLine() + "\n";
    }
    
    turtlescript::eval(std::string(res.c_str()));
    
    SetStatusText(filename);
    
    //wxMessageBox(wxString(turtlescript::context("$test")), "Output", wxOK | wxICON_INFORMATION);
    
    for(std::string str : turtlescript::stack()->name)
    {
        //wxMessageBox(wxString(str.c_str()), "Output", wxOK | wxICON_INFORMATION);
        item_list->Append(wxString(str.c_str()));
    }
}

void MainFrame::OnClose(wxCommandEvent &)
{
    item_list->Clear();
    turtlescript::clear();
    SetStatusText("No file");
}

void MainFrame::OnExit(wxCommandEvent &)
{
    Close(true);
}

void MainFrame::OnDoubleClick(wxCommandEvent &)
{
    wxString type;
    
    switch(turtlescript::stack()->type[item_list->GetSelection()])
    {
        case 1: type = "INTEGER"; break;
        case 2: type = "BOOLEAN"; break;
        case 3: type = "STRING"; break;
        case 4: type = "BIGNUM"; break;
        case 5: type = "BYTE"; break;
        case 6: type = "FLOAT"; break;
    }
    
    wxMessageBox(
        wxString("Name: ") + wxString(turtlescript::stack()->name[
        item_list->GetSelection()]) +
        wxString("\nValue: ") + wxString(turtlescript::context("$" + std::string(
        item_list->GetString(item_list->GetSelection()).c_str()) ).c_str()) +
        wxString("\nType: ") + type, "Data", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnDatatypes(wxCommandEvent &)
{
    wxMessageBox("TYPES     ---  ID\n"
                 "INTEGER   ---  1\n"
                 "BOOLEAN   ---  2\n"
                 "STRING    ---  3\n"
                 "BIGNUM    ---  4\n"
                 "BYTE      ---  5\n"
                 "FLOAT     ---  6", "Data types", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnAbout(wxCommandEvent &)
{
    wxMessageBox("greadturtlescript is a program written by Marek K. on 28/11/2018 in the C++ "
                 "programming language using C++ Boost Library and wxWidgets Libraray.\n"
                 "The program is available under the GNU GPL v3.\n"
                 "\n"
                 "This reads out a turtlescript file and returns all variables names in a list.\n"
                 "Double-clicking a variable name displays the name, content, and type of a variable.", "About", wxOK | wxICON_INFORMATION);
}

bool greadturtle::OnInit()
{
    MainFrame * frame = new MainFrame();
    frame->Show(true);
    
    return true;
}
greadturtle &app = ::wxGetApp();