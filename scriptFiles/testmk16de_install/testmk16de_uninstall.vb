Module testmk16de_uninstall

    Sub DelFile(ByVal filename As String)
        If (My.Computer.FileSystem.FileExists(filename)) Then My.Computer.FileSystem.DeleteFile(filename)
    End Sub

    Sub Main()
        Dim args As String() = Environment.GetCommandLineArgs()
        Dim name As String = args(1)
        Dim downloadModule As String = args(2)
        Dim installPath As String = args(3)
        For i As Integer = 4 To args.Length - 1
            installPath += " " & args(i)
        Next

        Dim smFolder As String = Environment.GetFolderPath(Environment.SpecialFolder.StartMenu) & "\" & name & "\"

        DelFile(smFolder & "Uninstall" & ".lnk")
        DelFile(smFolder & "Repair" & ".lnk")
        DelFile(smFolder & name & ".lnk")
        DelFile(Environment.GetFolderPath(Environment.SpecialFolder.Desktop) & "\" & name & ".lnk")
        DelFile(installPath & "host.txt")
        DelFile(installPath & "folder.txt")
        DelFile(installPath & "program.txt")
        DelFile(installPath & "name.txt")
        DelFile(installPath & "version.txt")
        DelFile(installPath & "bit.txt")
        'DelFile(installPath & "testmk16de_uninstall.exe")
        DelFile(installPath & "testmk16de_install.exe")
        DelFile(installPath & downloadModule)

        My.Computer.FileSystem.DeleteDirectory(smFolder, FileIO.DeleteDirectoryOption.DeleteAllContents)
        'My.Computer.FileSystem.DeleteDirectory(installPath, FileIO.DeleteDirectoryOption.DeleteAllContents)

        My.Computer.Registry.CurrentUser.DeleteSubKey("Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name)

        Console.WriteLine("Finish!")
        Console.ReadLine()
    End Sub

End Module
