Module caesarcrypt

    Sub encrypt()
        Dim text1(25), text2(25) As Char
        Dim key, last As Integer
        last = 0
        Dim txt, res As String

        Console.Write("Key: ")
        key = Console.ReadLine()
        Console.Write("Text: ")
        txt = Console.ReadLine()

        For i As Integer = 0 To 25
            text1(i) = Chr(97 + i)
        Next

        For i As Integer = 0 To 25
            Dim t As Integer = 97 + i + key
            If (t > 122) Then
                last = i
                Exit For
            Else
                text2(i) = Chr(t)
            End If
        Next

        For i As Integer = last To 25
            text2(i) = Chr(97 + i - last)
        Next

        For i As Integer = 0 To txt.Length - 1
            Dim a As String = txt.Substring(i, 1)
            For j As Integer = 0 To 25
                If (a = text1(j).ToString) Then res += text2(j).ToString
            Next
        Next

        Console.WriteLine("Key: {0}; Result: {1}", key, res)
    End Sub

    Sub decrypt(ByVal key As Integer, ByVal txt As String)
        Dim text1(25), text2(25) As Char
        Dim last As Integer = 0
        Dim res As String

        For i As Integer = 0 To 25
            text1(i) = Chr(97 + i)
        Next

        For i As Integer = 0 To 25
            Dim t As Integer = 97 + i + key
            If (t > 122) Then
                last = i
                Exit For
            Else
                text2(i) = Chr(t)
            End If
        Next

        For i As Integer = last To 25
            text2(i) = Chr(97 + i - last)
        Next

        For i As Integer = 0 To txt.Length - 1
            Dim a As String = txt.Substring(i, 1)
            For j As Integer = 0 To 25
                If (a = text2(j).ToString) Then res += text1(j).ToString
            Next
        Next

        If (key.ToString.Length = 1) Then Console.WriteLine("Key: 0{0}; Result: {1}", key, res) Else Console.WriteLine("Key: {0}; Result: {1}", key, res)
    End Sub

    Sub Main()
        Console.WriteLine("The developer of the program is Marek K.; The program uses Caesar cipher.")
        Console.Write("Enter ""encrypt"" or ""decrypt"": ")
        Dim ans As String = Console.ReadLine()
        If (ans = "encrypt") Then
            encrypt()
        ElseIf (ans = "decrypt") Then
            Console.Write("Text: ")
            Dim txt As String = Console.ReadLine()
            For i As Integer = 0 To 25
                decrypt(i, txt)
            Next
        End If
    End Sub

End Module
