#include <iostream>

using namespace std;

class coada
{
private:
    int *value;
    int idx_push, idx_pop;

public:
    coada()
    {
        value = new int[100];
        idx_push = idx_pop = -1;
    }

    void push(int x)
    {
        if (idx_pop == -1)
        {
            idx_pop = 0;
        }
        idx_push += 1; // in the case above idx_push is also -1 so both will be 0 the first value
        value[idx_push] = x;
    }

    int pop()
    {
        if (idx_pop != -1)
        {
            int aux = value[idx_pop];
            for (int i = 0; i < idx_push; i++)
            {
                value[i] = value[i + 1];
            }
            if (idx_push == 0)
            {
                delete value;
                idx_pop = -1;
            }

            idx_push -= 1;
            return aux;
        }
    }

    int idx_popGetter()
    {
        return this->idx_pop;
    }

    int idx_pushGetter()
    {
        return this->idx_push;
    }



    bool afisare()
    {
        if (idx_pop == - 1)
            return 0;
        else
        {
             for (int i = idx_pop; i <= idx_push; i++)
                cout<<this->value[i]<<" ";
             cout<<endl;
        }
        return 1;
    }

    coada& operator=(const coada& c)
    {
        if (this != &c)
        {
            if (this->value != NULL)
                delete[] value;
            this -> idx_pop = c.idx_pop;
            this -> idx_push = c.idx_push;
            this -> value = new int[100];
            for (int i = this -> idx_pop; i <= this -> idx_push; i++)
                this->value[i] = c.value[i];
        }
        return *this;
    }

    ~coada()
    {
        delete[] value;
    }

};


class stiva_2_cozi
{
private:
    coada one, two;
public:
    stiva_2_cozi()
    {

    }

    void push(int x)
    {
        two.push(x);
        int aux;
        aux = one.idx_pushGetter();
        while (aux != -1)
        {
            int y;
            y = one.pop();
            two.push(y);
            aux = one.idx_pushGetter();
        }
        one = two;
        aux = two.idx_pushGetter();
        while (aux != -1)
        {
            int y;
            y = two.pop();
            aux = two.idx_pushGetter();
        }
    }

    void pop()
    {
        if (one.idx_popGetter() == -1)
            cout<<"Stiva este goala"<<endl;
        else
        {
            cout<<one.pop()<<endl;
        }

    }

    void afisare()
    {
        if (!one.afisare())
            cout<<"Stiva goala"<<endl;
    }

    ~stiva_2_cozi()
    {

    }
};


int main()
{
    /*
    coada c;
    c.push(1);
    c.push(2);
    c.push(5);
    c.push(3);
    c.afisare();
    c.pop();
    c.afisare();
    c.pop();
    c.pop();
    c.pop();
    c.afisare();
    */

    stiva_2_cozi s;
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(3);
    s.afisare();
    s.pop();
    s.pop();
    s.afisare();
    s.pop();
    s.pop();
    s.afisare();
    s.push(5);
    s.afisare();
    return 0;
}
