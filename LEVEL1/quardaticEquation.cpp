#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double a, b, c, discriminant, root1, root2, realPart, imagPart;
        cout<<"Enter coefficients a, b and c: ";
        cin>>a>>b>>c;

        discriminant = b *(b – (4 * a * c));

        // condition for real and different roots
        if (discriminant > 0) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b – sqrt(discriminant)) / (2 * a);
            // to display the roots upto 2 decimal places 
            cout<<"root1 = %.2lf and root2 = %.2lf"<<root1<<root2;
        }

        // condition for real and equal roots
        else if (discriminant == 0) {
            root1 = root2 = -(b /(2 * a));
            cout <<"root1 = root2 = %.2lf;"<< root1;
        }

        // if roots are not real
        else {
            realPart = (–b / (2 * a));
            imagPart = sqrt(-discriminant) / (2 * a);
            cout<<"root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi"<<realPart<<imagPart<<realPart<<imagPart);
        }

        return 0;
}