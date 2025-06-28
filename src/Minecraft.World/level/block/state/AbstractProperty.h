#pragma once

#include <string>
#include <typeinfo>

class Boxed;
class Property {
    virtual std::wstring getName() const = 0;
    virtual std::wstring getName(Boxed const*) const = 0;
    virtual int getPossibleValues() const = 0;
    virtual const std::type_info& getValueClass() const = 0;
    virtual Boxed* getValue(const std::wstring&) const = 0;
    virtual std::wstring toString() const = 0;
    virtual bool equals(Property const*) const = 0;
    virtual int hashCode() const = 0;
    virtual int getValueCount() const = 0;
    virtual int getValueAtIndex(unsigned int) const = 0;
    virtual int getIndexForValue(Boxed*) const = 0;
};

template <typename T>
class AbstractProperty : public Property {
public:
    virtual std::wstring getName() const override;
    virtual int getPossibleValues() const override;
    virtual const std::type_info& getValueClass() const override;
    virtual Boxed* getValue(const std::wstring&) const override;
    virtual std::wstring toString() const override;
    virtual bool equals(Property const*) const override;
    virtual int hashCode() const override;
    virtual std::wstring getName(const int&) const = 0;
    virtual int getUnboxedValue(const std::wstring&) const = 0;
};
