#include <iostream>
#include <cstdlib>

class simpleInterest
{
    float P,R,T;
    
    public:
    simpleInterest(float Principle, float Rate, float Time )
    {
        if ( (Principle >= 0) && (0 <= Rate && Rate <= 100) && (Time >= 0 ))
        {
            P = Principle; R = Rate;  T = Time;
        }
        else
        {
            std::cout << "Please enter P > 0 and Rate betweem [0,100] \% and Time in year > 0" << std::endl;
            exit(1);
        }
    }

    float get_interest()
    {
        return (P*R*T)/100;
    }

    float get_totalAmount()
    {
        return (P + this->get_interest());
    }
};