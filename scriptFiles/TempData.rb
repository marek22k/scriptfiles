class TempData
    @data = nil;
    def SetData data
        @data = data
    end
    def GetData
        return @data
    end
    def DelData
        @data = nil;
    end
end