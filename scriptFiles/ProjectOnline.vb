Namespace ProjectOnline

    '#############################
    '## Copyright(c) by mk16.de ##
    '## A File by Marek Kuethe  ##
    '#############################

    Module ProjectOnlineHelp
        'ProjectOnlineHelp Sprache Deutsch
        Sub ProjectOnlineExample()
            'Dateienbank Key erstellen
            Dim db_key As ProjectOnline.Database.key = New ProjectOnline.Database.key("ProjektDateienbank")
            'Dateienbank erstellen
            Dim db As ProjectOnline.Database.myDatabase = New ProjectOnline.Database.myDatabase("ProjektDateienbank", db_key)
            'Web-Projekt erstellen
            Dim Projekt As ProjectOnline.WebProject.myWebProject = New ProjectOnline.WebProject.myWebProject("www.hundert-prozent.net", "http://www.hundert-prozent.net/Chat.php", "Chat", "www.hundert-prozent.net | Chatten mit allen! | hundert-prozent dein Netzwerk.", db)
            'Echtheit des Keys ueberpruefen(Freiwillige Option)
            Dim ik As Boolean = ProjectOnline.Database.keySystem.ifKey(db)
            If (ik = True) Then
                'Key ist echt
                MsgBox("Kein Fehler im Dateienbank key")
            Else
                'Key ist nicht echt
                MsgBox("Fehler im Dateienbank key")
            End If
            'Web-Projekt ueberschrift ausgeben
            MsgBox(Projekt.getLabelTextMax)
            'Web-Projekt Infos ausgeben
            MsgBox(Projekt.getLabelTextMin)
        End Sub

    End Module

    Namespace Database

        Module keySystem

            Function ifKey(ByVal db As Database.myDatabase)
                Dim key As Database.key = db.get_key()
                Dim dbName As String = db.get_dbName()
                If (key.getKey = "keySystem:" & My.User.Name & ":key_" & dbName) Then
                    Return True
                Else
                    Return False
                End If
            End Function

        End Module

        Class key

            Dim key

            Sub New(ByVal db As String)
                key = "keySystem:" & My.User.Name & ":key_" & db
            End Sub

            Function getKey()
                Return key
            End Function

        End Class

        Class myDatabase

            Dim db_datas(55) As String
            Dim db_name As String
            Dim db_key As Database.key

            Sub New(ByVal db As String, ByVal key As Database.key)
                db_name = db
                db_key = key
                Dim kV As String = db_key.getKey
                If Not (kV = "keySystem:" & My.User.Name & ":key_" & db_name) Then
                    MsgBox("KEY ERROR")
                    db_datas = Nothing
                    db_name = Nothing
                    db_key = Nothing
                    End
                End If
            End Sub

            Function get_key()
                Return db_key
            End Function

            Function get_dbName()
                Return db_name
            End Function

            Sub new_database(ByVal db_dataName As Integer, ByVal db_dataValue As Object)
                db_datas.SetValue(db_dataValue, db_dataName)
            End Sub

            Sub delete_database(ByVal db_dataName As Integer)
                db_datas(db_dataName) = Nothing
            End Sub

            Function get_database(ByVal db_dataName As Integer)
                Try
                    Return db_datas(db_dataName)
                Catch ex As Exception
                    Return Nothing
                End Try
            End Function

        End Class

    End Namespace

    Namespace WebProject

        Class myWebProject

            '0 Project Name
            '1 Domain URL
            '2 Domain Title
            '3 Domain Description
            '4 Doamin Enconding

            Dim md As Database.myDatabase

            Sub New(ByVal mP_name As String, ByVal url As String, ByVal urlTitle As String, ByVal urlDescription As String, ByVal Database As Database.myDatabase)
                md = Database
                md.new_database(0, mP_name)
                md.new_database(1, url)
                md.new_database(2, urlTitle)
                md.new_database(3, urlDescription)
            End Sub

            Function getLabelTextMax()
                Return md.get_database(0) & " - " & md.get_database(2)
            End Function

            Function getLabelTextMin()
                Return md.get_database(1) & " |-| " & md.get_database(3)
            End Function

        End Class

    End Namespace

End Namespace