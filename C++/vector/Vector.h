#ifndef VECTOR_H
#define VECTOR_H

class Vector{
private:
    int num;
    int *m_ptr;
    int cp;


public:
    Vector(): num(0), cp(0) { m_ptr=new int[0];}
    Vector(const Vector& vec){
        num = vec.num;
        cp = vec.cp;
        m_ptr = new int[num];
        for(int i=0; i != vec.num; ++i){
            m_ptr[i] = vec.m_ptr[i];
        }

    }

    //push_back, pop_back, size, operator[]

    void push_back(const int& val){
        int prev_num = num++;

        if(cp == 0){
            cp=1;
            int *tmp_ptr = new int[cp];
            tmp_ptr[0] = val;
            delete[] m_ptr;
            m_ptr = tmp_ptr;
        }

        else if(cp == prev_num){
            cp = 2*cp;
            int *tmp_ptr = new int[cp];
            for(int i=0; i < prev_num; ++i){
                tmp_ptr[i] = m_ptr[i];
            }
            tmp_ptr[num-1] = val;
            delete[] m_ptr;
            m_ptr = tmp_ptr;
        }
        else{
            m_ptr[num-1] = val;
        }
    }

    void pop_back(){ --num; }
    int size() const {return num;}

    int operator[](const int& num_elem) {return *(m_ptr+num_elem);}
    Vector& operator=(const Vector& vec) {
        if(this == &vec){
            return *this;
        }
        delete[] m_ptr;
        num = vec.num;
        cp = vec.cp;
        m_ptr = new int[num];
        for(int i=0; i != num; ++i){
            m_ptr[i] = vec.m_ptr[i];
        }
        return *this;
    }

    ~Vector(){delete[] m_ptr;}
};


#endif // VECTOR_H
