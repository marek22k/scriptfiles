Module Module3

    Dim sd1 As New SaveFileDialog
    Dim od1 As New OpenFileDialog
    Dim cd As New ColorDialog
    Dim fd As New FontDialog

    Public Function OpenFileDialog(ByVal Filter As String)
        od1.Filter = Filter
        If (od1.ShowDialog = DialogResult.Cancel) Then
            Return ("")
            Exit Function
        End If
        Return (od1.FileName)
    End Function

    Public Function SaveFileDialog(ByVal Filter As String)
        sd1.Filter = Filter
        If (sd1.ShowDialog = DialogResult.Cancel) Then
            Return ("")
            Exit Function
        End If
        Return (sd1.FileName)
    End Function

    Public Function ColorDialog()
        If (cd.ShowDialog = DialogResult.OK) Then
            Return (cd.Color)
            Exit Function
        End If
    End Function

    Public Function FontDialog()
        If (fd.ShowDialog = DialogResult.OK) Then
            Return (fd.Font)
            Exit Function
        End If
    End Function
End Module
