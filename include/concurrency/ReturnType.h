#ifndef RETURNTYPE_H
#define RETURNTYPE_H


enum Type { FAILURE, SUCCESS, UNKNOWN };
class ReturnType {

protected:
    Type type;
    void* returnData;
public:
    ReturnType(Type t, void *returnData) : type(t), returnData(returnData)
    {
    }

    void setData(void *data)
    {
        returnData = data;
    }
};
#endif