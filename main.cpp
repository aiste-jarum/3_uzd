#include "iostream"
#define ll long long
#include <vector>
#include <chrono>
using namespace std::chrono;

// template naudojama, kad butu galima deklaruoti bet kokio tipo vektoriu
template <typename DT>
class GenericMyVector {
private:
    DT* arr;

    // vektoriaus dabartinis dydis
    ll capacity;

    // vektoriaus ilgis
    ll length;

public:
    explicit GenericMyVector(ll = 100);

    // kiek elementu po push back funkcijos
    ll push_back(DT);

    // pop_back elementas
    DT pop_back();

    // vektorius dydis
    ll size() const;
    DT& operator[](ll);

    // iteratoriu klase
    class iterator {
    private:
        // dinaminis masyvas su pointeriais
        DT* ptr;

    public:
        explicit iterator()
            : ptr(nullptr)
        {
        }
        explicit iterator(DT* p)
            : ptr(p)
        {
        }
        bool operator==(const iterator& rhs) const
        {
            return ptr == rhs.ptr;
        }
        bool operator!=(const iterator& rhs) const
        {
            return !(*this == rhs);
        }
        DT operator*() const
        {
            return *ptr;
        }
        iterator& operator++()
        {
            ++ptr;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp(*this);
            ++*this;
            return temp;
        }
    };

    // pradzios iteratorius
    iterator begin() const;

    // pabaigos iteratorius
    iterator end() const;
};

// grazina vektoriaus dydi skirtingame tipe
template <typename DT>
GenericMyVector<DT>::GenericMyVector(ll n)
    : capacity(n), arr(new DT[n]), length(0)
{
}

// ideda elementa i norima vieta
template <typename DT>
ll GenericMyVector<DT>::push_back(DT data)
{
    if (length == capacity) {
        DT* old = arr;
        arr = new DT[capacity = capacity * 2];
        std::copy(old, old + length, arr);
        delete[] old;
    }
    arr[length++] = data;
    return length;
}

// popped back elementas
template <typename DT>
DT GenericMyVector<DT>::pop_back()
{
    return arr[length-- - 1];
}

// vektoriaus dydis
template <typename DT>
ll GenericMyVector<DT>::size() const
{
    return length;
}

//elemento per indeksa grazinimas
template <typename DT>
DT& GenericMyVector<DT>::operator[](ll index)
{
    // jeigu indeksas per didelis isveda klaida
    if (index >= length) {
        std::cout << "Error: Array index is too high - please choose existing index";
        exit(0);
    }

    //jeigu indeksas egzistuoja, grazina indeksa
    return *(arr + index);
}

// pradzios iteratorius
template <typename DT>
typename GenericMyVector<DT>::iterator
                      GenericMyVector<DT>::begin() const
{
    return iterator(arr);
}

// pabaigos iteratorius
template <typename DT>
typename GenericMyVector<DT>::iterator
                        GenericMyVector<DT>::end() const
{
    return iterator(arr + length);
}


template <typename V>
void display_vector(V& v)
{
    // iteratorius
    typename V::iterator ptr;
    for (ptr = v.begin(); ptr != v.end(); ptr++) {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';
}



    int main()
{
    /*   Operator[]
    //GenericMyVector<int> numbers {2, 4, 6, 8}; deklaravimas su skaliaustais neveikia, naudojama push back funkcija
    GenericMyVector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(6);
    numbers.push_back(8);
    std::cout << "Second element: " << numbers[1] << '\n';

    numbers[0] = 5;

    std::cout << "All numbers:";
    for (auto i : numbers) {
        std::cout << ' ' << i;
    }
    std::cout << '\n';
    */

    /*  Size
    //GenericMyVector<int> nums {1, 3, 5, 7}; deklaravimas su skaliaustais neveikia, naudojama push back funkcija
    GenericMyVector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(7);
    std::cout << "nums contains " << nums.size() << " elements.\n";
    */

    /* Operator==                   //vector klases pavyzdio nebuvo, todel parasytas naujas
    GenericMyVector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(10);
    if (numbers[0] == numbers[1])
    std::cout<<"Lygus"<<std::endl;
    */

    /* Operator!=                 //vector klases pavyzdzio nebuvo, todel parasytas naujas
    GenericMyVector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    if (numbers[0] != numbers[1])
    std::cout<<"Nelygus"<<std::endl;
    */
    /* Operator <=               //vector klases pavyzdzio nebuvo, todel parasytas naujas
    GenericMyVector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    if (numbers[0] <= numbers[1])
    std::cout<<"Salyga patenkinama"<<std::endl;
    */

    /* Su std::vector
        auto start = high_resolution_clock::now();
        unsigned int sz =  10000;  // 100000, 1000000, 10000000, 100000000
        std::vector<int> v1;
        for (int i = 1; i <= sz; ++i)
        v1.push_back(i);
        auto ending = high_resolution_clock::now();
        duration<double> diff = ending - start;
        std::cout << "Failas " << sz << " apdorotas ir isvesti rezultatai per " << diff.count() << " s." << std::endl;
    */

        /* Su sukurta vektoriaus klase
        auto start = high_resolution_clock::now();
        unsigned int sz =  100000000;  // 100000, 1000000, 10000000, 100000000
        GenericMyVector<int> v1;
        for (int i = 1; i <= sz; ++i)
        v1.push_back(i);
        auto ending = high_resolution_clock::now();
        duration<double> diff = ending - start;
        std::cout << "Failas " << sz << " apdorotas ir isvesti rezultatai per " << diff.count() << " s." << std::endl;
        */

}

