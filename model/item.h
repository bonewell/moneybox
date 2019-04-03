#ifndef MODEL_ITEM_H
#define MODEL_ITEM_H

#include <string>

namespace model {

class Item
{
public:
    void save();
    void fetch(int id);
    void load();

    int id;
    long long amount;
    std::string desc;
};
}  // namespace model

#endif // MODEL_ITEM_H
