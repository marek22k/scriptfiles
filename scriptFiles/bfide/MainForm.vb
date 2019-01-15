Public Class MainForm

    Dim fn As String = ""

    Sub NewDoc()
        fn = ""
        TextBox1.Text = ""
    End Sub

    Sub Open()
        If (OpenFileDialog1.ShowDialog() = DialogResult.OK) Then
            fn = OpenFileDialog1.FileName
            TextBox1.Text = My.Computer.FileSystem.ReadAllText(fn)
        End If
    End Sub

    Sub SaveAs()
        If (SaveFileDialog1.ShowDialog() = DialogResult.OK) Then
            fn = SaveFileDialog1.FileName
            Save()
        End If
    End Sub

    Sub Save()
        If (fn = "") Then
            SaveAs()
        End If
        If Not (fn = "") Then
            Try
                My.Computer.FileSystem.WriteAllText(fn, TextBox1.Text, False)
            Catch ex As Exception
                MsgBox(ex.ToString, MsgBoxStyle.Critical, ex.Message.ToString)
            End Try
        End If
    End Sub

    Sub Interpret()
        Try
            Save()
            If Not (My.Computer.FileSystem.FileExists("bfinterpreter.exe")) Then
                My.Computer.Network.DownloadFile(InputBox("bfinterpreter.exe", "bfinterpreter.exe", "http://test.mk16.de/scriptFiles/bfinterpreter/bfinterpreter.exe"), "bfinterpreter.exe")
            End If
            If Not (My.Computer.FileSystem.FileExists("interpret.bat")) Then
                My.Computer.FileSystem.WriteAllText("interpret.bat", My.Resources.interpret_bat, False)
            End If
            Process.Start("interpret.bat", """" + fn + """")
            'My.Computer.FileSystem.DeleteFile("interpret.bat")
        Catch ex As Exception
            MsgBox(ex.ToString, MsgBoxStyle.Critical, ex.Message.ToString)
        End Try
    End Sub

    Sub Check()
        Try
            Save()
            If Not (My.Computer.FileSystem.FileExists("bfchecker.exe")) Then
                My.Computer.Network.DownloadFile(InputBox("bfchecker.exe", "bfchecker.exe", "http://test.mk16.de/scriptFiles/bfchecker/bfchecker.exe"), "bfchecker.exe")
            End If
            If Not (My.Computer.FileSystem.FileExists("check.bat")) Then
                My.Computer.FileSystem.WriteAllText("check.bat", My.Resources.check_bat, False)
            End If
            Process.Start("check.bat", """" + fn + """")
            'My.Computer.FileSystem.DeleteFile("interpret.bat")
        Catch ex As Exception
            MsgBox(ex.ToString, MsgBoxStyle.Critical, ex.Message.ToString)
        End Try
    End Sub

    Private Sub ToolStripButton1_Click(sender As Object, e As EventArgs) Handles ToolStripButton1.Click
        Interpret()
    End Sub

    Private Sub ExitToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem.Click
        End
    End Sub

    Private Sub SaveAsToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles SaveAsToolStripMenuItem.Click
        SaveAs()
    End Sub

    Private Sub SaveToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles SaveToolStripMenuItem.Click
        Save()
    End Sub

    Private Sub OpenToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles OpenToolStripMenuItem.Click
        Open()
    End Sub

    Private Sub NewToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles NewToolStripMenuItem.Click
        NewDoc()
    End Sub

    Private Sub AboutToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles AboutToolStripMenuItem.Click
        AboutBox1.ShowDialog()
    End Sub

    Private Sub InterpretToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles InterpretToolStripMenuItem1.Click
        Interpret()
    End Sub

    Private Sub ChckToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles ChckToolStripMenuItem.Click
        Check()
    End Sub

    Private Sub ToolStripButton2_Click(sender As Object, e As EventArgs) Handles ToolStripButton2.Click
        Check()
    End Sub

    Private Sub ToolStripButton3_Click(sender As Object, e As EventArgs) Handles ToolStripButton3.Click
        Save()
    End Sub

    Private Sub ToolStripButton4_Click(sender As Object, e As EventArgs) Handles ToolStripButton4.Click
        Open()
    End Sub
End Class
