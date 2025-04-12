#pragma once
#include <iostream>

class Animal 
    : public Organism {

public:
    Animal(int strength, int initiative);
    
    void action() override; //override - bedizemy napisywac
    CollisionResult collision(Organism* o) override;
    void print() override;
    bool isAnimal() const override;
    bool isPlant() const override;
    virtual bool isAttackCountered(Animal* a) const;
    virtual bool isAttackRepelled(Animal* a) const;
    virtual bool escapeAttack();
    
};