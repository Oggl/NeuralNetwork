#include <iostream>
#include "Neuron_Functors.h"
#include "Network.h"
#include "NetworkParameter.h"
#include "NeuronDatareader.h"

#include <vector>
#include <functional>
#include <type_traits>

using namespace std;

using stepnetwork = Network<STEP>;
using lognetwork =  Network<LOGISTIC>;
using linearnetwork =  Network<LINEAR>;
using nConnection = std::tuple<unsigned int, unsigned int, float>;
using sigmoid_sym = Network<SIGMOID_SYM>;

int main(int argc, char ** argv)
{

    //stepnetwork network({5,5,5});
    //network.Allocate();
    try
    {

        NeuronDatareader * reader;
        reader = new NeuronDatareader(argv[1], argv[2]);
        //std::cout<< reader->GetInputSize() << std::endl;
        /*unsigned int flags = 0;


        std::vector<nConnection> conn = {
                                        std::make_tuple(0,5,0.5),std::make_tuple(1,5,0.5),std::make_tuple(2,5, 0.5),
                                        std::make_tuple(1,6,0.5),std::make_tuple(2,6,0.5),std::make_tuple(3,6,0.5),
                                        std::make_tuple(2,7,0.5),std::make_tuple(3,7,0.5),std::make_tuple(4,7,0.5),
                                        std::make_tuple(5,8,0.5),std::make_tuple(6,8,0.5),std::make_tuple(7,8,0.5),
                                        std::make_tuple(5,9,0.5),std::make_tuple(6,9,0.5),std::make_tuple(7,9,0.5),
                                        std::make_tuple(5,10,0.5),std::make_tuple(6,10,0.5),std::make_tuple(7,10,0.5),
                                        std::make_tuple(8,11,1),std::make_tuple(9,12,1),std::make_tuple(10,13 ,1)
                                        };

        unsigned int flags_ = 0;
        flags_ |= _FL_INIT_NW_;

        lognetwork network2({5,3,3,3}, conn, flags_);

        flags |= _FL_CONN_FF_;
        flags |= _FL_INIT_NW_;
        lognetwork network({reader->GetInputSize(), 30, 10},flags);
        network.TrainWithGD(reader);
        network2.Allocate();


        auto test = network2.GetResult();

        cout << *test << std::endl;
        network2.SetInput({0,1,2,3,4});
        //network2.Update();
        */

        unsigned int fl = 0;
        fl |= _FL_CONN_FF_;
        fl |= _FL_INIT_RAND_;
        //fl |= _FL_INIT_NW_;
        lognetwork network3({reader->GetInputSize(),100,10}, fl);

        //lognetwork network3({2,10,1},fl);

        //NeuronDatareader * reader;

        /*
        reader = new NeuronDatareader({
                                        {0,0,0},{0,0,0},
                                        {0,0,1},{0,1,0},{1,0,0},
                                        {0,1,1},{1,0,1},{1,1,0},
                                        {1,1,1}, {1,1,1}
                                      },
                                      {
                                        //{1,-1,-1,-1},{-1,1,-1,-1},{-1,1,-1,-1},{-1,1,-1,-1},
                                        //{-1,-1,1,-1},{-1,-1,1,-1},{-1,-1,1,-1},
                                        //{-1,-1,-1,1}
                                        {1,0,0,0},{1,0,0,0},
                                        {0,1,0,0},{0,1,0,0},{0,1,0,0},
                                        {0,0,1,0},{0,0,1,0},{0,0,1,0},
                                        {0,0,0,1}, {0,0,0,1}
                                      }
                                      );
                                      */
        //reader = new NeuronDatareader({{1,1},{0,1},{1,0},{0,0}},{{0},{1},{1},{0}});
        //network3.PrintNetwork();
        int batch_size =  10;
        network3.TrainWithGD(reader, 0.3f, 1);

    }
    catch(int errorflag)
    {
        if(errorflag == _EXP_FLAG_READ)
        {
            std::cout << "Data stream error!" << std::endl;
        }
    }
    catch(...)
    {
        std::cout << "Error!" << std::endl;
    }
    /*
    stepnetwork network({5,5,5});
    std::function<int(char)> myFun;

    myFun = foo;

    myFun = [] (char c) -> int { return c; };

    std::result_of<STEP(int)>::type bla;
    */
}
