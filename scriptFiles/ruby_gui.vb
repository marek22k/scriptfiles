Imports System.Windows.Forms
Imports System.Drawing

Module ruby_gui

    ' The author and developer of this program is Marek K.
    ' download: http://test.mk16.de/scriptFiles/ruby_gui.exe
    ' source code: http://test.mk16.de/scriptFiles/ruby_gui.vb

    Dim MainWindow As Form = New Form
    Dim CodeBox As TextBox = New TextBox
    Dim RunButton As Button = New Button
    Dim RunWButton As Button = New Button

    Dim tmpFile As String = "program.rb"
    Dim comment As String = "# IDE: Ruby IDE GUI from test.mk16.de" & vbCrLf
    Dim icon As String = "ruby_gui.ico"

    Sub RunButton_ClickHandler()
        My.Computer.FileSystem.WriteAllText(tmpFile, "# IDE: Ruby IDE GUI from test.mk16.de" & vbCrLf & CodeBox.Text, False)

        Dim cmd As New ProcessStartInfo("cmd.exe")
        cmd.Arguments = "/k ruby " & tmpFile
        cmd.WindowStyle = ProcessWindowStyle.Normal
        Process.Start(cmd)
    End Sub

    Sub RunWButton_ClickHandler()
        My.Computer.FileSystem.WriteAllText(tmpFile, comment & CodeBox.Text, False)

        Dim cmd As New ProcessStartInfo("cmd.exe")
        cmd.Arguments = "/k rubyw " & tmpFile
        cmd.WindowStyle = ProcessWindowStyle.Minimized
        Process.Start(cmd)
    End Sub

    Sub MainWindow_LoadHandler()
        If (My.Computer.FileSystem.FileExists(tmpFile)) Then
            CodeBox.Text = Replace(My.Computer.FileSystem.ReadAllText(tmpFile), comment, "")
        End If
    End Sub

    Function Print(ByVal form As Form)
        If (form.Name = "MainWindow") Then
            form.Text = "Ruby IDE GUI"
            form.FormBorderStyle = FormBorderStyle.FixedDialog
            form.MaximizeBox = False
            form.StartPosition = FormStartPosition.CenterScreen
            form.ClientSize = New Drawing.Size(915, 505)

            If (My.Computer.FileSystem.FileExists(icon)) Then
                form.Icon = New Icon(icon)
            End If

            CodeBox.Multiline = True
            CodeBox.Location = New Point(1, 2)
            CodeBox.Size = New Size(800, 500)
            CodeBox.Text = "puts ""Hello World"""

            RunButton.Text = "Run"
            RunButton.Size = New Size(105, 35)
            RunButton.Location = New Point(805, 465)

            RunWButton.Text = "Run (Window)"
            RunWButton.Size = New Size(85, 20)
            RunWButton.Location = New Point(825, 445)

            form.Controls.Add(CodeBox)
            form.Controls.Add(RunButton)
            form.Controls.Add(RunWButton)

            AddHandler RunButton.Click, AddressOf RunButton_ClickHandler
            AddHandler RunWButton.Click, AddressOf RunWButton_ClickHandler
            AddHandler MainWindow.Load, AddressOf MainWindow_LoadHandler
        End If

        Return form
    End Function

    Sub Main()
        MainWindow.Name = "MainWindow"
        CodeBox.Name = "CodeBox"
        RunButton.Name = "RunButton"
        RunWButton.Name = "RunWButton"

        MainWindow = Print(MainWindow)

        MainWindow.ShowDialog()
    End Sub

End Module
