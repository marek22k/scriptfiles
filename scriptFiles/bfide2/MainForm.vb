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
            Dim interpreter As String
            If (My.Settings.usei = 1) Then interpreter = My.Settings.i1
            If (My.Settings.usei = 2) Then interpreter = My.Settings.i2
            If (My.Settings.usei = 3) Then interpreter = My.Settings.i3
            If Not (My.Computer.FileSystem.FileExists(interpreter)) Then
                MsgBox("Error: Can't found file " & interpreter & ". Please look in Help -> About")
                Exit Sub
            End If
            My.Computer.FileSystem.WriteAllText("interpret.bat", My.Resources.part1_bat & interpreter & My.Resources.part2_bat, False)
            Process.Start("interpret.bat", """" & fn & """")
            'My.Computer.FileSystem.DeleteFile("interpret.bat")
        Catch ex As Exception
            MsgBox(ex.ToString, MsgBoxStyle.Critical, ex.Message.ToString)
        End Try
    End Sub

    Sub Check()
        Try
            Save()
            Dim checker As String
            If (My.Settings.usec = 1) Then checker = My.Settings.c1
            If (My.Settings.usec = 2) Then checker = My.Settings.c2
            If (My.Settings.usec = 3) Then checker = My.Settings.c3
            If Not (My.Computer.FileSystem.FileExists(checker)) Then
                MsgBox("Error: Can't found file " & checker & ". Please look in Help -> About")
                Exit Sub
            End If
            My.Computer.FileSystem.WriteAllText("check.bat", My.Resources.part1_bat & checker & My.Resources.part2_bat, False)
            Process.Start("check.bat", """" & fn & """")
            'My.Computer.FileSystem.DeleteFile("interpret.bat")
        Catch ex As Exception
            MsgBox(ex.ToString, MsgBoxStyle.Critical, ex.Message.ToString)
        End Try
    End Sub

    Private Sub NewToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles NewToolStripMenuItem1.Click
        NewDoc()
    End Sub

    Private Sub OpenToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles OpenToolStripMenuItem1.Click
        Open()
    End Sub

    Private Sub SaveToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles SaveToolStripMenuItem1.Click
        Save()
    End Sub

    Private Sub SaveAsToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles SaveAsToolStripMenuItem1.Click
        SaveAs()
    End Sub

    Private Sub ExitToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles ExitToolStripMenuItem1.Click
        End
    End Sub

    Private Sub InterpretToolStripMenuItem3_Click(sender As Object, e As EventArgs) Handles InterpretToolStripMenuItem3.Click
        Interpret()
    End Sub

    Private Sub CheckToolStripMenuItem_Click(sender As Object, e As EventArgs) Handles CheckToolStripMenuItem.Click
        Check()
    End Sub

    Private Sub SettingsToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles SettingsToolStripMenuItem1.Click
        SettingsForm.ShowDialog()
    End Sub

    Private Sub AboutToolStripMenuItem1_Click(sender As Object, e As EventArgs) Handles AboutToolStripMenuItem1.Click
        AboutBox1.ShowDialog()
    End Sub

    Private Sub ToolStripButton6_Click(sender As Object, e As EventArgs) Handles ToolStripButton6.Click
        Open()
    End Sub

    Private Sub ToolStripButton7_Click(sender As Object, e As EventArgs) Handles ToolStripButton7.Click
        Save()
    End Sub

    Private Sub ToolStripButton8_Click(sender As Object, e As EventArgs) Handles ToolStripButton8.Click
        Interpret()
    End Sub

    Private Sub ToolStripButton9_Click(sender As Object, e As EventArgs) Handles ToolStripButton9.Click
        Check()
    End Sub
End Class
