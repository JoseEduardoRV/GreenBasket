#ifndef PRODUCTCATEGORY_H
#define PRODUCTCATEGORY_H

#include <string>
#include <string_view>

class SectionInfo
{
    int m_id;
    std::string m_name;

    static void valdateId(int id);
    static void valdateName(std::string_view name);

public:
    explicit SectionInfo(std::string_view name, int id = 0);

    SectionInfo(const SectionInfo & other);

    ~SectionInfo() = default;

    bool operator==(const SectionInfo &other) const;

    int id() const { return m_id; }

    std::string_view name() const { return m_name; }
};

#endif // PRODUCTCATEGORY_H
