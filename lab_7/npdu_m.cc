//
// Generated file, do not edit! Created by nedtool 4.6 from npdu.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "npdu_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(Npdu);

Npdu::Npdu(const char *name, int kind) : ::cPacket(name,kind)
{
    this->id_var = 0;
    this->type_var = 0;
    this->src_var = 0;
    this->dest_var = 0;
    this->del_var = 0;
}

Npdu::Npdu(const Npdu& other) : ::cPacket(other)
{
    copy(other);
}

Npdu::~Npdu()
{
}

Npdu& Npdu::operator=(const Npdu& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Npdu::copy(const Npdu& other)
{
    this->id_var = other.id_var;
    this->type_var = other.type_var;
    this->src_var = other.src_var;
    this->dest_var = other.dest_var;
    this->del_var = other.del_var;
    this->mtab_var = other.mtab_var;
}

void Npdu::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->id_var);
    doPacking(b,this->type_var);
    doPacking(b,this->src_var);
    doPacking(b,this->dest_var);
    doPacking(b,this->del_var);
    doPacking(b,this->mtab_var);
}

void Npdu::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->id_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->src_var);
    doUnpacking(b,this->dest_var);
    doUnpacking(b,this->del_var);
    doUnpacking(b,this->mtab_var);
}

int Npdu::getId() const
{
    return id_var;
}

void Npdu::setId(int id)
{
    this->id_var = id;
}

int Npdu::getType() const
{
    return type_var;
}

void Npdu::setType(int type)
{
    this->type_var = type;
}

int Npdu::getSrc() const
{
    return src_var;
}

void Npdu::setSrc(int src)
{
    this->src_var = src;
}

int Npdu::getDest() const
{
    return dest_var;
}

void Npdu::setDest(int dest)
{
    this->dest_var = dest;
}

simtime_t Npdu::getDel() const
{
    return del_var;
}

void Npdu::setDel(simtime_t del)
{
    this->del_var = del;
}

Tmp& Npdu::getMtab()
{
    return mtab_var;
}

void Npdu::setMtab(const Tmp& mtab)
{
    this->mtab_var = mtab;
}

class NpduDescriptor : public cClassDescriptor
{
  public:
    NpduDescriptor();
    virtual ~NpduDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(NpduDescriptor);

NpduDescriptor::NpduDescriptor() : cClassDescriptor("Npdu", "cPacket")
{
}

NpduDescriptor::~NpduDescriptor()
{
}

bool NpduDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Npdu *>(obj)!=NULL;
}

const char *NpduDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int NpduDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int NpduDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *NpduDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "id",
        "type",
        "src",
        "dest",
        "del",
        "mtab",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int NpduDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "del")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "mtab")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *NpduDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "simtime_t",
        "Tmp",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *NpduDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int NpduDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Npdu *pp = (Npdu *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string NpduDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Npdu *pp = (Npdu *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return long2string(pp->getType());
        case 2: return long2string(pp->getSrc());
        case 3: return long2string(pp->getDest());
        case 4: return double2string(pp->getDel());
        case 5: {std::stringstream out; out << pp->getMtab(); return out.str();}
        default: return "";
    }
}

bool NpduDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Npdu *pp = (Npdu *)object; (void)pp;
    switch (field) {
        case 0: pp->setId(string2long(value)); return true;
        case 1: pp->setType(string2long(value)); return true;
        case 2: pp->setSrc(string2long(value)); return true;
        case 3: pp->setDest(string2long(value)); return true;
        case 4: pp->setDel(string2double(value)); return true;
        default: return false;
    }
}

const char *NpduDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 5: return opp_typename(typeid(Tmp));
        default: return NULL;
    };
}

void *NpduDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Npdu *pp = (Npdu *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getMtab()); break;
        default: return NULL;
    }
}


