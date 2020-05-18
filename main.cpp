#include <iostream>
#include <chrono>
#include <vector>

using namespace std::chrono;

class myvector
{
private:
    int vsize;
    int maxsize;
    int* anarray;
    void alloc_new();
public:
    myvector();
    myvector(int);
    myvector(const myvector&);
    ~myvector();
    void the_push_back(int);
    int size();
    int operator[] (int);
    myvector& operator+=(int);
    int at(int i);
    myvector& operator=(const myvector&);
};

myvector::myvector()
{
    maxsize = 10;
    anarray = new int[maxsize];
    vsize = 0;
}

myvector::myvector(int i)
{
    maxsize = i;
    anarray = new int[maxsize];
    vsize = 0;
}

myvector::myvector(const myvector& v)
{
    maxsize = v.maxsize;
    vsize = v.vsize;
    anarray = new int[maxsize];
    for (int i =0; i < v.vsize; i++)
        anarray[i] = v.anarray[i];
}

myvector::~myvector()
{
    delete[] anarray;
}

void myvector::the_push_back(int i)
{
        if(vsize + 1 > maxsize)
            alloc_new();
        anarray[vsize] = i;
        vsize++;
}

int myvector::operator[] (int i)
{
    return anarray[i];
}

int myvector::at(int i)
{
    if (i < vsize)
        return anarray[i];
}

void myvector::alloc_new()
{
    maxsize = vsize * 2;
    int* temporary = new int[maxsize];
    for (int i = 0; i < vsize; i++)
    {
        temporary[i] = anarray[i];
    }
    delete[] anarray;
    anarray = temporary;
}

int myvector:: size()
{
    return vsize;
}

myvector& myvector::operator+=(int i)
{
    this->the_push_back(i);
    return *this;
}

myvector& myvector::operator=(const myvector& v)
{
    if (this != &v)
    {
        maxsize = v.maxsize;
        vsize = v.vsize;
        delete[] anarray;
        anarray= new int[maxsize];
        for (int i = 0; i < v.vsize; i++)
            anarray[i] = v.anarray[i];
    }
    return *this;
}

int main()
{
    int sz = 10000;

    for (int j = 0; j < 5; j++)
    {   auto start = high_resolution_clock::now();
        myvector v2;
        for (int i = 1; i <sz; i++)
             v2.the_push_back(i);
        auto ending = high_resolution_clock::now();
        duration<double> diff = ending - start;
        std::cout << "Padaryta vektoriu uzpildyti "<< sz << " reiksmiu uztruko "<<diff.count()<<" s."<<std::endl;

        /*auto start2 = high_resolution_clock::now();
        std::vector<int> v;
        for (int i = 1; i < sz; i++)
            v.push_back(i);
        auto ending2 = high_resolution_clock::now();
        duration<double> diff2 = ending2 - start2;
        std::cout << "STD bibliotekos vektoriu uzpildyti "<<sz<<" reiksmiu uztruko "<<diff2.count()<<" s."<<std::endl;
        */
        sz *= 10;
        std::cout<<std::endl;

    }

}
