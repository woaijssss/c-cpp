
#ifndef __ADAPTER_H__
#define __ADAPTER_H__

class Target {
public:
        Target();

        virtual ~Target();

        virtual void request();
};

class Adaptee {
public:
        Adaptee();

        ~Adaptee();

        void specificRequest();
};

class Adapter: public Target, private Adaptee {
public:
        Adapter(Adaptee* ade);
        ~Adapter();
        void request();

private:
        Adaptee* _ade;
};

#endif  // __ADAPTER_H__
