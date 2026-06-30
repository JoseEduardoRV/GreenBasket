#include <stdexcept>

#include "sectioninfo.h"

void SectionInfo::valdateId(int id)
{
    if (id < 0)
        throw std::invalid_argument("Product Category id must be greater than zero");
}

void SectionInfo::valdateName(std::string_view name)
{
    if (name.empty())
        throw std::invalid_argument("Product Category name cannot be empty");
}

SectionInfo::SectionInfo(std::string_view name, int id)
    : m_id{id}
    , m_name{name}
{
    valdateId(id);
    valdateName(name);
}

SectionInfo::SectionInfo(const SectionInfo &other)
    : m_id{other.m_id}
    , m_name{other.m_name}

{

}

bool SectionInfo::operator==(const SectionInfo &other) const
{
    return m_id == other.m_id;
}
