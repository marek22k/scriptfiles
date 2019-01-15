Public Class Form1
    Dim path As String = InputBox("Workspace: ", "Path", Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) & "\")
    Sub Load()
        ListBox1.Items.Clear()
        Try
            For Each Suchen As String In My.Computer.FileSystem.GetFiles(path, FileIO.SearchOption.SearchTopLevelOnly, "*.cpp")
                ListBox1.Items.Add(Dir(Suchen))
            Next
            For Each Suchen As String In My.Computer.FileSystem.GetFiles(path, FileIO.SearchOption.SearchTopLevelOnly, "*.h")
                ListBox1.Items.Add(Dir(Suchen))
            Next
        Catch ex As Exception
            MsgBox("Error", MsgBoxStyle.Critical)
        End Try
        Try
            ListBox1.SelectedItem = "main.cpp"
            TextBox1.Text = My.Computer.FileSystem.ReadAllText(path & ListBox1.SelectedItem)
        Catch ex As Exception
            My.Computer.FileSystem.WriteAllText(path & "main.cpp", TextBox1.Text, False)
            Load()
        End Try
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        Dim temp As String = "run.bat"
        Dim cpp As String = "main.cpp"
        ListBox1.SelectedItem = "main.cpp"
        My.Computer.FileSystem.WriteAllText(path & temp, My.Resources.run_bat, False)
        My.Computer.FileSystem.WriteAllText(path & cpp, TextBox1.Text, False)
        Process.Start(path & temp)
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Load()
    End Sub

    Private Sub ListBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ListBox1.SelectedIndexChanged
        TextBox1.Text = My.Computer.FileSystem.ReadAllText(path & ListBox1.SelectedItem)
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Try
            My.Computer.FileSystem.WriteAllText(path & ListBox1.SelectedItem, TextBox1.Text, False)
        Catch ex As Exception

        End Try
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        My.Computer.FileSystem.DeleteFile(path & ListBox1.SelectedItem)
        Load()
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Dim name As String = InputBox("Filename: ", "Add file", ".cpp")
        My.Computer.FileSystem.WriteAllText(path & name, "", False)
        Load()
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        Load()
    End Sub
End Class
