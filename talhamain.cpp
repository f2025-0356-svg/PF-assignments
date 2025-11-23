
#include <iostream>
#include <iomanip>//controls the output precision 
using namespace std ;      
int main() 
{
    float num1,num2;//two floating point variables are declared  
    cout<<"Enter two decimal numbers=";
    cin>>num1>>num2;//getting the value from the user
    cout<<fixed<<setprecision(2);//decimal output precision
    //Displaying sum,product,difference and quotient in float
    cout<<"The result in floting point number:"<<endl;
    cout<<"Sum="<<num1+num2<<endl;
    cout<<"Difference="<<num1-num2<<endl;
    cout<<"Product="<<num1*num2<<endl;
    cout<<"Quotient="<<num1/num2<<endl;
    //type casting, changing float into integer.
    int int1=static_cast<int>(num1);
    int int2=static_cast<int>(num2);
    //Displaying sum,product,difference and quotient in integer
    cout<<"The chaged variable result into integer:"<<endl; 
    cout<<"Sum="<<int1+int2<<endl;
    cout<<"Difference="<<int1-int2<<endl;
    cout<<"Product="<<int1*int2<<endl;
    cout<<"Quotient="<<int1/int2<<endl;
    return 0;
}  