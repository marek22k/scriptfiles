Module rnd

    ''' <summary>
    '''  Generates a random number
    ''' </summary>
    ''' <param name="a">From</param>
    ''' <param name="b">To</param>
    Function randint(ByVal a As Integer, ByVal b As Integer) As Integer
        Try
            Dim rndObj As New Random
            Return rndObj.Next(a, b)
        Catch ex As Exception
            Return 0
        End Try
    End Function

End Module