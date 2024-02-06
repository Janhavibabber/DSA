//C++ Program

    //Prime numbers in a given range

    #include<iostream>

    using namespace std;

    //function to chek for prime number

    void prime(int num)

    {

        int div=0;

        //checking for number of divisor

        for(int i=1;i<=num;i++)

        {

            if(num%i==0)

                div++;                

        }

        //no divisors other than 1 and itself

        if(div==2)

            cout<<num<<endl;

    }

    int main()

    {

        cout<<"Enter range:";    

        int lowerLimit, upperLimit;

        //user input

        cin>>lowerLimit>>upperLimit;

        cout<<"Prime numbers between "<<lowerLimit<<" and "<<upperLimit<<"are:"<<endl;

        //finding prime numbers in the given range

        for(int i=lowerLimit;i<=upperLimit;i++)

            prime(i);

        return 0;

    }