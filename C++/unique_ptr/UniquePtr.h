#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

template<class T>
class UniquePtr{
    T *m_ptr;

public:
    UniquePtr(){m_ptr=nullptr;}

    ~UniquePtr(){delete m_ptr;}

};



#endif // UNIQUEPTR_H
