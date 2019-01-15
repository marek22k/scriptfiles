Class TempFile

    Dim file As String = Nothing

    Sub New()
        file = System.IO.Path.GetTempPath & "\" & System.IO.Path.GetRandomFileName & "." & System.IO.Path.GetRandomFileName & "." & System.IO.Path.GetRandomFileName & ".tmp"
    End Sub

    Sub setContent(ByVal content As String)
        My.Computer.FileSystem.WriteAllText(file, content, False)
    End Sub

    Function getContent() As String
        Return My.Computer.FileSystem.ReadAllText(file)
    End Function

    Function getTempName() As String
        Return file
    End Function

End Class