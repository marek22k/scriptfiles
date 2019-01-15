Class W3File

    Dim tempFile As TempFile
    Dim file As String = Nothing

    Sub New(ByVal WebFile As String)
        file = WebFile
        tempFile = New TempFile()
    End Sub

    Function getFileName() As String
        Return file
    End Function

    Function getTempFile() As TempFile
        Return tempFile
    End Function

End Class