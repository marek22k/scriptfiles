Public Class SettingsForm
    Sub Save()
        My.Settings.i1 = TextBox1.Text
        My.Settings.i2 = TextBox2.Text
        My.Settings.i3 = TextBox3.Text
        My.Settings.c1 = TextBox4.Text
        My.Settings.c2 = TextBox5.Text
        My.Settings.c3 = TextBox6.Text
        If (RadioButton1.Checked = True) Then My.Settings.usei = 1
        If (RadioButton2.Checked = True) Then My.Settings.usei = 2
        If (RadioButton3.Checked = True) Then My.Settings.usei = 3
        If (RadioButton4.Checked = True) Then My.Settings.usec = 1
        If (RadioButton5.Checked = True) Then My.Settings.usec = 2
        If (RadioButton6.Checked = True) Then My.Settings.usec = 3
    End Sub

    Sub LoadS()
        TextBox1.Text = My.Settings.i1
        TextBox2.Text = My.Settings.i2
        TextBox3.Text = My.Settings.i3
        TextBox4.Text = My.Settings.c1
        TextBox5.Text = My.Settings.c2
        TextBox6.Text = My.Settings.c3
        If (My.Settings.usei = 1) Then RadioButton1.Checked = True
        If (My.Settings.usei = 2) Then RadioButton2.Checked = True
        If (My.Settings.usei = 3) Then RadioButton3.Checked = True
        If (My.Settings.usec = 1) Then RadioButton4.Checked = True
        If (My.Settings.usec = 2) Then RadioButton5.Checked = True
        If (My.Settings.usec = 3) Then RadioButton6.Checked = True
    End Sub

    Private Sub SettingsForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        LoadS()
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        Save()
        Me.Close()
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        Save()
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        Me.Close()
    End Sub
End Class