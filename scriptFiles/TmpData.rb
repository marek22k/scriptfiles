# Filename: TmpData.rb
# Created by: m.k[aet]mk16[dot]de
# Created on: 05.06.2017
# World Wide Web: http://test.mk16.de/scriptFiles/TmpData.rb


class TmpData
    def initialize x=[]
        @TmpData = Hash.new
        @AryData = Array.new
        x.each { |y|
            @TmpData[y.to_s.length] = y.to_s
        }
    end
    def AddData data
        @TmpData[data.to_s.length] = data.to_s
    end
    def CreateAryData
        arr = @TmpData.to_a
        ary = Array.new
        arr.each { |x|
            ary << x[1]
        }
        @AryData = ary
    end
    def DeleteAryData
        @AryData = []
    end
    def DeleteTmpData
        @TmpData = {}
    end
    def DeleteAllData
        @AryData = []
        @TmpData = {}
    end
    def GetAryData
        return @AryData
    end
    def GetOneData
        return @AryData[0]
    end
end