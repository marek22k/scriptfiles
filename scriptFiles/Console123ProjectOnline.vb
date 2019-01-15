Namespace Console123ProjectOnline

    '#############################
    '## Copyright(c) by mk16.de ##
    '## A File by Marek Kuethe  ##
    '#############################

    Module console123

        Function Input(ByVal inputText As String)
            Dim xT As String = Console.Title
            Console.Title = "Input by mk16.de"
            Console.Write(inputText & ": ")
            Return Console.ReadLine()
            Console.Title = xT
        End Function

        Sub OutputHello(ByVal lang As language, ByVal hello As String)
            If (lang.getLanguage = "de-German") Then
                Console.Write("Hallo " & hello)
            ElseIf (lang.getLanguage = "fr-French") Then
                Console.Write("Bonjour " & hello)
            ElseIf (lang.getLanguage = "en-English") Then
                Console.Write("Hello " & hello)
            End If
        End Sub

    End Module

    Class language

        Dim dbKey As ProjectOnline.Database.key = New ProjectOnline.Database.key("LanguageDatabase")
        Dim db As ProjectOnline.Database.myDatabase = New ProjectOnline.Database.myDatabase("LanguageDatabase", dbKey)

        Sub New(ByVal languageShortcuts As String, ByVal language As String)
            db.new_database(0, language)
            db.new_database(1, languageShortcuts)
        End Sub

        Function getLanguage()
            Return db.get_database(1) & "-" & db.get_database(0)
        End Function

    End Class

    Class birthday

        Dim dbKey As ProjectOnline.Database.key = New ProjectOnline.Database.key("BirthdayDatabase")
        Dim db As ProjectOnline.Database.myDatabase = New ProjectOnline.Database.myDatabase("BirthdayDatabase", dbKey)

        Sub New(ByVal day As Integer, ByVal month As Integer, ByVal year As Integer)
            db.new_database(0, day)
            db.new_database(1, month)
            db.new_database(1, year)
        End Sub

        Function getBirthday()
            Return db.get_database(0) & "/" & db.get_database(1) & "/" & db.get_database(2)
        End Function

        Function getData(ByVal data As Integer)
            '0 Day
            '1 Month
            '2 Year
            Return db.get_database(data)
        End Function

    End Class

    Class person

        Dim nF As String
        Dim nL As String
        Dim bd As birthday
        Dim lang As language

        Sub New(ByVal firstName As String, ByVal lastName As String, ByVal birthday As birthday, ByVal language As language)
            nF = firstName
            nL = lastName
            bd = birthday
            lang = language
        End Sub

        Function allGet()
            Return nF & ";" & nL & ";" & bd.getBirthday & ";" & lang.getLanguage & ";"
        End Function

    End Class

End Namespace