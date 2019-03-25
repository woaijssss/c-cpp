
#ifndef __ABSTRACTION_H__
#define __ABSTRACTION_H__

class AbstractionImp;

class Abstraction {
public:
        virtual ~Abstraction();

        virtual void operation() = 0;

protected:
        Abstraction();

private:

};

class RefinedAbstraction: public Abstraction {
public:
        RefinedAbstraction(AbstractionImp* imp);
        ~RefinedAbstraction();

        virtual void operation();

protected:

private:
        AbstractionImp* _imp;
};

#endif  // __ABSTRACTION_H__
