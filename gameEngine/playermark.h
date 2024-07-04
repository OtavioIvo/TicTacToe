#ifndef PLAYERMARK_H
#define PLAYERMARK_H

#include <memory>


template<class Base, class Child>
class M : public Base
{
protected:
    M() : Base() {};
public:
    static std::shared_ptr<Base> Create() {return std::static_pointer_cast<Base>(std::make_shared<Child>()); }
};




class MarkBase : public std::enable_shared_from_this<MarkBase>
{
protected:
    MarkBase() {};
public:

    std::shared_ptr<MarkBase> MakeMark() { return shared_from_this(); }
    virtual ~MarkBase() {}
};




class MarkMachine : public M<MarkBase, MarkMachine>
{
//MarkMachine() : M() {}
    public:
    //static std::shared_ptr<MarkBase> Create() { return std::make_shared<MarkMachine>(); }
    ~MarkMachine() {}
};

class MarkUser : public M<MarkBase, MarkUser>
{

public:
  //  MarkUser() : M() {}
    ~MarkUser() {}
};

#endif // PLAYERMARK_H
