#include <iostream>


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
    int max_size();
    void the_pop_back();
    void resize(int i);
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

void myvector::the_pop_back ()
{
    vsize--;
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

int myvector::max_size()
{
    return maxsize;
}


void myvector::resize(int i)
{
    vsize = i;
}

int main()
{
    myvector nums;
    nums.the_push_back(1);
    nums.the_push_back(3);
    nums.the_push_back(5);
    nums.the_push_back(7);
    std::cout << "nums contains " << nums.size() << " elements.\n";
}
