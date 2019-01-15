Module MainModule

    Sub Main()

        Console.Title = "Ein -mal- eins Programm"
        Console.BackgroundColor = ConsoleColor.Blue
        Console.ForegroundColor = ConsoleColor.Cyan

        For faktor1 As Integer = 1 To 9
            For faktor2 As Integer = 1 To 9
                Dim ergebnis As Integer = faktor1 * faktor2
                Console.Write("{0} * {1} = {2}; ", faktor1, faktor2, ergebnis)
            Next
            Console.WriteLine()
        Next

        Console.WriteLine()
        Console.BackgroundColor = ConsoleColor.Magenta
        Console.ForegroundColor = ConsoleColor.Yellow

        While True
            Console.Write("Faktor 1: ")  ' Computer gibt "Faktor 1: " aus
            Dim faktor1 As Integer = Console.ReadLine() ' User gibt den ersten Faktor an
            Console.Write("Faktor 2: ") ' Computer gibt "Faktor 2: " aus
            Dim plus As Double = faktor1 * Console.ReadLine() ' Computer rechnet faktor 1 und faktor 2, der grade angefragt worden ist, zusammen
            Console.Write("Ergebnis: {0}", plus) ' Computer gibt dem User das Ergebnis der rechnung aus
            Console.WriteLine()
            Console.WriteLine()
        End While
    End Sub

End Module