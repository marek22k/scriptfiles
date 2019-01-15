Imports System.Windows.Forms

Module file

    Dim ofd1 As New OpenFileDialog
    Dim sfd1 As New SaveFileDialog

    Public Sub msgerror(ByVal errortext As String)
        If (errortext = "") Then
            errortext = "Sorry, an error has occurred"
        End If
        MsgBox(errortext, MsgBoxStyle.Critical)
    End Sub

    Public Sub fileCopy(ByVal from As String, ByVal after As String)
        Try
            My.Computer.FileSystem.CopyFile(from, after)
        Catch ex As Exception
            msgerror("")
        End Try
    End Sub

    Public Sub save(ByVal fileContents As String, ByVal wherestore As String)
        Try
            My.Computer.FileSystem.WriteAllText(wherestore, fileContents, True)
        Catch ex As Exception
            msgerror("")
        End Try
    End Sub

    Public Function open(ByVal file As String)
        Try
            Return (My.Computer.FileSystem.ReadAllText(file))
        Catch ex As Exception
            msgerror("")
        End Try
    End Function

    Public Function SaveFileDialog(ByVal Filter As String)
        sfd1.Filter = Filter
        If (sfd1.ShowDialog = DialogResult.Cancel) Then
            Exit Function
        End If
        Return (sfd1.FileName)
    End Function

    Public Function openFileDialog(ByVal Filter As String)
        ofd1.Filter = Filter
        If (ofd1.ShowDialog = DialogResult.Cancel) Then
            Exit Function
        End If
        Return (ofd1.FileName)
    End Function


    Public Sub deletefile(ByVal delete As String)
        Try
            My.Computer.FileSystem.DeleteFile(delete)
        Catch ex As Exception
            msgerror("")
        End Try
    End Sub

End Module
