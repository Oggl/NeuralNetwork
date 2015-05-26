#ifndef _NEURON_FUNCTORS_H_
#define _NEURON_FUNCTORS_H_

#include <cmath>


/*
Flags for network setup.
Not Used|Not Used|Connection Type Flags|Init Weigth and BIAS Flags
0000 0000 | 0000 0000 | 0000 0000 | 0000 0000


*/

#define _FL_INIT_RAND_ 0x00000001 //Pure Random Init
#define _FL_INIT_GAUSS_ 0x00000002 //Gaussian Init
#define _FL_INIT_NW_ 0x00000004 //Nguyen-Widrow Init
#define _FL_CONN_FF_  0x00000100 //Feedforward-Config

#define _EXP_FLAG_READ 0x00000001
#define _EXP_FLAG_DATA 0x00000002

class STEP
{
private:

public:
    STEP(){}

    int operator()(float c){
    return (c < 0)?(0):(1);
    }

    float prime(float c) const
    {
        return 0;
        //return LOGISTIC::LOGISTIC(c)*(1.0f - LOGISTIC(c));
    }
};

class LOGISTIC
{
private:

public:
    LOGISTIC(){}

    float operator()(float c) const
    {
        if(c < -45.0)
        {
            return 0.0f;
        }
        else if(c > 45.0)
        {
            return 1.0f;
        }
        else
        {
            return 1.0f/(1.0f + std::exp(-c));
        }
    }

    float prime(float c) const
    {
        return LOGISTIC()(c)*(1.0f - LOGISTIC()(c));
        //return LOGISTIC::LOGISTIC(c)*(1.0f - LOGISTIC(c));
    }
};

class HYPERBOLIC
{
private:

public:
    HYPERBOLIC(){}

    int operator()(float c){
    return tanhf(c);
    }
};

class SIGMOID_SYM
{
private:

public:
    SIGMOID_SYM(){}

    float operator()(float c)
    {
        return (2.0f/(1.0f + std::exp(-c))) - 1.0f;
    }

    float prime(float c)
    {
        return (2.0f*std::exp(c))/std::pow(std::exp(c)+1.0f,2.0f);//SIGMOID_SYM()(c)*(1.0f - SIGMOID_SYM()(c));
    }

};

class LINEAR
{
private:
public:
    LINEAR(){}

    float operator()(float c){
        if(c < -0.5f)
        {
            return 0.0f;
        }
        else if(c > 0.5f)
        {
            return 1.0f;
        }
        else
        {
            return c + 0.5f;
        }

    }

    float prime(float c) const
    {
        if(c < -0.5f)
        {
            return 0.0f;
        }
        else if(c > 0.5f)
        {
            return 0.0f;
        }
        else
        {
            return 1.0f;
        }
    }

};

//Flags


#endif // _NEURON_FUNCTORS_H_
