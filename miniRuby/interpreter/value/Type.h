#ifndef TYPE_H
#define TYPE_H
#include <string>
class Type {
    public:
        enum ValueType {
            IntegerType,
            ArrayType,
            StringType
        };

        Type(Type::ValueType type) : m_type(type) {}
        virtual ~Type() {}
		virtual std::string str() = 0;
        virtual Type::ValueType type(){return m_type;};

    private:
        enum ValueType m_type;
};

#endif
