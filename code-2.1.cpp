
#include<iostream>
using namespace std;

class Rectangle
{

    float Length,Width,Perimeter,Area;

    public:

        void GetData()
        {
                cout<<"Enter the data of rectangle";
                cin>>Length;
                cin>>Width;
                Perimeter=2*(Length+Width);
                Area=Length*Width;

        }

        void DisplayData()
        {


                cout<<Perimeter<<endl;
                cout<<Area;

        }

}R1;

int main()
{
     int NumberOfRectangle,i;
     cin>>NumberOfRectangle;
    for(i=0;i<=NumberOfRectangle;i++)
    {
        R1.GetData();
        R1.DisplayData();
    }
    return 0;
}
