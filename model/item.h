#ifndef MODEL_ITEM_H
#define MODEL_ITEM_H

namespace model {

/**
 * @brief The Item class
 */
class Item
{
public:
    void save();
    void fetch();
    void load();

protected:
    ~Item() = default;
};
}  // namespace model

#endif // MODEL_ITEM_H
