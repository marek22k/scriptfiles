namespace DOZEN {

    double bitToDozen(double x)
    {
        return x/12.0;
    }

    double bitToGros(double x)
    {
        return x/144.0;
    }

    double dozenToBit(double x)
    {
        return x*12.0;
    }

    double grosToBit(double x)
    {
        return x*144.0;
    }

    double grosToDozen(double x)
    {
        // x*144.0/12.0
        return x*12;
    }

    double DozenToGros(double x)
    {
        // x*12.0/144.0
        return x/12;
    }

}
