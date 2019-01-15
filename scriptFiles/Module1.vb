Module Module1
    Public Sub main()
        Module1.msg("Hallo", 3)
        Module1.suche("C:\", "Module1.vb")
        Module1.filestart("Module1.vb")
        Module1.textif("Module1.vb", "test text")
    End Sub
    Public Sub filestart(ByVal file As String)
        If (MsgBox("Do you want to run the file: " + file, MsgBoxStyle.YesNo) = MsgBoxResult.Yes) Then
            Process.Start(file)
        End If
    End Sub

    Public Function suche(ByVal suchort As String, ByVal suchwas As String)
        Try
            For Each Suchen As String In My.Computer.FileSystem.GetFiles(suchort, FileIO.SearchOption.SearchAllSubDirectories, suchwas)
                Return (Suchen)
            Next
        Catch ex As Exception
            Return ("Unfortunately, an error occurred.")
        End Try
    End Function
    Public Sub msg(ByVal message As String, ByVal onetwoThree As Integer)
        If (onetwoThree = 1) Then
            MsgBox(message, MsgBoxStyle.Critical)
        End If
        If (onetwoThree = 2) Then
            MsgBox(message, MsgBoxStyle.Exclamation)
        End If
        If (onetwoThree = 3) Then
            MsgBox(message, MsgBoxStyle.Information)
        End If
        If (onetwoThree = 4) Then
            MsgBox(message)
        End If
    End Sub
    Public Sub textif(ByVal t1 As String, ByVal t2 As String)
        If (t1 = t2) Then
            Module1.msg(t1 + " ist gleich wie " + t2, 3)
        Else
            Module1.msg(t1 + " ist nicht gleich wie " + t2, 3)
        End If
    End Sub

    Public Function uhrzeit()
        Dim dtp1 As New DateTimePicker
        Return (dtp1.Value)
    End Function

End Module
