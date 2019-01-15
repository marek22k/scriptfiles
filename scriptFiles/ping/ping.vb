Class ping

    Dim p As New Net.NetworkInformation.Ping
    Dim r As Net.NetworkInformation.PingReply

    ''' <summary>
    '''  Sends a ping request
    ''' </summary>
    ''' <param name="address">The address to which the request is sent</param>
    ''' <param name="timeout">The timeout to be used</param>
    Function send(ByVal address As String, ByVal timeout As Integer) As Boolean
        Try
            r = p.Send(address, timeout)
            Return True
        Catch ex As Exception
            Return False
        End Try
    End Function

    ''' <summary>
    '''  Returns the pingResult
    ''' </summary>
    Function getResult() As pingResult
        Dim n As New pingResult(r)
        Return n
    End Function

End Class

Class pingResult

    Dim openr As Object

    Sub New(ByVal r As Object)
        openr = r
    End Sub

    ''' <summary>
    '''  Returns the value Time
    ''' </summary>
    Function getTime()
        Return openr.RoundtripTime().ToString
    End Function

    ''' <summary>
    '''  Returns the value Status
    ''' </summary>
    Function getStatus()
        Return openr.Status.ToString()
    End Function

    ''' <summary>
    '''  Returns the value Address
    ''' </summary>
    Function getAddress()
        Return openr.Address.ToString()
    End Function

    ''' <summary>
    '''  Returns the Byte
    ''' </summary>
    Function getByte()
        Return openr.Buffer()
    End Function

End Class