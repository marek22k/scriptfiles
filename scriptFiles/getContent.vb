Class getContent

    ' ProjectOnline.vb
    ' W3File.vb
    ' TempFile.vb
    ' ClassLibraryNet.vb

    ' 0 Content
    ' 1 Web filename
    ' 2 Temp filename

    Dim contentDatabase As ProjectOnline.Database.myDatabase

    Sub setDatabase(ByVal db As ProjectOnline.Database.myDatabase)
        Dim result As Boolean = ProjectOnline.Database.keySystem.ifKey(db)
        If (result = True) Then
            contentDatabase = db
        Else
            MsgBox("KEY ERROR in getContent")
        End If
    End Sub

    Sub getWebResult(ByVal WebFile As W3File)
        Dim serverfile As String = WebFile.getFileName
        Dim tmpfile As String = WebFile.getTempFile.getTempName
        ClassLibraryNet.downloadWebFile(serverfile, tmpfile)
        contentDatabase.new_database(0, My.Computer.FileSystem.ReadAllText(tmpfile))
        contentDatabase.new_database(1, WebFile.getFileName)
        contentDatabase.new_database(2, tmpfile)
    End Sub

    Function getDatabase() As ProjectOnline.Database.myDatabase
        Return contentDatabase
    End Function

    Function getContent() As String
        Return contentDatabase.get_database(0).ToString
    End Function

End Class