' The author of this program is Marek Küthe
' Website: mk16.de
' E-Mail: m.k@mk16.de

Module good_bad

    Sub Main()
        Console.Title = "Hello User!"
        Console.WriteLine("Hello User! Enter a number:")

        Dim num As Integer = Console.ReadLine()

        If (num < 0) Then
            Console.Title = "Crazy"
            Console.WriteLine("The number is crazy!")
        ElseIf (num Mod 2 = 0) Then
            Console.Title = "Good"
            Console.WriteLine("The number is good!")
        Else
            Console.Title = "Bad"
            Console.WriteLine("The number is bad!")
        End If
    End Sub

End Module
