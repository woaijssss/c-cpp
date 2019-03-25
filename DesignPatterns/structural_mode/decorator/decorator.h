
#ifndef __DECORATOR_H__
#define __DECORATOR_H__

class Component {
public:
        virtual ~Component();
        virtual void operation();

protected:
        Component();
};

class ConcreteComponent: public Component {
public:
        ConcreteComponent();
        ~ConcreteComponent();

        void operation();
};

class Decorator: public Component {
public:
        Decorator(Component* com);

        virtual ~Decorator();

        void operation();

protected:
        Component* _com;
};

class ConcreteDecorator: public Decorator {
public:
        ConcreteDecorator(Component* com);
        ~ConcreteDecorator();

        void operation();

        void addedBehavior();
};

#endif  // __DECORATOR_H__
