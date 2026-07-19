#ifndef ADDTICKET_H
#define ADDTICKET_H

template <typename T>
class AddTicket : public ICommand
{

    std::list<T*> &m_list;

    T *createTicket()
    {
        return new T();
    }

    void addTicket(T *item)
    {
        if (!item) {
            return;
        }

        m_list.emplace_back(item);
    }

public:

    explicit AddTicket(std::list<T*> &list)
        : m_list{list}
    {

    }

    void execute() override
    {
        T *item = createTicket();

        // Algoritmo de configuración para agregar datos cuando un ticket nuevo se crea.

        addTicket(item);
    }

    T *createdItem() const
    {
        if (m_list.empty()) {
            return nullptr;
        }

        return m_list.back();
    }
};

#endif // ADDTICKET_H
