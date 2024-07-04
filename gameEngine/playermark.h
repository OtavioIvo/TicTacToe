#ifndef PLAYERMARK_H
#define PLAYERMARK_H

#include <memory>


class Mark : public std::enable_shared_from_this<Mark>
{
public:
    std::shared_ptr<Mark> MakeMark() { return shared_from_this(); }
    virtual ~Mark() {}
};

class MarkMachine : public Mark
{
private:
    struct Private{ explicit Private() = default; };
public:
    MarkMachine(Private) {}
    static std::shared_ptr<Mark> Create() {return std::make_shared<MarkMachine>(Private()); }
    ~MarkMachine() {}
};

class MarkUser : public Mark
{
private:
    struct Private{ explicit Private() = default; };
public:
    MarkUser(Private) {}
    static std::shared_ptr<Mark> Create() {return std::make_shared<MarkUser>(Private()); }
    ~MarkUser() {}
};

#endif // PLAYERMARK_H
