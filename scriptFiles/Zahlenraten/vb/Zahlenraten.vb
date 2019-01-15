Module Zahlenraten

    ' Creator: Marek K.

    Sub Main()
        Start()
        Console.ReadLine()
    End Sub

    Private target As Boolean = False

    Private Sub Start()
        Console.Write("Willkommen beim Spiel Zahlenraten. Du denkst dir eine Zahl und ich muss versuchen sie zu erraten. Die must mir jede Runde sagen ob deine Zahl groszer(b), kleiner(s) oder ob ich sie erraten habe(t). Fangen wir an! ")
        Console.Write("Bis zu welcher Zahl soll ich raten? ")
        Dim max As Integer = Console.ReadLine()
        Wtl()
        Dim x As Integer = max / 2
        Dim xx As Integer = max
        Dim xn As Integer = 0
        While target = False
            Dim ans As Integer = Query(x)
            If (ans = 1) Then ' if big
                xn = x
                x = (xx + xn) / 2
            ElseIf (ans = 0) Then ' if small
                xx = x
                x = (xx + xn) / 2
            End If
        End While
        Win()
    End Sub

    Private Sub Win()
        Console.Write("Ich habe die Zahl erraten!")
    End Sub

    Private Function Query(ByVal num As Integer)
        Console.Write("Ist die Zahl groszer oder kleiner als ")
        Console.Write(num)
        Console.Write("? Deine Antwort: ") ' Antworte mit b(big) fuer groszer, s(small) fuer kleiner oder t(target) für erraten.
        Dim ans As String = Console.ReadLine()
        If (ans = "b") Then
            Return 1
        ElseIf (ans = "s") Then
            Return 0
        ElseIf (ans = "t") Then
            target = True
        Else
            Return Query(num)
        End If
        Console.WriteLine()
        Console.WriteLine()
        Return Nothing
    End Function

    Private Sub Wtl()
        Console.WriteLine()
        Console.WriteLine()
    End Sub

End Module