Module mregistry

    Function gd(ByVal search As String, Optional ByVal where As Object = False)
        If (where = False) Then where = Environment.GetCommandLineArgs()
        Dim result As String
        For i As Integer = 1 To where.Length - 1
            If (where(i) = search) Then
                result = where(i + 1)
            End If
        Next
        Return result
    End Function

    Sub Main()
        Dim cl As Object = Environment.CommandLine
        Dim reg As Object = My.Computer.Registry
        Dim cr As String = "HKEY_CLASSES_ROOT"
        Dim cu As String = "HKEY_CURRENT_USER"
        Dim lm As String = "HKEY_LOCAL_MACHINE"
        Dim u As String = "HKEY_USERS"
        Dim cc As String = "HKEY_CURRENT_CONFIG"

        If Not (cl.Contains("-o")) Then Console.WriteLine("The author of this program is Marek K.")

        If (cl.Contains("-v") And cl.Contains("-k")) Then
            If (cl.Contains("-g")) Then
                Dim key As String = gd("-k")
                Dim value As String = gd("-v")
                Dim res As String = reg.GetValue(key, value, "Not found.")
                If Not (cl.Contains("-o")) Then Console.WriteLine("Result {0}", res) Else Console.Write(res)
            ElseIf (cl.Contains("-s")) Then
                Dim key As String = gd("-k")
                Dim value As String = gd("-v")
                Dim newvalue As String = gd("-n")
                reg.SetValue(key, value, newvalue)
            ElseIf (cl.Contains("-d")) Then
                Dim k As String() = Split(gd("-k"), "\", 2)
                Dim key As String = k(1)
                Dim root As String = k(0)
                Dim value As String = gd("-v")
                Dim osk As Object
                If (root = cr) Then
                    osk = reg.ClassesRoot.OpenSubKey(key, True)
                ElseIf (root = cu) Then
                    osk = reg.CurrentUser.OpenSubKey(key, True)
                ElseIf (root = lm) Then
                    osk = reg.LocalMachine.OpenSubKey(key, True)
                ElseIf (root = u) Then
                    osk = reg.Users.OpenSubKey(key, True)
                ElseIf (root = cc) Then
                    osk = reg.CurrentConfig.OpenSubKey(key, True)
                End If
                osk.DeleteValue(value)
            End If
        Else
            Dim k As String() = Split(gd("-k"), "\", 2)
            Dim key As String
            Dim root As String
            Try
                key = k(1)
                root = k(0)
            Catch ex As Exception
                End
            End Try
            If (cl.Contains("-s")) Then
                If (root = cr) Then
                    reg.ClassesRoot.CreateSubKey(key)
                ElseIf (root = cu) Then
                    reg.CurrentUser.CreateSubKey(key)
                ElseIf (root = lm) Then
                    reg.LocalMachine.CreateSubKey(key)
                ElseIf (root = u) Then
                    reg.Users.CreateSubKey(key)
                ElseIf (root = cc) Then
                    reg.CurrentConfig.CreateSubKey(key)
                End If
            ElseIf (cl.Contains("-d")) Then
                If (root = cr) Then
                    reg.ClassesRoot.DeleteSubKey(key)
                ElseIf (root = cu) Then
                    reg.CurrentUser.DeleteSubKey(key)
                ElseIf (root = lm) Then
                    reg.LocalMachine.DeleteSubKey(key)
                ElseIf (root = u) Then
                    reg.Users.DeleteSubKey(key)
                ElseIf (root = cc) Then
                    reg.CurrentConfig.DeleteSubKey(key)
                End If
            End If
        End If
        If Not (cl.Contains("-o")) Then Console.WriteLine("Finish!")
    End Sub

End Module
