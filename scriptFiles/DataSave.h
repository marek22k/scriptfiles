#ifdef DataSave
#undef DataSave
#endif

class DataSave
{
    private:
        int SaveObject = 0;

    public:
        DataSave(int obj = 0) : SaveObject(obj) {}
        int SetData(int obj)
        {
            SaveObject = obj;
            return 0;
        }
        int GetData()
        {
            return SaveObject;
        }
        DataSave operator+(DataSave obj2)
        {
            DataSave obj1(GetData() + obj2.GetData());
            return obj1;
        }
        DataSave operator-(DataSave obj2)
        {
            DataSave obj1(GetData() - obj2.GetData());
            return obj1;
        }
        DataSave operator*(DataSave obj2)
        {
            DataSave obj1(GetData() * obj2.GetData());
            return obj1;
        }
        DataSave operator/(DataSave obj2)
        {
            DataSave obj1(GetData() / obj2.GetData());
            return obj1;
        }
        DataSave operator%(DataSave obj2)
        {
            DataSave obj1(GetData() % obj2.GetData());
            return obj1;
        }
        bool operator==(DataSave obj2)
        {
            return (GetData() == obj2.GetData());
        }
        bool operator!=(DataSave obj2)
        {
            return (GetData() != obj2.GetData());
        }
        bool operator<(DataSave obj2)
        {
            return (GetData() < obj2.GetData());
        }
        bool operator>(DataSave obj2)
        {
            return (GetData() > obj2.GetData());
        }
};
