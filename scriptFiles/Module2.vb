Module Module2
    Public Sub main()
        Dim save As String
        save = "C:\file.txt"
        Try
            Module2.deletefile(save)
        Catch ex As Exception
        End Try
        Module2.filesave("C:\file.txt", "file", 0)
        Dim fileopen As String
        fileopen = Module2.fileopen("C:\file.txt")
        Module2.copyfile("C:\file.txt", "C:\file[1].txt")
    End Sub

    Public Sub filesave(ByVal wo As String, ByVal was As String, ByVal d As Integer)
        If (d = 1) Then
            Try
                My.Computer.FileSystem.DeleteFile(wo)
            Catch ex As Exception
            End Try
        End If
        My.Computer.FileSystem.WriteAllText(wo, was, True)
    End Sub

    Public Function fileopen(ByVal wo As String)
        Dim ot As String
        ot = My.Computer.FileSystem.ReadAllText(wo)
        Return (ot)
    End Function

    Public Sub deletefile(ByVal wo As String)
        My.Computer.FileSystem.DeleteFile(wo)
    End Sub

    Public Sub copyfile(ByVal wo As String, ByVal nach As String)
        My.Computer.FileSystem.CopyFile(wo, nach)
    End Sub
End Module
