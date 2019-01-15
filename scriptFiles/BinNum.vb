Class BinNum

    ' This is a code by mk16.de

    Dim BinaryNumber As Integer = 0

    ''' <summary>
    ''' A new Binary number
    ''' </summary>
    ''' <param name="binary">The Binary number</param>
    Sub New(ByVal binary As Object)
        BinaryNumber = binary
    End Sub

    ''' <summary>
    ''' Returns the Binary number
    ''' </summary>
    Function bin() As Integer
        Return BinaryNumber
    End Function

    ''' <summary>
    ''' Returns the Decimal number
    ''' </summary>
    Function dec() As Integer
        Dim d As Double = Nothing
        Dim length As Integer = Len(BinaryNumber)
        Dim patt As Integer = Nothing
        Dim x As Integer = Nothing
        For x = 1 To length
            patt = Val(Mid(BinaryNumber, length, 1))
            length = length - 1
            If (patt <> "0") Then
                d += 2 ^ (x - 1)
            End If
        Next
        Return d
    End Function

End Class