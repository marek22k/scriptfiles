Class value
    ' This is a code by mk16.de
    Dim objs As Integer
    Sub New(ByVal int As Integer)
        objs = int
    End Sub
    Function GetInteger() As Integer
        Return objs
    End Function
    Function GetString() As String
        Return objs.ToString
    End Function
End Class