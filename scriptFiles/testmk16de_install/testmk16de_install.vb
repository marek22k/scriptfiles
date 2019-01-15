Module testmk16de_install

    Sub CreateLink(ByVal file As String, ByVal linkFile As String, ByVal runFolder As String, ByVal args As String)
        Dim link As Object = CreateObject("WScript.Shell").CreateShortcut(linkFile)

        link.Arguments = args
        link.TargetPath = file
        link.WindowStyle = 1
        link.IconLocation = file & ", 0"
        link.WorkingDirectory = runFolder
        link.Save()
    End Sub

    Sub Main()
        Dim hostaddress As String = My.Computer.FileSystem.ReadAllText("host.txt")
        Dim hostfolderaddress As String = My.Computer.FileSystem.ReadAllText("folder.txt")
        Dim downloadModule As String = My.Computer.FileSystem.ReadAllText("program.txt")
        Dim name As String = My.Computer.FileSystem.ReadAllText("name.txt")
        Dim version As String = My.Computer.FileSystem.ReadAllText("version.txt")
        Dim bit As String = My.Computer.FileSystem.ReadAllText("bit.txt")
        Dim x As String = ""
        Try
            x = ""
            hostaddress = My.Computer.FileSystem.ReadAllText(x & "host.txt")
            hostfolderaddress = My.Computer.FileSystem.ReadAllText(x & "folder.txt")
            downloadModule = My.Computer.FileSystem.ReadAllText(x & "program.txt")
            name = My.Computer.FileSystem.ReadAllText(x & "name.txt")
            version = My.Computer.FileSystem.ReadAllText(x & "version.txt")
            bit = My.Computer.FileSystem.ReadAllText(x & "bit.txt")
        Catch ex As System.IO.FileNotFoundException
            Try
                x = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86)
                hostaddress = My.Computer.FileSystem.ReadAllText(x & "host.txt")
                hostfolderaddress = My.Computer.FileSystem.ReadAllText(x & "folder.txt")
                downloadModule = My.Computer.FileSystem.ReadAllText(x & "program.txt")
                name = My.Computer.FileSystem.ReadAllText(x & "name.txt")
                version = My.Computer.FileSystem.ReadAllText(x & "version.txt")
                bit = My.Computer.FileSystem.ReadAllText(x & "bit.txt")
            Catch ex2 As System.IO.FileNotFoundException
                x = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles)
                hostaddress = My.Computer.FileSystem.ReadAllText(x & "host.txt")
                hostfolderaddress = My.Computer.FileSystem.ReadAllText(x & "folder.txt")
                downloadModule = My.Computer.FileSystem.ReadAllText(x & "program.txt")
                name = My.Computer.FileSystem.ReadAllText(x & "name.txt")
                version = My.Computer.FileSystem.ReadAllText(x & "version.txt")
                bit = My.Computer.FileSystem.ReadAllText(x & "bit.txt")
            End Try
        End Try
        Dim host As String = hostaddress & hostfolderaddress
        Dim smFolder As String = Environment.GetFolderPath(Environment.SpecialFolder.StartMenu) & "\" & name & "\"
        Dim installPath As String
        If (bit = "x86") Then ' 32-bit
            installPath = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFilesX86) & "\" & name & "\"
        ElseIf (bit = "x64") Then ' 64-bit
            installPath = Environment.GetFolderPath(Environment.SpecialFolder.ProgramFiles) & "\" & name & "\"
        Else
            End
        End If

        Dim majorFile1 As String = installPath & downloadModule
        Dim uninstallFile As String = installPath & "testmk16de_uninstall.exe"
        Dim installFile As String = installPath & "testmk16de_install.exe"

        If (My.Computer.FileSystem.FileExists(majorFile1)) Then My.Computer.FileSystem.DeleteFile(majorFile1)
        If (My.Computer.FileSystem.FileExists(uninstallFile)) Then My.Computer.FileSystem.DeleteFile(uninstallFile)
        'If (My.Computer.FileSystem.FileExists(installPath & "host.txt")) Then My.Computer.FileSystem.DeleteFile(installPath & "host.txt")
        'If (My.Computer.FileSystem.FileExists(installPath & "folder.txt")) Then My.Computer.FileSystem.DeleteFile(installPath & "folder.txt")
        'If (My.Computer.FileSystem.FileExists(installPath & "program.txt")) Then My.Computer.FileSystem.DeleteFile(installPath & "program.txt")
        'If (My.Computer.FileSystem.FileExists(installPath & "name.txt")) Then My.Computer.FileSystem.DeleteFile(installPath & "name.txt")
        'If (My.Computer.FileSystem.FileExists(installPath & "version.txt")) Then My.Computer.FileSystem.DeleteFile(installPath & "version.txt")
        'If (My.Computer.FileSystem.FileExists(installPath & "bit.txt")) Then My.Computer.FileSystem.DeleteFile(installPath & "bit.txt")

        My.Computer.FileSystem.CreateDirectory(installPath)

        My.Computer.Network.DownloadFile(host & downloadModule, majorFile1)
        My.Computer.Network.DownloadFile(host & "/testmk16de_install/testmk16de_uninstall.exe", uninstallFile)
        If Not (My.Computer.FileSystem.FileExists(installFile)) Then My.Computer.Network.DownloadFile(host & "/testmk16de_install/testmk16de_install.exe", installFile)

        If Not (My.Computer.FileSystem.FileExists(installPath & "host.txt")) Then My.Computer.FileSystem.CopyFile(x & "host.txt", installPath & "host.txt")
        If Not (My.Computer.FileSystem.FileExists(installPath & "folder.txt")) Then My.Computer.FileSystem.CopyFile(x & "folder.txt", installPath & "folder.txt")
        If Not (My.Computer.FileSystem.FileExists(installPath & "program.txt")) Then My.Computer.FileSystem.CopyFile(x & "program.txt", installPath & "program.txt")
        If Not (My.Computer.FileSystem.FileExists(installPath & "name.txt")) Then My.Computer.FileSystem.CopyFile(x & "name.txt", installPath & "name.txt")
        If Not (My.Computer.FileSystem.FileExists(installPath & "version.txt")) Then My.Computer.FileSystem.CopyFile(x & "version.txt", installPath & "version.txt")
        If Not (My.Computer.FileSystem.FileExists(installPath & "bit.txt")) Then My.Computer.FileSystem.CopyFile(x & "bit.txt", installPath & "bit.txt")

        My.Computer.FileSystem.CreateDirectory(smFolder)
        CreateLink(majorFile1, smFolder & name & ".lnk", installPath, "")
        CreateLink(majorFile1, Environment.GetFolderPath(Environment.SpecialFolder.Desktop) & "\" & name & ".lnk", installPath, "")
        CreateLink(installFile, smFolder & "Repair" & ".lnk", installPath, "")
        CreateLink(uninstallFile, smFolder & "Uninstall" & ".lnk", installPath, name & " " & downloadModule & " " & installPath)

        Dim size As Integer = (My.Computer.FileSystem.GetFileInfo(installPath & downloadModule).Length +
            My.Computer.FileSystem.GetFileInfo(uninstallFile).Length +
            My.Computer.FileSystem.GetFileInfo(installFile).Length) / 1024 ' Unit: Kilo Byte

        My.Computer.Registry.CurrentUser.CreateSubKey("Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "DisplayName", name)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "DisplayVersion", version)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "InstallLocation", installPath)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "UninstallString", uninstallFile & " " & name & " " & downloadModule & " " & installPath)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "Publisher", "test.mk16.de")
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "HelpLink", hostaddress)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "URLInfoAbout", host)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "URLUpdateInfo", host & downloadModule)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "InstallDate", DateAndTime.Year(Date.Today) & DateAndTime.Month(Date.Today) & DateAndTime.Day(Date.Today))
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "EstimatedSize", size, Microsoft.Win32.RegistryValueKind.DWord)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "NoModify", 1, Microsoft.Win32.RegistryValueKind.DWord)
        My.Computer.Registry.SetValue("HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Uninstall\" & name, "NoRepair", 1, Microsoft.Win32.RegistryValueKind.DWord)

        Console.WriteLine("Finish!")
        Console.ReadLine()
    End Sub

End Module
