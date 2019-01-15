Namespace ObjectLibrary
    Class None

        Function none()
            Return New ObjectLibrary.None
        End Function

    End Class

    Class Save

        Dim save_obj As Object = Nothing

        Sub New(ByVal obj As Object)
            save_obj = obj
        End Sub

        Function getObject()
            Return save_obj
        End Function

    End Class
End Namespace